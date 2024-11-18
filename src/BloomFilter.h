#pragma once
#include <string>
#include <vector>

using namespace std;

class BloomFilter
{
public:
	//  enum for how many hashing functions to use.
	enum HashFreq
	{
		None,
		OneHash1Time,
		OneHash2Times,
		TwoHashes
	};

	// enum for whether a url is blacklisted or not. 
	enum URLBlacllisted
	{
		No,
		NoButInFilter,
		Yes
	};

	// ctor
	BloomFilter();

	// adds a url to the bloom filter and to the blacklisted urls list.
	void addToFilter(const string& url);

	// gets bloom filter size
	int getSize();

	// initializes the bloom filter.
	void Init(int size, HashFreq hashFreq);

	//check if the input url is in blacklisted
	URLBlacllisted isInFilter(const string& url);
private:

	// calculates the result of the hashing functions on the input url.
	void GetUrlHashedIndexes(const string& url, int& hashedIndex1, int& hashedIndex2);

	// calculates the result of the hashing functions on the input url.
	unsigned int hashFunc(const string& url, bool isTwice);

	// bloom filter
	vector<unsigned int> bloomFilter;

	// blacklisted urls list.
	vector<string> blackListedURLs;

	// hasher function.
	std::hash<string> hasher;

	// bloom filter's hashing frequency to usae in the hashing process.
	HashFreq hashFreq;
};