#include <stdio.h>
#include <stdlib.h>

// ESTRUTURA ALUNOS
typedef struct {
	char nome[60];
	char matricula[10];
	char login_aluno[10];
	char senha_aluno[10];

	float media[13];
	int qts_faltas[13];



} Aluno;

// ESTRUTURA SECRETÁRIO
typedef struct
{
	char codigo[10];
	char login_func[10];
	char senha_func[10];

} Secretario;

//FUNÇÃO LIMPA O LIXO DE MEMORIA CONTIDO NOS VETORES 'MÉDIA' E 'FALTAS' DA ESTRUTURA ALUNO
void limpaLixoMemoria(Aluno *alunos){
	int i, j, k;
	for (i = 0; i < 3; i++){
		for(j = 0; j < 13; j++){
			alunos[i].media[j] = 0;
			alunos[i].qts_faltas[j] = 0;
		}//for [12] materias	
	}//for [3] alunos
}
// FUNÇÕES QUE LOGA O SECRETÁRIO
void login_secretario(Secretario *secretarios, Aluno *alunos, char nomes_das_materias[13][30]){
	// DECLARAÇÃO DE VARIÁVEIS
	int i, z, contador_senha = 0, opcao_login = 0, total_de_func = 2, logado;
	char teste_login_func[10];
	char teste_senha_func[10];

	// MOSTRA AO USUÁRIO QUAIS SÃO OS SECRETÁRIOS CADASTRADOS NO SISTEMA
	printf("USUARIOS CADASTRADOS\n");
	for (i = 0; i < total_de_func; i++){
		printf("%d) %s\n", i, secretarios[i].login_func);
	}
	printf("ESCOLHA A OPCAO DO SEU USUARIO\n");
	scanf("%d", &opcao_login);
	// APÓS O USUÁRIO ESCOLHER QUAL SERÁ SEU LOGIN ELE DIGITA A SENHA DA CONTA
	printf("DIGITE SUA SENHA: \n");
	scanf("%s", &teste_senha_func);

	// LOOP QUE COMPARA A SENHA DIGITADA COM A SENHA CONTIDA NO STRUCT
	for (i = 0; i < 2; i++)
	{
		for (z = 0; z < 3; z++){
			// TESTE CONDICIONAL DE CARACTERE POR CARACTERE 
			if (teste_senha_func[z] == secretarios[opcao_login].senha_func[z])
			{
				contador_senha++;
			}
		}
	}

	// SE O CONTADOR FOR IGUAL A 6, SIGNIFICA QUE A SENHA ESTÁ CERTA E O PROGRAMA SEGUE PARA O MENU DO SECRETÁRIO
	if (contador_senha == 6)
	{
		funcoes_secretario(alunos, nomes_das_materias);
	}
	else{
		printf("FALHA NO LOGIN, DIGITE A SENHA CERTA\n");
	}
}

// FUNÇÃO QUE ENGLOBA AS FUNÇÕES QUE O USUÁRIO POSSUI
void funcoes_secretario(Aluno *alunos, char nomes_das_materias[13][30]){
	// DECLARAÇÃO DE VARIÁVEIS
	int opcao_func, continuar = 1;

	// LOOP QUE APRESENTA O MENU DE OPÇÕES DO SISTEMA PARA OS SECRETÁRIOS
	while(continuar != 0){
		system("cls");
		printf("O QUE DESEJA FAZER?\n");
		printf("1) INSERIR OU ATUALIZAR MEDIAS\n");
		printf("2) ATUALIZAR FALTAS\n");
		printf("3) VIZUALIZAR DADOS DO ALUNO \n");
		scanf("%d", &opcao_func);

		switch(opcao_func){
			case 1:
				inserir_atualizar_media(alunos, nomes_das_materias);
			break;

			case 2:
				atualizar_faltas(alunos, nomes_das_materias);
			break;

			case 3:
				vizualizar_dados_alunos(alunos, nomes_das_materias);
			break;

		}	

		printf("VOCE DESEJA VOLTAR AO MENU? [0] NAO [1] SIM\n");
		printf("AO CLICAR EM NAO, VOCE SAIRA DO SEU USUARIO\n");
		scanf("%d", &continuar);
	}

}

