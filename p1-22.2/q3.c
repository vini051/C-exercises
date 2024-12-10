/*
*   COMPARANDO O ACESSO AOS ELEMENTOS DE UM VETOR A PARTIR DA QUESTÃO 3 DA PROVA
*/

float Media(float *pV, int pn) {
    float pM = 0;
    int pInd;
    for (pInd = 0; pInd < pn; pInd++) {
        pM += pV[pInd];                 // acesso feito direto pelo índice
    }
    return (pM / pn);
}

float Media2(float *pV, int pn) {
    float *pVaux = pV, pM = 0;
    int pInd;
    for (pInd = 0; pInd < pn; pInd++) {
        pM += *pVaux;                   // acesso feito pelo ponteiro se movimentando
        pVaux++;
    }
    return (pM / pn);
}
