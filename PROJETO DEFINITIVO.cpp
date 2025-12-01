#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <locale>
#ifdef _WIN32
#include <windows.h>
#endif
#ifdef _MSC_VER
#include <io.h>    // _setmode, _fileno
#include <fcntl.h> // _O_U8TEXT
#endif

using namespace std;

void acentuacao(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    // configura locale global
    std::locale::global(std::locale(""));

#ifdef _MSC_VER
    // Apenas MSVC: coloca stdout em modo UTF-8 wide text para wcout
    // _O_U8TEXT existe em MSVC; como o bloco só compila no MSVC, não quebra em MinGW.
    _setmode(_fileno(stdout), _O_U8TEXT);
    std::wcout.imbue(std::locale());
#endif

return;
}

struct Clube {
    int id;
    string nome;
    string pais;
    short anoFundacao;
    string descricao;
};

void ordenamento_crescente_id(Clube *registros, int tamanho_registros){
    int menor;
    Clube aux_troca;
    for (int i = 0; i < tamanho_registros-1; i++) {
   	    menor = i;
   	    for (int j = i + 1; j < tamanho_registros; j++) {
   		    if (registros[j].id < registros[menor].id){
   			    menor = j;
   		    }
   	    }
   	    aux_troca = registros[i];
   	    registros[i] = registros[menor];
   	    registros[menor] = aux_troca;
    }
}

void ordenamento_crescente_nome(Clube *registros, int tamanho_registros){
    int menor;
    Clube aux_troca;

    for (int i = 0; i < tamanho_registros - 1; i++) {
        menor = i;
        for (int j = i + 1; j < tamanho_registros; j++) {
            if (registros[j].nome < registros[menor].nome) { 
                menor = j;
            }
        }
        aux_troca = registros[i];
        registros[i] = registros[menor];
        registros[menor] = aux_troca;
    }     
}

void ordenamento_crescente_pais(Clube *registros, int tamanho_registros){
    int menor;
    Clube aux_troca;

    for (int i = 0; i < tamanho_registros - 1; i++) {
        menor = i;
        for (int j = i + 1; j < tamanho_registros; j++) {
            if (registros[j].pais < registros[menor].pais) { 
                menor = j;
            }
        }
        aux_troca = registros[i];
        registros[i] = registros[menor];
        registros[menor] = aux_troca;
    }     
}

void ordenamento_crescente_ano(Clube *registros, int tamanho_registros){
    int menor;
    Clube aux_troca;
    for (int i = 0; i < tamanho_registros-1; i++) {
   	    menor = i;
   	    for (int j = i + 1; j < tamanho_registros; j++) {
   		    if (registros[j].anoFundacao < registros[menor].anoFundacao){
   			    menor = j;
   		    }
   	    }
   	    aux_troca = registros[i];
   	    registros[i] = registros[menor];
   	    registros[menor] = aux_troca;
    }
}

void busca_binaria_id(Clube *registros, int inicio, int fim, int busca){
    if(inicio>fim){
        cout << "\nID não encontrado.\n";
        return;
    }

    int meio=(inicio+fim)/2;

    if(registros[meio].id==busca){
        cout << endl << endl;
        cout << registros[meio].id << ", "
             << registros[meio].nome << ", "
             << registros[meio].pais << ", "
             << registros[meio].anoFundacao << ", "
             << registros[meio].descricao;
    }
    else if(registros[meio].id>busca) return busca_binaria_id(registros,inicio,meio-1,busca);
    else return busca_binaria_id(registros,meio+1,fim,busca);
}

void busca_binaria_nome(Clube *registros, int inicio, int fim, string busca){
    if(inicio>fim){
        cout << "\nNome não encontrado.\n";
        return;
    }

    int meio=(inicio+fim)/2;

    if(registros[meio].nome==busca){
        cout << endl << endl;
        cout << registros[meio].id << ", "
             << registros[meio].nome << ", "
             << registros[meio].pais << ", "
             << registros[meio].anoFundacao << ", "
             << registros[meio].descricao;
    }
    else if(registros[meio].nome>busca) return busca_binaria_nome(registros,inicio,meio-1,busca);
    else return busca_binaria_nome(registros,meio+1,fim,busca);
}

void busca_binaria_pais(Clube *registros, int inicio, int fim, string busca){
    if(inicio>fim){
        cout << "\nPaís não encontrado.\n";
        return;
    }

    int meio=(inicio+fim)/2;

    if(registros[meio].pais==busca){
        cout << endl << endl;
        cout << registros[meio].id << ", "
             << registros[meio].nome << ", "
             << registros[meio].pais << ", "
             << registros[meio].anoFundacao << ", "
             << registros[meio].descricao;
    }
    else if(registros[meio].pais>busca) return busca_binaria_pais(registros,inicio,meio-1,busca);
    else return busca_binaria_pais(registros,meio+1,fim,busca);
}

void busca_binaria_ano(Clube *registros, int inicio, int fim, int busca){
    if(inicio>fim){
        cout << "\nAno não encontrado.\n";
        return;
    }

    int meio=(inicio+fim)/2;

    if(registros[meio].anoFundacao==busca){
        cout << endl << endl;
        cout << registros[meio].id << ", "
             << registros[meio].nome << ", "
             << registros[meio].pais << ", "
             << registros[meio].anoFundacao << ", "
             << registros[meio].descricao;
    }
    else if(registros[meio].anoFundacao>busca) return busca_binaria_ano(registros,inicio,meio-1,busca);
    else return busca_binaria_ano(registros,meio+1,fim,busca);
}

