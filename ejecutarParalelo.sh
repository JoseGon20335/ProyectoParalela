g++ -c paralelo.cpp -o paralelo.o
g++ -c Particle.cpp -o Particle.o

g++ -o paralelo paralelo.cpp -fopenmp -lGL -lglut
./paralelo 10