# ARD/AFD: reconoce si una cadena completa es:
#   ID = [A-Za-z]([a-z][0-9])*
#   SUMA = +
#   ENTERO = [0-9]+
#   INCREMENTO = ++
# Lee un archivo .txt (una cadena por línea)

import sys


def es_entero(s: str) -> bool:
    if len(s) == 0:
        return False
    for ch in s:
        if not ('0' <= ch <= '9'):
            return False
    return True


def es_id(s: str) -> bool:
    # ID = [A-Za-z]([a-z][0-9])*
    if len(s) == 0:
        return False

    def es_primera(ch: str) -> bool:
        return ('A' <= ch <= 'Z') or ('a' <= ch <= 'z')

    def es_minuscula(ch: str) -> bool:
        return 'a' <= ch <= 'z'

    def es_digito(ch: str) -> bool:
        return '0' <= ch <= '9'

    # q0 -> q1
    if not es_primera(s[0]):
        return False

    estado = "q1"  # aceptación
    i = 1

    while i < len(s):
        ch = s[i]

        if estado == "q1":
            # Solo puede iniciar un par (minuscula, digito)
            if es_minuscula(ch):
                estado = "q2"
            else:
                return False

        elif estado == "q2":
            # Debe venir un dígito para cerrar el par y volver a q1
            if es_digito(ch):
                estado = "q1"
            else:
                return False

        i += 1

    return estado == "q1"


def acepta(s: str) -> bool:
    if s == "++":
        return True
    if s == "+":
        return True
    if es_entero(s):
        return True
    if es_id(s):
        return True
    return False


def main() -> None:
    if len(sys.argv) < 2:
        print("Uso: python ard.py archivo.txt")
        return

    ruta = sys.argv[1]

    with open(ruta, "r", encoding="utf-8") as f:
        for linea in f:
            cadena = linea.strip()

            if acepta(cadena):
                print("ACEPTA")
            else:
                print("NO ACEPTA")


if __name__ == "__main__":
    main()