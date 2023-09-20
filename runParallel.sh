g++ -c ./Particle/Particle.cpp -o ./Particle/Particle.o
g++ -c ./Parallel/Parallel.cpp -o ./Parallel/Parallel.o -fopenmp -lGL -lglut
g++ -o ./Parallel/Parallel ./Parallel/Parallel.o ./Particle/Particle.o -fopenmp -lGL -lglut

./Parallel/Parallel 5000 1920 1080 1
./Parallel/Parallel {num_particulas} {ancho} {alto} {radio_particula}