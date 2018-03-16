#include <iostream>

#include "search.h"

int main(){
	int vet[] = {-30,2,3,4,5,8,10,12,20,40,99};
	int size = sizeof(vet)/sizeof(*vet);

	//int *vet2 = edb::iteTernarySearch(std::begin(vet), std::end(vet),4);
	//std::cout << *vet2 << " last>> " << *std::end(vet) << std::endl;

	int *vet2;

	for (int i = 0; i < size; i++){
		vet2 = edb::recBinarySearch(std::begin(vet), std::end(vet), vet[i]);
		std::cout << "v:" << vet[i] << " in pos:  " << (vet2 - vet) << std::endl;
	}

	vet2 = edb::recBinarySearch(std::begin(vet), std::end(vet), 30);
	std::cout << *vet2 << " <<found | last>> " << *std::end(vet) << std::endl;
	//std::cout << *vet2 == *std::end(vet) << std::endl;
	

	return 0;

}