#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =========================
// ==== CLASSES E ENUNS ====
// =========================

enum textos_ascii_art{
    txtInicio = 1,
    txtErro = 2,
    txtCadastro = 3,
    txtSucesso = 4,
    txtLogin = 5,
    txtTelaInicial = 6,
    txtMeusDados = 7,
    txtObrigado = 8,
    txtCadastroPaciente = 9,
    txtRelatorios = 10,
    txtAgendamento = 11,
    txtReclamacao = 12,
    txtResultado = 13,
    txtConsultaPacientes = 14,
    txtCadastroMedico = 15,
    txtListaMedico = 16
} textos;

enum caminhos_unidades{
    Unidade1 = 1,
    Unidade2 = 2,
    Unidade3 = 3
} unidades;

typedef struct {  
    char id[255];
    char nome[255];
    char cpf[14];
    char ddd[2];
    char celular[10];
    char endereco[255];
    char rg[12];
    char cargo[255];
    char nascimento[10];
    char salario[255];
    char credencial[255];
    char status[255];
    char unidade[255];
    char senha[255];
} TFuncionario;

typedef struct {  
    char id[255];
    char nome[255];
    char cpf[14];
    char ddd[2];
    char celular[10];
    char endereco[255];
    char rg[12];    
    char nascimento[10];    
    char status[255];
    char unidade[255];    
    char plano[255];
    char email[255];
} TPaciente;

typedef struct {  
    char id[255];
    char nome[255];
    char cpf[14];
    char ddd[2];
    char celular[10];
    char endereco[255];
    char rg[12];    
    char nascimento[10];    
    char status[255];
    char unidade[255];    
    char credencial[255];
    char horarioAtendimento[255];
    char especialidade[255];
} TMedico;

typedef struct {  
    char IdPaciente[255];
    char IdFuncionario[255];
    char IdMedido[255];
    char IdAgendamento[255];
    char Unidade[255];
    char Data[255];
    char Instrucao[255];
    char CpfPaciente[255];
    char CpfMedico[255];
    char CpfFuncionario[255];
    char Status[255];
} TAgendamento;

typedef struct {      
    char Titulo[255];            
    char CpfPaciente[255];
    char Data[255];
    char Reclamacao[255];
    char Unidade[255];
} TReclamacao;


// ===========================
// ==== MÉTODOS E FUNÇÕES ====
// ===========================
int Login();
int Menu();
int Cadastrar();
void MeusDados();
void ExibiTextos(int typeTexto);
void LerArquivo(char nomeArquivo[200]);
void TelaInicial();

// =============================
// ==== VERIAVEIS ESTATICAS ====
// =============================
static TFuncionario Funcionario;

// ==========================
// ==== INICIO DO CÓDIGO ====
// ==========================
int main(){
    int finish = 0;
    do
    {        
        system("cls");     
        system("color 7");
        
        finish = Menu();

        printf("\n");        
        system("pause");
        system("cls");        
    } while (finish <= 0);    
}

int Menu(){       
    int finish = 0;
    int result = 0;
    do
    {         
        system("cls");
        ExibiTextos(txtInicio);

        int opcao;
        printf("\n-----------------------------------------------------------------------------------------");
        printf("\n-                                                                                       -");
        printf("\n-           1 - Login                                                                   -");
        printf("\n-           2 - Cadastro de Funcionario                                                 -");
        printf("\n-           3 - Finalizar Programa                                                      -");
        printf("\n-                                                                                       -");
        printf("\n-----------------------------------------------------------------------------------------");
        
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
               result = Login();            

                if (result == 1)            
                    TelaInicial();
                
                break;

            case 2:     
                Cadastrar();                            
                break;

            case 3:
                Logout();                
                finish = 1;
                break;

            default:
                system("cls");
                system("color 4");
                ExibiTextos(txtErro);                
                printf("\n\nOpcao Invalida!\n\n");
                system("pause");
                system("color 7");
                break;
        }
             
    } while (finish <= 0);

    return finish;
}

void TelaInicial(){
    int finish = 0;

    do
    {
        system("cls");
        ExibiTextos(txtTelaInicial);    

        int opcao;
        printf("\n-----------------------------------------------------------------------------------------");
        printf("\n-                                                                                       -");
        printf("\n-           1 - Meus Dados                                                              -");
        printf("\n-           2 - Cadastrar Paciente                                                      -");
        printf("\n-           3 - Cadastrar Medico                                                        -");
        printf("\n-           4 - Agendar uma Consulta                                                    -");
        printf("\n-           5 - Relatorios                                                              -");
        printf("\n-           6 - Cadastrar uma Reclamacao                                                -");        
        printf("\n-           7 - Sair                                                                    -");
        printf("\n-                                                                                       -");
        printf("\n-----------------------------------------------------------------------------------------");       

        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                MeusDados();
                break;
            case 2:
                CadastrarPaciente();
                break;
            case 3:
                CadastrarMedico();
                break;
            case 4:
                AgendarConsultas();
                break;
            case 5:
                Relatorios();
                break;
            case 6:
                Reclamacoes();
                break;
           
            case 7:            
                Logout();
                finish = 1;
                break;
            default:
                system("color 4");
                ExibiTextos(txtErro);
                printf('\n\nOpção Invalida!\n');
                system("color 7");
                system("pause");
                finish = 0;
                break;
        }        
        
    } while (finish <= 0);   
}

