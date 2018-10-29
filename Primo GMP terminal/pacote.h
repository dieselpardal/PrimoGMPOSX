#include <string.h>


#define BLACK "90"
#define RED "91"
#define GREEN "92"
#define YELLOW "93"
#define BLUE "94"
#define MAGNET "95"
#define CYAN "96"
#define WHITE "97"

#define BG_BLACK "40"
#define BG_RED "41"
#define BG_GREEN "42"
#define BG_YELLOW "43"
#define BG_BLUE "44"
#define BG_MAGNET "45"
#define BG_CYAN "46"
#define BG_WHITE "47"



char *progname;
int c2 =0;
void cls() {
    system("clear") ;
}

void pauses() {
printf("  Tecla para menu.");
getchar();getchar();
}

string chr(int i) 
{
       char x;
       stringstream ss;
       x = (char)(i);
       ss << x;
       return ss.str(); 
       }


unsigned long int strtoint(string s)// String to Int
{
unsigned long int numb; 
istringstream ( s ) >> numb;
return   numb;       
}
unsigned long long strtoint64(string s)// String to Int
{
unsigned long long numb; 
istringstream ( s ) >> numb;
return   numb;       
}
//void TextColor(int fontcolor,int backgroundcolor,HANDLE screen)
//{
//int color_attribute;
//color_attribute = backgroundcolor;
//color_attribute = _rotl(color_attribute,4) | fontcolor;
//SetConsoleTextAttribute(screen,color_attribute);
//}
string inttostr(unsigned long int number) // Int to String
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
} 
string floattostr(double number) // Float to String
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
} 
char* convertString(string nome) // String to Char
{
    
    char *name = new char[nome.length()+1];
    memcpy(name, nome.c_str(), nome.length() + 1);
   
    return name;
//char* buf;
//buf = &s[0];
//return buf;
}
 string convertChar(char *ch)  // char * to string
{
   stringstream ss;//create a stringstream
   ss << ch;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}
string convertChar(const char *ch)  // char * to string
{
    stringstream ss;//create a stringstream
    ss << ch;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}

