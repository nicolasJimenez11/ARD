# ARD

En este proyecto se implementa un Autómata Finito Determinista (AFD) en lenguaje C para reconocer cadenas que pertenecen a lenguajes formales específicos: identificadores, números enteros, el operador suma (+) y el operador incremento (++).

El programa lee un archivo de texto con una cadena por línea y determina si cada una es aceptada o rechazada según las reglas definidas, simulando el funcionamiento de un autómata sin utilizar expresiones regulares.

**Como ejecutarlo PY**

1.Asegúrate de tener Python instalado en tu computadora.

2.Prepara un archivo de texto (archivo.txt) con una cadena por línea.

3.Ejecuta el programa:

py ard.py archivo.txt

4Observa la salida para cada línea del archivo:

  -ACEPTA → si la cadena cumple alguna regla del AFD

  -NO ACEPTA → si la cadena no cumple ninguna regla

Si no proporcionas un archivo, se mostrará el mensaje:
Uso: python ard.py archivo.txt

**Como ejecutarlo C**


1.Asegúrate de tener un compilador de C instalado (por ejemplo, GCC).

2.Compila el programa:

gcc ard.c -o ard

3.Prepara un archivo de texto (archivo.txt) con una cadena por línea.

4.Ejecuta el programa:

./ard entrada.txt

5.Observa la salida para cada línea del archivo:

ACEPTA → cadena válida

NO ACEPTA → cadena inválida

6.Si no proporcionas un archivo, se mostrará el mensaje:

Uso: ./ard archivo.txt

**EXPLICACION DEL CODE**

El programa implementa un Autómata Finito Determinista (AFD) en Python y C que valida cadenas según cuatro tipos: enteros, identificadores, suma (+) e incremento (++). Primero, verifica si la cadena es un entero, comprobando que todos sus caracteres sean dígitos. Luego, valida si es un identificador siguiendo el patrón [A-Za-z] ([a-z][0-9]), simulando un autómata con dos estados: q1, estado de aceptación, y q2, que espera un dígito para completar el par. La función principal acepta() determina si la cadena cumple alguna de estas reglas, devolviendo verdadero si es válida. El programa lee un archivo de texto línea por línea, limpia los saltos de línea y evalúa cada cadena, imprimiendo ACEPTA o NO ACEPTA según corresponda. En Python se utiliza strip() para limpiar líneas y comparación directa de strings, mientras que en C se usan arrays de caracteres, strcspn() para eliminar saltos de línea y strcmp() para comparar cadenas, manteniendo la misma lógica y resultados en ambos lenguajes.

**ANALISIS**

El programa demuestra cómo un Autómata Finito Determinista (AFD) puede implementarse de manera práctica para reconocer patrones específicos en cadenas de texto. El análisis del código muestra que la separación de funciones (es_entero, es_id, acepta) permite modularidad y claridad, facilitando la extensión a otros lenguajes regulares si fuese necesario. El AFD utilizado para los identificadores es eficiente, ya que procesa cada carácter exactamente una vez y utiliza un número constante de estados, garantizando complejidad lineal respecto al tamaño de la cadena. Además, al implementar la misma lógica tanto en Python como en C, se observa cómo los conceptos teóricos de autómatas pueden trasladarse a distintos lenguajes de programación, respetando las diferencias de manejo de cadenas y estructuras de control, sin afectar el resultado final del reconocimiento de cadenas válidas o inválidas.
