# 65. Valid Number

Validate if a given string is numeric.

Some examples:

```
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
```
**Note**: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.


## analisis

Las siguientes fueron preguntas que se le realizaron al profesor para poder llegar a un mejor entendimiento de problema.

* ¿Hay algún tamaño máximo de los strings de entrada? Y si es así, ¿Cuál es?
    * Pueden limitar a 255 caracteres.
* ¿Qué símbolos se utilizan para empezar la parte decimal de un numero? Es decir, si se utiliza el punto, coma, ambas u otro símbolo más.
    * Para la parte decimail usen punto. Pero la coma también es valida por ejemplo 1,000.95 es valido. La coma debe estar en el lugar correcto. 10,0 este no es un número.
* Para la representación del número exponencial se ve en el ejemplo que “e” es válido. ¿Existe algún otro símbolo para esta representación, como por ejemplo ‘E’? en caso de ser afirmativo, ¿Cuáles son válidas para este problema? 
    * solo e en minúsculas. Después de la e no puede ir un número decial .ie. 45e87.98 no es valido pero e45 si, 
* Cuando el número tiene más de tres dígitos, ¿se utilizarán símbolos para separar los dígitos en grupos de tres?, en caso de ser afirmativo, ¿Qué símbolos se utilizarán en este problema?
    * Es posible, pero no obligatorio, el simbolo sería la coma , .  1,000 y 1000 son correctos, i.e, la coma no es obligatoria
* Bajo el contexto del problema, ¿las operaciones validas cuentan como valores numéricos?, es decir, se en la información de entrada se encuentra “1+1”, ¿se regresara verdadero?
    * nop, las operaciones no cuentan como número. 1+1 no es un número. Ni tampoco cualquiera que tenga * + / Los únicos caracteres acepetados en un número son , . e 
* ¿Un numero valido decimal puede empezar con el punto?
    * Si .5757 es valido
* Después del símbolo ‘e’ de exponente, ¿puede llevar signo para representar si es negativo o positivo?
    * si 45e-2 o 45e+56 es valido
* ¿Cualquier numero valido puede empezar “-” para saber si es negativo o “+” si es positivo?
    * Si +45 o -45 son validos
* Profesor una pregunta para la Kata, ¿se pueden tener espacios en blanco antes y/o despues de el numero? Por ejemplo “    452.20    “
¿Como manejamos esta clase de casos?
    * La respuesta es si, se deben ignorar pueden tener un while(char == ' ') al principio y al final. Lo que no es valido son espacios intermedios
* ¿Un numero decimal puede comenzar con un cero?
    * 0.5757 Si y sin 0 también i.e, .5757
* ¿Los numeros pueden ser octales o hexadecimales?
    * No solo decimales
* pregunta seguida de ¿A que dominio pertenecen los numeros?
    * Solo decimales de menos infinito a + infinito.
* ¿La construccion 00. es valida?
    * No, solo con un 0.1 es valida o .1 pero si 1.000 o .000

Lo que puedo observar por la informacion recolectada es que nos encontramos en un problema donde lo que tenemos que examinar es el poder construir un *token* numerico que cubra las cualidades de las descripciones que tenemos en la parte superiro. La manera en la que puedo solucionar este problema es mediante un automata finido no determinista para poder mostrar la estructura de un token numerico aceptable, una vez que contamos con este automata la implementacion puede suceder de una manera mas natural. A continuacion una imagen de como seria el automata que corresponde a un token de numeros.

![alt text](https://i.imgur.com/FS7NkYP.png)

Donde {n} es el conjunto que contiene todos los digitos del 0 al 9. Podemos observar en la imagen que la mantisa fue la parte mas complicada de crear en este problema, debido a que existen diferentes formas en las que se puede crear, sea con un solo punto, con un signo, con comas entre caracteres asi como una combinacion de todas estas caracteristicas. En la practica crear estos estados dentro de nuestro codigo se remonta con el hecho de que podemos crear diferentes switches que se encarguen de los diferentes estados del automata. 