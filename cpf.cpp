#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int cpf[11], Ccpf[2][11], contam[15], digit10_11[2], cpfsteste;
int resp, x, y, valor, resto;
float porcpfs[4];
main(){
	setlocale(LC_ALL,"");
	do{
		cpfsteste++; //total de cpfs testados
		contam[12] = 0;
		contam[13] = 0;
		valor = 10;
		printf("Digite os números de seu CPF, um número de cada vez!\n");
		for(x = 0; x <= 10; x++){
			scanf("%d", &cpf[x]);
			while((cpf[x] < 0) || (cpf[x] > 9)){
				printf("Digite o número de seu cpf corretamente!!:\n");
				scanf("%d", &cpf[x]);
			}
		}
		for(x = 0; x <= 8; x++){
				
			Ccpf[0][x] = cpf[x]; //cpf digitado, apenas os 9 números do cpf					
			Ccpf[1][x] = valor; //valor abaixo dos 9 números do cpf (de 10 até 2)
			valor = valor - 1;
			contam[x] = Ccpf[0][x] * Ccpf[1][x]; //valores multiplicados exemplo:(linha-1-coluna-1 * linha-2-coluna-1)
			contam[12] = contam[12] + contam[x]; //dentro de contam[10] terá a soma dos valores multiplicados de dentro dele (do 1º teste)	
		}		
		resto = contam[12]%11;
		if(resto < 2){
			digit10_11[0] = 0;
		}
		else{
			digit10_11[0] = 11 - resto;
		}
		valor = 11;
		Ccpf[0][9] = digit10_11[0];
		for(y = 0; y <=9; y++){
			Ccpf[1][y] = valor;
			valor = valor - 1;
			
			contam[y] = Ccpf[1][y] * Ccpf[0][y];
			contam[13] = contam[13] + contam[y];	
		}
				
		
		resto = contam[13]%11;
		if(resto < 2){
			digit10_11[1] = 0;
		}
		else{
			digit10_11[1] = 11 - resto;
		}
		if((digit10_11[0] == cpf[9]) && (digit10_11[1] == cpf[10])){
			printf("O CPF digitado é válido!\n");
			porcpfs[0]++;
				 //total de cpfs válidos
		}
		else{
			printf("O CPF digitado é inválido!!!\n");
			porcpfs[1]++;
				 //total de cpfs inválidos
		}
			
		printf("Verificar mais CPF? 1-sim/2-não\n");
		scanf("%d", &resp);
		while((resp < 1) || (resp > 2)){
			printf("Escolha uma das opções!!! 1-SIM/2-NÃO\n");
			scanf("%d", &resp);
		}
		system("cls");
	}while(resp == 1);
	porcpfs[2] = (porcpfs[0]/cpfsteste) * 100;
	porcpfs[3] = (porcpfs[1]/cpfsteste) * 100;
	printf("CPFs testados foram: [%d]\n", cpfsteste);
	printf("CPFs válidos: [%.0f]\nCPFs inválidos: [%.0f]\n", porcpfs[0], porcpfs[1]);
	printf("A porcentagem de CPFs válidos é: [%.1f%%]\n", porcpfs[2]);
	printf("A porcentagem de CPFs inválidos é: [%.1f%%]\n", porcpfs[3]);	
}
