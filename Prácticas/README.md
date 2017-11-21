# Reto 3 (TDA lineales)
### Implementación de una pila a partir de list<class T>

El reto 3 tiene un planteamiento muy sencillo. Se trata de implementar la clase
`stack` a partir de la clase `list`. La idea es que disponéis de la clase `list` con toda la
implementación ya hecha y tenéis que construir la clase `stack` a partir de esa implementación
sin tener que implementar nuevo código, es decir que la implementación
de las funciones se haría simplemente llamando a funciones ya implementadas de
las listas. Por ejemplo, la función quitar de la pila se podría construir a partir de la función
borrar de las listas, sin más que activarla como `p.borrar(p.begin())`, supuesto que `p`
es de tipo lista (que se comporta como una pila).

Autores: Elena Merelo Molina y Antonio Gámiz Delgado.
