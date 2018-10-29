
int Mersenne(int es)
 {
     int i;
   unsigned long int  digito;
   string x,y;      
   cls();
   borda(79,48);
   esc(22,2,1,"Primo de Mersenne");
   linha(3);
   esc(2,4,3,"               x");
   esc(2,5,3,"Formula:  M = 2  + y");
   linha(40);
     i=40;     
     esc(3,i+1,4,"Formula de MERSENNE:");
     esc(3,i+2,4,"Digita X so inteiro positivo. E Y so inteiro, pode positivo ou negativo.");
     esc(3,i+3,4,"Calcular e gravar o arquivo 'mersenne.txt'.");
     esc(3,i+4,4,"Apos, permite a pressionando o verificacao de primo.");
     esc(3,i+5,4,"Esse calculo feito por GMP componentes.");
     esc(3,i+6,4," ");
     esc(3,i+7,4,"Para sair, digite 'X' . ");
   x = resp(2,7,7,"x = "); if (x[0]=='x') return 0;
   y = resp(2,8,7,"y = "); if (y[0]=='x') return 0;
   linha(9);
   linha(32);
   esc(2,10,7,"Aguardo o calculo de Mersenne...");
   gotoxy(2,11,3); //cout << "->";
     
     if ( es == 1 )
     {
     NUM_MERSENNE = x;    
     arquivo = convertString("Mersenne"+ NUM_MERSENNE + ".txt");
     }
    digito = Cmersenne(x,y,es); //BIGNUMBER
    uTimeS2 = clock() - qTimeS;
     int coluna =4;
    for (int f=0;f<7;f++) esc(coluna,33+f,7,"                                                                   ");
    esc(coluna+2,34,7,"Total de ");   cout << digito << " digitos.";
    esc(coluna+2,35,7,"                                                             ");
    if ( es ==1 )
        {
            esc(coluna+2,34,2,"GRAVANDO!!! Arquivo: "+convertChar(arquivo));
            esc(coluna+2,35,7,"Total de ");   cout << TamanhoArq(arquivo) << " bytes do arquivo.";
        }
    gotoxy(coluna+2,36,6);
    cout<<"Tempo de Calculo : "<< uTimeS1 << " microsegundos. " << convertTime((unsigned long int)uTimeS1);
    gotoxy(coluna+2,37,6);
    cout<<"Tempo de Registro: "<< uTimeS2 << " microsegundos. " << convertTime((unsigned long int)uTimeS2);
    gotoxy(coluna+2,38,79);
    pauses();
    gotoxy(coluna+2,38,0);
 return 0;    
 }
void Proximo_Primo() {
    //  int primo;
    int i;
    string s,sf;
    unsigned long int  tam;
    clock_t     qTime;
    //uTime;
    i=7;
    tam = (unsigned long int)(pow(256,4));
    quadro(2,23,78,32);
    esc(2,23,14,"  Proximo o numero primo");
    gotoxy(40,23,11); cout << "Tamanho: " << tam << " numeros." ;
     s = resp(2,24,15,"  Comeco o numero primo ( n>3):");
    sf = resp(2,25,15,"  Quantos contagem do numero primo:");
    qTime = clock();
    proximo_primo(s,strtoint(sf)); 
    qTime = clock() - qTime;    
    esc(2,31,7,"--------------------------------------------------");
    gotoxy(2,30,5);
    cout <<"  Tempo : "<< qTime<< " microsegundos. " << convertTime((unsigned long int)qTime);
    gotoxy(2,32,7);
    pauses();       
    }
    
void Gerar_Primo(){
    //int primo;
    int i;
    string grande_primo;
    unsigned long int  fila, tam, pri, com, prip,err; //
    clock_t     qTime;
    //uTime;
    i=7;
    //subtam = (unsigned long int)(pow(256,sizeof(unsigned long int)));
    tam = (unsigned long int)pow(256,3); //sizeof(unsigned long int);
    esc(2,23,3,"   Gerar os numero primo");
    gotoxy(40,23,6); cout << "Tamanho: " << tam << " numeros.  " ;
    //esc(2,25,7,"   Os dados de primos esta carregado. Momento.         ");
    esc(2,24,7,"   Aguardo o momento de verificar.                   ");
    qTime = clock();
    pri=0; com=0; prip=0; err=0;
    for (fila = 2 ; fila <tam; fila++)
        {
        if ( fila == 2 || ( fila > 2 && fila % 2 != 0)) 
             {
               if (ehprimo_nat(fila) ) pri++; else com++;
             }
        if (fila % 10000 == 0 )
                 {
                   gotoxy(2,25,10); cout << "   Num:     " << fila << "        ";
                   gotoxy(2,26,10); cout << "   Primo:   " << pri << "        ";
                   gotoxy(2,27,10); cout << "   Composto:" << com << "        ";
                   cento(2,29,7,1,(int)((double)(fila) * 100 / (double)(tam))+1);
                 }
        } 

    cento(2,37,7,1,(int) (fila*100)/tam);

    qTime = clock() - qTime;
    //esc(45,29,10,"--> Ok");
    esc(2,30,15,"--------------------------------------------------------------");
    gotoxy(2,31,5);
    cout<<"  Tempo : "<< qTime<< " microsegundos. " << convertTime((unsigned long int)qTime);
    gotoxy(2,32,7);
    pauses();             
    
     }