// FUNÇÃO QUE AUXÍLIA O SECRETÁRIO A INSERIR OU ATUALIZAR AS MÉDIAS DO ALUNOS
void inserir_atualizar_media(Aluno *alunos, char nomes_das_materias[13][30]){
	// DECLARAÇÃO DE VARIÁVEIS
	int i, j, escolha_matricula, continuar = 1, escolha_materia = 0, continuar_inserindo_media = 1;

	system("cls");
	while(continuar != 0){
		continuar_inserindo_media = 1;
		// MOSTRA AO SECRETÁRIO QUAIS SÃO AS MATRÍCULAS CADASTRADAS NO SISTEMA
		printf("MATRICULAS\n");
		for(i = 0; i < 3; i++){
			// MOSTRA A MATRÍCULA DE CADA ALUNO
			printf("%d) %s \n",  i, alunos[i].matricula);
		}

		printf("QUAL DOS ALUNOS VOCE DESEJA INSERIR OU ATUALIZAR A MEDIA?\n");
		scanf("%d", &escolha_matricula);

		while(continuar_inserindo_media != 0){
			system("cls");
			for (i = 0; i < 13; i++){
			    // PRINTA A MATRIZ DE NOME DAS MATÉRIAS
			    printf("%d) %s", i, nomes_das_materias[i]);
			    printf("\n");

			}


			printf("QUAL DAS MATERIAS VOCE DESEJA INSERIR OU ATUALIZAR A MEDIA?\n");
			scanf("%d", &escolha_materia);

			printf("MEDIA:\n");
			scanf("%f", &alunos[escolha_matricula].media[escolha_materia]);
			

			system("cls");
			printf("EXECUTADO COM SUCESSO\n");
			
			for (i = 0; i < 13; i++){
			    // PRINTA A MATRIZ DE NOME DAS MATÉRIAS
			    printf("%d) %s", i, nomes_das_materias[i]);

			    // PRINTA O VETOR DE MÉDIAS DO ALUNO ESCOLHIDO
			    printf("%9.1f", alunos[escolha_matricula].media[i]);
			    
			    printf("\n");

			}


			printf("DESEJA INSERIR OU ATUALIZAR OUTRA MEDIA EM OUTRA DISCIPLINA DESSE MESMO ALUNO? [0] NAO [1] SIM\n");

			scanf("%d", &continuar_inserindo_media);
		}

		printf("DESEJA INSERIR OU ATUALIZAR A MEDIA DE OUTRO ALUNO? [0] NAO [1] SIM\n");
		scanf("%d", &continuar);
	}

}

// FUNÇÃO QUE AUXÍLIA O SECRETÁRIO A ATUALIZAR AS FALTAS DO ALUNOS
void atualizar_faltas(Aluno *alunos, char nomes_das_materias[13][30]){
	// DECLARAÇÃO DE VARIÁVEIS
	int i, j, escolha_matricula, continuar = 1, escolha_materia = 0, continuar_inserindo_faltas = 1;

	// LIMPA TELA
	system("cls");

	while(continuar != 0){
		continuar_inserindo_faltas = 1;
		// MOSTRA AO SECRETÁRIO QUAIS SÃO AS MATRÍCULAS CADASTRADAS NO SISTEMA
		printf("MATRICULAS\n");
		for(i = 0; i < 3; i++){
			// MOSTRA A MATRÍCULA DE CADA ALUNO
			printf("%d) %s \n",  i, alunos[i].matricula);
		}

		printf("QUAL DOS ALUNOS VOCE DESEJA ATUALIZAR AS FALTAS?\n");
		scanf("%d", &escolha_matricula);

		while(continuar_inserindo_faltas != 0){
			system("cls");
			for (i = 0; i < 13; i++){
			    // PRINTA A MATRIZ DE NOME DAS MATÉRIAS
			    printf("%d) %s", i, nomes_das_materias[i]);
 
			    printf("\n");

			}

			printf("QUAL DAS MATERIAS VOCE DESEJA ATUALIZAR AS FALTAS?\n");
			scanf("%d", &escolha_materia);

			printf("QUANTIDADE DE FALTAS [EM HORAS]:\n");
			scanf("%d", &alunos[escolha_matricula].qts_faltas[escolha_materia]);
			

			system("cls");
			printf("EXECUTADO COM SUCESSO\n");
			
			for (i = 0; i < 13; i++){
			    // PRINTA A MATRIZ DE NOME DAS MATÉRIAS
			    printf("%d) %s", i, nomes_das_materias[i]);
			  	// PRINTA O VETOR DE QUANTIDADE DE FALTAS DO ALUNO ESCOLHIDO
			    printf("%d", alunos[escolha_matricula].qts_faltas[i]);			    			    
			    printf("\n");

			}

			printf("DESEJA ATUALIZAR AS FALTAS EM OUTRA DISCIPLINA DESSE MESMO ALUNO? [0] NAO [1] SIM\n");
			scanf("%d", &continuar_inserindo_faltas);
		}

		printf("DESEJA ATUALIZAR AS FALTAS DE OUTRO ALUNO? [0] NAO [1] SIM\n");
		scanf("%d", &continuar);
	}

}

