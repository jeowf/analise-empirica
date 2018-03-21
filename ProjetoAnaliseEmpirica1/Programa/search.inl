namespace edb{
	
	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int linearSearch(T *first, T *last, T value){
		auto _first = first; // primeira posição do arranjo

		//enquanto houver valores a serem comparados
		while (first != last){
			//verifica se um valor x é igual a value
			if (*first == value)
				return first - _first; //retorna o índice
			first++; //incrementa o ponteiro
		}

		return NOT_FOUND; //caso value não seja encontrado
	}

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int iteBinarySearch(T *first, T *last, T value){
		
		auto _first = first;  //primeira posição do arranjo
		int i = last - first; //tamanho do vetor

		//enquanto houver intervalos de, no mínimo, 1 valor
		while (first < last - 1){
			//divide o tamanho pela metade para
			//obter o índice de comparação
			i /= 2; 

			//se encontrar o elemento
			if (first[i] == value)
				return first + i - _first; //retorna o índice

			//se value é menor que o elemento inspecionado
			else if (value < first[i] )
				//restringe o intervalo para a primeira metade
				last = first + i + 1; 

			//se value é maior que o elemento inspecionado
			else 
				//restringe o intervalo para a segunda metade
				first += i + 1;
		}

		return NOT_FOUND; //caso value não seja encontrado
	}

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int recBinarySearch(T *first, T *last, T value){
		return recBinarySearch(first,last,value, first);
	}

	template <typename T> 
	int recBinarySearch(T *first, T *last, T value, T *_first){
		//se não há elemento para ser verificado
		if (first >= last)
			return NOT_FOUND; //value não foi encontrado
		
		int i = (last - first)/2; //metade do tamanho do array

		//se value for encontrado no indice i
	 	if (first[i] == value) 
			return first + i - _first; //retorna o índice

		//se value é menor que o elemento inspecionado
		else if (value < first[i] )
			//restringe o intervalo para a primeira metade
			recBinarySearch(first, first + i, value, _first);

		//se value é maior que o elemento inspecionado
		else
			//restringe o intervalo para a segunda metade
			recBinarySearch(first + i + 1, last, value, _first);
	}

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int iteTernarySearch(T *first, T *last, T value){
		auto _first = first; //primeira posição
		int i = last - first;//tamanho do array

		//enquanto houverem elementos a serem comparados
		while (first < last){
			i /= 3; //divide o array em 3

			//se value for encontrado no índice i
			if (first[i] == value){
				return first + i - _first; //retorna o índice

			//se value for encontrado no índice 2i
			}else if (first[2*i] == value){
				return first + 2 * i - _first; //retorna o índice

			//se o valor está dentro do primeiro 1 terço do vetor
			}else if (value < first[i]){ 
				//ajusta intervalo para o terço correspondente
				last = first + i;

			//se o valor está dentro do ultimo 1 terço do vetor
			}else if (value > first[2*i]){ 
				//ajusta intervalo para o terço correspondente
				first += 2*i + 1;

			//se o valor está dentro do 1 terço do meio
			} else{ 
				//ajusta intervalo para o terço correspondente
				first += i + 1;
				last = first + i;
			}
		}

		return NOT_FOUND; //caso value não seja encontrado
	}

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int recTernarySearch(T *first, T *last, T value){

		return recTernarySearch(first, last, value, first);
	}

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int recTernarySearch(T *first, T *last, T value, T *_first){
		//se não há elemento para ser verificado
		if (first >= last)
			return NOT_FOUND; //value não foi encontrado

		int i = (last - first)/3; //1 terço do tamanho do array

		//se value está no índice i
		if (first[i] == value)
			return first + i - _first; //retorna o índice

		//se value está no índice 2i
		else if (first[2*i] == value)
			return first + 2 * i - _first; //retorna o índice

		//se o valor está dentro do primeiro 1 terço do vetor
		else if (value < first[i])
			//ajusta intervalo para o terço correspondente
			recTernarySearch(first, first + i, value, _first);

		//se o valor está dentro do ultimo 1 terço do vetor
		else if (value > first[2*i])
			//ajusta intervalo para o terço correspondente
			recTernarySearch(first + 2*i + 1, last, value, _first);

		//se o valor está dentro do 1 terço do meio
		else
			//ajusta intervalo para o terço correspondente			
			recTernarySearch (first + i + 1 , first + 2*i , value, _first);
	}

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int jumpSearch(T *first, T *last, T value){
		int n = last - first; //tamanho do array
		int m = sqrt(n); //salto
		int f = 0; //indice anterior ao salto
		int l = m; //índice do salto

		//para evitar ajustes de limite inferiores no array
		//basta retornar NOT_FOUND caso value seja menor que o
		//menor valor do vetor
		if (value < *first)
			return NOT_FOUND; //value não foi encontrado

		//enquanto houver elementos a serem comparados
		while (first[l - 1] < value){
			l += m; //incrementa last do novo intervalo
			f += m; //incrementa first do novo intervalo

			//se novo first for maior q o tamanho do vetor
			if (f >= n)
				return NOT_FOUND; //value não foi encontrado

			//se novo last for maior que tamanho do vetor
			if (l >= n)
				l = n; //ajusta-se os limites
		}

		//faz uma busca linear no subvetor
		return (linearSearch(first + f, first + l, value) + f);
	}

	//Retorna o índice de um elemento num intervalo
	template <typename T> 
	int fibSearch(T *first, T *last, T value){
		int f1 = 0;		  		//(n-2)ésimo termo de fibonacci
		int f2 = 1;		  		//(n-1)ésimo termo de fibonacci
		int f3 = f1 + f2; 		//n-ésimo termo de fibonacci
		int i = last - first;	//tamanho do vetor

		//verificador se os indices estão dentro do vetor
		int lim = -1; 

		//encontrar o menor termo de fibonnaci maior
		//que o tamanho do array
		while(f3 < i){
			f1 = f2;
			f2 = f3;
			f3 = f1 + f2;
		}

		//enquanto houver elementos a serem comparados
		while(f3 > 1){
			int val = std::min(lim+f1,i-1); //menor elemento

			//se value for menor que o valor no índice,
			//cada elemento volta dois termo na sequencia de fibonnaci
			if(first[val] > value){
				f3 = f1;
				f2 -= f1;
				f1 = f3 - f2;

			//se value for maior que o valor no índice
			//cada elemento volta um termo na sequencia de fibonacci
			}else if(first[val] < value){
				f3 = f2;
				f2 = f1;
				f1 = f3 - f2;
				lim = val;

			//se for igual ao valor no índice
			}else{
				return val;//retorna o índice
			}
		}

		return NOT_FOUND; //caso value não seja encontrado
	}

}    