string convertTime(unsigned long int t) // Microsegundo para ano, dia, hora, minutos, segundo e microsegundo.
{
string ss;
unsigned long int a,d,h,m,s,mm;
unsigned long int decimal = 1000000; // Converter para Segundo
a = 0;
d = 0;
h = 0;
m = 0;
s = 0;
mm= 0;
t = t/decimal;
ss="";
if ( t >= 31536000 )  { a = (int) (t / 31536);   t = t - a*31536000;} else
if ( t >= 86400 )     { d = (int) (t / 86400);   t = t - d*86400;} else
if ( t >= 3600 )      { h = (int) (t / 3600);    t = t - h*3600;} else
if ( t >= 60 )        { m = (int) (t / 60);      t = t - m*60;} else
                      { s = (int) (t / 1); t = t - s;}
//if ( t >= 0 ) 
mm = t; ss= "";
if ( a > 0 ) ss = ss + inttostr(a) + "a";
if ( d > 0 ) ss = ss + inttostr(d) + "d";
if ( h > 0 ) ss = ss + inttostr(h) + "h";
if ( m > 0 ) ss = ss + inttostr(m) + "min";
if ( s > 0 ) ss = ss + inttostr(s) + "s";
if ( mm> 0 ) ss = ss + inttostr(mm)+ "ms";
//if (ss == "") ss="0";
return ss;
}
void color(int corfg)
{
    std::string fg = "";
    switch (corfg) {
        case 0: fg=BLACK ; break;
        case 1: fg=RED ; break;
        case 2: fg=GREEN ; break;
        case 3: fg=YELLOW ; break;
        case 4: fg=BLUE ; break;
        case 5: fg=MAGNET ; break;
        case 6: fg=CYAN ; break;
        case 7: fg=WHITE ; break;
        default:
            break;
    }
    
    printf("\033[%sm",fg.c_str());
}       
void gotoxy(int x, int y, int corfg) {
    
    std::string fg = "";
    switch (corfg) {
        case 0: fg=BLACK ; break;
        case 1: fg=RED ; break;
        case 2: fg=GREEN ; break;
        case 3: fg=YELLOW ; break;
        case 4: fg=BLUE ; break;
        case 5: fg=MAGNET ; break;
        case 6: fg=CYAN ; break;
        case 7: fg=WHITE ; break;
        default:
            break;
    }
    
printf("\x1b[%d;%df\033[%sm", y, x,fg.c_str());
}
void gotoxyBG(int x, int y, int corfg, int corbg) {
    
    std::string fg = "";
    std::string bg = "";
    
    switch (corfg) {
        case 0: fg=BLACK ; break;
        case 1: fg=RED ; break;
        case 2: fg=GREEN ; break;
        case 3: fg=YELLOW ; break;
        case 4: fg=BLUE ; break;
        case 5: fg=MAGNET ; break;
        case 6: fg=CYAN ; break;
        case 7: fg=WHITE ; break;
        default:
            break;
    }
    
    switch (corbg) {
        case 0: bg=BG_BLACK ; break;
        case 1: bg=BG_RED ; break;
        case 2: bg=BG_GREEN ; break;
        case 3: bg=BG_YELLOW ; break;
        case 4: bg=BG_BLUE ; break;
        case 5: bg=BG_MAGNET ; break;
        case 6: bg=BG_CYAN ; break;
        case 7: bg=BG_WHITE ; break;
        default:
            break;
    }
    printf("\x1b[%d;%df\033[%s;%sm",y,x, bg.c_str(),fg.c_str());
}
void escBG(int x, int y, int corfg, int corbg, std::string s) {
    
    std::string fg = "";
    std::string bg = "";
    
    switch (corfg) {
        case 0: fg=BLACK ; break;
        case 1: fg=RED ; break;
        case 2: fg=GREEN ; break;
        case 3: fg=YELLOW ; break;
        case 4: fg=BLUE ; break;
        case 5: fg=MAGNET ; break;
        case 6: fg=CYAN ; break;
        case 7: fg=WHITE ; break;
        default:
            break;
    }
    
    switch (corbg) {
        case 0: bg=BG_BLACK ; break;
        case 1: bg=BG_RED ; break;
        case 2: bg=BG_GREEN ; break;
        case 3: bg=BG_YELLOW ; break;
        case 4: bg=BG_BLUE ; break;
        case 5: bg=BG_MAGNET ; break;
        case 6: bg=BG_CYAN ; break;
        case 7: bg=BG_WHITE ; break;
        default:
            break;
    }
    printf("\x1b[%d;%df\033[%s;%sm%s\033[0m",y,x, bg.c_str(),fg.c_str(), s.c_str());
}
void esc(int x, int y, int corfg, std::string s) {
    
    escBG(x,y,corfg,0,s);

}
void quadro(int coluna, int linha,int colunaF, int linhaF)
{
    int i,j;
    
    for (j=linha;j<= linhaF;j++)
             {
                 gotoxyBG(coluna, j,2,0 );
                 for (i=coluna;i<= colunaF;i++) cout << " ";
                 
             }

}

void cento(int coluna, int linha,int corfg,int corbg, unsigned long int f)
{
        unsigned long int i;
        gotoxyBG((int)(coluna+f), linha,1,0 );
        for (i=f;i< (int) (100*75 / 100 );i++) cout << "#";
        gotoxyBG(coluna, linha,corfg,corbg );
        for (i=0;i< (int) (f*75 / 100 );i++)
            
            
            cout << " ";
        gotoxyBG( (int) (coluna + 75) / 2 ,linha,corfg,corbg );
        cout << inttostr(f) << "%";
}

