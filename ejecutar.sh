g++ -c main.cpp -o main.o
g++ -c Particle.cpp -o Particle.o

g++ -o myprogram main.cpp Particle.cpp -lGL -lglut
./myprogram 10