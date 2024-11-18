FROM gcc:latest  

WORKDIR /usr/src/ex1

COPY ./src/ .

RUN g++ -o ex1 ./main.cpp ./ApplicationExecutor.cpp ./BloomFilter.cpp 

CMD ["./ex1"]



