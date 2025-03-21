// Copyright [2022] <COLOQUE SEU NOME AQUI...>
#include <string>


class Aluno {
 public:
    Aluno() {}  // construtor
    ~Aluno() {}  // destrutor
    std::string devolveNome() {
        return nome;
    }
    int devolveMatricula() {
        return matricula;
    }
    void escreveNome(std::string nome_) {
        nome = nome_;
    }
    void escreveMatricula(int matricula_) {
        matricula = matricula_;
    }
 private:
    std::string nome;
    int matricula;
};


Aluno *turma_filtra(Aluno t[], int N, int menor_matr) {
    Aluno *tf;

    int count = 0;
    for(int i = 0; i < N;i++) {
        if(t[i].devolveMatricula() >= menor_matr) {
            count++;
        }
    }
    tf = new Aluno[count]();  // retirar e alocar (com new)
    int index=0;
    for(int i=0;    i<N;    i++){
        if(t[i].devolveMatricula()>=menor_matr){
            tf[index] = t[i];
            index++;
        }
    }

    return tf;
}

int *turma_conta(Aluno t[], int N) {
    int *c;
    c = new int[26]{0};  // retirar e alocar (com new)
    for(int i=0;    i<N;    i++){
        char    p_char=t[i].devolveNome()[0];

        if(p_char>='A'&&p_char<='Z'){
            c[p_char-'A']++;
        }
    }
    
    return c;
}



/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/
