# Proyecto Robert: Robot con ruedas que puede moverse en espacios abiertos.

Este proyecto utiliza un **Arduino Uno R3** para controlar motores y sensores. La finalidad es gestionar el movimiento de los motores y recopilar datos de los sensores mediante funciones modulares. El sistema está diseñado para ser flexible, eficiente y escalable.

---

## Índice

- [Características](#características)
- [Requisitos](#requisitos)
- [Instalación](#instalación)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Uso del código](#uso-del-código)
- [Contribuciones](#contribuciones)
- [Licencia](#licencia)

---

## Características

- Control preciso de motores con un lenguaje amigable.
- Lectura y gestión de inputs de sensores.
- Código modular distribuido en varios archivos para facilitar el mantenimiento.
- Compatible con Arduino Uno R3, motores DC y Servo Motor.

---

## Requisitos

- **Hardware:**
  - Arduino Uno R3  
  - Motores (servomotor, motor DC, etc.)
  - Sensor ultrasónico.

- **Software:**
  - Arduino IDE
  - Git para control de versiones
 
  
---

## Instalación

1. **Haz un Fork de este repositorio**.
2. **Clona el repositorio:**
   ```bash
   git clone https://github.com/tu_usuario/robot-indep-robert.git

3. **Implementa.** 

---

## Estructura del Proyecto
Este proyecto está creado con una ideologia tipo controlador/implementación. Dentro de las diferentes carpetas se encuentran controladores para ciertas funciones especificas. Utiliza la estructura que se encuentre dentro del directorio `src/`. Dentro de esta carpeta se encuentran los siguientes directorios:
- **Controladores:** Aqui se encuentran las funciones principales del Robert, tales como la aceleración, el funcionamiento del Servo Motor, entre otros. Deberías acceder a este directorio solo para revisar la sintaxis y asegurarte de que implementes de manera adecuada las funciones.
- **Implementaciones:** En este directorio podemos encontrar las implementaciones de funcionamiento principal del Robert. Implementaciones tales como girar en 180°, buscar objetos cercanos o incluso frenar deberían estar alojadas en este directorio. 
- **Main:** Aqui se deberían terminar de juntar las diferentes funcionalidades del Robert. Se incluyen todos los archivos que sean necesarios para poder reutilizar el código creado en el directorio **controladores** e **implementaciones**. Tales como el mismo loop del Arduino deben ir incluidos en el archivo main.ino de este directorio.

Si tienes alguna sugerencia con respecto a la estructura del código o no entiendes algo, por favor, házmelo saber y podemos conversarlo.


--- 


## Uso del código
Para poder utilizar este código de manera adecuada, aquí te presento una serie de pasos que debes tener en cuenta para implementar las funciones adecuadas.

1. **Incluir la ruta del archivo a implementar:** Para poder incluir la funciónalidad de un archivo en especifico, haremos uso de la palabra clave `#include`, propia del lenguaje de programacion C++. Si por ejemplo, quieres hacer uso de la función `acelerarMotorTrasero() `, deberías incluir la siguiente línea en tu archivo:

``` c++
#include "controladores/motores/motores.h"
#include "controladores/motores/motores.cpp"
```
De esta manera, podrás incluir dentro de tus métodos la función `acelerarMotorTrasero()`, la cual solo se encuentra definida e implementada dentro de los directorios mencionados.

### ¿Dónde debo escribir el código para que el Robert funcione?
Como fue definido antes, existen 3 carpetas principales. Entre estas 3, la única que **no** debería modificarse es la carpeta `controladores/`, ya que esta alberga el código fuente del funcionamiento, y si estas funciones no están bien definidas o son alteradas sin conocimiento, pueden resultar en la fundición de un motor o el erróneo funcionamiento del Robert.

Primeramente, en el directorio `implementaciones/` debemos escribir el código para las funcionalidades básicas. Por ejemplo, podemos hacer lo siguiente para la función `frenar()`:

frenar.cpp:
``` c++
// Incluimos los controladores de los motores.
#include "controladores/motores/motores.h"
#include "controladores/motores/motores.cpp"

// Agregamos la siguiente línea para indicarle al compilador que se trata de código de Arduino.
#include <Arduino.h>

// Creamos la función "frenar()" en este caso
void frenar(P1, P2, OUT){
  // Utilizamos las funciones implementadas en motores.cpp
  retrocederMotorTrasero(P1, P2, OUT);
  delay(500);
  despotenciar(OUT);
  neutro(P1, P2, OUT);
}

```

Es de vital importancia que al utilizar cualquier funciónalidad que tenga que ver con los motores tanto traseros como delanteros, utilizemos la función ya creada `neutro();` con todos sus parámetros. De esta manera evitamos que los motores se quemen y nos aseguramos que funcione de manera correcta.

#### ¿Y cómo utilizo esta funcionalidad en el `main.ino`?
Para poder utilizarla, es necesario agregar la siguiente línea en el archivo `main.ino`
``` c++
// Agregamos la siguiente línea para poder utilizar la función creada en el otro archivo
#include "../implementaciones/frenar.cpp"

// variables de pin
int rueda_derecha = 4;
int rueda_izquierda = 5;
int potencia_motor_trasero = 6;

void setup(){
// codigo...
}

void loop(){
// codigo...
  frenar(rueda_derecha, rueda_izquierda, potencia_motor_trasero);
// codigo...
}

```
De esta manera implementamos todas las funciones de todos los archivos que estemos creando. Si no entiendes qué es lo que está pasando y el séntido de todo esto, te recomiendo que veas un tutorial de programación orientada a objetos e interfaces de código.

### Importante leer:
El código y las implementaciones de las funciones dentro de la carpeta `controladores/` está diseñada para que sea fácil de leer y entendible al lenguaje natural. Para acelerar, busca una función dentro de este mismo directorio que se llame `acelerar...` y podrás encontrarla. Si necesitas que el sensor mire a la izquierda, busca dentro del archivo ubicado dentro del árbol `servo-control/` una función que se llama `mirarIzquierda();` y la encontrarás. Solo pon ojo de qué es lo que quieres hacer funcionar, busca su carpeta, y luego encuentra la funcionalidad que deseas implementar en ese momento.

---

## Contribuciones
Para contribuir al repo, necesitamos manejarlo a través de Git para evitar archivos grandes y pesados. Primero, crea tu cuenta de GitHub, enlázala con tu Git en tu máquina y clona el repositorio. Aquí te dejo un par de líneas de bash para que puedas configurar tu git correctamente:
``` bash
git config --global user.name "nombre de usuario"
git config --global user.email "correo electronico"
```

De esta manera tu git queda conectado a tu cuenta de GitHub correctamente.

Para clonar el repo, primero haz un **fork**, y una vez creado ese fork clonalo con la siguiente línea:
``` bash
git clone https://github.com/tu-usuario/robot-indep-robert.git
```

Luego de esto, haz los cambios o genera nuevas propuestas y haz **commit** de ellos. Para subir tus cambios a GitHub, haz un **push** con todos tus cambios y luego haz un **Pull Request** hacia el repositorio original. Como ya sé quienes aportaran en el proyecto, cada uno de ustedes tiene una rama específica asignada, por lo que asegúrense de llevar los cambios desde su copia en su repositorio hasta el repo original pero a la rama que les corresponda. Aquí una serie de pasos:
``` bash
# hacemos fetch para actualizar referencias
git fetch origin

# commit de cambios
git commit -m "fix: arreglando referencias de include"

# hacemos push desde nuestra rama main local hacia nuestro repo fork
git push origin main
```
Una vez hecho el push hacia tu repo forkeado, debes hacer el **Pull Request**. Asegúrate que se vea de la siguiente forma:


<img width="926" alt="Captura de pantalla 2024-10-19 a la(s) 15 05 52" src="https://github.com/user-attachments/assets/5964d1f3-3f93-4efb-93ce-5ca685a60811">

En donde **base** es el repo original, aquí deberías poner el nombre de tu rama para subir tus cambios.

#### Importante:
Asegúrense que **SIEMPRE** mantengan sus forks actualizados. Si no los tienen actualizados a su versión más reciente, es muy posible que existan conflictos y no los deje subir sus cambios. Con el botón `Contribute` en sus forks pueden actualizar sus repos al estado del original. Como agregado, asegúrense de siempre ejecutar estas líenas cada tanto tiempo:

``` bash
// Actualizar sus referencias a nuevas ramas.
git fetch origin

// Traer cambios a su copia local en caso de existir.
git pull origin main
```
De esta manera evitamos conflictos y nos aseguramos de que todo fluya según lo acordado.

NOTA: La rama main está protegida y no es posible hacerle push directamente para que no se rompa nada. Por lo que es muy importante el Pull Request desde sus forks hacia la rama que tienen designada.

### Mensaje de commit
Para que los cambios sean lo más uniformes posibles, estoy siguiendo una sintáxis en los commits que hago. Un ejemplo puede ser el siguiente:

``` bash
# Ejemplo 1:
git commit -m "fixed: arreglando sintaxis de funcion mal implementada"

# Ejemplo 2:
git commit -m "add: nuevo archivo para controlar sensor infrarrojo"

#Ejemplo 3:
git commit -m "enhance: mejorado el reconocimiento de obstáculos"
```
A continuación les dejo una lista para que se puedan guiar:
- **'add'**, **'added'**, **'adding'**: Cuando agregues un nuevo archivo, nuevo directorio, crees algo totalmente nuevo no contemplado en la estructura original.
- **'fix'**, **'fixed'**: Cuando arregles un error de funcionamiento o incluso de sintáxis.
- **'enhance'**: Cuando mejores algo que ya existía y funcione mejor que antes.
- **'del'**, **'deleted'**, **'deleting'**: Cuando borres una o múltiples líneas, archivos, directorios.
- **'update'**, **'updating'**: Cuando tengas que hacer actualizar cambios mal recibidos o que requieran una mejora.

A medida que sea necesario, iré agregando más a la lista.

## Licencia

Copyright 2024, Nicolás Huitrayao "nicoosk".
Por la presente se concede permiso, libre de cargos, a cualquier persona que obtenga una copia de este software y de los archivos de documentación asociados (el "Software"), a utilizar el Software sin restricción, incluyendo sin limitación los derechos a usar, copiar, modificar, fusionar, publicar, distribuir, sublicenciar, y/o vender copias del Software, y a permitir a las personas a las que se les proporcione el Software a hacer lo mismo, sujeto a las siguientes condiciones:

El aviso de copyright anterior y este aviso de permiso se incluirán en todas las copias o partes sustanciales del Software.

EL SOFTWARE SE PROPORCIONA "COMO ESTÁ", SIN GARANTÍA DE NINGÚN TIPO, EXPRESA O IMPLÍCITA, INCLUYENDO PERO NO LIMITADO A GARANTÍAS DE COMERCIALIZACIÓN, IDONEIDAD PARA UN PROPÓSITO PARTICULAR E INCUMPLIMIENTO. EN NINGÚN CASO LOS AUTORES O PROPIETARIOS DE LOS DERECHOS DE AUTOR SERÁN RESPONSABLES DE NINGUNA RECLAMACIÓN, DAÑOS U OTRAS RESPONSABILIDADES, YA SEA EN UNA ACCIÓN DE CONTRATO, AGRAVIO O CUALQUIER OTRO MOTIVO, DERIVADAS DE, FUERA DE O EN CONEXIÓN CON EL SOFTWARE O SU USO U OTRO TIPO DE ACCIONES EN EL SOFTWARE.