void MeusDados(){
    system("cls");
    printf("\n\n");

    ExibiTextos(txtMeusDados);

    char nomeArquivo[200] = "db/funcionarios/";
    strcat(nomeArquivo, Funcionario.cpf);
    strcat(nomeArquivo, ".txt");

    printf("\n\n");
    LerArquivo(nomeArquivo);
    
    printf("\n\n");
    system("pause");
}

int Cadastrar(){
    system("cls");
    ExibiTextos(txtCadastro);    

    TFuncionario funcionario;
        
    //Nome
    printf("\n\nDigite seu Nome: ");
    gets(funcionario.nome);
    scanf("%[^\n]s", &funcionario.nome);
    setbuf(stdin, NULL);    

    //Senha
    printf("\n\nDigite sua Senha: ");    
    scanf("%s", &funcionario.senha);    

    //CPF
    printf("\nDigite seu CPF: ");
    scanf("%s", &funcionario.cpf);    

    //Cria o Ponteiro
    FILE *arquivo;     
    
    char nomeArquivo[200] = "db/funcionarios/";
    strcat(nomeArquivo, funcionario.cpf);
    strcat(nomeArquivo, ".txt");

    arquivo = fopen(nomeArquivo, "w");
        
    if(arquivo == NULL)
    {
        system("color 4");                
        ExibiTextos(txtErro);
        printf("\nOcorreu um erro!");
        system("color 7");  
        return 1;
    }

    //Unidade
    printf("\nDigite a sua Unidade: ");
    scanf("%s", &funcionario.unidade);

    //DDD
    printf("\nDigite o DDD do seu Celular: ");
    scanf("%s", &funcionario.ddd);

    //Celular
    printf("\nDigite seu Celular: ");
    scanf("%s", &funcionario.celular);

    //RG
    printf("\nDigite seu RG: ");
    scanf("%s", &funcionario.rg);

    //Cargo
    printf("\nDigite seu Cargo: ");
    scanf("%s", &funcionario.cargo);

    //Endereço
    printf("\nDigite seu Endereco completo: ");
    gets(funcionario.endereco);
    scanf("%[^\n]s", &funcionario.endereco);
    
    //Nascimento
    printf("\nDigite sua data de nascimento: ");
    scanf("%s", &funcionario.nascimento);

    //Salario
    printf("\nDigite seu salario: ");
    scanf("%s", &funcionario.salario);

    //Status
    strcpy(funcionario.status, "ativo");

    //ID
    strcpy(funcionario.id, GerarId());

    //Escreve no txt
    fprintf(arquivo, "%s: <= Id ", funcionario.id);
    fprintf(arquivo, "\n%s: <= Nome ", funcionario.nome);
    fprintf(arquivo, "\n%s: <= Senha ", funcionario.senha);
    fprintf(arquivo, "\n%s: <= CPF", funcionario.cpf);
    fprintf(arquivo, "\n%s: <= Unidade", funcionario.unidade);
    fprintf(arquivo, "\n%s: <= DDD", funcionario.ddd);
    fprintf(arquivo, "\n%s: <= Celucar", funcionario.celular);
    fprintf(arquivo, "\n%s: <= RG", funcionario.rg);
    fprintf(arquivo, "\n%s: <= Cargo", funcionario.cargo);
    fprintf(arquivo, "\n%s: <= Endereco", funcionario.endereco);
    fprintf(arquivo, "\n%s: <= Nascimento", funcionario.nascimento);
    fprintf(arquivo, "\n%s: <= Salario", funcionario.salario);
    fprintf(arquivo, "\n%s: <= Status", funcionario.status);

    //Salva    
    fclose(arquivo);
    
    system("cls");
    system("color 2");
    ExibiTextos(txtSucesso);    
    printf("\n\n");        
    system("pause");
    system("color 7");

    return 0;
}

