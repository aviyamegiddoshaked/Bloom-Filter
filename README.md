## Please note - a wiki folder that explains the final project, i.e. step 4 and last, appears in the EX1 repository under the branch EX4-BloomFilterServer

# EX1 - ASP
# Assignment 1 - Advanced systems Programing Course, BIU.
## Made by Tali Zikel and Aviya Megiddo Shaked
### In this assignment we implemented a Bloom filter algorithm.
We implemented a Bloom filter for rapid URL blacklisting checks, but acknowledged its susceptibility to false positives. To address this, we incorporated a secondary validation step for positive results, utilizing a conventional check to scrutinize whether the flagged URL is genuinely blacklisted or if it's a false positive. This approach allows us to capitalize on the efficiency of the Bloom filter for quick assessments while maintaining accuracy through a subsequent, more meticulous verification process.

## src folder

### main.cpp
The main function - intended for execution without the inclusion of tests, is accessible through the terminal for streamlined code execution.

### ApplicationExecutor.cpp + ApplicationExecutor.h
This runs the applications logic.
It reads the bloom filter information (size and frequency of hashing functions to use in the hashing), then reads series of commands in two formats:
"1 <url>" . this tell the program to add the url to the bloom filter and blacklisted urls list.
"2 <url>".  this tell the program to check if the url is blacklisted or not by checking if its in the bloom filter or/and in the blacklisted urls list.


### BloomFilter.cpp + BloomFilter.h
The given code snippet performs various operations on a URL. It starts by calculating hash values for the URL, determining corresponding Bloom filter indexes set to 1. The URL is then added to both the Bloom filter and a blacklist. Upon rehashing and Bloom filter initialization, the code checks if the URL is absent in the filter, returning "No" if true. If the URL is in the filter, it checks blacklist membership. If blacklisted, it returns "Yes",indicating a blacklisted URL. Otherwise, it returns "NoButInFilter," denoting a false positive, as the URL is in the Bloom filter but not blacklisted. The code effectively handles URL hashing, filtering, and blacklist checks.


## tests folder

### test_main.cpp

The test in Test.cpp creates a Bloom filter with two hash functions and a size of 8. It then adds "example.com" to the filter and checks if it's present. If the URL is in the filter, the test outputs "test passed," and if it's not in the filter, it outputs "test failed." Subsequently, it checks another URL, "example.com1," ensuring it's not in the filter, and outputs the corresponding result. In essence, this test validates the functionality of the Bloom filter by confirming its ability to correctly identify the presence or absence of specific URLs within the filter.


## CMakeLists.txt
Contains the compiler's test execution code, as well as the manual code execution functionality.

## Dockerfile
Contains the instructions for the cd.yml file on how to proceed.


## How to compile and run the program:

### Compile and run the main + src
cmake -B build -S .                       
cmake --build build
./build/CalcMain


### Compile and run the test + src
cmake -B build -S .                       
cmake --build build
cd build
ctest --test --output-on-failure

or

cmake -B build -S .                       
cmake --build build
./build/CalcTests


## Jira
We used Jira as a tool for tracking and documenting the progress of each step of our work. To begin with, we created a sprint that includes all the tasks we need to do. Every task that was in the process of being executed we placed under the "In Progress" column and every task that we completed was under the "Done" column.

## Github
The GitHub repository contains both the source code for the Docker container and the automated tests. The codebase includes instructions for building the Docker image, enclosing our program and its dependencies. Automated tests in the GitHub repository make sure the app is reliable and works properly.

## TDD
In the TDD process we worked gradually.
First, we created a general test, and a main function without content, and without any classes. Of course, the test failed as we expected.
after that, we created more specific test for the program, while writing the program itself. We added functions, classes, and wanted the program to pass the test for one specific hash function. But our test failed, and the output was also incorrect.
That's why we worked overtime to fix the code, to change the classes and functions, and also the test.
Next, the test for one hash function passed successfully.
In the last step, we updated the program so that it fits different hash functions.
The test passed as we expected.

## Docker Hub
We established a streamlined CI/CD process for our Bloom filter-based URL filtering program using GitHub Workflows. Following each pull request into the main branch, the CI pipeline automatically executed all tests, making sure the code is trustworthy. Additionally, for each release version, the workflow generates the creation and pushing of a Dockerized version of our program to a  private repository on DockerHub. The Docker image is like a packed box that holds our program and all things it needs in order to run. By using DockerHub, we make it easy to set up and share our program. This helps deliver it smoothly and efficiently on various computer systems.
