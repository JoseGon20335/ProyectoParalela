g++ -c Particle.cpp -o Particle.o
g++ -c paralelo.cpp -o paralelo.o -fopenmp -lGL -lglut
g++ -o paralelo paralelo.o Particle.o -fopenmp -lGL -lglut

./paralelo 100