int CadastrarPaciente(){
    system("cls");
    ExibiTextos(txtCadastroPaciente);    

    TPaciente paciente;
        
    //Nome
    printf("\n\nDigite o Nome: ");
    gets(paciente.nome);
    scanf("%[^\n]s", &paciente.nome);
    setbuf(stdin, NULL);         

    //CPF
    printf("\nDigite o CPF: ");
    scanf("%s", &paciente.cpf);    

    //Cria o Ponteiro
    FILE *arquivo;     
    
    char nomeArquivo[200] = "db/pacientes/";
    strcat(nomeArquivo, paciente.cpf);
    strcat(nomeArquivo, ".txt");

    arquivo = fopen(nomeArquivo, "w");
        
    if(arquivo == NULL)
    {
        system("color 4");                
        ExibiTextos(txtErro);
        printf("\nOcorreu um erro!");
        system("color 7");  
        return 1;
    }

    //Email
    printf("\nDigite o Email: ");
    scanf("%s", &paciente.email);

    //Unidade
    printf("\nDigite a Unidade: ");
    scanf("%s", &paciente.unidade);

    //DDD
    printf("\nDigite o DDD do Celular: ");
    scanf("%s", &paciente.ddd);

    //Celular
    printf("\nDigite o Celular: ");
    scanf("%s", &paciente.celular);

    //RG
    printf("\nDigite o RG: ");
    scanf("%s", &paciente.rg);  

    //Endereço
    printf("\nDigite o Endereco completo: ");
    gets(paciente.endereco);
    scanf("%[^\n]s", &paciente.endereco);
    
    //Nascimento
    printf("\nDigite a data de nascimento: ");
    scanf("%s", &paciente.nascimento);
    
    //Status
    strcpy(paciente.status, "ativo");

    //ID
    strcpy(paciente.id, GerarId());

    //Escreve no txt    
    fprintf(arquivo, "%s: <= Id ", paciente.id);
    fprintf(arquivo, "\n%s: <= Nome ", paciente.nome);    
    fprintf(arquivo, "\n%s: <= CPF", paciente.cpf);
    fprintf(arquivo, "\n%s: <= Email", paciente.email);
    fprintf(arquivo, "\n%s: <= Status", paciente.status);
    fprintf(arquivo, "\n%s: <= Unidade", paciente.unidade);
    fprintf(arquivo, "\n%s: <= DDD", paciente.ddd);
    fprintf(arquivo, "\n%s: <= Celucar", paciente.celular);
    fprintf(arquivo, "\n%s: <= RG", paciente.rg);    
    fprintf(arquivo, "\n%s: <= Endereco", paciente.endereco);
    fprintf(arquivo, "\n%s: <= Nascimento", paciente.nascimento);    

    //Salva    
    fclose(arquivo);

    //Abre Arquivo de CPFS
    char arquivoCpfs[255] = "db/pacientes/cpfsPacientes.txt";
    arquivo = fopen(arquivoCpfs, "a+");
        
    if(arquivo == NULL)
    {
        system("color 4");                
        ExibiTextos(txtErro);
        printf("\nOcorreu um erro!");
        system("color 7");  
        return 1;
    }

    fprintf(arquivo, "\n%s", paciente.cpf);

    //Salva    
    fclose(arquivo);

    system("cls");
    system("color 2");
    ExibiTextos(txtSucesso);    
    printf("\n");
    system("pause");
    system("color 7");

    return 0;
}

int Login(){
    int finish = 0;

    do
    {        
        system("cls");
        ExibiTextos(txtLogin);    

        int opcao;
        printf("\n-----------------------------------------------------------------------------------------");
        printf("\n-                                                                                       -");
        printf("\n-           1 - Continuar Login                                                         -");
        printf("\n-           2 - Voltar                                                                  -");        
        printf("\n-                                                                                       -");
        printf("\n-----------------------------------------------------------------------------------------");
        
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        TFuncionario funcionario;

        switch (opcao)
        {
            case 1:
                
                printf("\n\nDigite o seu CPF: ");        
                scanf("%s", &funcionario.cpf);

                printf("\nDigite a sua Senha: ");    
                scanf("%s", &funcionario.senha);

                printf("\nDigite a sua Unidade: ");    
                scanf("%s", &funcionario.unidade);

                //Cria o Ponteiro
                FILE *arquivo;     
                
                char nomeArquivo[200] = "db/funcionarios/";
                strcat(nomeArquivo, funcionario.cpf);
                strcat(nomeArquivo, ".txt");
                
                arquivo = fopen(nomeArquivo, "rt");    
                
                if(arquivo == NULL)
                {
                    system("cls");
                    system("color 4");                
                    ExibiTextos(txtErro);
                    printf("\nLogin Invalido!\n\n");
                    system("pause");
                    system("color 7");   
                    fclose(arquivo);                          
                }
                else
                {            
                    fclose(arquivo);   
                    MapFuncionario(nomeArquivo);   

                    if (strcmp(funcionario.cpf, Funcionario.cpf) == 0 && strcmp(funcionario.senha, Funcionario.senha) == 0 && strcmp(funcionario.unidade, Funcionario.unidade) == 0)
                    {
                        system("cls");  
                        system("color 2");  
                        ExibiTextos(txtSucesso);
                        printf("\n\n");                
                        system("color 7");  

                        finish = 1;
                    }
                    else
                    {
                        system("color 4");    
                        system("cls");
                        ExibiTextos(txtErro);
                        printf("\n === Login Invalido! === \n\n\n");
                        system("pause");
                        system("color 7");              
                    }                         
                }
                break;

            case 2:                 
                finish = 2;
                break;    

            default:
                system("cls");
                system("color 4");
                ExibiTextos(txtErro);
                printf("\n\n=== Opcao Invalida! ===\n\n");
                system("pause");   
                system("color 7");
                finish = 0;             
                break;                
        }
                             
    } while (finish == 0);
        
    return finish;
}

