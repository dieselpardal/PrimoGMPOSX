

unsigned long int gmp_fatorial ( unsigned long int i) // Fatorial GMP.
{
  unsigned long int cla;
  mpz_t n;
  mpz_init (n);
     mpz_fac_ui (n, i);			   // n = fatorial (i)	
     mpz_out_str (stdout, 10, n);  // escrever N.
     cla = mpz_sizeinbase( n, 10); // tamanho de algerismo.
  mpz_clear (n);   
  return cla;
}

int ehprimo ( string s) // verificar primo COM precisao GMP. 
{
  char *av;
  mpz_t n;
  int i;
  mpz_init (n);
  int cla = 0;
 av = (char*) malloc (1100000000);// 1,1 BILHOES DIGITOS! 
 //av = "18446744073709551557";
 for ( i=0;i<s.size(); i++ )  av[i]=s[i];
  if (mpz_set_str (n, av, 0) != 0) cla = 3;
  if (cla !=3 ) {
     cla = mpz_probab_prime_p (n, 5);
     //mpz_out_str (stdout, 10, n);
     }
  mpz_clear (n);
  free(av);
  return cla;
  	/* 0 =  is composite;
  	   1 =  is a probable prime;
       2 =  is a prime;
       3 = error.
    */
}

unsigned long int proximo_primo(string s, unsigned long int f) // verificar primo COM precisao GMP. 
{
  char *av;
  mpz_t n;
  unsigned long int  i;
  mpz_init (n);
  int cla = 0;
    
  av = (char*) malloc (1100000000);// 1,1 BILHOES DIGITOS!
 //av = (char * ) s;
  //for ( i=0;i<s.size(); i++ ) 
  for ( i=0;i<s.size(); i++ )  av[i]=s[i];
  if (mpz_set_str (n, av, 0) != 0) cla = 3;
  if (cla !=3 ) {
      cout << "AAAAAA  " << f << " = ";
     //g = (unsigned long int )(f / 100);
     for (i=1; i<f; i++) {
     //mpz_nextprime(n,n);
         
     cout << "  " << i << " = ";
     if (i % 1 == 0 )
        {
         //gotoxy(2,26,10); mpz_out_str (stdout, 10, n);
         cento(2,27,7,1,(int)((double)(i) * 100 / (double)(f))+1);
        }
     }
     }
  free(av);
  mpz_clear (n);
  return cla;
   
}

int Primo2( char *teste)
{ 
  unsigned long p, i;
  mpz_t pp, ll, aux;

  mpz_init(pp);
  mpz_init(ll);
  mpz_init(aux);
     /* Inicializamos as variáveis pp, ll e aux. */

  p = atol(teste); /* Lemos p. */

  mpz_set_ui(ll,(long)(4));
  mpz_ui_pow_ui(aux,(long)(2),p);
  mpz_sub_ui(pp,aux,(long)(1)); 
             /* Calculamos pp = Mp. */
  
  for ( i = 1 ; i + 2 <= p ; i++ )
  {
    mpz_powm_ui(aux,ll,(long)(2),pp); /* Elevamos ll ao quadrado modulo pp... */
    mpz_sub_ui(ll,aux,(long)(2));     /* ... e subtraimos 2, para calcular s(p-2) modulo Mp. */
  }

  if ( mpz_sgn(ll) == 0 )
  { printf("M%ld eh primo.\n",p); }
  else
  { printf("M%ld eh composto.\n",p); }
                     /* Imprimimos as conclusões. */

  return(0);
}


