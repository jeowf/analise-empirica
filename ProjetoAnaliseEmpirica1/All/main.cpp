#include <iostream>
#include <chrono>

#include "search.h"

#define N_AVERAGE 100
#define PRECISION 6

typedef int (*SearchFunction)(long int *, long int*, long int);

int main(){

	SearchFunction functions[] = {edb::linearSearch,
								  edb::iteBinarySearch,
								  edb::recBinarySearch,
								  edb::iteTernarySearch,
								  edb::recTernarySearch,
								  edb::jumpSearch,
								  edb::fibSearch};

	int s;
	long int *v;
	long int value = -1;

	while (std::cin >> s){
		//intancia o vetor com s elementos
		v = new long int[s];
		for (int i = 0; i < s; i++)
			v[i] = i;

		//imprime o tamanho do vetor
		std::cout << s << ", ";

		//simula o pior caso para cada função
		for (auto & e : functions){
			double time = 0;

			//executa a função N_AVERAGE vezes e em seguida calcula a média de tempo
			//das execuções
			for (int i = 0; i < N_AVERAGE; i++){
				//inicia o cronometro
				auto start = std::chrono::steady_clock::now();

				int x = e(v, v + s, value);

				auto end = std::chrono::steady_clock::now();

				//calcula tempo decorrido
				time += (std::chrono::duration <double, std::milli> (end-start).count()) / N_AVERAGE;
			}

			//time /= N_AVERAGE;
			std::cout << time << std::setprecision(PRECISION)<<", ";
		}
		
		std::cout << std::endl;

		delete v;
	}

	return 0;

}