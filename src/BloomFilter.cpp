#include "BloomFilter.h"
#include <algorithm>

BloomFilter::BloomFilter()
{
}

// calculates the result of the hashing functions on the input url.
// this returns indexes of the cells of bloom filter that are 1. 
void BloomFilter::GetUrlHashedIndexes(const string& url,
	int& hashedIndex1,
	int& hashedIndex2)
{

	if (hashFreq == OneHash1Time || hashFreq == OneHash2Times)
	{
		hashedIndex1 = hashFunc(url, hashFreq == OneHash1Time ? false : true);
	}
	else if (hashFreq == TwoHashes)
	{
		hashedIndex1 = hashFunc(url, false);
		hashedIndex2 = hashFunc(url, true);
	}
}

// adds a url to the bloom filter and to the blacklisted urls list.
void BloomFilter::addToFilter(const string& url)
{
	int hashedIndex1, hashedIndex2 = -1;

	GetUrlHashedIndexes(url, hashedIndex1, hashedIndex2);

	bloomFilter[hashedIndex1] = 1;
	if (hashFreq == TwoHashes)
	{
		bloomFilter[hashedIndex2] = 1;
	}
	blackListedURLs.push_back(url);
}


// calculates the result of the hashing functions on the input url.
unsigned int BloomFilter::hashFunc(const string& url, bool isTwice)
{
	unsigned int x = hasher(url);

	if (isTwice)
	{
		string s = to_string(x);
		x = hasher(s);
	}

	return x % bloomFilter.size();
}

int BloomFilter::getSize()
{
	return bloomFilter.size();
}

// initializes the bloom filter.
void BloomFilter::Init(int size, HashFreq hashFreq)
{
	bloomFilter.resize(size);
	this->hashFreq = hashFreq;
}

/* check if the input url is in blacklisted by doing the following :
 - if its not in the bloom filter
		 - its return No
-  else (its in the bloom filter)
	  - if its in the blacklisted urls list
			-  its return Yes (url is blacklisted)
	 - else
			- it returns NoButInFilter
			(url is in the bloom filter but its not in the blacklisted url list
			so it's not blacklisted - this is a false positive)
*/
BloomFilter::URLBlacllisted BloomFilter::isInFilter(const string& url)
{
	int hashedIndex1, hashedIndex2 = -1;

	GetUrlHashedIndexes(url, hashedIndex1, hashedIndex2);

	bool isBitHashInd1On = bloomFilter[hashedIndex1] == 1 ? true : false;
	bool isBitHashInd2On = true;

	if (hashFreq == TwoHashes)
	{
		isBitHashInd2On = bloomFilter[hashedIndex2] == 1 ? true : false;
	}

	if (isBitHashInd1On && isBitHashInd2On)
	{
		if (find(blackListedURLs.begin(), blackListedURLs.end(), url) != blackListedURLs.end())
			return Yes;

		return NoButInFilter;
	}

	return No;
}
