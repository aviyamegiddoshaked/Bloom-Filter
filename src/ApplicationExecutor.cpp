#include "ApplicationExecutor.h"
#include <iostream>
#include <sstream>

using namespace std;

// Runs the application logic.
// reads the bloom filter info (size and frequency of hashing functions to use in the hashing).
// then reads series of commands in two formats:
// "1 <url>" . this tell the program to add the url to the bloom filter and blacklisted urls list.
// "2 <url>".  this tell the program to check if the url is blacklisted or not
//             by checking if its in the bloom filter or/and in the blacklisted urls list.
void ApplicationExecutor::run()
{
	BloomFilter bloomFilter;
	string curLine;

	while (1)
	{
		int firstNum;
		getline(cin, curLine);
		istringstream ss(curLine);
		ss >> firstNum;

		if (firstNum <= 0)
			continue;

		if (bloomFilter.getSize() == 0)
		{
			// first word is number and we didnt see bloom filter line, 
			// so this a bloom filter line.

			int hashFreq1 = 0, hashFreq2 = 0;
			BloomFilter::HashFreq hashFreq = BloomFilter::HashFreq::None;
			bool isValidBFLine = true;
			int curNum = 0;
			while (ss >> curNum)
			{
				if (curNum == 1)
				{
					if (hashFreq == BloomFilter::HashFreq::None)
						hashFreq = BloomFilter::HashFreq::OneHash1Time;
					else if (hashFreq == BloomFilter::HashFreq::OneHash2Times)
						hashFreq = BloomFilter::HashFreq::TwoHashes;
				}
				else if (curNum == 2)
				{
					if (hashFreq == BloomFilter::HashFreq::None)
						hashFreq = BloomFilter::HashFreq::OneHash2Times;
					else if (hashFreq == BloomFilter::HashFreq::OneHash1Time)
						hashFreq = BloomFilter::HashFreq::TwoHashes;
				}
				else
				{
					isValidBFLine = false;
				}
			}

			if (hashFreq == BloomFilter::HashFreq::None || !isValidBFLine)
				continue;

			bloomFilter.Init(firstNum, hashFreq);

		}
		else if (firstNum == 1 || firstNum == 2)
		{
			string url;
			ss >> url;

			if (firstNum == 1)
			{
				bloomFilter.addToFilter(url);
			}
			else
			{
				BloomFilter::URLBlacllisted urlBlacllistedRes = bloomFilter.isInFilter(url);
				if (urlBlacllistedRes == BloomFilter::URLBlacllisted::No)
					cout << "false\n";
				else if (urlBlacllistedRes == BloomFilter::URLBlacllisted::NoButInFilter)
					cout << "true false\n";
				else if (urlBlacllistedRes == BloomFilter::URLBlacllisted::Yes)
					cout << "true true\n";
			}
		}
	}
}