Clube *lerRegistros(ifstream &arquivo_csv, int tamanho_registros){
    
    char lixo;
    Clube *registros=new Clube[tamanho_registros];  // Criando um vetor dinâmico de registros

    // Lendo os registros, linha por linha
    for (int i = 0; i < tamanho_registros; i++) {
        arquivo_csv >> registros[i].id;                     // Pega o id;
        arquivo_csv >> lixo;                                // Pega a vírgula
        getline(arquivo_csv, registros[i].nome, ',');       // Pega o nome do clube
        //arquivo_csv >> lixo; Acho que não precisa pegar a vírgula, pq o getline ja pega  // Pega a vírgula
        getline(arquivo_csv, registros[i].pais, ',');       // Pega o país
        //arquivo_csv >> lixo; Mesma coisa do de cima       // Pega a vírgula
        arquivo_csv >> registros[i].anoFundacao;            // Pega o ano de fundação
        arquivo_csv >> lixo;                                // Pega a vírgula
        arquivo_csv >> lixo;                                // Pega a primeira aspas dupla
        getline(arquivo_csv, registros[i].descricao, '"');  // Pega a descrição
        arquivo_csv.ignore();                               // Pula para a próxima linha
    }
    return registros;
}

Clube *inserirElemento(Clube *registros, int tamanho_registros, int aumento){

    int new_tamanho_registros = tamanho_registros+aumento; // Novo tamanho do vetor(Clube/struct) de registros

    Clube *new_registros = new Clube[new_tamanho_registros]; // Vetor alocado dinamicamente

    for(int i=0; i<tamanho_registros; i++) new_registros[i]=registros[i]; // Passa tudo que tinha no vetor antigo pro novo

    cout << "                                  ================================================= " << endl
         << "                                 |                                                 |" << endl
         << "                                 |   Digite cada item do registro respeitando a    |" << endl
         << "                                 |  seguinte ordem: nome _ _ _ _ _ _ _(string)     |" << endl
         << "                                 |                  país _ _ _ _ _ _ _(string)     |" << endl
         << "                                 |                  ano de fundação_ _(inteiro)    |" << endl
         << "                                 |                  descrição_ _ _ _ _(string)     |" << endl 
         << "                                 |                                                 |" << endl
         << "                                 |  O registro será inserido no final do arquivo   |" << endl
         << "                                 | por exemplo, se o último era 100, esse será 101 |" << endl
         << "                                 |                                                 |" << endl
         << "                                  ================================================= " << endl;

    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Para ignorar qualquer quebra de linha anterior ou qualquer conteúdo indesejado

    for(int i=tamanho_registros; i<new_tamanho_registros; i++){ // "For" para ler/pegar os novos registros na entrada padrão
        new_registros[i].id = i + 1;                  // Adiciona o ID usando o número de registro anterior e aumentando de 1 em 1
        cout << "ID: "<< new_registros[i].id << endl; // Mostra o ID atual do registro
        cout << "Nome: ";                             
        getline(cin, new_registros[i].nome);          // Pega o nome
        cout << "País: ";                             
        getline(cin, new_registros[i].pais);          // Pega o país
        cout << "Ano de fundação: ";                  
        cin >> new_registros[i].anoFundacao;          // Pega o ano de fundação
        cin.ignore();                                 // Ignora a quebra de linha do "cin" anterior    
        cout << "Descrição: ";                        
        getline(cin, new_registros[i].descricao);     // Pega a descrição
        cout << endl;
    }

    delete[] registros;
    registros = new_registros; // Transforma o Clube anterior no novo Clube
    tamanho_registros = new_tamanho_registros;

    return registros;
}

