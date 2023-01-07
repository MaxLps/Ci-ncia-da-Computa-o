#include <stdio.h>
#include <string.h>
int main() {
    char abc[27] = "abcdefghijklmnopqrstuvwxyz";
    char frase[200], lixo;
    int f[26];
    int n, i, j, maior;
    scanf("%d ", &n);
    while (n--) {
        fgets(frase, 200, stdin);
        for (i = 0; i < 26; i++)
            f[i] = 0;
        for (i = 0; i < strlen(frase); i++) {
            for (j = 0; j < 26; j++) {
                if (frase[i] == abc[j] || frase[i]+32 == abc[j]) {
                    f[j]++;
                    break;
                }
            }
        }
        maior = f[0];
        for (i = 1; i < 26; i++)
            if (f[i] > maior)
                maior = f[i];
        for (i = 0; i < 26; i++)
            if (f[i] == maior)
                printf("%c", abc[i]);
        printf("\n");
    }
    return 0;
}