void cento1(int coluna, int linha,int corfg,int corbg, unsigned long int x, unsigned long int y)
{
      int c1 = (int)((double)(x)*100/(double)y);
      if (c1 != c2) 
          {
                 c2 = c1;  
                 cento(coluna,linha,corfg,corbg,c1);
          }     
}
string resp(int coluna, int linha,int cor, string s)
{
        char  rs[100];
       // stringstream ss;
        string sok;
        gotoxy(coluna,linha,cor);
        cout << s;
        scanf("%s", rs);
        sok = convertChar(rs);
        return sok;
}
void linha(int i) {
    int cor = 2;
     for (int j=2;j<79;j++)
     esc(j,i,cor,"-");
     }
void borda(int xx, int yy) {
    int x,y;
    int cor = 2;
     gotoxy(1,2,0);
     for (x=1;x<xx;x++) 
         {
            esc(x,1,cor,"=");
            esc(x,yy,cor,"=");
         }   
       for (y=2;y<yy;y++) 
         {
            esc(0,y,cor,"|");
            esc(xx,y,cor,"|");
         }
        esc( 0, 1,cor,"o");
        esc(xx, 1,cor,"o");
        esc( 0,yy,cor,"o");
        esc(xx,yy,cor,"o");
     }
void reta(int xx, int yy, int x1, int y1, int tipo) {
     int x,y;
     for (y=yy;y<=y1;y++)
      for (x=xx;x<=x1;x++) 
         {
            esc(x,y,7," ");
         }   
    
     }
     
int file_exists(const char *filename)
{
  FILE *arquivo;

  if((arquivo = fopen(filename, "r")))
  {
    fclose(arquivo);
    return 1;
  }
  return 0;
}
string getRAM()
{
    FILE* stream = popen( "head -n1 /proc/meminfo", "r" );
    std::ostringstream output;
    int bufsize = 128;

    while( !feof( stream ) && !ferror( stream ))
    {
        char buf[bufsize];
        unsigned long bytesRead = fread( buf, 1, bufsize, stream );
        output.write( buf, bytesRead );
    }
    std::string result = output.str();

    std::string label, ram;
    std::istringstream iss(result);
    iss >> label;
    iss >> ram;

    return ram;
}
void Mostra_numero(const char *filename)
{
   gotoxy(1,1,15);
   FILE * pFile;
//int f;
   char buffer [100] ;
    
  if ( !file_exists(arquivo) ) {esc(5,26,1,"Nao encontrou o arquivo.");usleep(1000);}
   else
   {   
   pFile = fopen (filename , "r");
   cls();
   if (pFile == NULL) perror ("Error opening file");
   else
   {
     while ( ! feof (pFile) )
     {
       if ( fgets (buffer , 100 , pFile) != NULL )
         {
            fputs (buffer , stdout);
         }
     }
     fclose (pFile);
   }
       color(7);
   cout << endl << endl;
   pauses(); 
   }
} 
long TamanhoArq(const char *filename)
{
long t;
FILE *arq;
arq = fopen(filename,"r");
fseek (arq, 0, SEEK_END);
t = ftell (arq);
fclose(arq);
//printf("===> %s\n", argv);
//printf("\tTamanho = %i\n", t);
return t;
}


bool ehprimo1 ( unsigned long int i ) // verificar primo SEM precisao GMP. 
{
  unsigned long int f,g;
  bool v;
  v=true;
if ((i % 2 == 0) && (i > 2)) v=false;
else
 {       
 f = 3;
 g = (unsigned long int) sqrt(i);
 while ( v && (f<=g)) {
       if ( i % f == 0 ) v = false; else f=f+2;
       }     
 } 

return v;
}


int ehprimo_nat ( unsigned long int n) // verificar primo sem precisao. é normal.
{
 bool v;
 unsigned long int i, sq;
 if ( (n % 2 == 0) && (n > 2) ) 
    v = false;
  else
    v = true;
  if ( v ) {
    i = 3;
    sq = (unsigned long int)sqrt(n);
    while ( v && (i <= sq) ) 
      if ((n % i) == 0 )
        v = false;
      else
        i=i+2;
  }
  return v;
}