Clube *excluirElemento(Clube *registros, int &tamanho_registros){

    cout << "                             ======================================================== " << endl
         << "                            |                                                        |" << endl
         << "                            |   Digite a forma de procura que será utilizado         |" << endl
         << "                            |  para excluir os registros, por exemplo:               |" << endl
         << "                            |                                                        |" << endl
         << "                            |  Por ID(1), Nome(2), Ano de fundação(3)                |" << endl
         << "                            |                                                        |" << endl
         << "                            |  Detalhe!!! Qualquer tipo de busca, a maneira digitada |" << endl 
         << "                            |  deve estar igual ao do registro já existente          |" << endl
         << "                            |                                                        |" << endl
         << "                             ======================================================== " << endl;

    cout << endl << "Número do tipo da busca: ";
    short buscaExclusao; // Variavel que determinará o tipo de busca
    cin >> buscaExclusao;

    cout << "\n\n";

    switch(buscaExclusao){
        case 1:
            ordenamento_crescente_id(registros,tamanho_registros);
            break;
        case 2:
            ordenamento_crescente_nome(registros,tamanho_registros);
            break;
        case 3:
            ordenamento_crescente_ano(registros,tamanho_registros);
            break;
        default: // Opção de default para caso tenha sido digitado errado
            cout << "Opção inválida. Nenhuma alteração foi feita!" << endl;
            return registros; // Volta a parte inicial sem fazer nenhum alteração
    }

    cout << "                             ============================================================= " << endl
         << "                            |                                                             |" << endl
         << "                            |   Deseja excluir de forma unitária ou sequencial?           |" << endl
         << "                            |                                                             |" << endl
         << "                            |   Por exemplo:                                              |" << endl
         << "                            |    Forma unitária: ''Quero excluir o id 1, 24 e 83''        |" << endl
         << "                            |    Forma sequencial: ''Quero excluir do Arsenal ao Flamengo |" << endl
         << "                            |                                                             |" << endl
         << "                            |   Lembrando que qualquer formato de busca aceita todas as   |" << endl
         << "                            |   formas de exclusão                                        |" << endl
         << "                            |                                                             |" << endl
         << "                             ============================================================= " << endl;

    char formato_exclusao; // Variavel que determinara o formato da exclusão
    cout << endl;
    cout << "Formato desejado (u/s): ";
    cin >> formato_exclusao;

    while(formato_exclusao!='u' && formato_exclusao!='s'){
        cout << "Caracter não identificado, tente novamente!" << endl << endl;
        cout << "Formato desejado (u/s): ";
        cin >> formato_exclusao;
    }

    
    cin.ignore(); // Limpeza de buffer

    int quantidade_excluida; // Variavel utilizada na parte unitária (declarada antes do "if" para ser utilizada sempre que necessário)
    int cont=0; // EXTREMAMENTE IMPORTANTE. Determinará o tamanho do vetor após as alterações

    Clube *new_registros = new Clube[tamanho_registros]; // Redimensionamento padrão

    if (formato_exclusao == 'u') { // Início do "if" do formato unitário
        cout << "\n\n";
        cout << "Quantidade em que deseja excluir: ";
        cin >> quantidade_excluida; // Variavel já citada anteriormente

        if(buscaExclusao==1){ // "if" para ID unitário
            int *vet_exclusao= new int[quantidade_excluida]; // Vetor alocado dinamicamente que guardará o que será excluido

            cout << "\nDigite quais você deseja excluir (Não precisa ser em ordem) ";
            cout << endl;

            for(int i=0; i<quantidade_excluida; i++){ // "for" para ler os registros que serão excluidos
                cout << "Registro " << (i+1) << ": ";
                cin >> vet_exclusao[i];
            }

            for(int i=0; i<tamanho_registros; i++){       // "for" PRINCIPAL da exclusão
                bool igual=false;                         // Variavel para identificar quando o registro é igual ao do vetor
                for(int j=0; j<quantidade_excluida; j++){ // "for" para comparar se é igual
                    if(registros[i].id==vet_exclusao[j]){ 
                        igual=true;                       
                    }
                }
                if(!igual){                               // Após a comparação do "for" secundário e ainda dentro do for principal,
                    new_registros[cont]=registros[i];     // esse "if" tem a função de escrever os registros que não serão excluidos
                                                          // no vetor de registros que será feito o redimensionamento
                    cont++;                               // Essa para aumentar o tamanho do novo vetor
                }
            }
            delete[] vet_exclusao; // Exclusão do vetor que guardava temporariamente os registros que seriam excluidos

        }else if(buscaExclusao==2){ // "if" para nome unitário
            string *vet_exclusao= new string[quantidade_excluida]; // Vetor alocado dinamicamente que guardará o que será excluido

            cout << "\nDigite quais você deseja excluir (Não precisa ser em ordem)";
            cout << endl;
            
            cin.ignore();  // Limpeza de buffer para ler strings (nomes) após ler a quantidade (int)

            for(int i=0; i<quantidade_excluida; i++){ // "for" para ler os registros que serão excluidos
                cout << "Registro " << (i+1) << ": ";
                getline(cin, vet_exclusao[i]);
            }

            for(int i=0; i<tamanho_registros; i++){         // "for" PRINCIPAL da exclusão
                bool igual=false;                           // Variavel para identificar quando o registro é igual ao do vetor
                for(int j=0; j<quantidade_excluida; j++){   // "for" para comparar se é igual
                    if(registros[i].nome==vet_exclusao[j]){ 
                        igual=true;
                    }
                }
                if(!igual){                                 // Após a comparação do "for" secundário e ainda dentro do for principal,
                    new_registros[cont]=registros[i];       // esse "if" tem a função de escrever os registros que não serão excluidos
                                                            // no vetor de registros que será feito o redimensionamento
                    cont++;                                 // Essa para aumentar o tamanho do novo vetor
                }
            }
            delete[] vet_exclusao; // Exclusão do vetor que guardava temporariamente os registros que seriam excluidos
        
        }else if(buscaExclusao==3){ // "if" para ano de fundação unitário
            int *vet_exclusao= new int[quantidade_excluida]; // Vetor alocado dinamicamente que guardará o que será excluido

            cout << "\nDigite quais você deseja excluir (Não precisa ser em ordem)";
            cout << endl;

            for(int i=0; i<quantidade_excluida; i++){ // "for" para ler os registros que serão excluidos
                cout << "Registro " << (i+1) << ": ";
                cin >> vet_exclusao[i];
            }
            
            for(int i=0; i<tamanho_registros; i++){                // "for" PRINCIPAL da exclusão
                bool igual=false;                                  // Variavel para identificar quando o registro é igual ao do vetor
                for(int j=0; j<quantidade_excluida; j++){          // "for" para comparar se é igual
                    if(registros[i].anoFundacao==vet_exclusao[j]){
                        igual=true;
                    }
                }
                if(!igual){                            // Após a comparação do "for" secundário e ainda dentro do for principal,
                    new_registros[cont]=registros[i];  // esse "if" tem a função de escrever os registros que não serão excluidos
                                                       // no vetor de registros que será feito o redimensionamento
                    cont++;                            // Essa para aumentar o tamanho do novo vetor
                }
            }
            delete[] vet_exclusao; // Exclusão do vetor que guardava temporariamente os registros que seriam excluidos
        }

    }else if (formato_exclusao == 's'){ // Início do "if" do formato sequencial
        
        cout << "\n\n";
        cout << "De qual registro até qual registro deve ser excluído? (Não precisa estar em ordem)";
        cout << endl;

        if(buscaExclusao==1){ // "if" para ID sequencial
            int menor, maior; // Leitura de qual até qual será excluido
            cout << "Registro 1: ";
            cin >> menor;
            cout << "Registro 2: ";
            cin >> maior;

            if(maior<menor){      // Como pode ser escrito de forma não ordenada (o usuário
                int aux = menor;  // não tem obrigação de saber qual vem antes), esse "if"
                menor = maior;    // serve para deixar ordenado em ordem crescente
                maior = aux;
            }

            for(int i=0; i<tamanho_registros; i++){                 // "for" PRINCIPAL da exclusão
                if(registros[i].id<menor || registros[i].id>maior){ // Verificação se é menor que o primeiro e maior que o último
                    new_registros[cont]=registros[i];               
                    cont++;                                         // Essa para aumentar o tamanho do novo vetor
                }
            }

        }else if(buscaExclusao==2){ // "if" para nome sequencial
            string menor, maior;    // Leitura de qual até qual será excluido
            cout << "Registro 1: ";
            getline(cin, menor);
            cout << "Registro 2: ";
            getline(cin, maior);

            if(maior<menor){         // Como pode ser escrito de forma não ordenada (o usuário
                string aux = menor;  // não tem obrigação de saber qual vem antes), esse "if"
                menor = maior;       // serve para deixar ordenado em ordem crescente
                maior = aux;
            }

            for(int i=0; i<tamanho_registros; i++){                     // "for" PRINCIPAL da exclusão
                if(registros[i].nome<menor || registros[i].nome>maior){ // Verificação se é menor que o primeiro e maior que o último
                    new_registros[cont]=registros[i];
                    cont++;                                             // Essa para aumentar o tamanho do novo vetor
                }
            }

        }else if(buscaExclusao==3){ // "if" para ano de fundação sequencial
            int menor, maior;       // Leitura de qual até qual será excluido
            cout << "Registro 1: ";
            cin >> menor;
            cout << "Registro 2: ";
            cin >> maior;

            if(maior<menor){        // Como pode ser escrito de forma não ordenada (o usuário
                int aux = menor;    // não tem obrigação de saber qual vem antes), esse "if"
                menor = maior;      // serve para deixar ordenado em ordem crescente
                maior = aux;
            }

            for(int i=0; i<tamanho_registros; i++){                                   // "for" PRINCIPAL da exclusão
                if(registros[i].anoFundacao<menor || registros[i].anoFundacao>maior){ // Verificação se é menor que o primeiro e maior que o último
                    new_registros[cont]=registros[i];                                 
                    cont++;                                                           // Essa para aumentar o tamanho do novo vetor
                }
            }            
        }
    }

    delete[] registros;        // Liberar memória do redimensionamento
    registros=new_registros;   // Redimensionamento
    tamanho_registros = cont;  // Altera o tamanho tanto aqui quanto na função principal (main),
                               //  devido ao "&" utilizado la em cima no "Clube *excluirElemento(Clube *registros, int >>&<<tamanho_registros){"
    
    ordenamento_crescente_id(registros,tamanho_registros); // Após finalizar a parte de exclusão, ordena novamente para IDs crescentes
                                                           // a fim de não ter perigo de prejudicar nenhuma outra lógica após
    for(int i=0; i < tamanho_registros; i++) registros[i].id = i + 1;
                                        
    return registros; // Retorna o novo registro
}