void MapFuncionario(FILE *arquivo){    
    arquivo = fopen(arquivo, "rt");    

    for (int i = 1; !feof(arquivo); i++)
    {
        char linha[100];
        char *result = fgets(linha, 100, arquivo);       
        strtok(linha,":");

        if (result){            
            if (i == 1) strcpy(Funcionario.id, linha);                
            else if (i == 2) strcpy(Funcionario.nome, linha);                
            else if (i == 3) strcpy(Funcionario.senha, linha);                
            else if (i == 4) strcpy(Funcionario.cpf, linha);                
            else if (i == 5) strcpy(Funcionario.unidade, linha);   
            else if (i == 6) strcpy(Funcionario.ddd, linha);                
            else if (i == 7) strcpy(Funcionario.celular, linha);                
            else if (i == 8) strcpy(Funcionario.rg, linha);                
            else if (i == 9) strcpy(Funcionario.cargo, linha);                
            else if (i == 10) strcpy(Funcionario.endereco, linha);                
            else if (i == 11) strcpy(Funcionario.nascimento, linha);                
            else if (i == 12) strcpy(Funcionario.salario, linha);                                                                                       
            else if (i == 13) strcpy(Funcionario.status, linha);   
        }                                               
    }
    fclose(arquivo);   
}

void ExibiTextos(int typeTexto){     
    switch (typeTexto)
    {
        case 1:            
            LerArquivo("views/inicio.txt");                    
            break;        
        case 2:            
            LerArquivo("views/erro.txt");                    
            break;

        case 3:            
            LerArquivo("views/cadastro.txt");                    
            break;
        case 4:            
            LerArquivo("views/sucesso.txt");                    
            break;
        case 5:            
            LerArquivo("views/login.txt");                    
            break;
        case 6:            
            LerArquivo("views/telaInicial.txt");                    
            break;         
        case 7:            
            LerArquivo("views/meusDados.txt");                    
            break;
        case 8:            
            LerArquivo("views/obrigado.txt");                    
            break;
        case 9:            
            LerArquivo("views/cadastroPaciente.txt");                   
            break;
        case 10:            
            LerArquivo("views/relatorios.txt");                    
            break;
        case 11:            
            LerArquivo("views/agendamento.txt");                    
            break;
        case 12:            
            LerArquivo("views/reclamacoes.txt");                    
            break;
        case 13:            
            LerArquivo("views/resultado.txt");                    
            break;
        case 14:            
            LerArquivo("views/consultaPacientes.txt"); 
            break;
        case 15:            
            LerArquivo("views/cadastroMedico.txt");  
            break;
        case 16:            
            LerArquivo("views/listaMedicos.txt");  
            break;
        default:
            break;
    }    
}

void LerArquivo(char nomeArquivo[200]){
    FILE *fileName;
    char Linha[100];
    char *result;

    char aquivoName[200] = "";
    bzero(aquivoName, 200); // limpa a variavel aquivoName     
    strcpy(aquivoName, nomeArquivo);           
    
    fileName = fopen(aquivoName, "rt");

    if (fileName == NULL) 
    {
        system("color 4");                
        printf("\n\n=========== Problemas na abertura do arquivo ===========\n\n");
        system("pause");
        system("color 7");                
        return;
    }

    int i = 1;    
    while (!feof(fileName))
    {        
        result = fgets(Linha, 100, fileName);
        if (result)  
             printf(Linha);
        i++;
    }
    fclose(fileName);    
}

void Logout(){
    system("cls");
    system("color 2");

    ExibiTextos(txtObrigado);

    printf("\n\n");        
}

int GerarId(){
    FILE *Ids = fopen("db/Ids.txt","w"); 
    char linha[100];
    
    int i = 1;
    int newId = 0;
    while(!feof(Ids)){                                                                                              
        if (i == 2)
        {            
            fprintf(Ids, "%d", newId);                                                    
            FILE *noIds = fopen("db/noIds.txt","w");
            fprintf(noIds, "%d", newId);                                                    
            fclose(noIds);
            break;
        }
        else
        {
            FILE *noIds = fopen("db/noIds.txt","a+");
            fgets(linha, 100, noIds);
            fclose(noIds);

            int ultimoId = strtol(linha, NULL, 10); 

            newId = ultimoId + 1;            
        }

        i++;        
    }
    fclose(Ids);

    return linha;
}

