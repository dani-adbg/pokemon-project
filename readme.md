# Base del Proyecto

Para empezar el proyecto debemos saber lo que queremos hacer, en este caso un pequeño juego de Pokemon.

Usaremos ciertas cosas que son un tanto complejas, pero nada del otro mundo.

___
#### Incluir librerías
Para empezar incluiremos las librerías que usaremos.

![img](https://media.discordapp.net/attachments/1102771348603940946/1136517151306563715/image.png?width=518&height=239)

- ***iostream*** que es la librería base.

- ***string*** es la librería usada para definir cadenas de texto en variables.

#### Creación de Clase

Queremos tener 3 pokemones, por lo que son bastantes datos, para evitar tener tantos datos por separados, crearemos una clase **Pokemon** que contendrá los datos y con la herencia podremos crear e ingresar los parámetros de cada uno de los Pokemons.

Información sobre cómo crear una clase:
- [w3schools](https://www.w3schools.com/cpp/cpp_classes.asp)
- [microsoft](https://learn.microsoft.com/en-us/cpp/cpp/class-cpp?view=msvc-170)

![](https://media.discordapp.net/attachments/1102771348603940946/1136516118874435685/Captura_de_pantalla_2023-08-02_232834.png?width=885&height=498)

___

#### Creación de Pokemones
Aquí lo que harémos será crear la función ***main*** y con esto, crear los pokemones a partir del número que escojamos.

Con esto se ingresarán lo parámetros a la clase y se mostrarán los datos.

![](https://media.discordapp.net/attachments/1102771348603940946/1136516119214166026/Captura_de_pantalla_2023-08-02_232851.png?width=885&height=498)

Por temas de organización, se ha cambiado ***if*** por ***switch*** aunque se lo puede hacer tranquilamente con ambas.

***cin*** recogerá lo que se escriba luego del texto mostrado.

***switch*** se encargará de que dependiendo del número se cree un pokemón.

En las líneas *54*, *64*, *73* y *83* se crean los Pokemones, como primer parámetro entra el **nombre**, luego el **tipo** del pokemón, su **salud**, su **ataque** y por último su **defensa**.

A continuación, usando las funciones ***get*** creadas para obtener los datos de laclase, se muestran los datos del Pokemón creado.

Siendo este el resultado.

![](https://media.discordapp.net/attachments/1102771348603940946/1136522069396439081/image.png?width=885&height=498)

___

[Siguiente Parte](https://github.com/dani-adbg/pokemon-project/tree/3.-Organizaci%C3%B3n-de-funciones)