bool ehprimo_PNP ( string a1,string x1) // verificar primo COM precisao GMP. s = numero de PRIMO.
{
 //const char * string_a = a1.c_str();
 const char * string_x = x1.c_str(); 
 unsigned long int p;
 bool V = false;
 int i;
// string um1 = "1";
  mpz_t a;
  mpz_t r; 
  mpz_t n;  
  mpz_t xx;
  p = atol(string_x);
  mpz_init (a);
  mpz_init (n);
  mpz_init (r);
  mpz_init (xx);
    int cla = 0;
  char *av;
  av = (char*) malloc (110000000);// 0,1 BILHOES DIGITOS! 
  for ( i=0;i<a1.size(); i++ )  av[i]=a1[i];
  if (mpz_set_str (a, av, 0) != 0) cla = 3;
  
 // av = (char*) malloc (110000000);// 0,1 BILHOES DIGITOS! 
  for ( i=0;i<x1.size(); i++ )  av[i]=x1[i];
  if (mpz_set_str (n, av, 0) != 0) cla = 3;
  
  free(av);
  
  if (cla !=3 ) 
      {
      mpz_pow_ui (r, a, p - 1 ); // r = a ^ (p-1);
      mpz_mod (xx, r, n);  // PTR = SRC MOD SRC  // r = r mod n;
      if ( mpz_cmp_ui( xx,1) == 0 ) V = true; 
      //gotoxy(40,10+p,15); mpz_out_str (stdout, 10, n);
	 // gotoxy(50,10+p,15); mpz_out_str (stdout, 10, xx);
	 // gotoxy(60,10+p,15); mpz_out_str (stdout, 10, r); 
      }
mpz_clear (xx); 
mpz_clear (n);
mpz_clear (r);
mpz_clear (a);
return V; 
}
unsigned long int Cmersenne(string x, string y, int es)
 {
     
  unsigned long int cla;
  const char * avy = y.c_str();
  const char * B2 = "2";
  unsigned long int exp; // 4.294.967.295
           long int col; // -2.294.967.295 to 2.294.967.295
  const char * string_convertida = x.c_str();
  const char * string_convertida1 = y.c_str();
  
  FILE *arq;
  exp = atol(string_convertida);
  col = atol(string_convertida1);
  mpz_t n;
  mpz_t m;
  mpz_t u;  
  mpz_init (n);
  mpz_init (m);
  mpz_init (u);
  cla= -1;
  if (mpz_set_str (n, B2, 0) != 0) cla = 0; // n = converter de B2
  if (cla == 0 && mpz_set_str (u, avy, 0) != 0) cla = 0;
  if (cla !=0 ) {
     qTimeS = clock();
     //##############################
      mpz_pow_ui (m, n, exp); // m = n ^ exp;
     if (col<0 ) 
     {
        col = -col;
        mpz_sub_ui (m, m, col); // m = m - col;
     }
       else
      { 
        mpz_add_ui (m, m, col); 
      }
     //##########################     
      cla = mpz_sizeinbase( m, 10);
     uTimeS1 = clock() - qTimeS; 
     qTimeS = clock();
     switch (es) { 
            case 0:{
               mpz_out_str (stdout, 10, m); break;          
               } 
            case 1:{       
               //esc(2,12,15,"Gravar o arquivo: mersenne.txt");
               arq = fopen(arquivo , "w");
               mpz_out_str (arq, 10, m);
               fclose (arq);break;
              }
            case 2:{
                     cout << "Sem mostrar.";
                   }  
          }
     }
mpz_clear (n);
mpz_clear (m);
mpz_clear (u); 
  return cla;                   
 }
string perfeito ( unsigned long int n) {   // Formula de Perfeito = (2^ (n-1)) ( 2^n - 1)
  char *av;
  unsigned long int m;
  m = n - 1;
  string s = "100";
  mpz_t sum1,sum2,a2;
  mpz_init (sum1);
  mpz_init (sum2);
  mpz_init (a2);
  mpz_set_ui(a2,2); // a2 = 2
  mpz_pow_ui(sum1,a2,m); // sum1 = a2 ^ (n-1)
  mpz_pow_ui(sum2,a2,n);  //  sum2 = a^n
  mpz_sub_ui(sum2,sum2,1); // sum2 = sum2 - 1;
  mpz_mul(sum1,sum1,sum2); // sum1 = sum1 * sum2
   av = (char*) malloc (1100000000);// 1,1 BILHOES DIGITOS!
   mpz_get_str (av, 10, sum1);
   s = convertChar(av);
   free(av);
   mpz_clear (sum1);
   mpz_clear (sum2);
   mpz_clear (a2);
   
  return s;	
}

