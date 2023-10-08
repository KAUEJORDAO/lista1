#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_LINHA 200

typedef struct {
    char nome[MAX_NOME];
    float nota1;
    float nota2;
} Aluno;

int main() {
    FILE *entrada = fopen("C:\\Users\\kauee\\OneDrive\\Documentos\\lista1\\dadosentrada\\DadosEntrada.csv", "r");
    FILE *saida = fopen("SituacaoFinal.csv", "w");

    if (entrada == NULL || saida == NULL) {
        perror("Erro ao abrir os arquivos");
        return 1;
    }

    char linha[MAX_LINHA];
    Aluno aluno;

    fprintf(saida, "Nome,Media,Situacao\n");

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        // Use strtok para dividir a linha em tokens separados por vírgula
        char *token = strtok(linha, ",");
        if (token != NULL) {
            strncpy(aluno.nome, token, MAX_NOME);
            aluno.nome[MAX_NOME - 1] = '\0';

            // Leitura do telefone e do curso (não usados neste exemplo)
            strtok(NULL, ",");
            strtok(NULL, ",");

            // Leitura das notas
            token = strtok(NULL, ",");
            if (token != NULL) {
                aluno.nota1 = atof(token);
                token = strtok(NULL, ",");
                if (token != NULL) {
                    aluno.nota2 = atof(token);

                    // Calcula a média
                    float media = (aluno.nota1 + aluno.nota2) / 2;

                    // Determina a situação
                    const char *situacao = (media >= 7.0) ? "APROVADO" : "REPROVADO";

                    // Escreve os dados no arquivo de saída
                    fprintf(saida, "%s,%.2f,%s\n", aluno.nome, media, situacao);
                }
            }
        }
    }

    fclose(entrada);
    fclose(saida);

    printf("Processamento concluído. Resultados salvos em SituacaoFinal.csv.\n");

    return 0;
}