int Relatorios(){
    int finish = 0;

    do
    {
        system("cls");
        ExibiTextos(txtRelatorios);    

        int opcao;
        printf("\n-----------------------------------------------------------------------------------------");
        printf("\n-                                                                                       -");
        printf("\n-           1 - Quantidade de Pacientes Cadastrados                                     -");        
        printf("\n-           2 - Reclamacoes                                                             -");
        printf("\n-           3 - Unidade Mais Atendida                                                   -");        
        printf("\n-           4 - Lista de Medicos                                                        -");
        printf("\n-           5 - Consultar Pacientes                                                     -");
        printf("\n-           6 - Voltar                                                                  -");        
        printf("\n-                                                                                       -");
        printf("\n-----------------------------------------------------------------------------------------");       

        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                system("cls");
                system("color 6");
                ExibiTextos(txtResultado);

                int qtdPacientes = 0;
                                
                FILE* arquivo = fopen("db/pacientes/cpfsPacientes.txt", "rt");
                
                if(arquivo == NULL)
                {
                    system("color 4");   
                    system("cls");
                    ExibiTextos(txtErro);
                    printf("\nErro ao gerar Relatorio!\n");
                    system("pause");
                    system("color 7");  
                    finish = 0;
                    break;
                }


                for (int i = 1; !feof(arquivo); i++)
                {
                    char linha[100];
                    char *result = fgets(linha, 100, arquivo);                           

                    if (result && i > 1){                                    
                        qtdPacientes++;
                    }                                               
                }

                printf("\n\n\nQuantidade de Pacientes Cadastrados: %i\n\n", qtdPacientes);
                fclose(arquivo);   
                system("pause");    
                system("color 7");              
                break;

            case 2:
                system("cls");
                system("color 6");
                ExibiTextos(txtResultado);

                char *cpfPacienteReclacao;
                printf("\n\nDigite o CPF de um Pacinte ou Digite '0' para cancelar: ");
                scanf("%s", &cpfPacienteReclacao);

                if (strcmp(cpfPacienteReclacao, "0") == 0)
                {
                    system("color 7");
                    finish = 0;
                    break;    
                }
                else
                {
                    char arquivoPaciente[255] = "db/pacientes/reclamacoes/";
                    strcat(arquivoPaciente, cpfPacienteReclacao);
                    strcat(arquivoPaciente, ".txt");            

                    FILE* arqReclamacao = fopen(arquivoPaciente, "rt");
                
                    if(arqReclamacao == NULL)
                    {
                        system("color 4");   
                        system("cls");
                        ExibiTextos(txtErro);
                        printf("\nNENHUMA RECLAMACAO REGISTRADA\n\n");
                        system("pause");
                        system("color 7");  
                        finish = 0;
                        break;
                    }                

                    printf("\n\n=== RECLAMACOES ===\n\n");
                    LerArquivo(arquivoPaciente);
                    printf("\n\n");
                    system("pause");    

                    fclose(arqReclamacao);  
                }
                
                break;

            case 3:
                system("cls");
                system("color 6");
                ExibiTextos(txtResultado);

                int qtdUni1 = 0, qtdUni2 = 0, qtdUni3 = 0;

                                
                FILE* arqListaAgendamento = fopen("db/pacientes/agendamentos/listaAgendamentos.txt", "rt");
                
                if(arqListaAgendamento == NULL)
                {
                    system("color 4");   
                    system("cls");
                    ExibiTextos(txtErro);
                    printf("\nErro ao gerar Relatorio!\n");
                    system("pause");
                    system("color 7");  
                    finish = 0;
                    break;
                }


                for (int i = 1; !feof(arqListaAgendamento); i++)
                {
                    char linha[100];
                    char *result = fgets(linha, 100, arqListaAgendamento);                           

                    if (result && i > 1){                                    
                                                
                        if (strcmp(linha, "1\n") == 0 || strcmp(linha, "1") == 0) 
                        {
                            qtdUni1++;
                        }
                        else if (strcmp(linha, "2\n") == 0 || strcmp(linha, "2") == 0)
                        {
                            qtdUni2++;
                        }
                        else if (strcmp(linha, "3\n") == 0 || strcmp(linha, "3") == 0)
                        {
                            qtdUni3++;
                        }                        
                    }                                               
                }

                printf("\n\n-----------------------------------------------------------------------------------------");
                printf("\n-                      RESULTADO DAS UNIDADES MAIS ATENDIDAS                            -");                                                
                printf("\n-                                                                                       -");
                printf("\n-           Unidade 1 = %d                                                              -", qtdUni1);      
                printf("\n-           Unidade 2 = %d                                                              -", qtdUni2);      
                printf("\n-           Unidade 3 = %d                                                              -", qtdUni3);      
                printf("\n-                                                                                       -");
                printf("\n-----------------------------------------------------------------------------------------\n\n");   

                fclose(arqListaAgendamento); 

                system("pause");
                system("color 7");
                break;                

            case 4:
                system("cls");
                system("color 6");
                ExibiTextos(txtListaMedico);

                int qtdMedicos = 0;
                                
                FILE* arqMedicosCpfs = fopen("db/medicos/cpfsMedicos.txt", "rt");
                
                if(arqMedicosCpfs == NULL)
                {
                    system("color 4");   
                    system("cls");
                    ExibiTextos(txtErro);
                    printf("\nErro ao gerar Relatorio!\n");
                    system("pause");
                    system("color 7");  
                    finish = 0;
                    break;
                }                

                for (int i = 1; !feof(arqMedicosCpfs); i++)
                {
                    char linha[100];
                    char *result = fgets(linha, 100, arqMedicosCpfs);                           

                    if (result && i > 1){                                    
                        printf("\n%i. %s", (i-1) , linha);
                        qtdMedicos++;
                    }                                               
                }

                fclose(arqMedicosCpfs);  

                printf("\n\nQuantidade de Medicos Cadastrdos: %i", qtdMedicos);
                
                char cpfSelecionado[255];
                printf("\n\nDigite o CPF de um Medico ou Digite '0' para cancelar: ");
                scanf("%s", &cpfSelecionado);

                if (strcmp(cpfSelecionado, "0") == 0)
                {
                    system("color 7");
                    break;    
                }
                else
                {
                    char arquivoMedico[255] = "db/medicos/";
                    strcat(arquivoMedico, cpfSelecionado);
                    strcat(arquivoMedico, ".txt");            

                    FILE* arqMedico = fopen(arquivoMedico, "rt");
                
                    if(arqMedico == NULL)
                    {
                        system("color 4");   
                        system("cls");
                        ExibiTextos(txtErro);
                        printf("\nMedico nao encontrado!\n\n");
                        system("pause");
                        system("color 7");  
                        finish = 0;
                        break;
                    }                

                    printf("\n\n=== DADOS DO MEDICO ===\n\n");
                    LerArquivo(arquivoMedico);
                    printf("\n\n");
                    system("pause");    

                    fclose(arqMedico);  
                }
                
                system("color 7");                              
                break;

            case 5:
                system("cls");                
                ExibiTextos(txtConsultaPacientes);

                char cpfPaciente[255];
                printf("\n\nInforme o CPF do Paciente que deseja consultar: ");
                scanf("%s", &cpfPaciente);
                                                
                system("cls");
                system("color 6");
                ExibiTextos(txtResultado);

                //Ler dados Pessoais
                printf("\n\n === DADOS PESSOAIS ===\n\n");                
                char dodosPacientes[255] = "db/pacientes/";                                
                strcat(dodosPacientes, cpfPaciente);
                strcat(dodosPacientes, ".txt");
                
                LerArquivo(dodosPacientes);                
                printf("\n\n");

                //Ler Agendamentos
                printf("\n\n=== AGENDAMENTOS ===\n\n");
                char agendamentos[255] = "db/pacientes/agendamentos/";                                
                strcat(agendamentos, cpfPaciente);
                strcat(agendamentos, ".txt");
       
                FILE* arqAgendamentos = fopen(agendamentos, "rt");

                if (arqAgendamentos == NULL)
                {
                    printf("PACIENTE NAO POSSUI AGENDAMENTOS");                    
                }
                else{
                    LerArquivo(agendamentos);                
                    printf("\n\n");                    
                    fclose(arqAgendamentos);   
                }
                
                //Ler Reclamações
                printf("\n\n=== RECLOMACOES ===\n\n");
                char reclamacoes[255] = "db/pacientes/reclamacoes/";                                
                strcat(reclamacoes, cpfPaciente);
                strcat(reclamacoes, ".txt");
       
                FILE* arqReclamacoes = fopen(reclamacoes, "rt");

                if (arqReclamacoes == NULL)
                {
                    printf("PACIENTE NAO POSSUI RECLAMACOES\n\n");                    
                }
                else{
                    LerArquivo(reclamacoes);                
                    printf("\n\n");                    
                    fclose(arqReclamacoes);   
                }
                                
                system("pause");    
                system("color 7");    
                break;

            case 6:                
                finish = 1;          
                break;    

            default:
                system("cls");
                system("color 4");
                ExibiTextos(txtErro);
                printf("\n\nOpção Invalida!\n");
                system("pause");
                system("color 7");
                finish = 0;
                break;
        }        
        
    } while (finish <= 0);      

    return 0;
}