void buscarElemento(Clube *registros, int tamanho_registros){

    cout << "                                  ======================================= " << endl
         << "                                 |                                       |" << endl
         << "                                 |   Digite qual o jeito desejado para   |" << endl
         << "                                 |  buscar o registro                    |" << endl
         << "                                 |                                       |" << endl
         << "                                 |   Pode ser tanto por:                 |" << endl
         << "                                 |   ID(1), Nome(2), País(3)             |" << endl
         << "                                 |   ou Ano de Fundação(4)               |" << endl
         << "                                 |                                       |" << endl
         << "                                  ======================================= " << endl;

    cout << endl;
    int formato;
    cout << endl << "Digite o formato desejado: ";
    cin >> formato;
    cout << endl; 

    switch(formato){
        case 1:
            ordenamento_crescente_id(registros,tamanho_registros);
            break;
        case 2:
            ordenamento_crescente_nome(registros,tamanho_registros);
            break;
        case 3:
            ordenamento_crescente_pais(registros,tamanho_registros);
            break;
        case 4:
            ordenamento_crescente_ano(registros,tamanho_registros);
            break;
        default: // Opção de default para caso tenha sido digitado errado
            cout << "Opção inválida. Nenhuma alteração foi feita!" << endl;
            return; // Volta a parte inicial sem fazer nenhum alteração
    }

    cout << "                             ============================================================= " << endl
         << "                            |                                                             |" << endl
         << "                            |   Deseja buscar de forma unitária ou sequencial?            |" << endl
         << "                            |                                                             |" << endl
         << "                            |   Por exemplo:                                              |" << endl
         << "                            |    Forma unitária: ''Quero buscar o id 1, 24 e 83''         |" << endl
         << "                            |    Forma sequencial:''Quero buscar do Arsenal ao Flamengo'' |" << endl
         << "                            |                                                             |" << endl
         << "                            |   Lembrando que qualquer formato de busca aceita todas as   |" << endl
         << "                            |   formas de itens                                           |" << endl
         << "                            |                                                             |" << endl
         << "                             ============================================================= " << endl;

    char formato_busca; // Variavel que determinara o formato da exclusão
    cout << endl;
    cout << "Formato desejado (u/s): ";
    cin >> formato_busca;

    while(formato_busca!='u' && formato_busca!='s'){
        cout << "Caracter não identificado, tente novamente!" << endl << endl;
        cout << "Formato desejado (u/s): ";
        cin >> formato_busca;
    }
    
    cin.ignore(); // Limpeza de buffer

    if(formato_busca=='u'){ // Faz a busca no formato unitário
        int quantidade;
        cout << "ATENTE-SE, que tanto para países quanto para o ano de fundação, será mostrado apenas o primeiro da lista!!";
        cout << "\n\nQuantidade em que deseja buscar: ";
        cin >> quantidade;
        cout << endl;

        int *vet_procura_int=new int[quantidade];           // Vetores auxiliares que guardarão os itens buscados
        string *vet_procura_string=new string[quantidade];

        cin.ignore(); // Limpeza de buffer
        
        if(formato==1){ // Caso tenha escolhido buscar ID, entra aqui
            for(int i=0; i<quantidade; i++){ // "for" para pegar os itens desejados
                cout << (i+1) << "º ID que procura: ";
                cin >> vet_procura_int[i];
            }

            cout << "\n\nRegistros:";
            for(int i=0; i<quantidade; i++){
                busca_binaria_id(registros,0,tamanho_registros,vet_procura_int[i]); // Utilização da busca binária
            }
            delete[] vet_procura_int; // Liberação de memória
        }else if(formato==2){ // Caso tenha escolhido buscar Nome, entra aqui
            for(int i=0; i<quantidade; i++){ // "for" para pegar os itens desejados
                cout << (i+1) << "º Nome que procura: ";
                getline(cin,vet_procura_string[i]);
            }

            cout << "\n\nRegistros:";
            for(int i=0; i<quantidade; i++){
                busca_binaria_nome(registros,0,tamanho_registros,vet_procura_string[i]); // Utilização da busca binária
            }
            delete[] vet_procura_string; // Liberação de memória
        }else if(formato==3){ // Caso tenha escolhido buscar país, entra aqui
            for(int i=0; i<quantidade; i++){ // "for" para pegar os itens desejados
                cout << (i+1) << "º País que procura: ";
                getline(cin,vet_procura_string[i]);
            }

            cout << "\n\nRegistros:";
            for(int i=0; i<quantidade; i++){
                busca_binaria_pais(registros,0,tamanho_registros,vet_procura_string[i]); // Utilização da busca binária
            }
            delete[] vet_procura_string; // Liberação de memória
        }else if(formato==4){ // Caso tenha escolhido buscar ano, entra aqui
            for(int i=0; i<quantidade; i++){ // "for" para pegar os itens desejados
                cout << (i+1) << "º Ano que procura: ";
                cin >> vet_procura_int[i];
            }

            cout << "\n\nRegistros:";
            for(int i=0; i<quantidade; i++){
                busca_binaria_ano(registros,0,tamanho_registros,vet_procura_int[i]); // Utilização da busca binária
            }
            delete[] vet_procura_int; // Liberação de memória
        }
    }else if(formato_busca=='s'){
        cout << endl;
        cout << "                             ======================================================================== " << endl
             << "                            |  Deseja que os registros sejam impressos na ordem crescente de IDs(1)  |" << endl
             << "                            |  ou na ordem crescente/alfabética da sua determinada escolha(2)?       |" << endl
             << "                             ======================================================================== " << endl;

        cout << "\nFormato de impressão desejado: ";
        int impressao;
        cin >> impressao;

        cin.ignore();

        if(impressao==1) ordenamento_crescente_id(registros,tamanho_registros); // Caso a pessoa tenha escolhido imprimir na ordem
                                                                                //  crescente de IDs, aqui já vai ordenar em formato de ID

        cout << "\n\nNa busca sequencial mostrará do 1º registro que colocar até o 2º.\n\n";
        if(formato==1){      // Independente se escolheu a opção 1 de impressão ou a 2, aqui o formato não
            int menor,maior; // altera, pois já iria imprimir os IDs de forma crescente de qualquer jeito
            cout << "1º ID: ";
            cin >> menor;
            cout << "\n2º ID: ";
            cin >> maior;

            if(maior<menor){        // Como pode ser escrito de forma não ordenada (o usuário
                int aux = menor;    // não tem obrigação de saber qual vem antes), esse "if"
                menor = maior;      // serve para deixar ordenado em ordem crescente
                maior = aux;
            }        

            cout << "\n\nRegistros:";
            for(int i=0; i<tamanho_registros; i++){
                if(registros[i].id>=menor && registros[i].id<=maior){ // Imprime apenas os que estão entre 
                        cout << endl << endl;                         // o primeiro e o último desejado
                        cout << registros[i].id << ", "
                             << registros[i].nome << ", "
                             << registros[i].pais << ", "
                             << registros[i].anoFundacao << ", "
                             << registros[i].descricao;
                }
            }
        }else if(formato==2){ // Caso tenha escolhido buscar nome, entra aqui
            string menor,maior;
            cout << "1º Nome: ";
            getline(cin,menor);
            cout << "\n2º Nome: ";
            getline(cin,maior);

            if(maior<menor){        // Como pode ser escrito de forma não ordenada (o usuário
                string aux = menor;    // não tem obrigação de saber qual vem antes), esse "if"
                menor = maior;      // serve para deixar ordenado em ordem crescente
                maior = aux;
            }

            if(impressao==1){  // Caso tenha escolhido imprimir em ordem crescente de ID, entra nesse "if"
                int id_menor,id_maior;
            
                for(int i=tamanho_registros-1; i>=0; i--){ // Aqui pega o ID dos registros buscados
                    if(registros[i].nome==menor) id_menor=i+1;
                    if(registros[i].nome==maior) id_maior=i+1;
                }

                cout << "\n\nRegistros:";
                for(int i=0; i<tamanho_registros; i++){                          // Imprime apenas os que estão entre o primeiro
                    if(registros[i].id>=id_menor && registros[i].id<=id_maior){  //  e o último desejado no formato de ID
                            cout << endl << endl;
                            cout << registros[i].id << ", "
                                 << registros[i].nome << ", "
                                 << registros[i].pais << ", "
                                 << registros[i].anoFundacao << ", "
                                 << registros[i].descricao;
                    }
                }
            }else{ // Caso tenha escolhido imprimir em ordem padrão do item específico, entra nesse "else"
                cout << "\n\nRegistros:";
                for(int i=0; i<tamanho_registros; i++){                       // Imprime apenas os que estão entre o primeiro e 
                    if(registros[i].nome>=menor && registros[i].nome<=maior){ // o último desejado no formato alfabético de nomes
                            cout << endl << endl;
                            cout << registros[i].id << ", "
                                 << registros[i].nome << ", "
                                 << registros[i].pais << ", "
                                 << registros[i].anoFundacao << ", "
                                 << registros[i].descricao;
                    }
                }
            }
        }else if(formato==3){ // Caso tenha escolhido buscar país, entra aqui
            string menor,maior;
            cout << "1º País: ";
            getline(cin,menor);
            cout << "\n2º País: ";
            getline(cin,maior);

            if(maior<menor){        // Como pode ser escrito de forma não ordenada (o usuário
                string aux = menor;    // não tem obrigação de saber qual vem antes), esse "if"
                menor = maior;      // serve para deixar ordenado em ordem crescente
                maior = aux;
            }        

            if(impressao==1){ // Caso tenha escolhido imprimir em ordem crescente de ID, entra nesse "if"

                int id_menor,id_maior;
            
                for(int i=tamanho_registros-1; i>=0; i--){ // Aqui pega o ID dos registros buscados
                    if(registros[i].pais==menor) id_menor=i+1;
                    if(registros[i].pais==maior) id_maior=i+1;
                }

                cout << "\n\nRegistros:";
                for(int i=0; i<tamanho_registros; i++){                          // Imprime apenas os que estão entre o primeiro
                    if(registros[i].id>=id_menor && registros[i].id<=id_maior){  //  e o último desejado no formato de ID
                            cout << endl << endl;
                            cout << registros[i].id << ", "
                                 << registros[i].nome << ", "
                                 << registros[i].pais << ", "
                                 << registros[i].anoFundacao << ", "
                                 << registros[i].descricao;
                    }
                }
            }else{ // Caso tenha escolhido imprimir em ordem padrão do item específico, entra nesse "else"
                cout << "\n\nRegistros:";
                for(int i=0; i<tamanho_registros; i++){                        // Imprime apenas os que estão entre o primeiro e 
                    if(registros[i].pais>=menor && registros[i].pais<=maior){  // o último desejado no formato alfabético de países
                        cout << endl << endl;
                        cout << registros[i].id << ", "
                             << registros[i].nome << ", "
                             << registros[i].pais << ", "
                             << registros[i].anoFundacao << ", "
                             << registros[i].descricao;
                    }
                }
            }
        }else if(formato==4){ // Caso tenha escolhido buscar ano, entra aqui
            int menor,maior;
            cout << "1º Ano de fundação: ";
            cin >> menor;
            cout << "\n2º Ano de fundação: ";
            cin >> maior;

            if(maior<menor){        // Como pode ser escrito de forma não ordenada (o usuário
                int aux = menor;    // não tem obrigação de saber qual vem antes), esse "if"
                menor = maior;      // serve para deixar ordenado em ordem crescente
                maior = aux;
            }       
            
            if(impressao==1){ // Caso tenha escolhido imprimir em ordem crescente de ID, entra nesse "if"

                int id_menor,id_maior;
             
                for(int i=tamanho_registros-1; i>=0; i--){ // Aqui pega o ID dos registros buscados
                    if(registros[i].anoFundacao==menor) id_menor=i+1;
                    if(registros[i].anoFundacao==maior) id_maior=i+1;
                }

                cout << "\n\nRegistros:";
                for(int i=0; i<tamanho_registros; i++){                          // Imprime apenas os que estão entre o primeiro
                    if(registros[i].id>=id_menor && registros[i].id<=id_maior){  //  e o último desejado no formato de ID
                            cout << endl << endl;
                            cout << registros[i].id << ", "
                                 << registros[i].nome << ", "
                                 << registros[i].pais << ", "
                                 << registros[i].anoFundacao << ", "
                                 << registros[i].descricao;
                    }
                }
            }else{ // Caso tenha escolhido imprimir em ordem padrão do item específico, entra nesse "else"
                cout << "\n\nRegistros:";
                for(int i=0; i<tamanho_registros; i++){                                      // Imprime apenas os que estão entre o primeiro e 
                    if(registros[i].anoFundacao>=menor && registros[i].anoFundacao<=maior){  // o último desejado no formato crescente de ano
                        cout << endl << endl;
                        cout << registros[i].id << ", "
                             << registros[i].nome << ", "
                             << registros[i].pais << ", "
                             << registros[i].anoFundacao << ", "
                             << registros[i].descricao;
                    }
                }
            }
        }
    }

    cout << endl << endl;
}

