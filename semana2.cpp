#include <iostream>

using namespace std;

class Pessoa {
 private:
    static const int quantidade = 3;
    string nome;
    string matricula;
 public:
    float notas[quantidade];
    Pessoa() {  // construtor
    }
    Pessoa(string nome_, string matricula_) {  // construtor
        nome = nome_;
        matricula = matricula_;
        for (int i=0; i<quantidade; i++) {
            notas[i] = 0.0;
        }
    }
    ~Pessoa() { 
    };  // destrutor
    void alteraNome(string nome_) {
        nome = nome_;
    }
    void alteraMatricula(string matricula_) {
        matricula = matricula_;
    }
    string devolveNome() {
        return nome;
    }
    string devolveMatricula() {
        return matricula;
    }
    float media() {
        float m = 0.0;
        for (int i=0; i<quantidade; i++) {
            m += notas[i];
        }
        m /= quantidade;
        return m;
    }
    bool compara(Pessoa *p) {
        float m1, m2;
        m1 = media();
        m2 = (*p).media();
        return (m1 >= m2);
    }
};



float maior_media(Pessoa A, Pessoa B) {  // passagem de parâmetros por valor (cópia)
    float x = A.media();
    float y = B.media();
    if (x > y) {
        return x;
    }
    return y;
}

float maior_media_2(Pessoa *A, Pessoa *B) {  // passagem de parâmetros por ponteiro (sem cópia)
    float x = A->media();  // ou: (*A).media()
    float y = B->media();  // ou: (*B).media()
    if (x > y) {
        return x;
    }
    return y;
}

float maior_media_3(Pessoa &A, Pessoa &B) {  // passagem de parâmetros por referência (sem cópia)
    float x = A.media();
    float y = B.media();
    if (x > y) {
        return x;
    }
    return y;
}






int main() {

    float x = 7.5;
    float *p;  // declaração de ponteiro para float

    float v[3] = {4.5, 9.5, 5.7};  // alocação estática (gerenciado pelo compilador)
    float *q;

    p = &x;  // inicialização de ponteiro ("endereço de x")

    cout << "x = " << x << std::endl;
    cout << "p = " << p << std::endl;
    cout << "*p = " << *p << std::endl;  // "conteúdo de p"

    q = v;
    cout << "q = " << q << std::endl;
    //ou
    q = &v[0];
    cout << "q = " << q << std::endl;

    q++; // ou 'q = q + 1;' ou 'q += 1';  // aritmética de ponteiros
    cout << "*q = " << *q << std::endl;  // "conteúdo de q"

    q = v + 2;  // aritmética de ponteiros
    cout << "*q = " << *q << std::endl;  // "conteúdo de q"

    v[2] = 2 * *q;  // ou 'v[2] = 2 * v[2];'
    cout << "*q = " << *q << std::endl;  // "conteúdo de q"

    /*
    -----------------------------
    Texto qualquer... 
    */ 

    bool condicao;

    condicao = true;

    if (condicao) {
        int histograma[10] = {4,7,2,1,9,0,8,3,3,5};  // alocação estática (sob responsabilidade do compilador)
        // 'histograma' foi declado dentro do 'if' e só existe
        // neste contexto 

        int *hist2;

        hist2 = new int[10];  // alocação dinâmica (sob responsabiliade do programador)

        for (int i=0; i < 10; i++) {
            hist2[i] = 0;
        }

        for (int i=0; i < 10; i++) {
            cout << histograma[i] << ' ';
        }
        cout << endl;
        for (int i=0; i < 10; i++) {
            cout << hist2[i] << ' ';
        }
        cout << endl;

        // cout << i;  // error: ‘i’ was not declared in this scope

        delete [] hist2;  // desalocação de vetor
        // para cada 'new', deve haver um 'delete'
    }

    // 'histograma' é automaticamente desalocado pelo compilador

    // cout << histograma[0] << endl;  // error: ‘histograma’ was not declared in this scope

    // cout << hist2[0] << endl;  // error: ‘hist2’ was not declared in this scope
    // no entanto, a área de memória ocupada por 'hist2' continua existindo (é preciso desalocá-la antes de perder o acesso)

    float a = 7.5;
    float *p1 = &a;
    
    float **q1 = &p1;

    cout << "a = " << a << std::endl;  // "conteúdo de q"
    cout << "*p1 = " << *p1 << std::endl;  // "conteúdo de q"
    cout << "p1 = " << p1 << std::endl;  // "conteúdo de q"
    cout << "*q1 = " << *q1 << std::endl;  // "conteúdo de q"
    cout << "*p1 = " << *p1 << std::endl;  // "conteúdo de q"
    cout << "**q1 = " << **q1 << std::endl;  // "conteúdo de q"
   

    int mat[500][700];
    // int mat[5000][7000];  // não foi possível espaço contíguo neste caso

    // const int M = 5000;
    // const int N = 7000;
    const int M = 5;
    const int N = 7;

    int **mat2;

    mat2 = new int *[M];
    for (int i=0; i < N; i++) {
        mat2[i] = new int[N];
    }

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if ((i+j) % 2 == 0) {
                mat2[i][j] = 1;
            } else {
                mat2[i][j] = 0;
            }
        }
    }

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cout << mat2[i][j] << ' ';
        }
        cout << endl;
    }

    // ---------------------------------

    Pessoa aluno1("Fulano de Tal", "1234");

    cout << aluno1.devolveNome() << ' ' << aluno1.devolveMatricula() << endl;
    aluno1.notas[0] = 7.0;
    aluno1.notas[1] = 8.0;
    aluno1.notas[2] = 6.0;

    Pessoa aluno2("Clicano", "5678");

    cout << aluno2.devolveNome() << ' ' << aluno2.devolveMatricula() << endl << endl;
    aluno2.notas[0] = 8.0;
    aluno2.notas[1] = 9.0;
    aluno2.notas[2] = 7.0;

    float media;
    media = maior_media(aluno1, aluno2);
    cout << media << endl;

    media = maior_media_2(&aluno1, &aluno2);
    cout << media << endl;

    media = maior_media_3(aluno1, aluno2);
    cout << media << endl;

    cout << "\nFim\n";

    return 0;
}