# README
## Integrantes:
Jose Miguel Gonzalez - 20335
Luis Diego Santos - 20226

## Intrucciones:
Correr el archivo sh:
- sh ejecutarParalelo.sh
- sh ejecutarSecuencial.sh

## Comando:
Estos intrucciones son las que se ejecutan en el archivo .sh
g++ -c Particle.cpp -o Particle.o

g++ -c paralelo.cpp -o paralelo.o -fopenmp -lGL -lglut
g++ -o paralelo paralelo.o Particle.o -fopenmp -lGL -lglut

g++ -c secuencial.cpp -o secuencial.o -lGL -lglut
g++ -o secuencial secuencial.o Particle.o -lGL -lglut

./secuencial <numero>
./paralelo <numero>

## Librerias:
- GLUT (OpenGL Utility Toolkit): Esta biblioteca proporciona una interfaz para crear ventanas y realizar gráficos 2D y 3D utilizando OpenGL. Se utiliza para la representación gráfica en tu programa.

- C++ Standard Library: Estás utilizando varias clases y funciones de la biblioteca estándar de C++, como iostream para entrada/salida, cmath para funciones matemáticas, vector para contenedores de datos dinámicos, chrono para manejar el tiempo, y random para generación de números aleatorios.

## Archivos:

### paralelo.cpp
- Simula un conjunto de partículas en paralelo utilizando la biblioteca OpenMP y OpenGL. Las partículas se generan con propiedades aleatorias como velocidad, posición y color.
### secuencial.cpp
- Es una versión secuencial del programa que genera y simula un conjunto de partículas. A diferencia de la versión paralela, este programa no utiliza paralelismo para generar ni actualizar las partículas. En lugar de eso, todas las operaciones se realizan secuencialmente en un solo hilo de ejecución.
### Particle.h:
- Este archivo contiene la declaración de la estructura Particle, que representa una partícula en el sistema. Define los atributos de una partícula, como su velocidad, posición, colores y radio. Además, incluye la declaración del constructor de Particle, que inicializa los atributos de una partícula cuando se crea.

### Particle.cpp:
- En este archivo se implementa el constructor de la estructura Particle, que toma los valores iniciales de los atributos de una partícula y los asigna a los miembros correspondientes. La implementación del constructor aquí asegura que las partes del programa que crean y trabajan con partículas tengan acceso a la definición completa de la estructura y su comportamiento.

### ejecutarParalelo.sh:
- Ejecutar paralelo

### ejecutarSecuencial.sh
- Ejecutar secuencial