void salvarBinario(Clube *registros, int tamanho_registros){

    ofstream bancoBinario("Banco de dados.bin", ios::binary); // Inicializa o arquivo binário

    // Salva o cabeçalho exatamente igual ao CSV
    string cabecalho = "identificador,nome_do_clube,pais_do_clube,ano_de_fundacao,descricao";
    int tam = cabecalho.size();
    bancoBinario.write(reinterpret_cast<char*>(&tam), sizeof(int));
    bancoBinario.write(cabecalho.c_str(), tam);

    // Salva a quantidade de registros
    bancoBinario.write(reinterpret_cast<char*>(&tamanho_registros), sizeof(int));

    // "for" para salvar todos os registros
    for (int i = 0; i < tamanho_registros; i++) {
        char virgula = ','; // Variavel utilizada para colocar vírgulas

        // ID
        bancoBinario.write(reinterpret_cast<char*>(&registros[i].id), sizeof(int));
        bancoBinario.write(&virgula, 1);

        // Nome
        tam = registros[i].nome.size();
        bancoBinario.write(reinterpret_cast<char*>(&tam), sizeof(int));
        bancoBinario.write(registros[i].nome.c_str(), tam);
        bancoBinario.write(&virgula, 1);

        // País
        tam = registros[i].pais.size();
        bancoBinario.write(reinterpret_cast<char*>(&tam), sizeof(int));
        bancoBinario.write(registros[i].pais.c_str(), tam);
        bancoBinario.write(&virgula, 1);

        // Ano de fundação
        bancoBinario.write(reinterpret_cast<char*>(&registros[i].anoFundacao), sizeof(int));
        bancoBinario.write(&virgula, 1);

        // Descrição com aspas
        string desc = "\"" + registros[i].descricao + "\"";
        tam = desc.size();
        bancoBinario.write(reinterpret_cast<char*>(&tam), sizeof(int));
        bancoBinario.write(desc.c_str(), tam);
    }

    bancoBinario.close();
}

