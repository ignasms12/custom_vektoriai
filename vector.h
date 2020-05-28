#include <iostream>


template <class T> class Vec {

	
	public: // interfeisas

		typedef T* iterator;
		typedef const T* const_iterator;
		typedef size_t size_type;
		typedef T value_type;

		// rule of three
		Vec() { create(); }

		explicit Vec(size_type n, const T& t = T{}) { create(n, t); }

		Vec(const Vec& v) { create(v.begin(), v.end()); }

		Vec& operator=(const Vec&);

		~Vec() { uncreate(); }

		T& operator[](size_type i) { return data[i]; }

		const T& operator[](size_type i) const { return data[i]; }
		int i = 0;
		void push_back (const T& t){
			if (avail == limit){
				grow();
				++i;
				std::cout << i << std::endl;
			}
			unchecked_append(t);
		}

		size_type size() const { return avail - data; }

		iterator begin() { return data; }

		const_iterator begin() const { return data; }

		iterator end() { return avail; }

		const_iterator end() const { return avail; }


	private:
		iterator data; // kaip buvo anksčiau
		iterator avail; // pirmasis po paskutiniojo sukonstruoto Vec elementas
		iterator limit; // pirmasis po paskutiniojo Vec elementas
		// atminties išskyrimo valdymui
		std::allocator<T> alloc; // objektas atminties valdymui
		// išskirti atmintį (array) ir ją inicializuoti
		void create() ;
		void create(size_type, const T&);
		void create(const_iterator, const_iterator);
		// sunaikinti elementus array ir atlaisvinti atmintį
		void uncreate();
		// pagalbinės funkcijos push_back realizacijai
		void grow();
		void unchecked_append(const T&);
};

template <class T> void Vec<T>::create() {
	data = avail = limit = nullptr;
}
template <class T> void Vec<T>::create(size_type n, const T& val) {
	data = alloc.allocate(n); // grąžina ptr į array pirmą elementą
	limit = avail = data + n; // sustato rodykles į vietas
	uninitialized_fill(data, limit, val); // inicializuoja elementus val reikšme
}
template <class T>
void Vec<T>::create(const_iterator i, const_iterator j) {
	data = alloc.allocate(j - i); // išskirti vietos j-i elementams
	limit = avail = std::uninitialized_copy(i, j, data); // nukopijuoja elementus iš intervalo
}

template <class T> void Vec<T>::uncreate() {
	if(data == nullptr){
		iterator it = avail;
		while (it != data)
		alloc.destroy(--it);
	}
	else if (data) {
		// sunaikinti (atbuline tvarka) sukonstruotus elementus
		iterator it = avail;
		while (it != data)
		alloc.destroy(--it);
		// atlaisvinti išskirtą atmintį. Turi būti data != nullptr
		alloc.deallocate(data, limit - data);
	}
	// reset'inam pointer'iuss - Vec'ius tuščias
	data = limit = avail = nullptr;
}

template <class T> void Vec<T>::grow() {
	// dvigubai daugiau vietos, nei buvo
	size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
	// išskirti naują vietą ir perkopijuoti egzistuojančius elementus
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);
	// atlaisvinti seną vietą
	uncreate();
	// reset'int rodykles į naujai išskirtą vietą
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}
// tariame, kad `avail` point'ina į išskirtą, bet neinicializuotą vietą
template <class T> void Vec<T>::unchecked_append(const T& val) {
	alloc.construct(avail++, val);
}

template <class T> Vec<T>& Vec<T>::operator=(const Vec& rhs) {
 // patikriname ar ne lygu
 if (&rhs != this) {
	// atlaisviname seną this objekto atmintį
	uncreate();
	// perkopijuojame elementus iš rhs į lhs (this)
	create(rhs.begin(), rhs.end());
 }
 return *this;
}