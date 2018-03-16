#ifndef SEARCH_H
#define SEARCH_H

#include <iterator>

namespace edb{ 
	template <typename T> 
	T * linearSearch(T *, T *, T );

	template <typename T> 
	T * iteBinarySearch(T *, T *, T);

	template <typename T> 
	T * recBinarySearch(T *, T *, T);

	template <typename T> 
	T * iteTernarySearch(T *, T *, T);

	template <typename T> 
	T * recTernarySearch(T *, T *, T);

	template <typename T> 
	T * jumpSearch(T *, T *, T);

	template <typename T> 
	T * fibSearch(T *, T *, T);
}

#include "search.inl"

#endif