int Primo() {
    int primo;
    int i;
    string s;
   // time_t rawtime;
    unsigned long int tamanhoMersenne;
    string x;
    string numeroMersenne, pedacoMersenne, pedacoMersenneEsquerdo, pedacoMersenneDireito;
    clock_t tempoInicio, tempoFinal, cronometro;
    //uTime;
   
    cls();
    borda(79,48);
    esc(16,2,3,"VERIFICACAO DO NUMERO PRIMO DE MERSENNE GRAVANDO");
    linha(3);
    linha(40);
    i=40;
    int cor = 4;
    esc(3,i+1,cor,"Formula de MERSENNE e Verificar o Numerio Primo:");
    esc(3,i+2,cor,"Digita X so inteiro positivo. E Y so inteiro, pode positivo ou negativo.");
    esc(3,i+3,cor,"Calcular e gravar o arquivo 'mersenne.txt'.");
    esc(3,i+4,cor,"Apos, o verificacao de primo e grava o arquivo 'Resultado_MPrimo.txt'.");
    esc(3,i+5,cor,"Esse calculo feito por GMP componentes.");
    esc(3,i+6,cor,"  ");
    esc(3,i+7,cor,"Para sair, digite 'X' . ");
    //x = resp(2,7,7," Numero de Mersenne? "); if (x[0]=='x') return 0;
    i=7;
    gotoxy(2,i,7); cout << "Arquivo: " << arquivo ;
    gotoxy(2,i+1,6); cout << "Tamanho: " << TamanhoArq(arquivo) << " digitos." ;
    esc(2,i+2,7,"Os dados de primos esta carregado. Momento.");
   
    if ( file_exists(arquivo) )
    {
      numeroMersenne = abrir(arquivo);
    
    
    tamanhoMersenne = numeroMersenne.length();
    esc(45,i+2,3,"Ok");
    if (tamanhoMersenne > 22) {
        pedacoMersenneEsquerdo = numeroMersenne.substr(0,10);
        pedacoMersenneDireito =  numeroMersenne.substr(tamanhoMersenne-10,10);
        pedacoMersenne = pedacoMersenneEsquerdo + ".." +pedacoMersenneDireito ;
    } else {
        pedacoMersenne = tamanhoMersenne;
    }
    gotoxy(2,i+3,6); cout << "Mersenne: " << pedacoMersenne;
    esc(2,i+4,1,"Tecla qualquer tecla para comecar a verificar o primo.");
    cin.ignore ();
   // resp(2, i+4, 1, "Tecla para comecar a verificar o primo.");
    esc(2,i+5,7,"Aguardo o momento de verificar.");
    tempoInicio = clock();
    primo = ehprimo(numeroMersenne);
    tempoFinal = clock();
    cronometro = tempoFinal - tempoInicio;
    
    esc(55,i+5,3,"Ok");
    esc(2,i+6,7,"---------------------------------------------------");
    esc(2,i+8,7,"Resultado:" );
    gotoxy(13,i+8,1);
    switch ( primo ) {
           case 0: cout << "Composto.";                       break;
           case 1: cout << "Primo Provavel.";                 break;
           case 2: cout << "Primo.";                          break;
           case 3: cout << "Error.";                          break;
           }
    gotoxy(2,i+10 ,3);
    cout<<"Tempo Inicial: "<< tempoInicio<< " microsegundos ou  " << convertTime((unsigned long int)tempoInicio);
    gotoxy(2,i+11 ,3);
    cout<<"Tempo Final: "<< tempoFinal<< " microsegundos ou " << convertTime((unsigned long int)tempoFinal);
    gotoxy(2,i+12,3);
    cout<<"Tempo Diferenca: "<< cronometro<< " microsegundos ou " << convertTime((unsigned long int)cronometro);
    
    {
        FILE *arquivo1;
        arquivo1 = fopen(arqResultado, "w");
        if (arquivo1!=NULL)
        { char *temp;
            fputs ("\n  VERIFICACAO DO NUMERO PRIMO DE MERSENNE GRAVANDO\n",arquivo1);
            fputs ("---------------------------------------------------\n\n",arquivo1);
            temp = convertString("Arquivo:" + convertChar(arquivo)+".\n\n");
            fputs (temp ,arquivo1);
            temp = convertString("Tamanho: " +inttostr(TamanhoArq(arquivo)) +" digitos.\n\n") ;
            fputs (temp,arquivo1);
            temp = convertString("Mersenne: " + pedacoMersenne +".\n\n") ;
            fputs (temp,arquivo1);
            fputs ("---------------------------------------------------\n\n",arquivo1);
            fputs ("Resultado:",arquivo1);
            switch ( primo ) {
                case 0: fputs ("Composto.\n\n",arquivo1);                       break;
                case 1: fputs ("Primo Provavel.\n\n",arquivo1);                 break;
                case 2: fputs ("Primo.\n\n",arquivo1);                          break;
                case 3: fputs ("Error.\n\n",arquivo1);                          break;
            }
            temp = convertString("Tempo Inicial: " + inttostr(tempoInicio) + " microsegundos ou  " + convertTime((unsigned long int)tempoInicio)+".\n\n");
            fputs (temp,arquivo1);
            temp = convertString("Tempo Final: " + inttostr(tempoFinal) + " microsegundos ou  " + convertTime((unsigned long int)tempoFinal)+".\n\n");
            fputs (temp,arquivo1);
            temp = convertString("Tempo Diferenca: " + inttostr(cronometro) + " microsegundos ou  " + convertTime((unsigned long int)cronometro)+".\n\n");
            fputs (temp,arquivo1);
            fputs ("---------------------------------------------------\n",arquivo1);
            fputs ("FIM DE LINHA\n",arquivo1);
            fclose (arquivo1);
        }
    
    }
    }
    gotoxy(2,32,7);
    pauses();             
    return 0;
     }
