// Copyright [2024] <COLOQUE SEU NOME AQUI...>

/*
    *** Importante ***

    O código de fila em vetor está disponível internamente (não precisa de implementação aqui)

*/


void retira_veiculo(structures::ArrayQueue<int> *f, int k) {
    int size = f->size();
    if (k < 1 || k > size) {
        return;
    }

    structures::ArrayQueue<int> tempQueue;

    for (int i = 0; i < size; i++) {
        int car = f->dequeue();
        if (i + 1 != k) {
            tempQueue.enqueue(car);
        }
    }

    while (!tempQueue.empty()) {
        f->enqueue(tempQueue.dequeue());
    }
}

void mantenha_veiculo(structures::ArrayQueue<int> *f, int k) {
    int size = f->size();
    if (k < 1 || k > size) {
        return;
    }

    structures::ArrayQueue<int> tempQueue;

    for (int i = 0; i < size; i++) {
        int car = f->dequeue();
        if (i + 1 == k) {
            tempQueue.enqueue(car);
        }
    }

    while (!tempQueue.empty()) {
        f->enqueue(tempQueue.dequeue());
    }
}
/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/

