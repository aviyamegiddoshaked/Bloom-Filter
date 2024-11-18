// Test.cpp
#include <iostream>
#include "ApplicationExecutor.h"

int main()
{
	// Creating a filter with a specific hash function
	BloomFilter bloomFilter;
	bloomFilter.Init(8, BloomFilter::HashFreq::TwoHashes);

	// Example of using the filters
	bloomFilter.addToFilter("example.com");

	BloomFilter::URLBlacllisted urlBlacllistedRes = bloomFilter.isInFilter("example.com");
	if (urlBlacllistedRes == BloomFilter::URLBlacllisted::Yes)
		cout << "test passed\n";
	else
		cout << "test failed\n";

	BloomFilter::URLBlacllisted urlBlacllistedRes2 = bloomFilter.isInFilter("example.com1");
	if (urlBlacllistedRes2 == BloomFilter::URLBlacllisted::No)
		cout << "test passed\n";
	else
		cout << "test failed\n";

	return 0;
}