void gravar_resultado(string MER1,string MER2,unsigned long int MER3, string pedacoMersenne, string a,unsigned long int PRIMO,string b,string Ini_hor, string cronometro) {
     time_t rawtime;
     struct tm * timeinfo;
     time ( &rawtime );
     timeinfo = localtime ( &rawtime );
     string s,Fim_hor; 
     Fim_hor=ctime(&rawtime);
     FILE *arq;
     arq = fopen(convertString("Resultado_MPrimo"+MER1+".txt"), "w");
      if (arq!=NULL)
        {
     fputs ("Resultado de Mersenne e Verificacao de Numero Primo:\n",arq);
     fputs ("-----------------------------------------------------\n",arq);
     fputs (convertString("MERSENNE:        2^"+MER1+" +("+MER2+")\n"),arq);
     fputs (convertString("NUMERO MERSENNE: "+pedacoMersenne+"\n"),arq);
     fputs (convertString("TAMANHO:         "+inttostr(MER3)+" digitos.\n"),arq);
     fputs (convertString("CRONOMETRO:      "+a+".\n"),arq);
     fputs ("\n",arq);
     
     switch ( PRIMO ) {
           case 0: s="Composto.";                       break;
           case 1: s="Primo Provavel.";                 break;
           case 2: s="Primo.";                          break;
           case 3: s="Error.";                          break;
           }
     
     fputs (convertString("PRIMO:           "+s+"\n"),arq);
     fputs (convertString("TEMPO FINAL:     "+b+".\n"),arq);
     fputs ("\n",arq);
     Fim_hor=ctime(&rawtime);
     fputs (convertString("Inicial Horario: "+Ini_hor+".\n"),arq);
     fputs (convertString("  Final Horario: "+Fim_hor+".\n"),arq);
     fputs (convertString("Tempo Diferenca: "+cronometro+".\n"),arq);
     fputs ("-----------------------------------------------------\n",arq);
     
     }
    fclose (arq);
}
int Mersenne_Primo() {
   time_t rawtime; 
   string inicio_Horario, Final_Horario;   
   struct tm * timeinfo;
    int i;
    unsigned long int digito, tamanhoMersenne;
   int primo;
   string x,y; 
   string numeroMersenne;
    string pedacoMersenne, pedacoMersenneEsquerdo, pedacoMersenneDireito;
    clock_t  tempoInicial;
    clock_t  tempoFinal;
    clock_t  cronometro;
    
   cls();
   borda(79,48);
   esc(16,2,2,"Primo de Mersenne e Verificar o Primo com gravar");
   linha(3);
   esc(2,4,3,"               x");
   esc(2,5,3,"Formula:  M = 2  + y");
   linha(40);
     i=40;
    int cor = 4;
     esc(3,i+1,cor,"Formula de MERSENNE e Verificar o Numerio Primo:");
     esc(3,i+2,cor,"Digita X so inteiro positivo. E Y so inteiro, pode positivo ou negativo.");
     esc(3,i+3,cor,"Calcular e gravar o arquivo 'mersenne.txt'.");
     esc(3,i+4,cor,"Apos, o verificacao de primo e grava o arquivo 'Resultado_MPrimo.txt'.");
     esc(3,i+5,cor,"Esse calculo feito por GMP componentes.");
     esc(3,i+6,cor,"Record: 2^43.112.609 - 1 e 12.978.189 digitos (23/06/2008).");
     esc(3,i+7,cor,"Para sair, digite 'X' . ");
   x = resp(2,7,7,"x = "); if (x[0]=='x') return 0;
   y = resp(2,8,7,"y = "); if (y[0]=='x') return 0;
   for (int f=0;f<7;f++) esc(2,32+f,15,"                                                      ");
   linha(9);
   linha(32);
   time ( &rawtime );
   timeinfo = localtime ( &rawtime );     
   inicio_Horario=ctime(&rawtime);
   esc(2,10,3,"   Horario de Inicial: "+inicio_Horario);
   esc(2,11,6," 1) Aguardo o calculo de Mersenne...");
    esc(2,11,7," ------------------------------------------------------------");
    NUM_MERSENNE = x;
    arquivo = convertString("Mersenne"+ NUM_MERSENNE + ".txt");
    digito = Cmersenne(x,y,1);
    uTimeS2 = clock() - qTimeS;    
    esc(2,13,6," 2) Total de "+ inttostr(digito)+" digitos.");
    esc(2,14,6," 3) Total de " + inttostr( TamanhoArq(arquivo )) + " bytes do arquivo.");
    gotoxy(2,15,6);
    cout<<" 4) Tempo de Calculo : "<< uTimeS1 << " microsegundos. " << convertTime((unsigned long int)uTimeS1);
    gotoxy(2,16,6);
    cout<<" 5) Tempo de Registro: "<< uTimeS2 << " microsegundos. " << convertTime((unsigned long int)uTimeS2);
    esc(2,17,6," 6) Abrir um arquivo de Mersenne. Aguarde.");
    if( file_exists(arquivo))
    {
    numeroMersenne = abrir(arquivo);
    tamanhoMersenne = numeroMersenne.length();
    esc(45,17,3,"Ok");
    if (tamanhoMersenne > 22) {
        pedacoMersenneEsquerdo = numeroMersenne.substr(0,10);
        pedacoMersenneDireito =  numeroMersenne.substr(tamanhoMersenne-10,10);
        pedacoMersenne = pedacoMersenneEsquerdo + ".." +pedacoMersenneDireito ;
    } else {
        pedacoMersenne = tamanhoMersenne;
    }
    gotoxy(2,18,6); cout << " 7) Mersenne: " << pedacoMersenne;
   // gotoxy(2,19,7);
   // cout << "   8) Verificar se ha Numero Primo. Aguarde.";
    esc(2,19,1," 8) Tecla para comecar a verificar o primo.");
    cin.ignore ();
    tempoInicial = clock();
   
    primo = ehprimo(numeroMersenne);  // ******* GO PRIME!!!
    
    tempoFinal = clock();
    cronometro = tempoFinal - tempoInicial;
    esc(47,19,2,"Ok");
    esc(2,20,7," 9) Resultado: " );
    
    switch ( primo ) {
        case 0: {gotoxy(18,20,1); cout << "Composto.";                       break;}
        case 1: {gotoxy(18,20,3); cout << "Primo Provavel.";                 break;}
        case 2: {gotoxy(18,20,2); cout << "Primo.";                          break;}
        case 3: {gotoxy(18,20,1); cout << "Error.";                          break;}
           }
    gotoxy(2,21,6);
    cout<<"10) Tempo Inicial  : "<< tempoInicial<< " microsegundos. " << convertTime((unsigned long int)tempoInicial) << "\n";
    gotoxy(2,22,6);
    cout<<"11) Tempo Final    : "<< tempoFinal  << " microsegundos. " << convertTime((unsigned long int)tempoFinal) << "\n";
    gotoxy(2,23,6);
    cout<<"12) Tempo Diferenca: "<< cronometro  << " microsegundos. " << convertTime((unsigned long int)cronometro) << "\n";
    esc(2,24,2,"13) Gravar o resultado: Resultado_MPrimo"+x+".txt");
    gravar_resultado(x,y,digito,pedacoMersenne,convertTime((unsigned long int)uTimeS1),primo,convertTime((unsigned long int)tempoFinal),inicio_Horario,convertTime((unsigned long int)cronometro) );
    esc(58,24,2,"Ok");
    esc(2,26,6,"Fim de Relatorio.");
    
    time ( &rawtime );
    Final_Horario=ctime(&rawtime);
    esc(2,29,7,"   Horario de Final: "+Final_Horario);
    gotoxy(2,38,79);
    pauses();
    gotoxy(2,38,0);
    }
    return 0;
    
     }
void Indisponsivel() {
     esc(2,30,1,"Indisponsivel.");
     usleep(1000);
     } 
