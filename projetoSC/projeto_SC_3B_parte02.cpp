#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
int nova[10], pronta[10], susp[10], exe, fim[512], termi, escolha, x, aptos, y, aux;
int processador, retorno, aux2;



void entrada(){
	if(nova[0] == 0){ //analisa se a memória está vazia
		x = 0;
	}
	if(x > 9){ //-------------------x é a posição no vetor da memória se for maior q 9, o vetor está cheio
		printf("   =====================\n");
		printf("   ====MEMÓRIA CHEIA====\n");
		printf("   =====================\n\n");
		system("pause");
		system("cls");
	}
	else{ //--------------se x for menor q 9 o usuário pode continuar digitando um novo processo
		printf("===========================================\n");
		printf("Para simular um processo, digite uma letra!\n\n");
		printf("-");
		fflush(stdin);
		scanf("%c", &nova[x]);
		system("cls");
		if(x > 0){
			for(y = 0; y < x; y++){ //--------------analisa se o usuário ja digitou letra repetida
				while(nova[x] == nova[y]){
					printf("   ===================\n");
					printf("   Digite outra letra:\n");
					printf("   ===================\n\n");
					fflush(stdin);
					scanf("%c", &nova[x]);
					system("cls");
				}
			}
		}
		x++;
	}
	
}

void filaaptos(){
	if(nova[0] == 0){ //verifica se a fila da memória está vazia, acho q ta bem explicito :)
		printf("   ===================================\n");
		printf("   ====FILA DA MEMÓRIA ESTÁ VAZIA!====\n");
		printf("   ===================================\n\n");
		system("pause");
		system("cls");
	}
	else{
		if(pronta[0] == 0){ //--------caso tenha espaço na fila de aptos,tudo q esta na memória sera enviado para fila de aptos
			aptos = 0;
			for(y = 0; y <= 9; y++){
				pronta[y] = nova[y];
				nova[y] = NULL;
				aptos++;
			}
			printf("   ================================================\n");
			printf("   ====PROGRAMA DA MEMÓRIA ENVIADO COM SUCESSO!====\n");
			printf("   ================================================\n\n");
			system("pause");
			system("cls");
		}
		else{ //-----------------se fila de aptos contém pelo elementos na posição 0, a memória não vai ser enviada
			printf("   ===================================\n");
			printf("   ===FILA DE APTOS NÃO ESTÁ VAZIA!===\n");
			printf("   ===================================\n\n");
			system("pause");
			system("cls");
		}
	}
}

void processoexe(){
	// 1 - executar até o final
	// 2 - fim do tempo quantum (volta para vetor pronta[])
	// 3 - suspensão
	
	exe = rand()%3 + 1;
	//printf("teste %d\n", exe); printf temporário, deve ser removido no caso de projeto completo---------------------------------------=========--ATENÇÃO
	processador = pronta[0]; //------escolha da 6º opção, posição 0 da fila de aptos enviado para processador!
	for(y = 0; y <= 9; y++){ //------fila de aptos anda depois da posição 0 ter sido armazenado em outro lugar
		pronta[y] = pronta[y + 1];
		//printf("[%c]\n", pronta[y]); printf("temporário, REMOVEEEEEEEEEEEEEEEER-------------------------------------------------============---ATENÇÃO
		if(pronta[y + 1] == 0){
			pronta[y] = NULL;
		}
	}
	/*for(aptos = 0; aptos <= 9; aptos++){ ----- caso eu precise por algum motivo, não questione qual!!!
		if(pronta[aptos + 1] == 0){
			pronta[aptos] = NULL;
		}
	}
	y = aptos;
	pronta[y] = NULL;
	aptos--;*/
	
	if(exe == 1){ //---------------processo finalizado
		fim[termi] = processador;
		termi++;
		printf("\t===========================\n");
		printf("\t====PROCESSO FINALIZADO====\n");
		printf("\t===========================\n\n");
		system("pause");
		system("cls");
	}
	else{
		if(exe == 2){//--------------processo volta para fila de aptos
			//pronta[9] = processador;
			aux2 = 0;
			for(retorno = 0; retorno <= 9; retorno++){
				if((aux2 == 0) && (pronta[retorno] == 0)){
					pronta[retorno] = processador;
					aux2 = 1;
				}
			}
			printf("\t=================================\n");
			printf("\t====PROCESSO NA FILA DE APTOS====\n");
			printf("\t=================================\n\n");
			system("pause");
			system("cls");
			
		}
		else{ //------------------processo será enviado para fila de suspenso caso não estaja lotado
			
			if(aux > 9){
				printf("   ==================================\n");
				printf("   ===FILA DE SUSPENSO ESTÁ LOTADO===\n");
				printf("   ==================================\n\n");
				system("pause");
				system("cls");
			}
			else{
				susp[aux] = processador;
				aux++; // variavel armazena o total de valores q estão na fila de suspenso
				printf("   ====================================\n");
				printf("   ====PROCESSO NA FILA DE SUSPENSO====\n");
				printf("   ====================================\n\n");
				system("pause");
				system("cls");
			}
		}
	}	
}