bool GMP_Perfeito ( string s) // verificar Numero Perfeito com GMP.  INVERSAO
{
	string roda = "/";
    bool V = false;
    char *av;
    int i;
    int cla = 0;
  mpz_t np,ff,moe,soma,x; 
  mpz_init (np);
  mpz_init (ff);
  mpz_init (moe);
  mpz_init (soma);
  mpz_init (x);
 // mpz_init (y);
  av = (char*) malloc (1100000000);// 1,1 BILHOES DIGITOS! 
  for ( i=0;i<s.size(); i++ )  av[i]=s[i];
  if (mpz_set_str (np, av, 0) != 0) cla = 3;
  if (cla !=3 ) { 
	 //mpz_set_ui(ff,1);
	 mpz_cdiv_q_ui(ff,np,2);
	 mpz_add_ui(ff,ff,1);
	 //mpz_sub_ui(ff,np,1);
	 mpz_set_ui(soma,0);
	 while ( mpz_cmp_si( ff,0) > 0) { // ff < np -> -1; ff = np -> 0; ff > np -> +1 
	 								 mpz_mod(moe,np,ff);
									 if(  (mpz_cmp_ui( moe,0) == 0) )	
									 	{
									 		mpz_add(soma,soma,ff);
											mpz_mul_ui(x,soma,100);
											mpz_cdiv_q(x,x,np); 
											gotoxy(50,6,15); mpz_out_str (stdout, 10, x);
	   										cout << "%    ";
									 	}
									 mpz_sub_ui(ff,ff,1);
	 							  }						
	 } 
   if ( mpz_cmp( soma,np) == 0 ) V = true;
   mpz_clear(np);
   mpz_clear(ff);
   mpz_clear(moe);
   mpz_clear(soma);
   mpz_clear(x);
   //mpz_clear(y);
   free(av);
  return V;
}

bool GMP_Perfeito1 ( string s) // verificar Numero Perfeito com GMP. NORMAL
{
  if (s == "1" ) return true;

  string roda = "/";
  bool V = false;
  char *av; 
    int i;
    int cla = 0;
  mpz_t np,ff,moe,soma,x,np2,np3; 
  mpz_init (np);
  mpz_init (ff);
  mpz_init (moe);
  mpz_init (soma);
  mpz_init (x);
  mpz_init (np2);
  mpz_init (np3);
 // mpz_init (y);
  av = (char*) malloc (1100000000);// 1,1 BILHOES DIGITOS! 
  for ( i=0;i<s.size(); i++ )  av[i]=s[i];
  if (mpz_set_str (np, av, 0) != 0) cla = 3;
  if (cla !=3 ) { 
	 mpz_set_ui(ff,1); // ff = 1;
	 mpz_cdiv_q_ui(np2,np,2); // np2 = np / 2;	
	 mpz_add_ui(np2,np2,1); // np2 = np2 + 1;
	 mpz_cdiv_q_ui(np3,np,3);	
	 mpz_add_ui(np3,np3,1);
	 mpz_set_ui(soma,0);
	 while ( mpz_cmp( ff,np2) < 0) {
	 								 
									 mpz_mod(moe,np,ff);
									 if(mpz_cmp_ui( moe,0) == 0 )	
									 	{
											mpz_add(soma,soma,ff);
											mpz_mul_ui(x,soma,100);
											mpz_cdiv_q(x,x,np); 
											gotoxy(50,6,15); mpz_out_str (stdout, 10, x);
	   										cout << "%    ";
	   										mpz_add_ui(x,ff,1);
											if (mpz_cmp( x,np3) == 0 ) 
												{
												esc(60,6,15,"AAA:" + s);	
												mpz_cdiv_q_ui(ff,np,2);	
												}
	   										
									 	}
									 mpz_add_ui(ff,ff,1);
	 							  }						
	 } 
   if ( mpz_cmp( soma,np) == 0 ) V = true;
   mpz_clear(np);
   mpz_clear(ff);
   mpz_clear(moe);
   mpz_clear(soma);
   mpz_clear(x);
   mpz_clear(np2);
   mpz_clear(np3);
   //mpz_clear(y);
   free(av);
  return V;
}

