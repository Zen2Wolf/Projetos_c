// 1HID 2� bimestre-Enzo Dante, Isaac de Oliveira e Rafael Paroni.
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
	printf("Escolha um curso a qual o candidato far� o vestibulinho:\nDigite um numero que corresponda ah um curso:\n");
	printf("===============================================\n");
	printf(" 1-Inform�tica / 2-Adminstra��o / 3-Eletr�nica\n");
	printf("===============================================\n");
	scanf("%d", &curso); 
	//curso a ser escolhido, se escolher errado ir� entrar no la�o abaixo
	
	while((curso < 1) || (curso > 3)){
		printf("escolhe uma das op��es!!!\n");
		printf("===============================================\n");
		printf(" 1-Inform�tica / 2-Adminstra��o / 3-Eletr�nica\n");
		printf("===============================================\n");
		scanf("%d", &curso);
		system("cls");
	}
	NumeroDeIdentificacao++; //n�mero de identifica��o do candidato e total de candidatos
	printf("Curso escolhido com sucesso! \nN�mero de identifica��o �: %d\n", NumeroDeIdentificacao);
	printf("================================================\n");
	printf("n�mero de identifica��o: ");
	scanf("%d", &ni);
	while(ni != NumeroDeIdentificacao){
		printf("digite corretamente o n�mero de identifica��o:");
		scanf("%d", &ni);
	}
	fflush(stdin);
	//abaixo dever� ser colocado as informa��es do candidato
	
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
		//se a condi��o for verdadeira, o candidato � aprovado, caso contr�rio � reprovado
		printf("~~~~~~~~~~~~~~~~~~~~APROVADO~~~~~~~~~~~~~~~~~~~~\n");
		printf("================================================\n"); 
		
			if(curso == 1){ 	/*se foi aprovado, ter� um teste para ver qual curso foi escolhido
							 		e em seguida ir� verificar se a nota � a maior do curso escolhido */
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


	printf("\ndeseja inscrever outro candidato? sim=1/n�o=2\n"); //mais candidatos poder�o ser adicionados, n�o se sabe quantos
	scanf("%d", &resp);
	while((resp < 1) || (resp > 2)){
		printf("use: sim=1/n�o=2\n");
		scanf("%d", &resp);
	}	
	system("cls"); //deixar� a tela menos polu�da, facilitando o entendimento do usu�rio
}
porcentagem = (aprovados/NumeroDeIdentificacao) * 100;  //calculando a porcentagem de aprovados
printf("Candidatos foram aprovados: %.0f\n", aprovados); //finalizando o programa mostrando as informa��es finalizadas
printf("Porcentagem de candidatos aprovados: %.1f%%\n", porcentagem);
printf("melhores candidatos:\n================================\n");
printf("Inform�tica:\nNome: %s \nNota: %.1f\n================================\n", nomei, notai);
printf("Adminstra��o:\nNome: %s \nNota: %.1f\n================================\n", nomea, notaA);
printf("Eletr�nica:\nNome: %s \nNota: %.1f\n================================\n", nomee, notae);
}