// FUNÇÃO QUE AUXÍLIA O SECRETÁRIO A VIZUALIZAR OS DADOS DOS ALUNOS
void vizualizar_dados_alunos(Aluno *alunos, char nomes_das_materias[13][30]){
	// DECLARAÇÃO DE VARIÁVEIS
	int i, j;

	printf("ALUNOS CADASTRADOS\n");
	for (i = 0; i < 3; i++){
		printf("=================================================== \n");
		printf("NOME                : %s \n",  alunos[i].nome);

	    printf("MATRICULA           : %s \n",  alunos[i].matricula);

	    printf("LOGIN               : %s \n",  alunos[i].login_aluno);

	    printf("SENHA               : %s \n",  alunos[i].senha_aluno);
		printf("=================================================== \n");
		printf("                                      FALTAS\n");
	    for (j = 0; j < 13; j++){
	    	// PRINTA A MATRIZ DE NOME DAS MATÉRIAS
		    printf("%d) %s", j, nomes_das_materias[j]);
		    // PRINTA A MÉDIA NA MATÉRIA E A QUANTIDADE DE FALTAS LOGO AO LADO
		    printf("%9.1f    %d", alunos[i].media[j], alunos[i].qts_faltas[j]);
		    	    
		    printf("\n");

		}
	    printf("=================================================== \n");
	}

}

// FUNÇÃO QUE LOGA O ALUNO
void login_aluno(Aluno *alunos, char nomes_das_materias[13][30]){
	// DECLARAÇÃO DE VARIÁVEIS
	int i, z, j, contador_senha = 0, opcao_login = 0, total_de_alunos = 3;
	char teste_login_aluno[10];
	char teste_senha_aluno[10];

	// MOSTRA AO USUÁRIO QUAIS SÃO OS ALUNOS CADASTRADOS NO SISTEMA
	printf("USUARIOS CADASTRADOS\n");
	for (i = 0; i < total_de_alunos; i++){
		printf("%d) %s\n", i, alunos[i].login_aluno);
	}
	printf("ESCOLHA A OPCAO DO SEU USUARIO\n");
	scanf("%d", &opcao_login);
	// APÓS O USUÁRIO ESCOLHER QUAL SERÁ SEU LOGIN ELE DIGITA A SENHA DA CONTA
	printf("DIGITE SUA SENHA: \n");
	scanf("%s", &teste_senha_aluno);

	// LOOP QUE COMPARA A SENHA DIGITADA COM A SENHA CONTIDA NO STRUCT
	for (i = 0; i < 3; i++)
	{
		for (z = 0; z < 3; z++){
			// TESTE CONDICIONAL DE CARACTERE POR CARACTERE 
			if (teste_senha_aluno[z] == alunos[opcao_login].senha_aluno[z])
			{
				contador_senha++;
			}
		}

	}

	// SE O CONTADOR FOR IGUAL A 9, SIGNIFICA QUE A SENHA ESTÁ CERTA E O PROGRAMA SEGUE PARA O MENU DO ALUNO
	if (contador_senha == 9)
	{
		system("cls");
		funcoes_aluno(alunos, nomes_das_materias, opcao_login);
	}
	else{
		printf("FALHA NO LOGIN, DIGITE A SENHA CERTA\n");
	}

}

