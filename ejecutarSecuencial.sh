g++ -c main.cpp -o main.o
g++ -c Particle.cpp -o Particle.o

g++ -o secuencial secuencial.cpp -fopenmp -lGL -lglut
./secuencial 10