void ordenar_e_imprimir_elementos(Clube *registros, int tamanho_registros){
    cout << "                                  ================================= " << endl
         << "                                 |                                 |" << endl
         << "                                 |   Digite de qual jeito deseja   |" << endl
         << "                                 |   ordernar os registros         |" << endl
         << "                                 |   (ordem crescente/alfabética)  |" << endl
         << "                                 |                                 |" << endl
         << "                                 |   ID(1), Nome(2), País(3)       |" << endl
         << "                                 |   ou Ano de Fundação(4)         |" << endl
         << "                                 |                                 |" << endl
         << "                                  ================================= " << endl;

    cout << "\n\nOrdenamento desejado: ";
    int ordenamento;
    cin >> ordenamento;

    switch(ordenamento){
        case 1:
            ordenamento_crescente_id(registros,tamanho_registros);
            break;
        case 2:
            ordenamento_crescente_nome(registros,tamanho_registros);
            break;
        case 3:
            ordenamento_crescente_pais(registros,tamanho_registros);
            break;
        case 4:
            ordenamento_crescente_ano(registros,tamanho_registros);
            break;
        default: // Opção de default para caso tenha sido digitado errado
            cout << "Opção inválida. Nenhuma alteração foi feita!" << endl;
            return; // Volta a parte inicial sem fazer nenhum alteração
    }

    cout << endl << endl;
    cout << "                              ================================================================= " << endl
         << "                             |  Seu arquivo atual está desse formato abaixo, caso              |" << endl
         << "                             |  queira que seja impresso algum trecho ou registro específico,  |" << endl 
         << "                             |  entre na opção 3 do menu principal (Burscar Elemento)          |" << endl
         << "                              ================================================================= " << endl;

    cout << endl << "Para iniciar a impressão digite '1': ";
    int iniciar;
    cin >> iniciar;

    if(iniciar!=1) ordenar_e_imprimir_elementos(registros,tamanho_registros); // Caso o usuária desejar não iniciar a impressão agora,
                                                                              // volta para o inicio da função de ordenar e imprimir
    for(int i=0; i<tamanho_registros; i++){ // "for" básico para impressão
        cout << endl << endl;
        cout << registros[i].id << ", "
             << registros[i].nome << ", "
             << registros[i].pais << ", "
             << registros[i].anoFundacao << ", "
             << registros[i].descricao;
    }

    cout << endl;
}