// FUNÇÃO ONDE AS OPÇÕES DO ALUNO SÃO APRESENTADAS
void funcoes_aluno(Aluno *alunos, char nomes_das_materias[13][30], int indice_aluno_logado){
	// DECLARAÇÃO DE VARIÁVEIS
	int opcao_menu_aluno, j, i, indice_disciplina, continuar = 1;

	// LOOP QUE APRESENTA O MENU DE OPÇÕES DO SISTEMA PARA OS ALUNOS
	while(continuar != 0){
		system("cls");
		printf("VOCE DESEJA\n");
		printf("1) VIZUALIZAR SEUS DADOS\n");
		printf("2) VIZUALIZAR MEDIAS E FALTAS DE TODAS AS DISCIPLINAS\n");
		printf("3) VIZUALIZAR MEDIAS E FALTAS DE UMA DISCIPLINA ESPECIFICA\n");
		scanf("%d", &opcao_menu_aluno);

		switch(opcao_menu_aluno){
			case 1:
				printf("=================================================== \n");
				printf("NOME                : %s \n",  alunos[indice_aluno_logado].nome);

			    printf("MATRICULA           : %s \n",  alunos[indice_aluno_logado].matricula);

			    printf("LOGIN               : %s \n",  alunos[indice_aluno_logado].login_aluno);

			    printf("SENHA               : %s \n",  alunos[indice_aluno_logado].senha_aluno);
				printf("=================================================== \n");

			break;

			case 2:
				printf("=================================================== \n");
				printf("                                      FALTAS\n");
				for (j = 0; j < 13; j++){
				    // PRINTA A MATRIZ DE NOME DAS MATÉRIAS
				    printf("%d) %s", j, nomes_das_materias[j]);
				    // PRINTA A MÉDIA NA MATÉRIA E A QUANTIDADE DE FALTAS LOGO AO LADO
				    printf("%9.1f    %d", alunos[indice_aluno_logado].media[j], alunos[indice_aluno_logado].qts_faltas[j]);				 
				    printf("\n");

				    // SE O ALUNO TIRAR NA MÉDIA 7,0 PONTOS E NÃO FALTAR MAIS DE 75% DE AULAS ELE É APROVADO
				    // 75% EQUIVALE A 15 HORAS DE DISCIPLINA E AS FALTAS SÃO LANÇADAS EM HORAS NO SISTEMA
				    if(alunos[indice_aluno_logado].media[j] > 7 && alunos[indice_aluno_logado].qts_faltas[j] < 15){
				    	printf("STATUS: APROVADO\n");
				    	
					}
					else{
					    printf("STATUS: REPROVADO\n");
					} 

				    printf("\n");

				}
			    printf("=================================================== \n");
			break;

			case 3:
				system("cls");
				printf("=================================================== \n");
				for (j = 0; j < 13; j++){
				    // PRINTA A MATRIZ DE NOME DAS MATÉRIAS
				    printf("%d) %s", j, nomes_das_materias[j]);	
				    printf("\n");
				}

				printf("QUAL DISCIPLINA VOCE DESEJA VIZUALIZAR?\n");
				scanf("%d", &indice_disciplina);

				printf("                                   FALTAS\n");

				// PRINTA A MATÉRIA ESPECÍFICA
			    printf("%s", nomes_das_materias[indice_disciplina]);

			    // PRINTA A MÉDIA NA MATÉRIA E A QUANTIDADE DE FALTAS LOGO AO LADO
			    printf("%9.1f    %d", alunos[indice_aluno_logado].media[indice_disciplina], alunos[indice_aluno_logado].qts_faltas[indice_disciplina]);
			    
			    printf("\n");

			    // SE O ALUNO TIRAR NA MÉDIA 7,0 PONTOS E NÃO FALTAR MAIS DE 75% DE AULAS ELE É APROVADO
				// 75% EQUIVALE A 15 HORAS DE DISCIPLINA E AS FALTAS SÃO LANÇADAS EM HORAS NO SISTEMA
			    if(alunos[indice_aluno_logado].media[indice_disciplina] > 7 && alunos[indice_aluno_logado].qts_faltas[indice_disciplina] < 15){
				    printf("STATUS: APROVADO\n");
				    	
				}
				else{
				    printf("STATUS: REPROVADO\n");
				}    

			    printf("\n");

				
				printf("=================================================== \n");
			break;

		}
		printf("VOCE DESEJA VOLTAR AO MENU? [0] NAO [1] SIM\n");
		printf("AO CLICAR EM NAO, VOCE SAIRA DO SEU USUARIO\n");
		scanf("%d", &continuar);
	}

}

