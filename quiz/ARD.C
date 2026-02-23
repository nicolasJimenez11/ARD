#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* ---------- VALIDACIONES ---------- */

bool es_entero(const char *s) {
    if (strlen(s) == 0)
        return false;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return false;
    }
    return true;
}

bool es_id(const char *s) {
    // ID = [A-Za-z]([a-z][0-9])*
    if (strlen(s) == 0)
        return false;

    // Primera letra
    if (!((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z')))
        return false;

    char estado[3] = "q1";  // estado de aceptación
    int i = 1;

    while (s[i] != '\0') {

        if (strcmp(estado, "q1") == 0) {
            // Debe venir minúscula
            if (s[i] >= 'a' && s[i] <= 'z') {
                strcpy(estado, "q2");
            } else {
                return false;
            }
        }
        else if (strcmp(estado, "q2") == 0) {
            // Debe venir dígito
            if (s[i] >= '0' && s[i] <= '9') {
                strcpy(estado, "q1");
            } else {
                return false;
            }
        }

        i++;
    }

    return strcmp(estado, "q1") == 0;
}

bool acepta(const char *s) {
    if (strcmp(s, "++") == 0)
        return true;

    if (strcmp(s, "+") == 0)
        return true;

    if (es_entero(s))
        return true;

    if (es_id(s))
        return true;

    return false;
}

/* ---------- PROGRAMA PRINCIPAL ---------- */

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Uso: ./ard archivo.txt\n");
        return 1;
    }

    FILE *archivo = fopen(argv[1], "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    char linea[256];

    while (fgets(linea, sizeof(linea), archivo)) {

        // Eliminar salto de línea
        linea[strcspn(linea, "\n")] = '\0';

        if (acepta(linea)) {
            printf("ACEPTA\n");
        } else {
            printf("NO ACEPTA\n");
        }
    }

    fclose(archivo);
    return 0;
}