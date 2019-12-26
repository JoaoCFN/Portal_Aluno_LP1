#include <stdio.h>
#include <stdlib.h>

// ESTRUTURA ALUNOS
typedef struct {
	char nome[60];
	char matricula[10];
	char login_aluno[10];
	char senha_aluno[10];

	float media[3];
	int qts_faltas;



} Aluno;

// ESTRUTURA ALUNOS
typedef struct
{
	char codigo[10];
	char login_func[10];
	char senha_func[10];

} Secretario;


// FUNÇÕES QUE LOGA O SECRETÁRIO
void login_secretario(int n, Secretario *secretarios, int y, Aluno *alunos){
	int i, z, contador_senha = 0, opcao_login = 0, total_de_func = 2;

	char teste_login_func[10];
	char teste_senha_func[10];

	printf("USUARIOS CADASTRADOS\n");
	for (i = 0; i < total_de_func; i++){
		printf("%d) %s\n", i, secretarios[i].login_func);
	}
	

	printf("ESCOLHA A OPCAO DO SEU USUARIO\n");
	scanf("%d", &opcao_login);
	printf("DIGITE SUA SENHA: \n");
	scanf("%s", &teste_senha_func);

	for (i = 0; i < 2; i++)
	{
		for (z = 0; z < 3; z++){
			
			if (teste_senha_func[z] == secretarios[opcao_login].senha_func[z])
			{
				contador_senha++;
			}	
					
		}
		
	}

	if (contador_senha == 6)
	{
		funcoes_secretario(3, alunos);
	}
	else{
		printf("FALHA NO LOGIN, DIGITE A SENHA CERTA\n");
	}
}

// FUNÇÃO QUE ENGLOBA AS FUNÇÕES QUE O USUÁRIO POSSUI
void funcoes_secretario(int y, Aluno *alunos){
	system("cls");
	int opcao_func;
	printf("O QUE DESEJA FAZER?\n");
	printf("1) INSERIR MEDIAS\n");
	printf("2) ATUALIZAR MEDIAS \n");
	printf("3) VIZUALIZAR DADOS DO ALUNO \n");
	scanf("%d", &opcao_func);

	switch(opcao_func){
		case 1:
			inserir_media(3, alunos);
		break;

		case 2:

		break;

		case 3:
			vizualizar_dados_alunos(3, alunos);
		break;

	}


}

// FUNÇÃO QUE AUXÍLIA O SECRETÁRIO A INSERIR AS MÉDIAS DO ALUNOS
void inserir_media(int y, Aluno *alunos){
	int i, escolha_matricula, continuar = 1;
	Secretario medias[3];

	system("cls");
	while(continuar != 0){

		printf("MATRICULAS\n");
		for(i = 0; i < 3; i++){
			printf("%d) %s \n",  i, alunos[i].matricula);
		}
		printf("QUAL DOS ALUNOS VOCE DESEJA INSERIR A MEDIA?\n");
		scanf("%d", &escolha_matricula);

		printf("MEDIA:\n");
		scanf("%f", &alunos[escolha_matricula].media[escolha_matricula]);

		printf("MEDIAS ATUAIS\n");
		for(i = 0; i < 3; i++){
			printf("%s: %f \n", alunos[i].matricula, alunos[i].media[i]);
		}

		printf("DESEJA INSERIR OUTRA MEDIA? [0] NAO [1] SIM\n");	
		scanf("%d", &continuar);
	}
	if (continuar != 0){
		system("cls");
		int main();	
	}
	  
}

// FUNÇÃO QUE AUXÍLIA O SECRETÁRIO A VIZUALIZAR OS DADOS DOS ALUNOS
void vizualizar_dados_alunos(int y, Aluno *alunos){
	int i;
	printf("ALUNOS CADASTRADOS\n");
	for (i = 0; i < 3; i++){
		printf("NOME                : %s \n",  alunos[i].nome);

	    printf("MATRICULA           : %s \n",  alunos[i].matricula);

	    printf("LOGIN               : %s \n",  alunos[i].login_aluno);

	    printf("SENHA               : %s \n",  alunos[i].senha_aluno);
	    printf("MEDIA               : %f \n",  alunos[i].media[i]);
	    printf("=================================================== \n");
	}
	
}