int main() {

    acentuacao(); // Função inicial (não pode sair daqui), que serve para abilitar a opção de acentos no terminal
    
    string linha;                                
    int tamanho_registros;
    char continuar; // Muito importante e usado ao longo do projeto

    ifstream arquivo_csv("Banco de Dados.csv"); // Caso o arquivo não tenha aberto
    if (!arquivo_csv) {
        cout << "Erro: não foi possível abrir o arquivo de dados!" << endl;
        return 1;
    }

    getline(arquivo_csv, linha);  // Descarta a primeira linha do arquivo
    arquivo_csv >> tamanho_registros;  // Pega a quantidade de registros
    arquivo_csv.ignore();         // Pula o fim de linha

    Clube *registros = lerRegistros(arquivo_csv,tamanho_registros); // Função que irá ler todos os registros iniciais do arquivo csv
    arquivo_csv.close(); // Como o arquivo já foi lido, ele pode ser fechado para liberar memória
    int numSwitch; // Número que será utilizado tanto para as funções quanto para finalizar o do{}while

    do{
        
        cout << endl;
        cout << "                                  ================================================= " << endl
             << "                                 |                                                 |" << endl
             << "                                 |  Digite 1 para inserir um novo elemento         |" << endl
             << "                                 |  Digite 2 para remover algum registro           |" << endl
             << "                                 |  Digite 3 para buscar algum registro            |" << endl
             << "                                 |  Digite 4 para ordenar e imprimir os registros  |" << endl
             << "                                 |                                                 |" << endl
             << "                                 |  Digite -1 para finalizar                       |" << endl
             << "                                 |                                                 |" << endl
             << "                                  ================================================= " << endl;

        cout << endl << "Opção escolhida: ";
        cin >> numSwitch; // Número que será digitado pelo usuário 

        switch(numSwitch){ // Switch Case que levará para a condição do número em que foi escrito
            case 1: // Caso o número digitado tenha sido "1"
                do{

                    cout << endl;
                    // Linha do tamanho exato do terminal (apenas estético)
                    cout << "________________________________________________________________________________________________________________________";
                    cout << endl;
                    cout << endl;
                    cout << "                                  ================================================= " << endl
                         << "                                 |                                                 |" << endl
                         << "                                 |   Digite a quantidade de registros que serão    |" << endl
                         << "                                 |  adicionados ao sistema (cada registro          |" << endl
                         << "                                 |  contém 5 itens)                                |" << endl
                         << "                                 |                                                 |" << endl
                         << "                                  ================================================= " << endl;
                    int aumento; // Quantidade de registros que será adicionado
                    cout << endl << "Quantidade que será adicionada: ";
                    cin >> aumento;
                    cout << endl;
                    registros = inserirElemento(registros,tamanho_registros,aumento);
                    // Função que irá fazer o incremento do elemento e já fazer a troca do "registros"
                
                    tamanho_registros+=aumento; // Aumenta a quantidade de número de registros permanentemente

                    cout << "Número atual de registros é: " << tamanho_registros << endl << endl;

                    cout << "Deseja continuar incrementando elementos? (s/n) ";
                    cin >> continuar;

                    while(continuar!='s' && continuar!='n'){
                        cout << "Caracter não identificado, tente novamente!" << endl << endl;
                        cout << "Deseja continuar incrementando elementos? (s/n) ";
                        cin >> continuar;
                    }
                    
                }while(continuar=='s');
                break;

            case 2:
                do{
                    cout << endl;
                    // Linha do tamanho exato do terminal (apenas estético)
                    cout << "________________________________________________________________________________________________________________________";
                    cout << endl;
                    cout << endl;
                    registros = excluirElemento(registros,tamanho_registros); // Chamando a Função de exclusão

                    cout << endl;
                    cout << "Deseja continuar excluindo elementos? (s/n) ";
                    cin >> continuar; // Variavel criada anteriormente (apenas para finalizar laço)

                    while(continuar!='s' && continuar!='n'){
                        cout << "Caracter não identificado, tente novamente!" << endl << endl;
                        cout << "Deseja continuar excluindo elementos? (s/n) ";
                        cin >> continuar;
                    }
                }while(continuar=='s');
                break;

            case 3:
                do{
                    cout << endl;
                    // Linha do tamanho exato do terminal (apenas estético)
                    cout << "________________________________________________________________________________________________________________________";
                    cout << endl;
                    cout << endl;
                    buscarElemento(registros,tamanho_registros); // Chamando a Função de busca

                    cout << endl;
                    cout << "Deseja continuar buscando elementos? (s/n) ";
                    cin >> continuar; // Variavel criada anteriormente (apenas para finalizar laço)

                    while(continuar!='s' && continuar!='n'){
                        cout << "Caracter não identificado, tente novamente!" << endl << endl;
                        cout << "Deseja continuar buscando elementos? (s/n) ";
                        cin >> continuar;
                    }
                }while(continuar=='s');
                break;

            case 4:
                do{
                    cout << endl;
                    // Linha do tamanho exato do terminal (apenas estético)
                    cout << "________________________________________________________________________________________________________________________";
                    cout << endl;
                    cout << endl;
                    ordenar_e_imprimir_elementos(registros,tamanho_registros); // Chamando a Função de ordenação e impressão

                    cout << endl;
                    cout << "Deseja continuar ordenando e imprimindo elementos? (s/n) ";
                    cin >> continuar; // Variavel criada anteriormente (apenas para finalizar laço)

                    while(continuar!='s' && continuar!='n'){
                        cout << "Caracter não identificado, tente novamente!" << endl << endl;
                        cout << "Deseja continuar ordenando e imprimindo elementos? (s/n) ";
                        cin >> continuar;
                    }
                }while(continuar=='s');
                break;
        }
        
        cout << endl;
        cout << "________________________________________________________________________________________________________________________";
        cout << endl;

    }while(numSwitch!=-1);

    cout << endl << "                                  ============================================ " << endl
                 << "                                 |                                            |" << endl
                 << "                                 |  Com todas as funções já finalizadas, seu  |" << endl
                 << "                                 |  novo arquivo CSV e Binário serão criados  |" << endl
                 << "                                 |  com suas alterações realizadas, os nomes  |" << endl
                 << "                                 |  dos novos arquivos são:                   |" << endl
                 << "                                 |    ''New Banco de Dados.csv''              |" << endl
                 << "                                 |    ''Banco de dados.bin''                  |" << endl
                 << "                                 |                                            |" << endl
                 << "                                  ============================================ " << endl;

    ofstream newBanco("New Banco de Dados.csv"); // Banco de Dados todo atualizado após as alterações

    newBanco << "identificador,nome_do_clube,pais_do_clube,ano_de_fundacao,descricao" << endl;
    newBanco << tamanho_registros << endl;

    for(int i=0; i<tamanho_registros; i++){
        newBanco << registros[i].id << ','
                 << registros[i].nome << ','
                 << registros[i].pais << ','
                 << registros[i].anoFundacao << ','
                 << '"' << registros[i].descricao << '"';
        newBanco << endl;
    }

    newBanco.close();

    salvarBinario(registros, tamanho_registros);

    return 0;
}
