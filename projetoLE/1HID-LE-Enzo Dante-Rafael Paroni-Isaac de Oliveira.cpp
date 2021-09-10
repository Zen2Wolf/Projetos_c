//1HID   LE   Enzo Dante, Isaac de Oliveira e Rafael Paroni

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int anod, bissexto, mesd, dian, resto, x, ano;
char continuar;

main(){
 do{
 
	printf("Este programa ira dizer o dia da semana em que voce nasceu\n");
	printf("Digite o dia de seu nascimento:\n");
	scanf("%d", &dian);
	if(dian <= 31){
		dian = dian - 1;
		
		printf("Agora digite o mes de seu nascimento:\n");
		scanf("%d", &mesd);
		if((mesd == 1) || (mesd == 10)){
			x = 0;
		}else{
			if((mesd == 2) || (mesd == 3) || (mesd == 11)){
				x = 3;
			}else{
				if((mesd == 4) || (mesd == 7)){
					x = 6;
				}else{
					if(mesd == 5){
						x = 1;
					}else{
						if(mesd == 6){
							x = 4;
						}else{
							if(mesd == 8){
								x = 2;
							}else{
								x = 5;
							}
						}
					}
				}
			}
		}
	  if((mesd > 0) && (mesd < 12)){
	  	
		printf("E para finalizar, digite um ano entre 1900 e 2399:\n");
		scanf("%d", &anod);
		if((anod >= 1900) && (anod <= 2399)){
			if(((anod%400 == 0) || (anod%4 == 0) && !(anod%100 == 0)) && ((mesd == 1) && (dian <= 31) || (mesd == 2) && (dian <=29))){
				
					printf("Eh um ano bissexto!!!\n");
					ano = anod - 1900;
					bissexto = ano/4;
					bissexto = bissexto - 1;
			}
			else{
				printf("O ano nao eh bissexto!\n");
				ano = anod - 1900;
				bissexto = ano/4;
			}
			printf("Digite qualquer tecla para continuar!!!!\n");
			system("pause");
			system("cls");
			
			resto = (ano + bissexto + x + dian)%7;
			dian = dian + 1;
			printf("%d / %d / %d\n", dian, mesd, anod);
			
			if(resto == 0){
				printf("Voce nasceu na segunda-feira!\n");
			}
			else{
				if(resto == 1){
					printf("Voce nasceu na terca-feira!\n");
				}
				else{
					if(resto == 2){
						printf("Voce nasceu na quarta-feira!\n");
					}
					else{
						if(resto == 3){
							printf("Voce nasceu na quinta-feira!\n");
						}
						else{
							if(resto == 4){
								printf("Voce nasceu na sexta-feira!\n");
							}
							else{
								if(resto == 5){
									printf("Voce nasceu no sabado!\n");
								}
								else{
									printf("Voce nasceu no domingo!\n");
								}
							}
						}
					}
				}
			}			
		}
		else{
			printf("O ano nao esta entre 1900 e 2399!\n");
		}
		
	 }
	  else{
	  	printf("O mes nao esta entre 1 e 12!\n");
	  }		
	}
	else{
		printf("O dia eh maior que 31!\n");		
	}
	printf("repetir programa? sim ou nao\n");
	scanf("%s", &continuar);
	fflush(stdin);      // este comando é mt util, caso tenha espaço no scanf %s ele n pula outras perguntas!!!
 }while((continuar == 's') || (continuar == 'S'));
	system("pause");
	return(0);
}