string GoldbachInteiro(unsigned long int i, int j)
{
// SEQUENCIA. Mais demora, i:numero par  f: quantidade de nyumero de Primo.   j: 0= contar. 1=equacoes.
   unsigned long int  d1, d2;
   string  s, s1;
   bool v;
   s1 = "";
   P1 = 0;
   d1 = 2;
   v = true;
   while (d1 < i) 
         {
          d2 = 2;
          while (d2 <= d1) 
                {
                 if ( (d1 + d2) == i )
                    {
                     if (j == 1 ) 
                        {
                         s = inttostr(d1) + " + " + inttostr(d2);
                         s1 = s1 + s + "; ";
                        }
                     P1++;
                    }
                 d2++;
                 while (!ehprimo1(d2)) d2++;
                 }
          if ( v ) 
             {
              d1++;
              while ( !ehprimo1(d1)) d1++;
             }
         }
   if (j == 0 ) s1 = inttostr(P1);
   
   return s1;
}     
string GoldbachPrecisao(unsigned long int i, int j)
{
// SEQUENCIA. Mais demora, i:numero par  f: quantidade de nyumero de Primo.
   unsigned long int  d1, d2;
   string  s, s1;
   bool v;
   s1 = "";
   P1 = 0;
   d1 = 2;
   v = true;
   while (d1 < i) 
         {
          d2 = 2;
          while (d2 <= d1) 
                {
                 if ( (d1 + d2) == i )
                    {
                     if (j == 1 ) 
                        {
                         s = inttostr(d1) + " + " + inttostr(d2);
                         s1 = s1 + s + "; ";
                        }
                     P1++;
                    }
                 d2++;
                 while (!ehprimo(inttostr(d2))) d2++;
                 }
          if ( v ) 
             {
              d1++;
              while ( !ehprimo(inttostr(d1))) d1++;
             }
         }
   if (j == 0 ) s1 = inttostr(P1);
   return s1;
}
int Goldbach()
 {
     int i;
     //digito;
   string x1,y1,escolhe;
   unsigned long int f,x,y, contar;
   cls();
   borda(79,48);
   esc(22,2,14,"Conjectura de Goldbach");
   linha(3);
   linha(40);
     i=40;     
     esc(3,i+1,6,"Todo numero par maior ou igual a 4 eh a soma de dois primos.");
     esc(3,i+2,6,"Por exemplo: 4 = 2 + 2; 6 = 3 + 3; 8 = 5 + 3; 10 = 3 + 7 = 5 + 5; etc.");
     esc(3,i+3,6,"Atualmente testando todos os numeros ate 10^18.");
     esc(3,i+4,6,"Digita Inicial x e Final x: numero somente pares.");
     esc(3,i+5,6,"OBjetivo: quais numeros pares nao encontra somar numero primo?");
     esc(3,i+6,6,"Esse calculo feito por GMP componentes.");
     esc(3,i+7,6,"Para sair, digite 'X' . ");
   escolhe =resp(2,  4,10,"1) digito Inteiro         2) Grande precisao     Qual? "); 
   if (escolhe[0]=='x') return 0; 
   x1 = resp(2,  5,10,"Inicio x = "); if (x1[0]=='x') return 0;
   y1 = resp(2,  6,10,"Final  x = "); if (y1[0]=='x') return 0;
   linha(9);
   linha(34);
    qTimeS = clock();
    x = strtoint(x1);
    y = strtoint(y1); 
    gotoxy(2,10,14);
     int linha =0;
     contar = 0;
     x1 = "";
     int opcao = 0;
    for (f = x; f<=y; f=f+2) {
    if ( escolhe[0] == '2') x1 = GoldbachPrecisao(f,opcao);
    if ( escolhe[0] == '1') x1 = GoldbachInteiro(f,opcao);
        if ( linha > 22) { linha = 0; }
            
    esc(2,11 + linha,1,"                                                                            .");
    gotoxy(2,11 + linha,7);
    cout << f << "=" << x1 << "   " << endl;
    cento(2,39,7,1,(int) (f*100)/y);
         linha ++;
       if ( strtoint(x1) == 0 )
       { contar++;
       esc(6,35,15,"Total de ");   cout << contar << " encontros: " << f << ".";
       }
    }


    uTimeS2 = clock() - qTimeS;  
    for (int f=0;f<3;f++) esc(4,35+f,15,"                                                           ");
    esc(6,35,15,"Total de ");   cout << contar << " encontros.";
    gotoxy(6,36,11);
    cout<<"Tempo de Registro: "<< uTimeS2 << " microsegundos. " << convertTime((unsigned long int)uTimeS2);
    gotoxy(6,37,79);
    pauses();
    gotoxy(6,38,0);
 return 0;    
 }      

int Fermat()
 {
     int i;
     unsigned long int digito;
   string x1,y1,z1,n1;
   string x2,y2,z2,n2;   
   cls();
   borda(79,48);
   esc(22,2,3,"Teorema de Fermat");
   linha(3);
   esc(13,4,1,"n"); esc(21,4,1,"n"); esc(29,4,1,"n");
   esc(2,5,7,"Formula:  X   +   Y   =   Z");
   esc(12,5,6,"X");esc(20,5,2,"Y");esc(28,5,3,"Z");
   linha(40);
     i=40;
     int cor = 4;
     esc(3,i+1,cor,"Ultimo Teorema de Fermat: inspirado nas equacoes diofantinas, e, certamente,");
     esc(3,i+2,cor,"o mais famoso. Nao ha solucao com x, y, z inteiros positivos e n inteiro,");
     esc(3,i+3,cor,"n>2 para essa formula. Vamos tentar a encontra algumas solucoes, basta o ");
     esc(3,i+4,cor,"Colocar os dados de: os dados n1 e n2 sao inicial e final, respectivamente,");
     esc(3,i+5,cor," e x, y e z sao numeros. E aguardamos os resultados por milagre.");
     esc(3,i+6,cor,"Esse calculo feito por GMP componentes.");
     esc(3,i+7,cor,"Para sair, digite 'X' . ");
   x1 = resp(2,  7,6,"Inicio x = "); if (x1[0]=='x') return 0;
   x2 = resp(2,  8,6,"Final  x = "); if (x2[0]=='x') return 0;
   y1 = resp(40, 7,2,"Inicio y = "); if (y1[0]=='x') return 0;
   y2 = resp(40, 8,2,"Final  y = "); if (y2[0]=='x') return 0;
   n1 = resp(40, 9,3,"Inicio n = "); if (n1[0]=='x') return 0;
   n2 = resp(40,10,3,"Final  n = "); if (n2[0]=='x') return 0;
   
   linha(11);
   linha(34);
   //esc(2,12,14,"Aguardo o possibilidade de Formula de Fermat..."); 
   //gotoxy(2,13,10); //cout << "->";   
    qTimeS = clock();
    digito = CFermat(x1,x2,y1,y2,n1,n2);
    uTimeS2 = clock() - qTimeS;  
    for (int f=0;f<3;f++) esc(1,35+f,7,"                                                                             ");
    esc(2,35,7,"Total de ");   cout << digito << " encontros.";
    //esc(2,35,15,"                                               ");
    //if ( es ==1 ) {esc(2,35,15,"Total de ");   cout << TamanhoArq(arquivo) << " bytes do arquivo."; }
    gotoxy(2,36,6);
    cout<<"Tempo de Registro: "<< uTimeS2 << " microsegundos. " << convertTime((unsigned long int)uTimeS2);
    gotoxy(2,37,7);
    pauses();
    gotoxy(2,38,0);             
 return 0;    
 } 

          
 unsigned long int Willians(unsigned long int n)
 {
  unsigned long int m,i,p;
  p = (unsigned long int)pow(2,n);
  i =0;
//  int c1 = 0;
//  int c2 = 0;
  if ( n>0 ) {
  double n1 = (double)1/n;
  double n2 = (double) n;       
  for (m=1; m <= p; m++) 
      {
       cento1(2,33,7,1,m,p);
       i = i + (unsigned long int) (pow( n2 / (1 + ii(m)), n1)  ); 
      }
}
  return  1 + i;       
  }
 int FWillians()
 {
    unsigned long int primo;
    int i;
    string s; 
     clock_t     qTime;
     //uTime;
    i=40;
    int cor =4;
    reta (2,1+i,78,7+i,0);
    esc(2,1+i,cor,"Formula de Willians");
    esc(2,2+i,cor,"Ja podemos examinar uma segunda formula para primos, devida a Willans. Ela:");
    esc(2,3+i,cor,"P(n) = 1 + E(m,1,2^n, |int(sqrt(n/(1+ii(m)),n))|)");
    esc(2,4+i,cor,"Onde: E ( variavel, inicio, final, formula) = Somatorio");
    esc(2,5+i,cor,"      ii(x)  = Contagem de numeros primos");
    esc(2,6+i,cor,"      int(x) = Arredonda um valor decimal para o valor inteiro ");
    esc(2,7+i,cor,"      | x |  = Modulo de x. ");
    i = 22;
    reta (2,1+i,78,11+i,0);
    s = resp(2,i+1,3,"Numero: ");
    esc(2,2+i,7,"Aguardo o momento de verificar.");
    qTime = clock();
    primo = Willians(strtoint(s));
    qTime = clock() - qTime;  
    esc(2,3+i,7,"------------------------------------------");
    esc(2,4+i,7,"Resultado:" );
    gotoxy(15,4+i,6);cout << "P(" << s << ") = " << primo ;
    gotoxy(2,6+i,6);
    cout<<"Tempo : "<< qTime<< " microsegundos. " << convertTime((unsigned long int)qTime);
    gotoxy(2,32,7);
    pauses(); 
     return 0;
     }
