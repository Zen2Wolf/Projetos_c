#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
int resp, ni, NumeroDeIdentificacao, idade, curso;
float nota, notai, notaA, notae, porcentagem, aprovados;
char nome[200], nomei[200], nomea[200], nomee[200];
main(){
setlocale(LC_ALL,"");
resp = 1;

while(resp == 1){
	printf("Escolha um curso a qual o candidato fará o vestibulinho:\nDigite um numero que corresponda ah um curso:\n");
	printf("===============================================\n");
	printf(" 1-Informática / 2-Adminstração / 3-Eletrônica\n");
	printf("===============================================\n");
	scanf("%d", &curso); 
	//curso a ser escolhido, se escolher errado irá entrar no laço abaixo
	
	while((curso < 1) || (curso > 3)){
		printf("escolhe uma das opções!!!\n");
		printf("===============================================\n");
		printf(" 1-Informática / 2-Adminstração / 3-Eletrônica\n");
		printf("===============================================\n");
		scanf("%d", &curso);
		system("cls");
	}
	NumeroDeIdentificacao++; //número de identificação do candidato e total de candidatos
	printf("Curso escolhido com sucesso! \nNúmero de identificação é: %d\n", NumeroDeIdentificacao);
	printf("================================================\n");
	printf("número de identificação: ");
	scanf("%d", &ni);
	while(ni != NumeroDeIdentificacao){
		printf("digite corretamente o número de identificação:");
		scanf("%d", &ni);
	}
	fflush(stdin);
	//abaixo deverá ser colocado as informações do candidato
	
	printf("nome do candidato: ");
    gets(nome);
	printf("idade do candidato: ");
	scanf("%d", &idade);
	printf("nota do candidato(deve ser entre 0 e 10): ");
    scanf("%f", &nota);
    fflush(stdin);
    
	while((nota < 0 ) || (nota > 10)){ //a nota deve ser entre 0 e 10
    	printf("digite corretamente a nota: ");
    	scanf("%f", &nota);
    	fflush(stdin);
	}
	printf("================================================\n");
	if((nota >= 7) && (idade > 18)){
		//se a condição for verdadeira, o candidato é aprovado, caso contrário é reprovado
		printf("~~~~~~~~~~~~~~~~~~~~APROVADO~~~~~~~~~~~~~~~~~~~~\n");
		printf("================================================\n"); 
		
			if(curso == 1){ 	/*se foi aprovado, terá um teste para ver qual curso foi escolhido
							 		e em seguida irá verificar se a nota é a maior do curso escolhido */
				if(nota > notai){
					notai = nota;
					strcpy(nomei, nome);
				}
			}
			else{
				if(curso == 2){
					if(nota > notaA){
						notaA = nota;
						strcpy(nomea, nome);
					}
				}
				else{
					if(nota > notae){
						notae = nota;
						strcpy(nomee, nome);
					}
				}
			}
		aprovados++; //a quantidade de aprovados no total independente de qual curso escolheu
	}
	else{
		printf("~~~~~~~~~~~~~~~~~~~REPROVADO~~~~~~~~~~~~~~~~~~~~\n");
		printf("================================================\n");
	}


	printf("\ndeseja inscrever outro candidato? sim=1/não=2\n"); //mais candidatos poderão ser adicionados, não se sabe quantos
	scanf("%d", &resp);
	while((resp < 1) || (resp > 2)){
		printf("use: sim=1/não=2\n");
		scanf("%d", &resp);
	}	
	system("cls"); //deixará a tela menos poluída, facilitando o entendimento do usuário
}
porcentagem = (aprovados/NumeroDeIdentificacao) * 100;  //calculando a porcentagem de aprovados
printf("Candidatos foram aprovados: %.0f\n", aprovados); //finalizando o programa mostrando as informações finalizadas
printf("Porcentagem de candidatos aprovados: %.1f%%\n", porcentagem);
printf("melhores candidatos:\n================================\n");
printf("Informática:\nNome: %s \nNota: %.1f\n================================\n", nomei, notai);
printf("Adminstração:\nNome: %s \nNota: %.1f\n================================\n", nomea, notaA);
printf("Eletrônica:\nNome: %s \nNota: %.1f\n================================\n", nomee, notae);
}
