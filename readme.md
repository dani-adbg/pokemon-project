# Organización de funciones

En esta parte organizaremos un poco nuestro código, separándolo en funciones para evitar redundancia, acortándolo y haciéndolo un poco más eficiente.

___
#### Librerías
Las librerías que agregaremos son para una función que nos servirá para que calcule el tiempo.

![](https://media.discordapp.net/attachments/1102771348603940946/1137831893799292978/image.png?width=363&height=101)

___
#### Función para calcular el tiempo
Esta función a la que nombraremos ***sleep***, le pasaremos un parámetro de tipo entero que serán los segundos que calculará. 

![](https://media.discordapp.net/attachments/1102771348603940946/1137831986430476410/image.png?width=602&height=114)

El parámetro de tipo entero con nombre ***sec*** lo multiplicaremos por *1000* y lo guardarémos en una variable también de tipo entero con el nombre ***milliseconds*** para que nos de un resultado en milisegundos.
En la siguiente línea usaremos funciones que nos proporcionan las librerías ***thread*** y ***chrono*** en la que le pasaremos el parámetro milliseconds.
___
### Separar el código en funciones para mayor organización
Ahora el código que antes teníamos en la función ***main*** de nuestro programa, lo separaremos en dos funciones más, esto nos servirá para implementar nuevas funciones luego sin repetir código de manera poco eficiente.

#### Mostrar los datos del Pokemon
Primera función que separaremos del código en ***main***. Esta función la nombraremos ***showData***.

![](https://media.discordapp.net/attachments/1102771348603940946/1137832036078469191/image.png?width=636&height=396)

Aquí le pasarémos el parámetro *pokemon* para obtener sus datos.
También estarémos usando la función ***sleep*** creada anteriormente, usando un ciclo for que por cada vez que se repita, imprimirá un punto y luego esperará 1 segundo.

#### Seleccionar Pokemon
A esta función le llamaremos ***selectPokemon***. 

![](https://media.discordapp.net/attachments/1102771348603940946/1137832110267306114/image.png?width=563&height=466)

Aquí solo transcribiremos el código que escribimos en el avance anterior, con la diferencia de que no mostrarémos los datos directamente y que retornaremos este pokemon.

___
#### Función Main 
Como dividimos el código en varias funciones más, nuestra función ***main*** cambiará.

![](https://media.discordapp.net/attachments/1102771348603940946/1137832140646666370/image.png?width=508&height=181)

En vez de escribir todo el código, llamarémos la función ***selectPokemon*** y la guardarémos en la constante con nombre ***pokemon*** con base a la clase ***Pokemon***.
Luego llamaremos la función ***showData*** y le pasarémos el parámetro ***pokemon*** que recolectamos de la función ***selectPokemon***.
___
Con esto podemos seguir al [siguiente avance](https://github.com/dani-adbg/pokemon-project/tree/4.-Movimientos-y-Pokemon-Rival)