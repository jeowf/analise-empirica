#include <iostream>

namespace edb{
	template <typename T> 
	T * linearSearch(T *first, T *last, T value){
		while (first != last){
			if (*first == value)
				return first;
			first++;
		}

		return last;
	}

	template <typename T> 
	T * iteBinarySearch(T *first, T *last, T value){

		int i = last - first;
		auto notfound = last;

		while (first < last){
			i /= 2;

			if (first[i] == value)
				return first + i;
			else if (value < first[i] )
				last = first + i + 1;
			else
				first += i + 1;
		}

		return notfound;
	}

	template <typename T> 
	T * recBinarySearch(T *first, T *last, T value){

		int i = (last - first)/2;
		auto notfound = last;
		int a = last - first;

		 if (first >= last){
		 	//std::cout << " TESTE: " << *last << std::endl;
		 	return last;
		 }
		
		if (first[i] == value)
			return first + i;
		else if (value < first[i] )
			recBinarySearch(first, first + i, value);
		else
			recBinarySearch(first + i + 1, last, value);

		//return last;
		//return notfound;
		
	}

	template <typename T> 
	T * iteTernarySearch(T *first, T *last, T value){

		int i = last - first;
		auto notfound = last;

		while (first < last){
			i /= 3;

			if (first[i] == value){
				return first + i;
			}else if (first[2*i] == value){
				return first + 2 * i;
			}else if (value < first[i]){ //se o valor está dentro do primeiro 1 terço do vetor
				last = first + i;
			}else if (value > first[2*i]){ //se o valor está dentro do ultimo 1 terço do vetor
				first += 2*i + 1;
			} else{ //se o valor está dentro do 1 terço do meio
				first += i + 1;
				last = first + i;
			}
		}

		return notfound;
	}

	template <typename T> 
	T * recTernarySearch(T *first, T *last, T value){

		int i = last - first;
		auto notfound = last;

		while (first < last){
			i /= 3;

			if (first[i] == value){
				return first + i;
			}else if (first[2*i] == value){ 
				return first + 2 * i;
			}else if (value < first[i]){
				last = first + i;
			}else if (value > first[2*i]){
				first += 2*i + 1;
			} else{
				first += i + 1;
				last = first + i;
			}
		}

		return notfound;
	}



}    