int AgendarConsultas(){
    int finish = 0;

    do
    {
        system("cls");
        ExibiTextos(txtAgendamento);    

        TAgendamento agendamento;

        //Data
        printf("\n\nInforme a data do agendamento: ");    
        scanf("%s", &agendamento.Data);

        //Validar Data ---

        //Unidade
        printf("\n\nInforme a Unidade para o agendamento: ");        
        scanf("%s", &agendamento.Unidade);

        //Instrição
        printf("\n\nInforme o Motivo ou o que deve ser tratado na Consulta: ");
        gets(agendamento.Instrucao);
        scanf("%[^\n]s", &agendamento.Instrucao);

        //CPF Paciente
        printf("\n\nInforme o CPF do Paciente: ");
        gets(agendamento.CpfPaciente);
        scanf("%[^\n]s", &agendamento.CpfPaciente);

        //CPF Medico
        printf("\n\nInforme o CPF do Medico: ");
        gets(agendamento.CpfMedico);
        scanf("%[^\n]s", &agendamento.CpfMedico);        

        //CPF Funcionario        
        strcpy(agendamento.CpfFuncionario, Funcionario.cpf);         

        //Id Funcionario
        strcpy(agendamento.IdFuncionario, Funcionario.id); 

        //Id Agendamento
        strcpy(agendamento.IdAgendamento, GerarId());

        //Id Paciente
        strcpy(agendamento.IdPaciente, GerarId()); 

        //Id Medico ------
        strcpy(agendamento.IdMedido, "0"); 

        //Staus 
        strcpy(agendamento.Status, "aberto"); 

        //Cria o Ponteiro
        FILE *arquivo;     
        
        char nomeArquivo[200] = "db/pacientes/agendamentos/";
        strcat(nomeArquivo, agendamento.CpfPaciente);

        //strcat(nomeArquivo, agendamento.IdAgendamento);
        strcat(nomeArquivo, ".txt");

        arquivo = fopen(nomeArquivo, "a+");
            
        if(arquivo == NULL)
        {
            system("color 4");   
            system("cls");
            ExibiTextos(txtErro);
            printf("\nPaciente nao encontrado!\n");
            system("pause");
            system("color 7");  
            finish = 0;
            break;
        }

        //Pula para o fim do Arquivo
        fseek(arquivo, 0, SEEK_END);        

        //Escreve no txt           
        fprintf(arquivo, "\n\n%s: <= Data ", agendamento.Data);    
        fprintf(arquivo, "\n%s: <= Unidade", agendamento.Unidade);
        fprintf(arquivo, "\n%s: <= Instrucao", agendamento.Instrucao);
        fprintf(arquivo, "\n%s: <= CPF do Paciente", agendamento.CpfPaciente);
        fprintf(arquivo, "\n%s: <= CPF do Funcionario", agendamento.CpfFuncionario);
        fprintf(arquivo, "\n%s: <= CPF do Medico", agendamento.CpfMedico);
        fprintf(arquivo, "\n%s: <= Id Funcionario", agendamento.IdFuncionario);
        fprintf(arquivo, "\n%s: <= Id Paciente", agendamento.IdPaciente);    
        fprintf(arquivo, "\n%s: <= Id Medico", agendamento.IdMedido);
        fprintf(arquivo, "\n%s: <= Id Agendamento", agendamento.IdAgendamento);
        fprintf(arquivo, "\n%s: <= Status", agendamento.Status); 

        fclose(arquivo); 

        //Cria o Ponteiro
        FILE *arqUnidade;     
        
        char nomArq[200] = "db/pacientes/agendamentos/";
        strcat(nomArq, "listaAgendamentos");
        strcat(nomArq, ".txt");

        arqUnidade = fopen(nomArq, "a+");
            
        if(arqUnidade == NULL)
        {
            system("color 4");   
            system("cls");
            ExibiTextos(txtErro);
            printf("\nArquivo nao encontrado!\n");
            system("pause");
            system("color 7");  
            finish = 0;
            break;
        }

        fseek(arqUnidade, 0, SEEK_END);    

        fprintf(arqUnidade, "\n%s", agendamento.Unidade);

        fclose(arqUnidade); 


        system("cls");
        system("color 2");
        ExibiTextos(txtSucesso);    
        printf("\n");
        system("pause");
        system("color 7");
        finish = 1; 
    } while (finish <= 0);    

    return 0;    
}

