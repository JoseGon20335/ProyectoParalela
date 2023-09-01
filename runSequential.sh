g++ -c ./Particle/Particle.cpp -o ./Particle/Particle.o
g++ -c ./Sequential/Sequential.cpp -o ./Sequential/Sequential.o -lGL -lglut
g++ -o ./Sequential/Sequential ./Sequential/Sequential.o ./Particle/Particle.o -lGL -lglut

./Sequential/Sequential 5000 1920 1080 1