unsigned long int fatorial(unsigned long int n)
{
 int m,f;
 m=1;
 for (f = 2; f<=n; f++) m = m * f; 
 return m;
}
      
unsigned long int Minac(unsigned long int n)
 {
  unsigned long int i,i1;
  i =0;
  if ( n>0 ) { 
  for (i=2; i <= n; i++) 
      {
       cento1(2,33,7,1,i,n);
       i1 = fatorial(i-1);
       i = i + (unsigned long int)((i1+1)/i - (unsigned long int)(i1/i)); 
      }
}
  return  i;       
  }    
 int FFatorial()
 {  unsigned long int si;
    //int primo;
    int i;
    string s; 
     clock_t     qTime;
     //uTime;
    i=40;
    reta (2,1+i,78,7+i,0);
    esc(2,1+i,4,"Fatorial com alto precisao");
    esc(2,2+i,4,"Exemplo: 5! = 2.3.4.5 = 240. Precisao eh ate 2 bilhoes digitos.");
  
    i = 22;
    reta (2,1+i,78,11+i,0);
    s = resp(2,i+1,3,"Numero: ");
    esc(2,2+i,7,"Aguardo o momento de verificar.");
    esc(2,3+i,7,"------------------------------------------");
    esc(2,4+i,7,"Resultado:" );
    gotoxy(15,4+i,3);
     si = strtoint(s);
     qTime = clock();
    if ( si < 50 ) {
         color(10);
         cout << s << "! = ";
         si = gmp_fatorial(si);
         qTime = clock() - qTime;     
    gotoxy(2,6+i,6);
    cout<<"Tempo : "<< qTime<< " microsegundos. " << convertTime((unsigned long int)qTime);
    gotoxy(2,7+i,6);
    cout<<"Total "<< si<< " digitos. ";
    gotoxy(2,32,7);
    pauses(); 
         }
     else
     {
      cls();
      gotoxy(0,1,7); cout << s << "! = " << endl << endl;
      color(10);
      si = gmp_fatorial(si);
      qTime = clock() - qTime; 
      color(14);
      cout << endl << "------------------------------------------" <<endl;
      color(6);
      cout<<"Tempo : "<< qTime<< " microsegundos. " << convertTime((unsigned long int)qTime) << endl << si << " digitos." << endl;
      color(7);
      pauses();      
         }
    
     return 0;
     } 
unsigned long int pii(unsigned long int i) // contagem do primo.
{  
   unsigned long int B, g;
  if ( (i == 0) || (i == 1))
    { return 0; }
  else if ( i == 2 )
    { return 1; }
  else
  {
    g = 1;
    B = 3;
    while (B <= i) 
      {
      if ( ehprimo1(B) )  g++;
      B = B + 2;
      cento1(2,33,7,1,B,i);
      }
    return g;
  }
} 
int conta_NP() 
{
 unsigned long int primo;
    int i;
    string s; 
    clock_t     qTime;
    //uTime;
    i=40;
    reta (2,1+i,78,7+i,0);
    esc(2,1+i,4,"A funcao de conta NP");
    esc(2,2+i,4,"A funcao que conta os numeros primos ate um certo numero.");
    esc(2,3+i,4,"Eh semelhante de simbolo PI. Exemplo:");
    esc(2,4+i,4,"pi(1) = 0; pi(2) = 1; pi(17) = 7; pi(20) = 8; pi(29) = 10");
    esc(2,5+i,4,"A medida que os numeros aumentam, o deserto de primos aumenta cada vez mais.");
    i = 22;
    reta (2,1+i,78,11+i,0);
    s = resp(2,i+1,3,"pi(x)--> x: ");
    esc(2,2+i,6,"Aguardo o momento de verificar.");
    qTime = clock();
    primo = pii(strtoint(s));
    qTime = clock() - qTime;  
    esc(2,3+i,7,"------------------------------------------");
    esc(2,4+i,7,"Resultado:" );
    gotoxy(15,4+i,3);cout << "pi(" << s << ") = " << primo ;
    gotoxy(2,6+i,6);
    cout<<"Tempo : "<< qTime<< " microsegundos. " << convertTime((unsigned long int)qTime);
    gotoxy(2,31,7);
    pauses(); 
 return 0;   
}
string zeta(string a2,string a1)
{
 unsigned long int s1,k,j,g;
 double r1;
 r1 = 1;
 s1 = strtoint(a2);
 k=1;
 if (a1 == "1") 
 {
 for (j=0;j<100;j++) {
     cento1(2,33,7,1,j,100);
     for (g=1;g<100000;g++)
         {
         r1 = r1 + (1 / pow(k++,s1));            
         } 
 }
}
 if (a1 == "2") 
 {
 for (j=0;j<=100;j++) {
     cento1(2,33,7,1,j,100);
     for (g=1;g<100;g++)
         {
         r1 = r1 + (1 / fprimo(k++));            
         } 
     }
 }
 if (a1 == "3") // Produto 
 {
 for (j=0;j<=100;j++) {
     cento1(2,33,7,1,j,100);
     for (g=1;g<100;g++)
         {
         r1 = r1 * (1 / (1 - (1/pow(fprimo(k++),s1) )));            
         } 
     }
 } 
 if (a1 == "4") // Reciprocal
 {
 for (j=0;j<=100;j++) {
     cento1(2,33,7,1,j,100);
     for (g=1;g<100;g++)
         {
         r1 = r1 +( u(k)/ pow(k,s1) );
         k++;            
         } 
     }
 } 
  a2 = floattostr(r1);
  return a2;     
}

