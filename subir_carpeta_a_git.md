### Pasos a seguir para subir una carpeta a un repositorio:
1. Hacemos git clone *repositorio al que queramos subir la carpeta*, por ejemplo en mi caso:
`git clone https://github.com/ElenaMerelo/Estructura-de-Datos`

2. Nos metemos en el repositorio que hemos clonado, situado en el directorio en el que se encuentra la terminal:
`cd Estructura-de-Datos`
3. Luego `git pull`

4. Una vez dentro copiamos la carpeta deseada(/home/blablabla) en el repositorio clonado , en el que nos encontramos, indicándolo con un punto:
`cp -r /home/elena/Escritorio/University\ stuff/2º/1º\ Cuatrimestre/ED/Reto3\(Elena\)/ .`

5. Nos metemos en la carpeta copiada (`cd /home/elena/Escritorio/University\ stuff/2º/1º\ Cuatrimestre/ED/Reto3\(Elena\)/`) y se van añadiendo al repositorio los ficheros dentro de la carpeta que queremos copiar, en mi caso tenía ficheros .cpp, .h y un makefile:
`git add Reto3\(Elena\)/*.cpp`, `git add Reto3\(Elena\)/*.h`, `git add Reto3\(Elena\)/Makefile`

6. `git status` para comprobar que lo hemos hecho bien.

7. Se hace commit de lo añadido, si no es como si no hubiéramos hecho nada: `git commit -am "Comentario"`

8. Finalmente se escribe en la terminal `git push` para que se suba a Github.