// FUNÇÃO QUE LOGA O ALUNO
void login_aluno(int y, Aluno *alunos){
	int i, z, contador_senha = 0, opcao_login = 0, total_de_alunos = 3;

	char teste_login_aluno[10];
	char teste_senha_aluno[10];

	printf("USUARIOS CADASTRADOS\n");
	for (i = 0; i < total_de_alunos; i++){
		printf("%d) %s\n", i, alunos[i].login_aluno);
	}
	
	printf("ESCOLHA A OPCAO DO SEU USUARIO\n");
	scanf("%d", &opcao_login);
	printf("DIGITE SUA SENHA: \n");
	scanf("%s", &teste_senha_aluno);

	for (i = 0; i < 3; i++)
	{
		for (z = 0; z < 3; z++){
			
			if (teste_senha_aluno[z] == alunos[opcao_login].senha_aluno[z])
			{
				contador_senha++;
			}						
		}
		
	}

	if (contador_senha == 9)
	{
		system("cls");
		funcoes_aluno();
	}
	else{
		printf("FALHA NO LOGIN, DIGITE A SENHA CERTA\n");
	}
	
}

// FUNÇÕES DOS ALUNOS
funcoes_aluno(){
	printf("AAAAAAAAAAAAAAAAAAAAAAAAA\n");
}

int main(){
	// DECLARAÇÃO DE VARIÁVEIS
	int i, escolha_menu, continuar = 1;
	char linha[100];
	char *result;

	// VARIÁVEL TIPO STRUCT
	Secretario secretarios[2];
	Aluno alunos[3];

	// PONTEIRO ENTRADA DOS FUNCIONÁRIOS
	FILE * entrada_func;
	// PONTEIRO ENTRADA DOS ESTUDANTES
	FILE * entrada_alun;


	entrada_func = fopen("sec.txt", "r");


	// TESTES DE ABERTURA DO ARQUIVO DE FUNCIONÁRIOS
	if (entrada_func == NULL){
		printf("Nao foi possivel ler o arquivo de entrada dos funcionarios\n");
	}

	while (!feof(entrada_func)){
        // LÊ UMA linha (INCLUSIVE COM O '\N') O FGETS
        if (result){
            for(i = 0; i < 2; i++){

                result = fgets(linha, 100, entrada_func);
                sprintf(secretarios[i].codigo, "%s", result);
                printf("CODIGO                 : %s \n",  secretarios[i].codigo);

                result = fgets(linha, 100, entrada_func);
                sprintf(secretarios[i].login_func, "%s", result);
                printf("LOGIN                  : %s \n",  secretarios[i].login_func);

                result = fgets(linha, 100, entrada_func);
                sprintf(secretarios[i].senha_func, "%s", result);
                printf("SENHA                  : %s \n",  secretarios[i].senha_func);
            }
        }
    }

	fclose(entrada_func);

	entrada_alun = fopen("est.txt", "r");

	if(entrada_alun == NULL){
		printf("Não foi possivel ler o arquivo de entrada dos alunos\n");
	}
	printf("==================================================================\n");

	while (!feof(entrada_alun)){
	    // LÊ UMA linha (INCLUSIVE COM O '\N')O 'FGETS'
	    if (result){  // SE FOI POSSÍVEL LER VAI EXECUTAR
	        for(i = 0; i < 3; i++){
	            result = fgets(linha, 100, entrada_alun);
	            sprintf(alunos[i].nome, "%s", result);
	            printf("NOME                : %s \n",  alunos[i].nome);

	            result = fgets(linha, 100, entrada_alun);
	            sprintf(alunos[i].matricula, "%s", result);
	            printf("MATRICULA           : %s \n",  alunos[i].matricula);

	            result = fgets(linha, 100, entrada_alun);
	            sprintf(alunos[i].login_aluno, "%s", result);
	            printf("LOGIN               : %s \n",  alunos[i].login_aluno);

	            result = fgets(linha, 100, entrada_alun);
	            sprintf(alunos[i].senha_aluno, "%s", result);
	            printf("SENHA               : %s \n",  alunos[i].senha_aluno);
	        }
    	}
    }

	fclose(entrada_alun);

	system("cls");

	while (continuar != 0){

		printf("SEJA BEM VINDO!\n");
		printf("VOCE EH:\n");
		printf("1) SECRETARIO\n");
		printf("2) ALUNO \n");

		scanf("%d", &escolha_menu);
		system("cls");
		switch(escolha_menu){
			case 1:
				login_secretario(2, secretarios, 3, alunos);
			break;

			case 2:
				login_aluno(3, alunos);
			break;

			case 3:

			break;

		}

		printf("DESEJA CONTINUAR O PROGRAMA? [0] NAO [1] SIM\n");
		scanf("%d", &continuar);
	}





	return 0;

}