int Reclamacoes(){
    int finish = 0;

    do
    {
        system("cls");
        ExibiTextos(txtReclamacao);    

        TReclamacao reclamacao;

        //Data
        printf("\n\nInforme a Data da Reclamacao: ");        
        scanf("%s", &reclamacao.Data);
        
        //Unidade
        printf("\nInforme a Unidade: ");        
        scanf("%s", &reclamacao.Unidade);   

        //CPF Paciente
        printf("\nInforme o CPF do Paciente: ");
        gets(reclamacao.CpfPaciente);
        scanf("%[^\n]s", &reclamacao.CpfPaciente);
        
        //Reclamacao
        printf("\nDigite a Reclamacao: ");
        gets(reclamacao.Reclamacao);
        scanf("%[^\n]s", &reclamacao.Reclamacao);

        //Cria o Ponteiro
        FILE *arquivo;     
        
        char nomeArquivo[200] = "db/pacientes/reclamacoes/";
        strcat(nomeArquivo, reclamacao.CpfPaciente);        
        strcat(nomeArquivo, ".txt");

        arquivo = fopen(nomeArquivo, "a+");
            
        if(arquivo == NULL)
        {
            system("color 4");                
            ExibiTextos(txtErro);
            system("cls");
            printf("\nOcorreu um erro!\n");
            printf("\n");
            system("pause");
            system("color 7");  
            finish = 0;
            break;
        }

        //Escreve no txt            
        fprintf(arquivo, "\n\n%s: <= Data ", reclamacao.Data);    
        fprintf(arquivo, "\n%s: <= Unidade", reclamacao.Unidade);        
        fprintf(arquivo, "\n%s: <= CPF do Paciente", reclamacao.CpfPaciente);
        fprintf(arquivo, "\n%s: <= Reclamacao", reclamacao.Reclamacao);

        fclose(arquivo); 

        system("cls");
        system("color 2");
        ExibiTextos(txtSucesso);    
        printf("\n");
        system("pause");
        system("color 7");
        finish = 1; 
    } while (finish <= 0);
    
    return 0;
}