void suspensoapt(){
	if(susp[0] == 0){ //-------------------analisa se na posição 0 está vazia
		printf("   ===================================\n");
		printf("   ====FILA DE SUSPENSO ESTÁ VAZIA====\n");
		printf("   ===================================\n\n");
		system("pause");
		system("cls");
	}
	else{
		
	
		for(y = 0; y <= 9; y++){ //printa todos os valores na fila de suspenso para remover uma das posições
			printf("[%c]\n", susp[y]);
		}
		printf("\n   ===========================================================\n");
		printf("   Diga a posição que queira remover(utilize número de 0 á 9):\n");
		printf("   ===========================================================\n");
		printf(" - ");
		scanf("%d", &aux2);
		while((aux2 < 0) || (susp[aux2] == 0)){  //---------------ira analisar se existem processo na posição digitada pelo usuário
			printf("   ==========================================\n");
			printf("   ====NÃO EXISTE PROCESSO NESTA POSIÇÃO!====\n");
			printf("   ==========================================\n\n");
			printf(" - Digite outra posição!:\n");
			printf(" - ");
			scanf("%d", &aux2);
		}
		system("pause");
		system("cls");
		if(pronta[9] != 0){ //---------------analisa se a fila de aptos está cheia, julgando caso a última posição tenha algo
			printf("   =================================\n");
			printf("   ====FILA DE APTOS ESTÁ LOTADO====\n");
			printf("   =================================\n");
			system("pause");
			system("cls");
		}
		else{
			aptos = 0;
			for(y = 0; y <= 9; y++){ //-------envia o valor na posição digitada pelo usuário para fila de aptos
				if((pronta[y] ==  0) && (aptos == 0)){//procura um espaço vazio
					pronta[y] = susp[aux2];
					susp[aux2] = NULL;
					aptos++;
					aux--; // variavel armazena o total de valores q estão na fila de suspenso
				}
			}
			for(y = 0; y < 9; y++){ //--------faz a fila andar após a posição 0 ficar vazia
				if(susp[y] == 0){
					susp[y] = susp[y + 1];
					susp[y + 1] = NULL;
				}
			}
			printf("   =================================\n");
			printf("   ========POSIÇÃO REMOVIDA=========\n");
			printf("   ====MOVIDA PARA FILA DE APTOS====\n");
			printf("   =================================\n\n");
			system("pause");
			system("cls");
		}
	}
}

main(){
	srand(time(NULL));
	setlocale(LC_ALL,"");
	printf("\t======================================\n");
	printf("\t=======-SIMULADOR DE PROCESSOS-=======\n");
	printf("\t======================================\n\n");
	while(true){
		printf("\n\tEscolha uma das opções\n");
		printf("====================================\n\n");
		printf("  1---Carregar o programa na memoria(digite uma letra)\n  2---Listar programas na memoria (mostrar vetor na memoria)\n");
		printf("  3---Listar programas na fila de aptos (mostrar vetor na fila de aptos)\n  4---Listar programas na fila de suspensos (mostrar valores na fila de suspensos)\n");
		printf("  5---Enviar programa da memoria para fila de aptos\n  6---Executar programa (Ciclo do processador)\n  7---Tirar programa da fila de suspensos\n\n");
		printf("  --");
		scanf("%d", &escolha);
		while((escolha < 1) || (escolha > 7)){
			printf("\n    ================================\n");
			printf("    ====Escolha uma das opções!!====\n");
			printf("    ================================\n");
			printf("  --");
			scanf("%d", &escolha);
		}
		system("cls");
		
		if(escolha == 1){ //-------- a maioria dos comandos aqui são p printar o vetor e chamar um procedimento
			entrada();
		}
		else{
			if(escolha == 2){
				for(y = 0; y <= 9; y++){
					printf("[%c]\n", nova[y]);
				}
				system("pause");
				system("cls");
			}
			else{
				if(escolha == 3){
					for(y = 0; y <= 9; y++){
						printf("[%c]\n", pronta[y]);
					}
					system("pause");
					system("cls");
				}
				else{
					if(escolha == 4){
						for(y =0; y <= 9; y++){
							printf("[%c]\n", susp[y]);
						}
						system("pause");
						system("cls");
					}
					else{
						if(escolha == 5){
							filaaptos();
						}
						else{
							if(escolha == 6){
								if(pronta[0] != 0){
									processoexe();
								}
								else{
									printf("\n   =================================\n");
									printf("   ====FILA DE APTOS ESTÁ VAZIA!====\n");
									printf("   =================================\n\n");
									system("pause");
									system("cls");
								}
							}
							else{
								suspensoapt();
							}
						}
					}
				}
			}
		}		
	}
}
