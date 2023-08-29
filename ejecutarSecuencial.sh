g++ -c Particle.cpp -o Particle.o
g++ -c secuencial.cpp -o secuencial.o -lGL -lglut
g++ -o secuencial secuencial.o Particle.o -lGL -lglut

./secuencial 100