int CadastrarMedico(){
    system("cls");
    ExibiTextos(txtCadastroMedico);    

    TMedico medico;
        
    //Nome
    printf("\n\nDigite o Nome: ");
    gets(medico.nome);
    scanf("%[^\n]s", &medico.nome);
    setbuf(stdin, NULL);         

    //CPF
    printf("\nDigite o CPF: ");
    scanf("%s", &medico.cpf);    

    //Cria o Ponteiro
    FILE *arquivo;     
    
    char nomeArquivo[200] = "db/medicos/";
    strcat(nomeArquivo, medico.cpf);
    strcat(nomeArquivo, ".txt");

    arquivo = fopen(nomeArquivo, "w");
        
    if(arquivo == NULL)
    {
        system("color 4");                
        ExibiTextos(txtErro);
        printf("\nOcorreu um erro!");
        system("color 7");  
        return 1;
    }

    //Unidade
    printf("\nDigite a Unidade: ");
    scanf("%s", &medico.unidade);

    //DDD
    printf("\nDigite o DDD do Celular: ");
    scanf("%s", &medico.ddd);

    //Celular
    printf("\nDigite o Celular: ");
    scanf("%s", &medico.celular);

    //RG
    printf("\nDigite o RG: ");
    scanf("%s", &medico.rg);  

    //Endereço
    printf("\nDigite o Endereco completo: ");
    gets(medico.endereco);
    scanf("%[^\n]s", &medico.endereco);
    
    //Nascimento
    printf("\nDigite a data de nascimento: ");
    scanf("%s", &medico.nascimento);
    
    //Status
    strcpy(medico.status, "ativo");

    //ID
    strcpy(medico.id, GerarId());

    //Escreve no txt    
    fprintf(arquivo, "%s: <= Id ", medico.id);
    fprintf(arquivo, "\n%s: <= Nome ", medico.nome);    
    fprintf(arquivo, "\n%s: <= CPF", medico.cpf);
    fprintf(arquivo, "\n%s: <= Status", medico.status);
    fprintf(arquivo, "\n%s: <= Unidade", medico.unidade);
    fprintf(arquivo, "\n%s: <= DDD", medico.ddd);
    fprintf(arquivo, "\n%s: <= Celucar", medico.celular);
    fprintf(arquivo, "\n%s: <= RG", medico.rg);    
    fprintf(arquivo, "\n%s: <= Endereco", medico.endereco);
    fprintf(arquivo, "\n%s: <= Nascimento", medico.nascimento);    

    //Salva    
    fclose(arquivo);

    //Abre Arquivo de CPFS
    char arquivoCpfs[255] = "db/medicos/cpfsMedicos.txt";
    arquivo = fopen(arquivoCpfs, "a+");
        
    if(arquivo == NULL)
    {
        system("color 4");                
        ExibiTextos(txtErro);
        printf("\nOcorreu um erro!");
        system("color 7");  
        return 1;
    }

    fprintf(arquivo, "\n%s: <= CPF - Nome => %s", medico.cpf, medico.nome);

    //Salva    
    fclose(arquivo);

    system("cls");
    system("color 2");
    ExibiTextos(txtSucesso);    
    printf("\n");
    system("pause");
    system("color 7");

    return 0;
}