int main(){
	// DECLARAÇÃO DE VARIÁVEIS
	int i, escolha_menu, continuar = 1;
	char linha[100];
	char *result;

	// MATRIZ DAS DISCIPLINAS
	char nomes_das_materias[13][30] = {"LINGUA PORTUGUESA      :",
	                                   "MATEMATICA             :",
	                                   "BIOLOGIA               :",
	                                   "FISICA                 :",
	                                   "QUIMICA                :",
	                                   "FILOSOFIA              :",
	                                   "INGLES                 :",
	                                   "GEOGRAFIA              :",
	                                   "HISTORIA               :",
	                                   "SOCIOLOGIA             :",
	                                   "EDUCACAO FISICA        :",
	                                   "EDUCACAO ARTISTICA     :",
	                                   "LITERATURA             :"};


	// VARIÁVEIS DO TIPO STRUCT SECRETARIO E ALUNO
	Secretario secretarios[2];
	Aluno alunos[3];

	// PONTEIRO ENTRADA DOS FUNCIONÁRIOS
	FILE * entrada_func;
	// PONTEIRO ENTRADA DOS ESTUDANTES
	FILE * entrada_alun;

	// ABERTURA DO ARQUIVO
	entrada_func = fopen("sec.txt", "r");


	// TESTES DE ABERTURA DO ARQUIVO DE FUNCIONÁRIOS
	if (entrada_func == NULL){
		printf("Nao foi possivel ler o arquivo de entrada dos funcionarios\n");
	}

	// ESTA FUNÇÃO SERVE PARA ZERAR OS VETORES QUE ARMAZENAM AS FALTAS E AS MEDIAS DA ESTRUTURA DE ALUNO
	// POIS QUANDO ELAS SÃO INICIADAS PEGAM O LIXO DA MEMÓRIA E MOSTRAM OUTROS VALORES
	limpaLixoMemoria(alunos);

	//CICLO QUE PREENCHE A ESTRUTURA DE SECRETARIOS
	while (!feof(entrada_func)){
        // LÊ UMA LINHA (INCLUSIVE COM O '\N') O FGETS
        if (result){ // SE FOI POSSÍVEL LER EXECUTA O PREENCHIMENTO
            for(i = 0; i < 2; i++){

                result = fgets(linha, 100, entrada_func);
                sprintf(secretarios[i].codigo, "%s", result);

                result = fgets(linha, 100, entrada_func);
                sprintf(secretarios[i].login_func, "%s", result);

                result = fgets(linha, 100, entrada_func);
                sprintf(secretarios[i].senha_func, "%s", result);
            }
        }
    }

	fclose(entrada_func);
	// FECHAMENTO DO ARQUIVO

	// ABERTURA DO ARQUIVO
	entrada_alun = fopen("est.txt", "r");

	if(entrada_alun == NULL){
		printf("Não foi possivel ler o arquivo de entrada dos alunos\n");
	}

	//CICLO QUE PREENCHE A ESTRUTURA DE ALUNOS
	while (!feof(entrada_alun)){
	    // LÊ UMA LINHA (INCLUSIVE COM O '\N') O FGETS
	    if (result){  // SE FOI POSSÍVEL LER EXECUTA O PREENCHIMENTO
	        for(i = 0; i < 3; i++){
	            result = fgets(linha, 100, entrada_alun);
	            sprintf(alunos[i].nome, "%s", result);

	            result = fgets(linha, 100, entrada_alun);
	            sprintf(alunos[i].matricula, "%s", result);

	            result = fgets(linha, 100, entrada_alun);
	            sprintf(alunos[i].login_aluno, "%s", result);

	            result = fgets(linha, 100, entrada_alun);
	            sprintf(alunos[i].senha_aluno, "%s", result);
	        }
    	}
    }

	fclose(entrada_alun);
	// FECHAMENTO DO ARQUIVO

	// CICLO QUE APRESENTA O MENU AO USUÁRIO
	while (continuar != 0){
		system("cls");
		printf("=================================================\n");
		printf("SEJA BEM VINDO AO PORTAL DO ALUNO!\n");
		printf("VOCE EH:\n");
		printf("1) SECRETARIO\n");
		printf("2) ALUNO \n");
		printf("=================================================\n");
		scanf("%d", &escolha_menu);
		system("cls");
		switch(escolha_menu){
			case 1:
				// APÓS ESCOLHER ENTRAR COMO SECRETÁRIO A FUNÇÃO DE LOGIN É CHAMADA
				login_secretario(secretarios, alunos, nomes_das_materias);
			break;

			case 2:
				// APÓS ESCOLHER ENTRAR COMO ALUNO A FUNÇÃO DE LOGIN É CHAMADA
				login_aluno(alunos, nomes_das_materias);
			break;

			default:
				// QUALQUER OUTRO VALOR DIGITADO RESULTA NO FECHAMENTO DO PROGRAMA
				printf("FIM DO PROGRAMA!\n");
				return 0;
			break;

		}

		printf("DESEJA CONTINUAR O PROGRAMA? [0] NAO [1] SIM\n");
		scanf("%d", &continuar);
	}


	return 0;

}
