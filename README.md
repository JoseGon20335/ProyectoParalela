# README
## Integrantes:
Jose Miguel Gonzalez - 20335
Luis Diego Santos - 20226

## Intrucciones:
Correr el archivo sh:
- sh ejecutar.sh

## Comando:
Estos intrucciones son las que se ejecutan en el archivo .sh
g++ -c main.cpp -o main.o
g++ -c Particle.cpp -o Particle.o

g++ -o myprogram main.cpp Particle.cpp -lGL -lglut
./myprogram <numParticles>

## Librerias:
- GLUT (OpenGL Utility Toolkit): Esta biblioteca proporciona una interfaz para crear ventanas y realizar gráficos 2D y 3D utilizando OpenGL. Se utiliza para la representación gráfica en tu programa.

- C++ Standard Library: Estás utilizando varias clases y funciones de la biblioteca estándar de C++, como iostream para entrada/salida, cmath para funciones matemáticas, vector para contenedores de datos dinámicos, chrono para manejar el tiempo, y random para generación de números aleatorios.

## Archivos:
### main.cpp: 
- Este archivo contiene la función principal del programa, donde se inicia y controla la ejecución del proyecto. Aquí se configura el entorno gráfico, se generan las partículas, se gestionan sus actualizaciones y se maneja la representación en pantalla. Es el núcleo del programa donde todas las piezas se ensamblan para crear la simulación de partículas en pantalla.
### Particle.h:
- Este archivo contiene la declaración de la estructura Particle, que representa una partícula en el sistema. Define los atributos de una partícula, como su velocidad, posición, colores y radio. Además, incluye la declaración del constructor de Particle, que inicializa los atributos de una partícula cuando se crea.

### Particle.cpp:
- En este archivo se implementa el constructor de la estructura Particle, que toma los valores iniciales de los atributos de una partícula y los asigna a los miembros correspondientes. La implementación del constructor aquí asegura que las partes del programa que crean y trabajan con partículas tengan acceso a la definición completa de la estructura y su comportamiento.

### ejecutar.sh:
- Ejecutable
