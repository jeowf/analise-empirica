// #include <iostream>
// #include <math.h>//sqrt jumpSearch
// #include <algorithm>//min fibSearch

namespace edb{
	template <typename T> 
	int linearSearch(T *first, T *last, T value){
		auto _first = first;

		while (first != last){
			if (*first == value)
				return first - _first;
			first++;
		}

		return NOT_FOUND;
	}

	template <typename T> 
	int iteBinarySearch(T *first, T *last, T value){

		auto _first = first;
		int i = last - first;

		while (first < last - 1){ //enteder pq o -1 funfa kkkkkk
			i /= 2;

			if (first[i] == value)
				return first + i - _first;
			else if (value < first[i] )
				last = first + i + 1;
			else
				first += i + 1;
		}

		return NOT_FOUND;
	}

	template <typename T> 
	int recBinarySearch(T *first, T *last, T value){
		return recBinarySearch(first,last,value, first);
	}

	template <typename T> 
	int recBinarySearch(T *first, T *last, T value, T *_first){

		if (first >= last)
			return NOT_FOUND;
		
		int i = (last - first)/2;

	 	if (first[i] == value)
			return first + i - _first;
		else if (value < first[i] )
			recBinarySearch(first, first + i, value, _first);
		else
			recBinarySearch(first + i + 1, last, value, _first);
			
	}

	template <typename T> 
	int iteTernarySearch(T *first, T *last, T value){

		auto _first = first;
		int i = last - first;

		while (first < last){
			i /= 3;

			if (first[i] == value){
				return first + i - _first;
			}else if (first[2*i] == value){
				return first + 2 * i - _first;
			}else if (value < first[i]){ //se o valor está dentro do primeiro 1 terço do vetor
				last = first + i;
			}else if (value > first[2*i]){ //se o valor está dentro do ultimo 1 terço do vetor
				first += 2*i + 1;
			} else{ //se o valor está dentro do 1 terço do meio
				first += i + 1;
				last = first + i;
			}
		}

		return NOT_FOUND;
	}

	template <typename T> 
	int recTernarySearch(T *first, T *last, T value){

		return recTernarySearch(first, last, value, first);
	}

	template <typename T> 
	int recTernarySearch(T *first, T *last, T value, T *_first){

		if (first >= last)
			return NOT_FOUND;

		int i = (last - first)/3;

		if (first[i] == value)
			return first + i - _first;

		else if (first[2*i] == value)
			return first + 2 * i - _first;

		else if (value < first[i])
			recTernarySearch(first, first + i, value, _first);

		else if (value > first[2*i])
			recTernarySearch(first + 2*i + 1, last, value, _first);

		else
			recTernarySearch (first + i + 1 , first + 2*i , value, _first);
	}

/*
	template <typename T> 
	int jumpSearch(T *first, T *last, T value){

		int i = last - first;
		int s = sqrt(i);
		int start = 0;
		int out = 0;
		while(start < i){
			if(value < first[start]){
				last = first + start + 1;
				out = linearSearch(first, last, value);
				return out;
			}	
			else{
				//evita que exerceda o limite do array.
				if(i - start < s){ 
					first += start;				
					out = linearSearch(first, last, value);

					if(out == -1){
						return out;
					}						
					else{
						return out + start;
					}
				}else{
					start += s;
				}
			}
		}
		return NOT_FOUND;
	}
*/
	template <typename T> 
	int jumpSearch(T *first, T *last, T value){
		int n = last - first;
		int m = sqrt(n);
		int f = 0;
		int l = m;

		//se o valor procurado for menor que o menor valor
		//então retorne NOT_FOUND
		if (value < *first)
			return NOT_FOUND;

		//enquanto for possível balbalbla
		while (first[l - 1] < value){
			l += m;
			f += m;

			if (f >= n)
				return NOT_FOUND;

			if (l >= n)
				l = n;
		}

		return (linearSearch(first + f, first + l, value) + f);
	}


	template <typename T> 
	int fibSearch(T *first, T *last, T value){
		int f1 = 0;
		int f2 = 1;
		int f3 = f1 + f2;
		int i = last - first;

		while(f3 < i){
			f1 = f2;
			f2 = f3;
			f3 = f1 + f2;
		}

		int lim = -1;

		while(f3 > 1){
			int val = std::min(lim+f1,i-1);

			if(first[val] > value){
				f3 = f1;
				f2 -= f1;
				f1 = f3 - f2;
			}else if(first[val] < value){
				f3 = f2;
				f2 = f1;
				f1 = f3 - f2;
				lim = val;
			}else{
				return val;
			}
		}
		return NOT_FOUND;
	}
/*
	template <typename T> 
	int fibSearch(T *first, T *last, T value){
		int n = last - first;
		int f1 = 0;			//F(1)
		int f2 = 1; 		//F(2)
		int fn = f1 + f2; 	//F(n) = F(n-1) + F(n-2)
		int offset = -1;

		while (fn < n){
			f1 = f2;
			f2 = fn;
			fn = f1 + f2;
		}

		while (fn > 1){


		}



		return NOT_FOUND;
	}*/
}    
