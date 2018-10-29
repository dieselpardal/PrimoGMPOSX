//
//  main.cpp
//  Primo GMP terminal
//
//  Created by Ivan Diesel on 11/16/15.
//  Copyright © 2015 Ivan Diesel. All rights reserved.
//
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include "gmp.h"
using namespace std;

clock_t  qTimeS, uTimeS1, uTimeS2;
unsigned long int P1;
string NUM_MERSENNE;
int XGMP = 1;
char * arquivo;
char * arqResultado;

#include  "pacote.h"
#include  "specialgmp.h"
#include  "funcoes.h"

int capa1() {
    cls();
    borda(79,40);
    linha(3);
    return 0;
}
int capa() {
    arquivo = convertString("Mersenne"+ NUM_MERSENNE + ".txt");
    arqResultado = convertString("Resultado"+ NUM_MERSENNE + ".txt");
    int i, escolhe;
    int lista = 25;
    const char *nomes[25] = {"-","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","a","x","X","b"};
    char *var;
    std::string s;
    //char* ss;
    escolhe=99;
    cls();
    borda(79,40);
    escBG(2,2,7,1,"                 NUMEROS PRIMOS - versao 1.3 para MAX OSX                    ");
    linha(3);
    int cor = 7;
    esc(2, 5,6,"ESCOLHE:");
    esc(2, 6,cor," 1) Mersenne so mostrar");            esc(40,06,cor,"15) Formula de Primo");
    esc(2, 7,cor," 2) Mersenne so gravar");             esc(40,07,cor,"16) Lista de Mersenne e Primo partir");
    esc(2, 8,cor," 3) Mostra o numero no arquivo");     esc(40, 8,cor,"17) Verificacao de Numero Perfeito");
    esc(2, 9,cor," 4) Mersenne e Primo - Resultado");   esc(40, 9,cor,"18) Lista de Numero Perfeito");
    esc(2,10,cor," 5) Primo de Mersenne Gravando");     esc(40,10,cor,"19) Lista de Numero Primo P=NP");
    esc(2,11,cor," 6) Mersenne so num digitos");        esc(40,11,cor,"20) Particao ( nao disponivel)");
    esc(2,12,cor," 7) Teorema de Fermat");
    esc(2,13,cor," 8) Conjectura de Goldbach");
    esc(2,14,cor," 9) Gerar 4GB numeros primos");
    esc(2,15,cor,"10) Proximo Primo");
    esc(2,16,cor,"11) Formula de Willians");
    esc(2,17,cor,"12) Conta de Num Primo");
    esc(2,18,cor,"13) Fatorial");
    esc(2,19,cor,"14) Funcao zeta de Riemann");            esc(40,19,cor,"B) [ ]GMP   [ ] Caseiro");
    esc(2,20,cor,"X) Sair");
    esc(60,20,cor,"A) Tabela Cor");

    esc(50,4,1,"MAX 4.294.967.295 INTEIROS");
    if (NUM_MERSENNE.length() >0 )
    {
      esc(2,4,1,"MERSENNE("+NUM_MERSENNE+")");
    } else {
        esc(2,4,1,"NENHUM MERSENNE.");
    }
    linha(21);
    linha(33);
    
    esc(3,24,7,"Arquivo '"+convertChar(arquivo)+"': ");
    if ( file_exists(arquivo) )
    { esc(45,24,2,"Ok");
        esc(3,25,3,"Tamanho:");
        i = (int)TamanhoArq(arquivo);
        gotoxy(12,25,6);
        printf("%i bytes.",i);
    }
    else esc(45,24,1,"NOK");
    
    switch ( XGMP ) {
        case 1: esc(44,19,3,"X"); break;
        case 2: esc(53,19,3,"X"); break;
    }

    i=33;
 
    esc(3,i+1,6,"Desenvolvido por Ivan Diesel. Componentes de GMP. CopyRight 2011 DIESEL.");
    esc(3,i+2,6,"           VERIFICAR O PRIMO: Calcular o primo e vem o resultado.");
    esc(3,i+3,6,"O grande numeros se refere a grandes inteiros positivo feito por software.");
    esc(3,i+4,6,"Essa sistema sao muitas vezes usam rapidos algoritmos de operacos muitos ");
    esc(3,i+5,6,"fornecem primitivos numeros teoricos, tais como a exponenciacao modular.");
    esc(3,i+6,6,"Premio de Primo: Site de EFF: https://www.eff.org/awards/coop");
    s = "";
    
    while ( s == "") s = resp(3,22,3,"Seleciona:");
    var = convertString(s);

    i = 0;
    while ( (i < lista) && (strcmp(var,nomes[i]) != 0) )
    {
       //cout << i << "(" << var << ")" << nomes[i] << endl;
       i++;
    }
      // cout << i << "(AAAA)"  << endl;
    if (i >= lista) {
        escolhe = 666;
    }
    //cout << i << "  " << var << endl;
    //pauses();
    switch ( i ) {
        case 1:  Mersenne(0);               break;
        case 2:  Mersenne(1);               break;
        case 3:  Mostra_numero(arquivo);    break;
        case 4:  Mersenne_Primo();          break;
        case 5:  Primo();                   break;
        case 6:  Mersenne(2);               break;
        case 7:  Fermat();                  break;
        case 8:  Goldbach();                break;
        case 9:  Gerar_Primo();             break;
        case 10: Proximo_Primo();           break;
        case 11: FWillians() ;              break;
        case 12: conta_NP();                break;
        case 13: FFatorial();               break;
        case 14: Riemann1();                break;
        case 15: Fprimo1();                 break;
        case 16: Lista_Mersenne_partit();          break;
        case 17: Verificar_Numero_Perfeito();      break;
        case 18: Lista_Numero_Perfeito();          break;
        case 19: Lista_Numero_Primo_P_NP();        break;
        case 21: tabela_cor();                     break;
        case 22: { cls(); escolhe=0; cout << "Obrigado por usar app. \n";gotoxy(1,2,7);};  break;
        case 23: { cls(); } ;                break;
        case 24: if (XGMP == 1) XGMP = 2; else XGMP = 1; break;
    }
    return escolhe;
}

int main(int argc, char *argv[])
{
    NUM_MERSENNE = "";
    while (!(capa() == 0) ) continue;
    //pauses();
    return EXIT_SUCCESS;
}

