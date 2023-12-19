#include <stdio.h>
#include <stdlib.h>

int main() {
    // Crie um ponteiro que indique uma variável do tipo inteiro
    int *ponteiro;

    // Defina que esse ponteiro é igual à alocação de memória para guardar oito dados do tipo inteiro
    ponteiro = (int *)malloc(8 * sizeof(int));

    // Verifique se a alocação foi bem-sucedida
    if (ponteiro == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1; // Saia do programa com código de erro
    }

    // Efetue a realocação de memória para um tamanho que guarde doze dados inteiros
    int *ponteiroRealocado = (int *)realloc(ponteiro, 12 * sizeof(int));

    // Verifique se a realocação foi bem-sucedida
    if (ponteiroRealocado == NULL) {
        printf("Erro na realocação de memória.\n");
        free(ponteiro); // Libere o espaço alocado anteriormente
        return 1; // Saia do programa com código de erro
    } else {
        ponteiro = ponteiroRealocado; // Atualize o ponteiro original para apontar para a nova alocação
    }

    // Agora, você pode usar o ponteiro para acessar a memória alocada
    // ...

    // Libere o espaço alocado nas funções anteriores
    free(ponteiro);

    return 0; // Saia do programa com sucesso
}
