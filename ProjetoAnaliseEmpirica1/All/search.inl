// #include <iostream>
// #include <math.h>//sqrt jumpSearch
// #include <algorithm>//min fibSearch

namespace edb{
	
	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int linearSearch(T *first, T *last, T value){
		auto _first = first; // primeira posição do arranjo
		//Verdadeiro até encontrar o valor ou chegar na ultima posição
		while (first != last){
			if (*first == value)
				return first - _first;
			first++;
		}
		//se não encontrar retorna -1
		return NOT_FOUND;
	}

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int iteBinarySearch(T *first, T *last, T value){//Binaria Iterativa
		
		auto _first = first;//salva a primeira posição
		int i = last - first;// tamanho do vetor

		while (first < last - 1){ //enteder pq o -1 funfa kkkkkk
			i /= 2;// pega o meio do vetor

			if (first[i] == value)// olha o elemento do meio e retorna se verdadeiro
				return first + i - _first;
			else if (value < first[i] )// olha os elementos anteriores
				last = first + i + 1;
			else // olha os elementos posteriores
				first += i + 1;
		}
		//se não encrontrar
		return NOT_FOUND;
	}

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int recBinarySearch(T *first, T *last, T value){
		return recBinarySearch(first,last,value, first);
	}

	template <typename T> 
	int recBinarySearch(T *first, T *last, T value, T *_first){//Binario recursivo
		// verifica a posição do first
		if (first >= last)
			return NOT_FOUND;
		
		int i = (last - first)/2;//metade do vetor

	 	if (first[i] == value) // se achar retorne o indice
			return first + i - _first;
		else if (value < first[i] )// se for menor chame novamente com o um novo last
			recBinarySearch(first, first + i, value, _first);
		else//senão chame com um novo first no meio do array
			recBinarySearch(first + i + 1, last, value, _first);
			
	}

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int iteTernarySearch(T *first, T *last, T value){
		//pega o primeiro indice
		auto _first = first;
		int i = last - first;// tamanho do array
		//enquanto a posição do first não passar limite
		while (first < last){
			i /= 3; //divide o array em 3

			if (first[i] == value){// se for o primeiro divisor
				return first + i - _first;
			}else if (first[2*i] == value){//se for o segundo divisor
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

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int recTernarySearch(T *first, T *last, T value){

		return recTernarySearch(first, last, value, first);
	}

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int recTernarySearch(T *first, T *last, T value, T *_first){
		//se a posição do first passar limite
		if (first >= last)
			return NOT_FOUND;

		int i = (last - first)/3;//divide o vetor em 3

		if (first[i] == value)// se achar no primeiro divisor retorne o indice
			return first + i - _first;

		else if (first[2*i] == value)//procure no segundo
			return first + 2 * i - _first;

		else if (value < first[i])//se for menor q o primeiro divisor chama a função pro primeiro terço
			recTernarySearch(first, first + i, value, _first);

		else if (value > first[2*i])//se for maior q o segundo divisor chama a função pro ultimp terço
			recTernarySearch(first + 2*i + 1, last, value, _first);

		else//se não chama a função pro terço do meio
			recTernarySearch (first + i + 1 , first + 2*i , value, _first);
	}

	//Retorna o índice de um elemento num intervalo
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

		//enquanto for possível
		while (first[l - 1] < value){
			l += m;
			f += m;

			if (f >= n)
				return NOT_FOUND;

			if (l >= n)
				l = n;
		}
		//faz uma busca linear no subvetor
		return (linearSearch(first + f, first + l, value) + f);
	}

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int fibSearch(T *first, T *last, T value){
		int f1 = 0;
		int f2 = 1;
		int f3 = f1 + f2;
		int i = last - first;
		// Encontrar o menor termo de fibonnaci maior que o tamanho do array
		while(f3 < i){
			f1 = f2;
			f2 = f3;
			f3 = f1 + f2;
		}
		//verificador se os indices estão dentro do vetor
		int lim = -1;

		while(f3 > 1){
			int val = std::min(lim+f1,i-1);// retorna o menor elemento

			if(first[val] > value){//se for menor que o valor cada elemento volta dois termo na sequencia de fibonnaci
				f3 = f1;
				f2 -= f1;
				f1 = f3 - f2;
			}else if(first[val] < value){//se for menor que o valor cada elemento volta um termo na sequencia
				f3 = f2;
				f2 = f1;
				f1 = f3 - f2;
				lim = val;
			}else{
				return val;// se for igual retorna o indice
			}
		}
		return NOT_FOUND;
	}

}    
