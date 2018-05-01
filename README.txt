Para compilar con opciones de depuración:
	cd build/
	cmake -D CMAKE_BUILD_TYPE=Debug ..
	make

Para compilar con optimización
	cd build/
	cmake -D CMAKE_BUILD_TYPE=Release ..
	make


Para ejecutar:
	./bin/practica1 <problema> <semilla (opcional)>
Ej:
	./bin/practica1 ./instancias/chr22a.dat 7
