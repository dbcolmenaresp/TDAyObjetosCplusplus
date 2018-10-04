# TDAyObjetosCplusplus
Conceptos básicos de Tipo Abstracto de Datos y Orientación a Objetos en C++

## Abstraccion

La abstraccion consiste en ignorar aquellos aspectos del objeto a describir que no son relevantes, 
para de esta manera concentrarse en los que si lo son.

Es el principio que permite al observador del objeto o concepto que se requiere representar, 
ignorar aquellos aspectos que no son relevantes, para de esta manera concentrase en los que si lo son.

Para un objeto o concepto pueden existir varias descripciones de diferentes niveles de detalle, 
de acuerdo al proposito de su creacion, del contexto donde se ubica y de la perspectiva del analista.
una descripcion completa y detallada de un objeto o concepto puede representar adecuadamente la realidad 
y ser de mayor utilidad en un una mayor variedad de contexos, pero representa un nivel de complejidad 
que puede complicar el manejo de la descripcion y representar la perdida de esfuerzo en detalles que 
no son relevantes en un contexto determinado.

Una representacion demasiado simple de un objeto o concepto puede pasar por alto cracteristicas que son importantes en el analisis que se pretende realizar.

Un mayor nivel de informacion para describir un objeto o concepto no lo hace necesariamente mas util pero si lo hace inherentemente mas complejo.

Se requiere hacer un balance que permita obtener un nivel adecuado entre la complejidad y simplicidad en la descripcin que se desarrolla para un análisis adecuado.

## Tipos abstractos de datos

La abstraccion de los datos permite definir el dominio y la estrucutra de los datos, el conjunto 
de atributos que caracterizan a estos datos, asi como las operaciones validas aplicables sobre los mismos.

La abstraccion es un mecanismo por medio del cual se define un concepto general a partir del conocimiento 
que se tenga de objetos particulares.

Como resultado de la aplicacion de la abstraccion se obtiene un tipo abstracto de datos, el cual 
es un tipo de datos definido por el usuario, cuyas operaciones especifican como un cliente puede manipular 
los datos.

El tipo abstracto de datos debe verse como una caja negra que encierra todo lo relacionado 
al concepto que esta describiendo.

Se trata de abstraer los datos (atributos) y las operaciones (metodos) comunes a un conjunto de objetos.
Permite ver el concepto como un todo, sin tener que distraer la atencion en los detalles.

## Elementos de un tipo abstracto de datos:

Encabezado: nombre del tipo abstracto de datos.

Descripcion de los datos: se especifican los datos y las estrucutras correspondientes para representarlos.
Los datos constituyen los atributos del concepto u objeto definido por medio del tipo abstracto de datos.

Lista de operaciones: se forma por el conjunto de operaciones que se definen como validas para el tipo abstracto de datos.

Para cada operacion deberá indicarse:  
 Entrada: generalmente proporcionada por el usuario.  
 Precondiciones: establecen la situacion en la cual se aplicará la operación.  
 Proceso: es el conjunto de acciones que definen la operacion.  
 Salida: valores proporcionados, luego de la operacion, al usuario.  
 Postcondiciones: indican las condiciones qe deberán complirse una vez ejecutada la operación.  

La mayoria de los tipos abstractos de datos tienen una operacion especial, llamada inicializador, 
que asigna valores iniciales a los datos.

## Plantilla para un tipo abstracto de datos:

A continuacion se muestra un ejemplo de plantilla que representa un tipo abstracto de datos, en el cual
se incluyen los datos genericos que este debe contener para describir de manera adecuada el objeto en estudio.

----------------------------------

Tipo Abstracto de Datos:

Nombre del tipo abstracto de datos:

Datos:  
 Nombre del dato: Tipo del dato

Operaciones  
 Inicializador  
 Operacion 1  
 Operacion 2  
 .  
 .  
 .  
 Operacion n

Fin de Tipo Abstracto de datos

----------------------------------

Aplicar la abstracción a un modelo de estudiante universitario para obtener el tipo abstracto 
de datos correspondiente.

Dominio: alumno universitario.

Datos: representan las caracteristicas mas importantes de todo alumno universitario. 
 Nombre: cadena de caracteres.  
 Direccion: cadena de caracteres.  
 Matricula: numero entero.  
 Año de ingreso: numero entero.  
 Carrera: cadena de caracteres.  
 Promedio: numero real. 

Operaciones validas: representan aquellas operaciones que se pueden realizar sobre o con los 
datos de un alumno universitario.

 Actualizar direccion: un alumno puede cambiar de domicilio.  
 Actualizar promedio: un alumno aprueba materias.  
 Actualizar carrera: un alumno puede cambiar de carrera.  

## Orientaciona objetos: conceptos

La orientación a objetos es el paradigma de construcción de software mas usado y popular en 
el desarrollo de software moderno, dado que permite una perspectiva más realista para la 
resolucion de problemas, al facilitar el modelado del dominio del problema en un lenguaje de 
programacion que sigua este enfoque orientado a objetos.

La importancia del uso del paradigma orientado a objetos para el desarrollo de software 
moderno radica en que los metodos anteriormente aplicados para el desarrollo de programas 
se enfocaban en la disposicion separada de datos y funciones, enfoque que no se corresponde 
con la percepcion de la realidad ya que la disposicion separada de datos y funciones no se 
corresponde con el modelo de las cosas del mundo real.

En el mundo real se trata con objetos fisicos, tales como personas, autos o aviones, cuya 
representación a traves de atributos y funciones es mas adecuada.

Los atributos o caracteristicas de los objetos estan representados por los datos que 
describen un objeto. En una persona su edad, su profesion, su domicilio, etc; en un auto la 
potencia, el numero de matricula, el precio, número de puertas, etc.

El comportamiento son las acciones que ejecutan los objetos del mundo real, como respuesta a 
un determinado estimulo. El comportamiento esta compuesto en esencia por las funciones de un 
objeto que se llama para ejecutar una accion determinada sobre los atributos de dicho objeto. 
Si se pisa el freno de un auto, este reduce su velocidad; Si se pisa el acelerador, el auto 
aumenta su velocidad, etc.

La resolucion de un problema a traves del enfoque orientado a objetos consiste en la 
implementacion de un programa con varios objetos que interactuan a traves del intercambio de 
llamadas a las funciones internas de otros objetos, denomidados estos llamados envio de 
mensajes a otros objetos.

Las propiedades fundamentales que caracterizan la orientacion a objetos son las siguientes:

Abstracción consiste en ignorar aquellos aspectos del objeto o concepto a describir que no 
son relevantes, para de esta manera concentrarse en los que si lo son.

Encapsulamiento consiste en incluir dentro de una clase todos los atributos y metodos que la 
definen, de tal manera que otros objetos puedan usarla sin necesidad de conocer su estructura 
interna.

Ocultación

Herencia permite compartir atributos y metodos entre clases y las clases derivadas, tambien 
llamadas subclases, las cuales heredan atributos y metodos de las plases superiores, que 
reciben el nombre de superclases o clases base.

Polimorfismo una operacion puede tener el mismo nombre en diversas clases y funcionar de 
manera diferente en cada una, lo cual permite la implementacion de multiples formas de un 
mismo metodo, de tal manera que cada una de ellas se adapte a la clase sobre la cual se 
aplicará.

Para una referencia a los conceptos de la orientacion a objetos, referirse a 
Fundamentos de programacion de Luis Joyanes Aguilar, capitulo 2, seccion 2.4, pagina 56.