int Riemann1()
{
 string resultar;
    int i,j;
    string s1,s2; 
    clock_t     qTime;//uTime;
    i=40;
    reta (2,1+i,78,7+i,0);
    int cor = 4;
    esc(2,1+i,cor,"Funcao zeta de Riemann");
    esc(2,2+i,cor,"Eh uma funcao complexa de variavel complexa definida para Re(s)> 1 pela serie");
    esc(2,3+i,cor,"SS(s) = Somatorio(k,1,oo,k^-s)");
    esc(2,4+i,cor,"Onde somatorio (variavel, inicio, final, formula)");
    esc(2,5+i,cor,"Fora do conjunto dos numeros complexos com parte real maior do que a unidade");
    esc(2,6+i,cor,"a funcao de Riemann pode ser definida por continuacao analitica da expresao");
    esc(2,7+i,cor,"anterior. O resultado eh uma funcao meromorfa com um polo em s=1 de residuo 1");
    esc(40,1+i,3,"oo = 100000000 vezes ou seja 10^8 vezes.");
    i = 22;j=60;
    reta (2,1+i,78,11+i,0);
    esc(j,1+i,3,"1) Normal");
    esc(j,2+i,3,"2) Primo");
    esc(j,3+i,3,"3) Produto");
    esc(j,4+i,3,"4) Reciprocal");
    esc(j,5+i,3,"5) --");
    s1 = resp(j,6+i,7,"Escolhe: ");
    s2 = resp(2,i+1,3,"Zeta(s)--> s: ");
    esc(2,2+i,7,"Aguardo o momento de verificar.");
    qTime = clock();
    resultar = zeta(s2,s1);
    qTime = clock() - qTime;  
    esc(2,3+i,7,"------------------------------------------");
    esc(2,4+i,7,"Resultado:" );
    gotoxy(15,4+i,3);cout << "Zeta(" << s2 << ") = " << resultar ;
    gotoxy(2,6+i,6);
    cout<<"Tempo : "<< qTime<< " microsegundos. " << convertTime((unsigned long int)qTime);
    gotoxy(2,31,7);
    pauses(); 
 return 0;   
}
int Fprimo1()
{
 string resultar;
    int i,j;
    unsigned long int k;
    string s; 
    clock_t     qTime;
    //uTime;
    i=40;
    reta (2,1+i,78,7+i,0);
    int cor =4;
    esc(2,1+i,cor,"Funcao de Primo.");
    esc(2,2+i,cor,"Eh uma funcao complexa de variavel complexa definida para Re(s)> 1 pela serie");
    esc(2,3+i,cor,"SS(s) = Somatorio(k,1,oo,k^-s)");
    esc(2,4+i,cor,"Onde somatorio (variavel, inicio, final, formula)");
    esc(2,5+i,cor,"Fora do conjunto dos numeros complexos com parte real maior do que a unidade");
    esc(2,6+i,cor,"a funcao de Riemann pode ser definida por continuacao analitica da expresao");
    esc(2,7+i,cor,"anterior. O resultado eh uma funcao meromorfa com um polo em s=1 de residuo 1");
    esc(55,1+i,6,"oo = 100000000 vezes");
    i = 22;j=60;
    reta (2,1+i,78,11+i,0);
    s = resp(2,i+1,3,"Primo(x)--> x: ");
    esc(2,2+i,7,"Aguardo o momento de verificar.");
    qTime = clock();
    k = fprimo(strtoint(s));
    qTime = clock() - qTime;  
    esc(2,3+i,7,"------------------------------------------");
    esc(2,4+i,7,"Resultado:" );
    gotoxy(15,4+i,6);cout << "SS(" << s << ") = " << k ;
    gotoxy(2,6+i,6);
    cout<<"Tempo : "<< qTime<< " microsegundos. " << convertTime((unsigned long int)qTime);
    gotoxy(2,31,7);
    pauses(); 
 return 0;   
} 
bool Nperfeito(uint_fast64_t np) {
	uint_fast64_t soma = 0; 
	int rod=0;
	string roda = "/";
	for ( uint_fast64_t f = 1; f < np; f++)	
			{
				if ((np % f) == 0) { 
						soma = soma +f;
						esc(50,6,7,roda);
						if (rod >= 3) rod = 0; else rod = rod + 1;
	   							switch (rod) {
	   								case 0: roda = "|";break;
	   								case 1: roda = "/";break;
	   								case 2: roda = "-";break;
	   								case 3: roda = "\\";break;
	   							}
						}	
			}				
	if ( soma == np ) return true;
	return false;
}
bool Rperfeito(uint_fast64_t np) {
	uint_fast64_t soma = 0; 
	uint_fast64_t np2 = (uint_fast64_t)(np / 2 + 1);
	uint_fast64_t np3 = (uint_fast64_t)(np / 3 + 1); 
 //	uint_fast64_t np4 = (uint_fast64_t)(np / 4 + 1);
	int rod=0;
	string roda = "/";
	for ( uint_fast64_t f = 1; f < np2; f++)	
			{
				if (f == np3) f = (uint_fast64_t)( np/2 );
				if ((np % f) == 0) { 
						soma = soma +f;
						esc(50,6,7,roda);
						if (rod >= 3) rod = 0; else rod = rod + 1;
	   							switch (rod) {
	   								case 0: roda = "|";break;
	   								case 1: roda = "/";break;
	   								case 2: roda = "-";break;
	   								case 3: roda = "\\";break;
	   							}
						}	
			}				
	if ( soma == np ) return true;
	return false;
}
void Cperfeito(uint_fast64_t np) {
	uint_fast64_t npp = 0; 
	//int rod=0;
	npp = (uint_fast64_t)(np / 2 + 1);
	string roda = "/";
	for ( uint_fast64_t f = 1; f < npp; f++)	
			{
				cout << f<<"="<< (np % f) << "," ;
			}			
}
int Verificar_Numero_Perfeito() {
	 uint_fast64_t xi,xf,quant,ca,cb, perf;
    int i,rod;
    unsigned long int es1;
	 //bool per;
	 string x1,x2,mm,es, roda;
	// HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
    clock_t     qTime;
    //uTime;
	cls();
  // res_primo="";
   borda(79,48);
   esc(5,2,3," Verificacao de Numeros Perfeitos - Tentar quantos numeros existem.");
   linha(3);
   linha(40);
     i=40;     
     esc(2,i+1,4,"um numero perfeito e um numero inteiro para o qual a soma de todos os seus ");
	 esc(2,i+2,4,"divisores positivos proprios (excluindo ele mesmo) Eh igual ao proprio numero.");
     esc(3,i+3,4,"Escolhe 1 ou 2. Digita X1 e X2, somente o inteiro positivo.");
     esc(3,i+4,4,"Esse calculo feito por caseiro.");
     esc(3,i+5,4,"Para sair, digite 'X' . ");
     es  = resp(2,5,7,"Escolhe: 1) LOOP NATURAL  2) LOOP FORMULA 3)LOOP FORM GMP:"); if (x1[0]=='x') return 0;
	 x1 = resp(2,7,7,"x Inicio= "); if ((x1[0]=='0') || (x1[0]=='x')) return 0;
	 x2 = resp(30,7,7,"x Final = "); if (x2[0]=='x') return 0;
	 linha(7);
	 esc(3,8,2,"Quantidade  n      Tempo                               Numeros Perfeito");
	 esc(3,9,3,"---------------------------------------------------------------------------");
	 xi = strtoint64(x1);
     xf = strtoint64(x2);
     es1 = strtoint64(es);
	 cb=0;ca=0;
     quant = 0; rod = 0;roda = "/";
     cout << "\n";esc(2,5,3,"[..........................................................................]");
	 qTime = clock();
	 switch ( es1) {
	 case 1 :
     {
	 for (uint_fast64_t f=xi;f<=xf;f++)
	    { qTime = clock();
	   	 if ( Nperfeito(f)) {
	   	 						quant = quant + 1;
	   	 						qTime = clock() - qTime; 
								esc(3,9+(int)quant,7, tab(5,inttostr(quant))+
								                  tab(15,convertTime((unsigned long int)qTime))+
								                  tab(54,inttostr(f)) + " \n"); 		
								
	   						} else
	   						{  ca = (int)( (74 * f) / xf);
	   							esc(3 + (int)ca,5,7,roda);
								if ( ca > cb) {
										cb = ca;
										esc(2 +(int)ca,5,12,"#");
								}
								esc(2,6,3,inttostr(f));
	   							if (rod >= 3) rod = 0; else rod = rod + 1;
	   							switch (rod) {
	   								case 0: roda = "|";break;
	   								case 1: roda = "/";break;
	   								case 2: roda = "-";break;
	   								case 3: roda = "\\";break;
	   							}
	   						}
	   }} break; 
	   case 2:{
	   for (uint_fast64_t f=xi;f<=xf;f++)
	    { qTime = clock();
		  perf = pow(2,f-1)*(pow(2,f)-1);
	   	 if ( Rperfeito(perf)) {
	   	 						quant = quant + 1;
	   	 						qTime = clock() - qTime; 
								esc(3,9+(int)quant,7, tab(4,inttostr(quant))+
												  tab(4,inttostr(f))+
								                  tab(15,convertTime((unsigned long int)qTime))+
								                  tab(50,inttostr(perf)) + " \n"); 		
								
	   						} else
	   						{  ca = (int)( (74 * f) / xf);
	   							esc(3 + (int)ca,5,7,roda);
								if ( ca > cb) {
										cb = ca;
										esc(2 + (int)ca,5,1,"#");
								}
								esc(2,6,3,inttostr(f));
	   							if (rod >= 3) rod = 0; else rod = rod + 1;
	   							switch (rod) {
	   								case 0: roda = "|";break;
	   								case 1: roda = "/";break;
	   								case 2: roda = "-";break;
	   								case 3: roda = "\\";break;
	   							}
	   						}
	   }
		} break;
		case 3: {
				uint_fast64_t f=xi;
				 while (f<=xf)
	    			{ qTime = clock();
	    			  esc(2,6,3,inttostr(f));
					  mm = perfeito(f);
					  esc(1,9+(int)f,7, "A"+inttostr(f)+"="+mm);
	    			  if ( GMP_Perfeito1(mm)) 
					  {
	   	 						quant = quant + 1;
	   	 						qTime = clock() - qTime; 
								esc(5,9+(int)f,7, tab(4,inttostr(quant))+
												  tab(4,inttostr(f))+
								                  tab(15,convertTime((unsigned long int)qTime))+
								                  tab(50,mm) + " \n"); 		
								
	   						} else
	   						{  ca = (int)( (74 * f) / xf);
	   							esc(3 + (int)ca,5,7,roda);
								if ( ca > cb) {
										cb = ca;
										esc(2 + (int)ca,5,1,"#");
								}
								//esc(2,6,14,inttostr(f));
	   							if (rod >= 3) rod = 0; else rod = rod + 1;
	   							switch (rod) {
	   								case 0: roda = "|";break;
	   								case 1: roda = "/";break;
	   								case 2: roda = "-";break;
	   								case 3: roda = "\\";break;
	   							}
	   						} 
					f = proximo_primo(f);
				} 
	}break;
	}
	 gotoxy(2,4,7);
     pauses();
    return 0;
}
int Lista_Numero_Perfeito() {
	 uint64_t xi,xf,quant,n, perf;
	 int i,rod,ca,cb;
	 string x1,x2,mm, roda;
	// HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
    clock_t     qTime;
    //uTime;
	cls();
  // res_primo="";
   borda(79,48);
   esc(5,2,3," Lista de Numeros Perfeitos - Formula.");
   linha(3);
   linha(40);
     i=40;     
     esc(2,i+1,4," A proposta de formula de Euclides de numero perfeito: 2^(n-1)(2^n-1).");
	 esc(2,i+2,4,"Escolhe 1 ou 2 para permite calcular loop normal e formula respectivamente.");
     esc(3,i+3,4,"Digita X1 e X2, somente o inteiro positivo.");
     esc(3,i+4,4,"Esse calculo feito por caseiro.");
     esc(3,i+5,4,"Para sair, digite 'X' . ");
	 x1 = resp(2,7,7,"x Inicio= "); if (x1[0]=='x') return 0;
	 x2 = resp(30,7,7,"x Final = "); if (x2[0]=='x') return 0;
	 linha(7);
	 esc(3,8,2,"Quantidade        Tempo                               Numeros Perfeitos");
	 esc(3,9,3,"---------------------------------------------------------------------------");
	 xi = strtoint64(x1);
     xf = strtoint64(x2);
	 cb=0;ca=0;
     quant = 1; rod = 0;roda = "/";
     cout << "\n";esc(2,5,3,"[..........................................................................]");
	 qTime = clock();
	 for (n=xi;n<=xf;n++)
	   { perf = pow(2,n-1)*(pow(2,n)-1);
	   	 
	   	 qTime = clock() - qTime; 
		 esc(3,9+(int)quant,7, tab(5,inttostr(quant))+tab(16,convertTime((unsigned long int)qTime))+tab(50,inttostr(perf)) + ": \n");
	   	// Cperfeito(perf);
	   	
	   	 if ( Nperfeito(perf)) 
			{
				esc(75,9+(int)quant,2,"Ok");
				
	   		 } 
			else
			 {
			 esc(75,9+(int)quant,1,"NOk");
	   	 	}
	   	 	quant = quant + 1;
		 ca = (int)( (74 * n) / xf);
	   	 esc(3 + ca,5,7,roda);
		 if ( ca > cb) { cb = ca;
						 esc(2 + ca,5,12,"#");	
						}
		 esc(2,6,14,inttostr(n));
	   	 if (rod >= 3) rod = 0; else rod = rod + 1;
	   	 switch (rod) {
	   		case 0: roda = "|";break;
	   		case 1: roda = "/";break;
	   		case 2: roda = "-";break;
	   		case 3: roda = "\\";break;
	   		}
	   	}
	   
	 gotoxy(2,31,7);
     pauses();
    return 0;
}
int Lista_Numero_Primo_P_NP() {
	 uint64_t xi,xf,quant,n,bug,ok;
	 int i,rod,ca,cb,bx,by;
	 bool a,b;
	 string x1,x2,mm, roda;
	// HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
    clock_t     qTime;
    //uTime;
	cls();
  // res_primo="";
   borda(79,48);
   esc(5,2,3," Lista de Numeros Primos P=NP - Formula.");
   linha(3);
   linha(40);
     i=40;     
     esc(2,i+1,4," A proposta de formula de Numero Primo sem Loop baseado em P=NP.");
     esc(3,i+2,4,"Digita X1 e X2, somente o inteiro positivo.");
     esc(3,i+3,4,"Esse calculo feito por formula: y=a^(x-1) mod x.");
     esc(3,i+4,4,"Para sair, digite 'X' . ");
	 x1 = resp( 2,7,7,"x Inicio= "); if (x1[0]=='x') return 0;
	 x2 = resp(30,7,7,"x Final = "); if (x2[0]=='x') return 0;
	 linha(7);
	
	 xi = strtoint64(x1);
     xf = strtoint64(x2);
	 cb=0;ca=0;
     quant = 1; 
	 rod = 0;
	 roda = "/";
	 ok = 0 ;
	 bug = 0;
	 bx=by=0;
     cout << "\n";esc(2,5,3,"[..........................................................................]");
     esc(3,8,3,"NUM");
	 esc(33,8,2,"PRIMO");
     esc(53,8,1,"BUG");
     esc(3,9,3,"Lista de numero de BUG - ERRO DE CALULCAR PRIMO");
	 qTime = clock();
	 for (n=xi;n<=xf;n++)
	   {  
	   	 qTime = clock() - qTime; 
		// esc(3,9+quant,15, tab(5,inttostr(quant))+tab(16,convertTime(qTime))+tab(50,inttostr(perf)) + ": \n"); 		
	   	// Cperfeito(perf);
	   	 a = ehprimo_PNP("2",inttostr(n)); // P=NP
	   	 b = ehprimo(inttostr(n)); // Primo GMP
	   	 if (a ) 
			 {
			    ok = ok + 1;
	   		 } 
		if (a != b)
			 {
			    bug = bug + 1;	
			    esc(60,8,1,inttostr(bug));
			    esc(3+bx*10,10+by,2,inttostr(n));
			    esc(3+bx*10,10+by+1,2,"--");
			    if (by>27) { by=-1; bx = bx+1; if (bx>8) bx=0;}
			    by = by +1;
	   	 	}
	   	quant = quant + 1;
	   		esc(10,8,3,inttostr(quant));
            esc(40,8,3,inttostr(ok));
            
            
		 ca = (int)( (74 * n) / xf);
	   	 esc(3 + ca,5,7,roda);
		 if ( ca > cb) { cb = ca;
						 esc(2 + ca,5,1,"#");
						}
		 esc(2,6,3,inttostr(n));
	   	 if (rod >= 3) rod = 0; else rod = rod + 1;
	   	 switch (rod) {
	   		case 0: roda = "|";break;
	   		case 1: roda = "/";break;
	   		case 2: roda = "-";break;
	   		case 3: roda = "\\";break;
	   		}
	   
	   	}
	   
	 gotoxy(2,39,7);
     pauses();
    return 0;
}
int Lista_Mersenne_partit() {
    time_t rawtime; 
   string inicio_Horario, Final_Horario, mm;   
   struct tm * timeinfo;
    int i,xi,xf,cor;
    unsigned long int digito;
   int primo, Nprimos, Nprimos_Provavel;
   string x,x1,y,res_primo; 
   string grande_primo;
    clock_t     qTime;
    //uTime;
   FILE *arq;
   //HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
cls();
   res_primo="";
   borda(79,48);
   esc(5,2,3," Lista de Mersenne e Tentar a verificar o Primo com gravar e resultado");
   linha(3);
   esc(2,4,3,"               x");
   esc(2,5,3,"Formula:  M = 2  + y");
   linha(40);
     i=40;     
     esc(3,i+1,4,"Formula de MERSENNE e Verificar o Numerio Primo:");
     esc(3,i+2,4,"Digita X so inteiro positivo. E Y so inteiro, pode positivo ou negativo.");
     esc(3,i+3,4,"Calcular e gravar o arquivo 'mersenne.txt'.");
     esc(3,i+4,4,"Apos, o verificacao de primo e grava o arquivo 'Resultado_MPrimo.txt'.");
     esc(3,i+5,4,"Esse calculo feito por GMP componentes.");
     esc(3,i+6,4,"Record: 2^43.112.609 - 1 e 12.978.189 digitos (23/06/2008).");
     esc(3,i+7,4,"Para sair, digite 'X' . ");
   x  = resp(2,7,7,"x Inicio= "); if (x[0]=='x') return 0;
   x1 = resp(30,7,7,"x Final = "); if (x1[0]=='x') return 0;
   y  = resp(2,8,7,"y = "); if (y[0]=='x') return 0;
   Nprimos_Provavel=0;
   Nprimos=0;
   for (int f=0;f<7;f++) esc(1,33+f,7,"                                                      ");
   linha(9);
   linha(32);
    cls();
    arq = fopen("Lista_Mersenne.txt", "w");
               
   mm="  TABELA DE TENTATIVA DE PRIMO DE MERSENNE: 2^M+("+y+")\n";
   fputs (convertString(mm),arq);
   esc(2,1,3,mm);
   mm="----------------------------------------------------------------------------\n";
   fputs (convertString(mm),arq); esc(1,2,2,mm);
   mm="       Mersenne        Digitos     Tempo cal.        Primo?      Tempo Final\n";
   fputs (convertString(mm),arq); esc(0,3,3,mm);
   gotoxy(0,4,3);
   xi = (int)strtoint(x);
   xf = (int)strtoint(x1);
  
   for (i = xi; i <= xf; i++)
       {
   time ( &rawtime );
   timeinfo = localtime ( &rawtime );     
   inicio_Horario=ctime (&rawtime);
   //esc(2,11,11,"1) Aguardo o calculo de Mersenne..."); 
    x = inttostr(i);
    digito = Cmersenne(x,y,1);
    uTimeS2 = clock() - qTimeS;
    if( file_exists(arquivo))
    {
    grande_primo = abrir(arquivo);
    qTime = clock();    
    primo = ehprimo(grande_primo);
    qTime = clock() - qTime; 
           cor = 11;
           switch ( primo ) {
           case 0: { res_primo =  "Composto.";       cor=7;                             break; }
           case 1: { res_primo =  "Primo Provavel."; cor=3; Nprimos_Provavel++;         break; }
           case 2: { res_primo =  "Primo.";          cor=2; Nprimos++;                  break; }
           case 3: { res_primo =  "Error.";          cor=1;                             break; }
           }
   mm=tab(15,x)+tab(15,inttostr(digito))+tab(13,inttostr(uTimeS1))+"ms "+tab(15,res_primo)+tab(13,convertTime((unsigned long int)qTime))+"\n";
   fputs (convertString(mm),arq);
   color(cor);
   //cout << tab(15,x) << tab(15,inttostr(digito)) << tab(13,inttostr(uTimeS1)) << "ms " << tab(15,res_primo) << tab(13,convertTime(qTime))<< "\n"; 
   cout << mm; 
    }
    mm=" ----------------------------------------------------------------------------\n"; 
   fputs (convertString(mm),arq);
    color(3);
    cout << mm;
    mm="TOTAL:    "+inttostr(Nprimos)+" primos e "+inttostr(Nprimos_Provavel)+" primos provaveis \n"; 
    fputs (convertString(mm),arq);
    color(2);
    cout << mm;
    color(3);
    cout << " Ok \n";
    cout << " Fim de Relatorio. \n";
    time ( &rawtime );
    Final_Horario=ctime(&rawtime);
    mm="Horario de Final: "+Final_Horario+"\n"; 
    fputs (convertString(mm),arq);
    cout << mm;
      fclose (arq);
    color(15);
       }
    pauses();
    color(3);
    return 0;
     }
