//Nome completo: Rodrigo Boaventura 
//Matrícula: UC22103134
//Curso: Ciência da Computação
//Nome completo: Nycollas Passos Martins
//Matrícula: UC2011002500
//Curso: Ciência da Computação
//Nome: André Luís Cordeiro Porto da Silva
//Matricula: UC 22421199
//Curso: Ciência da Computação

#include <stdio.h>
#include <locale.h>

int main(){
    int numeroSessoes, numeroPessoas, idade, totalInteiras, totalMeias;
    char sexo, resultado;
    float totalArrecadado;
    int qtdCriancas, qtdAdolescentes, qtdAdultos, qtdIdosos, qtdMaioresIdadeMasc, qtdMaioresIdadeFem;
    char nomeFilme[50];
    
    setlocale (LC_ALL, "Portuguese");
    // Solicita a quantidade de sessões, aceitando exatamente 2 (duas) sessões
    do{
      printf("Digite a quantidade de sessões: ");
      scanf("%d", &numeroSessoes);
    }while(numeroSessoes != 2);
    
    // Solicita a quantidade de pessoas que assistiram ao filme, não aceitando valor inferior a 0 (zero).
    do{
      printf("Digite a quantidade de pessoas que assistiram ao filme: ");
      scanf("%d", &numeroPessoas);
    }while(numeroPessoas < 0);
    
    // Solicite ao usuário o nome do filme
    printf("Digite o nome do filme: ");
    scanf("%s", nomeFilme);
    
    // Inicializa as variáveis
    totalInteiras = 0;
    totalMeias = 0;
    totalArrecadado = 0;
    qtdCriancas = 0;
    qtdAdolescentes = 0;
    qtdAdultos = 0;
    qtdIdosos = 0;
    qtdMaioresIdadeMasc = 0;
    qtdMaioresIdadeFem = 0;

    // Lê os dados de cada pessoa
    for(int i = 0; i < numeroPessoas; i++){
        // Solicita e valida o sexo
        do{
            printf("Digite o sexo (M - masculino, F - feminino): ");
            scanf("%s", &sexo);
        }while(sexo != 'M' && sexo != 'F');

        // Solicita e valida a idade
        do{
            printf("Digite a idade (3 - 100 anos): ");
            scanf("%d", &idade);
        }while(idade < 3 || idade > 100);

        // Solicita e valida se foi pago inteira ou meia entrada
        do{
            printf("Digite o tipo da entrada (I - Inteira, M - Meia): ");
            scanf("%s", &resultado);
        }while(resultado != 'I' && resultado != 'M');

        // Contabiliza o valor arrecadado
        if(resultado == 'I'){
            totalInteiras++;
            totalArrecadado += 50;
        } else {
            totalMeias++;
            totalArrecadado += 25;
        }

        // Contabiliza as pessoas de acordo com a classificação de idade
        if(idade >= 3 && idade <= 13){
            qtdCriancas++;
        } else if(idade >= 14 && idade <= 17){
            qtdAdolescentes++;
        } else if(idade >= 18 && idade <= 64){
            qtdAdultos++;
        } else if(idade >= 65 && idade <= 100){
            qtdIdosos++;
        }

        // Contabiliza as pessoas maiores de idade de acordo com o sexo
        if(idade >= 18){
            if(sexo == 'M'){
                qtdMaioresIdadeMasc++;
            } else {
                qtdMaioresIdadeFem++;
            }
        }
    }

    // Mostra o nome do filme, a quantidade de pessoas do sexo feminino e a quantidade de pessoas do sexo masculino que assistiram ao filme.
    printf("\nO filme %s teve %d pessoas do sexo feminino e %d pessoas do sexo masculino\n", nomeFilme, qtdMaioresIdadeFem, qtdMaioresIdadeMasc);

    // Mostra a quantidade de pessoas, seguindo a classificação por idade indicada
    printf("Crianças: %d\n", qtdCriancas); 
    printf("Adolescentes: %d\n", qtdAdolescentes); 
    printf("Adultos: %d\n", qtdAdultos); 
    printf("Idosos: %d\n", qtdIdosos); 

    // Mostra a quantidade de pessoas maiores de idade do sexo masculino e a quantidade de pessoas maiores de idade do sexo feminino que estiveram presentes.
    printf("Maiores de idade do sexo feminino: %d\n", qtdMaioresIdadeFem);
    printf("Maiores de idade do sexo masculino: %d\n", qtdMaioresIdadeMasc);

    // Mostra o valor total arrecadado na sessão e informa se houve mais pagamento de inteira que de meia entrada.
    printf("Valor arrecadado: %.2f\n", totalArrecadado);
    printf("Inteiras: %d\n", totalInteiras);
    printf("Meias: %d\n", totalMeias);
    if(totalInteiras > totalMeias){
        printf("Houve mais pagamento de inteiras que de meias entradas\n");
    } else {
        printf("Houve mais pagamento de meias entradas que de inteiras\n");
    }

    // Nova funcionalidade: mostra a porcentagem de pessoas maiores de idade em relação ao total
    printf("\nPorcentagem de pessoas maiores de idade em relação ao total: %.2f%%\n", (float)qtdMaioresIdadeMasc/(float)numeroPessoas*100);

    return 0;
