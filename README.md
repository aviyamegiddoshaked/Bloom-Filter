# BloomFilter Server

## first step  Advanced systems Programing Course, BIU, 2024.

## Implementation of a Bloom Filter Algorithm

This project implements a Bloom Filter, a space-efficient probabilistic data structure used for rapid URL blacklisting checks. Written in C++, it includes functionalities such as adding URLs to the filter, checking whether a URL is present, and managing false positives.

To address the Bloom Filter's susceptibility to false positives, we incorporated a secondary validation step. This step involves a conventional lookup for flagged URLs to verify whether they are genuinely blacklisted. This combination allows the system to leverage the Bloom Filter’s efficiency for quick assessments while ensuring accuracy through meticulous follow-up checks.

In this assignment, the Bloom Filter was specifically utilized in the **Facebook Clone project** to enhance content moderation. It was employed to prevent users from posting with forbidden URLs, thereby improving platform security and ensuring harmful or restricted content was effectively blocked. By integrating this Bloom Filter into the Facebook Clone, we demonstrated its real-world application in safeguarding user interactions and maintaining a secure environment.


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


## Test-Driven Development (TDD)
In developing our project, we adhered to a structured Test-Driven Development (TDD) approach, working iteratively and methodically.

We began by drafting a general test and setting up a basic main function without any implemented classes or logic. Predictably, this initial test failed, as no functionality was yet in place. From there, we incrementally enhanced our program, writing more specific tests alongside the implementation of classes and functions.

Our initial focus was on making the program pass tests for a single hash function. Despite our efforts, the test initially failed, producing incorrect outputs. This setback prompted us to revisit and refine our code, modifying the structure of both the classes and the tests themselves. After considerable effort, we succeeded in making the test for one hash function pass.

In the final phase, we extended the program's functionality to accommodate multiple hash functions, ensuring the updated tests passed seamlessly.



## Docker Hub
Docker Hub and CI/CD Pipeline
To optimize deployment for our project, we integrated a robust CI/CD pipeline using GitHub Workflows and Docker. Every pull request to the main branch triggered an automated CI pipeline to execute all tests, verifying the reliability of the codebase.

For each release version, our workflow generated a Dockerized version of the program, which was then pushed to a private repository on DockerHub. The Docker image encapsulated the program along with all its dependencies, ensuring easy setup and portability.

This streamlined process facilitated efficient distribution of the program, enabling consistent performance across various systems and simplifying deployment for diverse environments.