long int CFermat(string x1,string x2,string y1,string y2,string n1,string n2)
{
 //int Cmersenne(string x, string y, int es)
    unsigned long int cla;
  const char * cx1 = x1.c_str();
  const char * cx2 = x2.c_str();
  const char * cy1 = y1.c_str();
  const char * cy2 = y2.c_str();
  const char * cn1 = n1.c_str();
  const char * cn2 = n2.c_str();
  string s; 
  long int nx1;
  long int nx2;
  long int ny1;
  long int ny2;
  //long int nz1;
  //long int nz2;
  
  long int fx;
  long int fy;
  //long int fz;
  unsigned long int fn;
  
  long int nn1; // 4.294.967.295
  long int nn2; // -2.294.967.295 to 2.294.967.295
  
  long int encontro;
  long int nencontro;
  

  int i;
  int ri;
  int linha;
  int cor;
  int lin;
  
  mpz_t mx; mpz_init(mx);
  mpz_t my; mpz_init(my);
  mpz_t mz; mpz_init(mz);
  mpz_t mr; mpz_init(mr); //resultado
  mpz_t dif; mpz_init(dif); // Diferente
  mpz_t menor; mpz_init(menor);
  mpz_t ax1; mpz_init (ax1);
  mpz_t ax2; mpz_init (ax2);
  mpz_t ay1; mpz_init (ay1);
  mpz_t ay2; mpz_init (ay2);
  mpz_t an1; mpz_init (an1);
  mpz_t msz; mpz_init (msz);
  nx1 = atol(cx1);
  nx2 = atol(cx2);
  ny1 = atol(cy1);
  ny2 = atol(cy2);
  nn1 = atol(cn1);
  nn2 = atol(cn2);

  cla= -1;
  encontro = -1;
  if (mpz_set_str (ax1, cx1, 0) != 0) cla = 0;
  if (cla == 0 && mpz_set_str (ax2, cx2, 0) != 0) cla = 0;
  if (cla == 0 && mpz_set_str (ay1, cy1, 0) != 0) cla = 0;
  if (cla == 0 && mpz_set_str (ay2, cy2, 0) != 0) cla = 0;
  
  if (cla !=0 ) {
     
     //##############################
      encontro = 0;
     nencontro = 0;
     linha=0; cor = 1;
     esc(2,38,2," R: Soma de X^n e Y^n ;  I: Contar o encontro de igual de X^n+Y^n e Z^n.");
     esc(2,39,2," D: Diferente de R e Z ( D = |R - Z| ).  X=x^n     Y=y^n     Z=z^n      ");
     for (fn = nn1; fn <=nn2; fn++)
         { for (i =0; i<1;i++) esc(2, 37+i, 1,"                                                                           ");
           for (i =0; i<8;i++) esc(2,12+i,15,"                                                                       ");
           cento(2,36,7,1,(int) (fn*100)/nn2);
           for (fx = nx1; fx <=nx2; fx++)
                   {
                      for (fy = ny1; fy <=ny2; fy++)
                          {
                                     mpz_set_ui (ax1, fx);
                                     mpz_set_ui (ay1, fy);
                                     mpz_set_ui (an1, fn);
                                     mpz_pow_ui (mx, ax1, fn);
                                     mpz_pow_ui (my, ay1, fn);                             
                                     mpz_add    (mr, mx, my);
                                     mpz_root   (msz,mr,fn);
                                     mpz_pow_ui (mz, msz, fn); 
                                     ri = mpz_cmp(mr,mz);
                                     mpz_sub(dif, mr,mz);
                                                                          
                                     if ( ri == 0 ) 
                                               {
                                                 encontro++;
                                                 gotoxyBG(2,20+linha++,cor,0);
                                                 cout << encontro << ": " << fx << "^" << fn << " + " << fy << "^" << fn << " = " ;
                                                 mpz_out_str (stdout, 10, msz);
                                                 cout << "^" << fn << "          ";
                                                 if ( linha > 13 ) { linha=0; if (cor == 1) cor = 2; else cor = 1; }
                                               } 
                                    // if ( ri < 0 ) {
                                    //                  mpz_add_ui (menor,dif);
                                    //             }          
                                     //s = resp(40,21,14,"Pause...");
                          } // DISPLAY INICIO
                           {
                                     lin=-2;                                     
                                     gotoxy( 4,14+lin,6); cout << fn;
                                     gotoxy(24,14+lin,6); cout << fn;
                                     gotoxy(44,14+lin,6); cout << fn;
                                     esc(20,15+lin,7,"+                =");
                                     gotoxy( 2,15+lin,3); cout << fx;
                                     gotoxy(22,15+lin,3); cout << fy;
                                     gotoxy(42,15+lin,5); mpz_out_str (stdout, 10, msz);
                                     gotoxy( 2,17+lin,6); cout << "X = " ; mpz_out_str (stdout, 10, mx);
                                     gotoxy( 2,18+lin,2); cout << "Y = " ; mpz_out_str (stdout, 10, my);
                                     gotoxy( 2,19+lin,3); cout << "Z = " ; mpz_out_str (stdout, 10, mz);
                                     gotoxy( 2,20+lin, 7); cout << "R = " ; mpz_out_str (stdout, 10, mr);
                                     gotoxy( 2,21+lin,07); cout << "D = " ; mpz_out_str (stdout, 10, dif); cout << "    ";
                                     gotoxy( 55,6+lin,7); cout << "I = " << encontro << ".";
                                     cento(2,37,7,1,(int) (fx*100)/nx2);
                                     }          
                          // DISPLAY FINAL
                   }
         }
     }
mpz_clear (ax1);
mpz_clear (ax2);
mpz_clear (ay1);
mpz_clear (ay2);
//mpz_clear (az1);
//mpz_clear (az2);
  
  return encontro;  
}  
