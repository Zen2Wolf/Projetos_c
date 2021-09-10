#include<stdio.h>
#include<stdlib.h>
int escolha, a[10], x, control, totalTeste, total, aux, reset;
main(){
	total = 10;
	while(escolha != 4){
		printf("\n==========Escolha uma das opcoes============\n");
		printf("1-Inserir novo processo\n2-Processar processo\n3-Ordenar processo\n4-encerrar programa\n\n");
		scanf("%d", &escolha);
		while((escolha < 1) || (escolha > 4)){
			printf("Escolha uma das opcoes:\n");
			scanf("%d", &escolha);
		}
		if(escolha == 1){
			printf("Total de processos restantes: [%d]\n\n", total);
			printf("Digite um numero: ");
			scanf("%d", &a[control]);
			control++;
			total--;
			system("cls");
			if(total == 0){
				printf("deseja apagar todos os processos? 1-sim/2-nao\n");
				scanf("%d", &reset);
				while((reset < 1) || (reset > 2)){
					printf("Escolha uma das opcoes: ");
					scanf("%d", &reset);
				}
				if(reset == 1){
					control = 0;
					total = 10;
					printf("Resetado!!!\n\n");
				}
				
			}
		}
		else{
			if(escolha == 2){
				for(x =0; x<=8; x++){
					if(a[x] < a[x+1]){
						aux = a[x];
						a[x] = a[x+1];
						a[x+1] = aux;
					}
					
				}
				x = 9;
				a[x] = NULL;
				system("pause");
				system("cls");
			}
			else{
				if(escolha == 3){
					//organizar vetor!!!!
					int totalo = control;
					while(totalo > 1){
						for(int y = 0; y <= 9-1; y++){
							if(a[y] > a[y+1]){
								aux = a[y];
								a[y] = a[y+1];
								a[y+1] = aux;
							}
							
						}
						totalo--;
					}
					for(x = 0; x<9; x++){
						if(a[x] == 0){
							a[x] = a[x+1];
							a[x+1] = NULL;
						}
					}
					for(x = 0; x< 9; x++){
						printf("[%d]\n",a[x]);
					}
					system("pause");
					system("cls");
				}
				escolha = 4;
			}
		}
		
		
		
		
	}
	
	
	
	
}
