FROM ubuntu:16.04
COPY avtomat.cpp /avtomat.cpp
RUN apt-get -y update
RUN apt-get -y install build-essential
RUN g++ -o avtomat avtomat.cpp && ./avtomat
