#include <iostream>
#include <chrono>
#include <iomanip>

#include "search.h"

#define N_AVERAGE 100
#define PRECISION 7

typedef int (*SearchFunction)(long int *, long int*, long int);

int main(){

	SearchFunction functions[] = {edb::linearSearch,
								  edb::iteBinarySearch,
								  edb::recBinarySearch,
								  edb::iteTernarySearch,
								  edb::recTernarySearch,
								  edb::jumpSearch,
								  edb::fibSearch};

	int s, n_samples, s_samples;
	long int *v;
	long int value = s_samples*n_samples;

	std::cin >> n_samples >> s_samples;

	//Inicia a alocação do vetor
	v = new long int[n_samples * s_samples];

	//Inicia o vetor com valores ordenados
	for (int i = 0; i < n_samples * s_samples; i++)
		v[i] = i;
	
	//para cada amostra
	for (int i = 1; i <= n_samples; i++){
		s = i * s_samples;

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
		
		std::cout << "END" << std::endl;
	}

	// int xx;
	// for (int i = 0; i < s_samples; i++){
	// 	xx = functions[5](v, v + s_samples, (long int) (i));
	// 	std::cout << "find " << v[i] << " at " << xx << "\n";
	// }
	// xx = functions[5](v, v + s_samples, (long int) (s_samples));

	// std::cout << s_samples << " " << xx << "\n";
	return 0;
}