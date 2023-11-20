#include <stdio.h>

int main() {
    int numLinhas, numColunas, numPecas;
    scanf("%d %d", &numLinhas, &numColunas);
    scanf("%d", &numPecas);

    int tab[numLinhas][numColunas];
    for (int i = 0; i < numLinhas; i++)
        for (int j = 0; j < numColunas; j++)
            tab[i][j] = 0;

    for (int i = 0; i < numPecas; i++) {
        int posX, posY;
        scanf("%d %d", &posX, &posY);
        tab[posX - 1][posY - 1] = 1;
    }

    int maxPecasBrancas = 0;
    for (int i = 0; i < numLinhas; i++)
        for (int j = 0; j < numColunas; j++)
            if (tab[i][j] == 0) {
                maxPecasBrancas++;

                for (int x = i - 1; x <= i + 1; x++)
                    for (int y = j - 1; y <= j + 1; y++)
                        if (x >= 0 && x < numLinhas && y >= 0 && y < numColunas)
                            tab[x][y] = 1;
            }

    printf("%d\n", maxPecasBrancas);

    return 0;
}