string abrir(char *arquivo1) {
   FILE * pFile;
   bool v;
   char buffer [100] ;
   stringstream ss;
   v= true;
   //ss.str("");
   ss.clear();
   pFile = fopen (arquivo1  , "r");
   if (pFile == NULL) perror ("Error opening file");
   else
   {
     while ( ! feof (pFile) )
     {
       if ( fgets (buffer , 100 , pFile) != NULL )
         {
            ss << buffer;
            //fputs (buffer , stdout);
         }
     }
     fclose (pFile);
   }
   return ss.str();
}
     
void
print_usage_and_exit ()
{
  fprintf (stderr, "usage: %s -q nnn\n", progname);
  fprintf (stderr, "usage: %s nnn ...\n", progname);
  exit (-1);
}

void teste ()
{
    int f;
//    char *nome;
//    char buf[10];
    string s;
  cls();
  for (f=0;f<100;f++) {
      s = "Color ";
      s = s +inttostr(f);
      system(s.c_str());
    
      cout << "AAAAAAAAA \n" << s << endl;  
      printf("BBBBBBBBB  \n");
   gotoxy(2,2,15);
   }
}

//int demorar_teste() {
//unsigned long int   count, max = 4000000;// increasing 'max' from 3,000,000,000 to 4,000,000,000 decreases cpu usage!
//	    double  input = 0.0;
//	    double  step = 1; //MAX_INPUT / (double)max;
//	    clock_t     qTime, uTime;
//	     
//	    // examine quick sqrt function
//	    qTime = clock();
//	     
//	    for(count = 0, input = 0.0; count < max; count++, input += step)
//        {
//        sqrt( input );
//        }
//	    qTime = clock() - qTime;
//	    cout<<"cpuClk = "<< qTime<< " microsegundo." << endl;
//return 0;    
//}

void tabela_cor()
{
     int c,f,g;
     c=0;
     cls();
     for (f=0;f<10;f++)
     for (g=0;g<26;g++) {
         gotoxy(1+f*8,g,c);
         cout << "A--" << c;
         c++;         
         }
     gotoxy(2,47,15);
    pauses();
     }
unsigned long int ii(unsigned long int i) // contagem do primo.
{  
   unsigned long int f, g;
  if ( (i == 0) || (i == 1))
    { return 0; }
  else if ( i == 2 )
    { return 1; }
  else
  {
    g = 1;
    f = 3;
    while (f <= i) 
      {
      if ( ehprimo1(f) )  g++;
      f = f + 2;
      }
    return g;
  }
}
unsigned long int proximo_primo(unsigned long int i) // proximo primo.
{  
    i++;
	while (!ehprimo1(i)) i++; 
    return i;
}
unsigned long int fprimo(unsigned long int i) // Funcao de primo sem Willian.
{
 unsigned long int f,g;  
 g=1;
 f=3;
 if (i==0) return 0;
 if (i==1) return 2;
 while ( g<i ) 
       {
        while ( (!ehprimo1(f)) ) f++; 
        g++;
        f++;
        }
return f-1;
}
unsigned long int u(unsigned long int i) // FUncao de Mobius.
{
 unsigned long int f,g;  
 g=1;
 f=3;
 if (i==0) return 0;
 if (i==1) return 2;
 while ( g<i ) 
       {
        while ( (!ehprimo1(f)) ) f++; 
        g++;
        f++;
        }
return f-1;
}

string tab(int i,string s) 
{
string ss;
char *s1;
unsigned long t;
int x;
ss = "";
s1 = convertString(s);
t = strlen(s1);
if (i>t) {
          for (x=0;x<(i-t);x++) ss = ss + " ";
          }
return   ss + s;       
}

void couts(string s,int corfg )
{
    std::string fg = "";
    switch (corfg) {
        case 0: fg=BLACK ; break;
        case 1: fg=RED ; break;
        case 2: fg=GREEN ; break;
        case 3: fg=YELLOW ; break;
        case 4: fg=BLUE ; break;
        case 5: fg=MAGNET ; break;
        case 6: fg=CYAN ; break;
        case 7: fg=WHITE ; break;
        default:
            break;
    }
    
    printf("\033[%sm", fg.c_str());
        cout << s;
}



