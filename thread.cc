#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

//funzioni
void stringMenage();
void xorForString(char *s1,char *s2,int n);


//variabili
int s=0;
bool t1,t2,t3,t4;//FORSE DENTRO AD OGNI THREAD VANNO SETTATE A FALSE IN USCITA (TRANNE UNA..)LG


//particolare attenzione a questa, è un mutex (google it)
pthread_mutex_t M;



void *thread1_process (void * arg)  //che tipo di ritorno è void* ?
{ int k=1;
 while(k)
   {
 sleep(1);
     pthread_mutex_lock(&M);//blocco la variabile;

	//eseguo il comando 
     if(t1){ printf("Ciao, sono thread1\n");  k=0;t2=true;}
 //funziona anche senza le variabili booleane t1,t2,etc... , ma a me i thread non vengono eseguiti in ordine corretto, forse è colpa del multithreading

	//sblocco la variabile
     pthread_mutex_unlock(&M); 
    
   
   }
 pthread_exit (0);
}

void *thread2_process (void * arg)
{ int k=1;
 while(k)
   {
 sleep(1);
     pthread_mutex_lock(&M);//guarda attentamente cosa fa la funzione printf su internet, poichè qui cout e compagnia non vanno (c non c++ =P)
   if(t2){ printf("Ciao, sono thread2\n");  k=0;t3=true;} 
    
     pthread_mutex_unlock(&M);
     
   }
 pthread_exit (0);
}

void *thread3_process (void * arg)
{ int k=1;
 while(k)
   {
 sleep(1);
     pthread_mutex_lock(&M); 
   if(t3){ printf("Ciao, sono thread3\n");  k=0;t4=true;}
    
     pthread_mutex_unlock(&M);
    
   }
 pthread_exit (0);
}

void *thread4_process (void * arg)
{ int k=1;
 while(k)
   {
 sleep(1);
     pthread_mutex_lock(&M); 
      if(t4){ printf("Ciao, sono thread4\n\n");  k=0;}
   
     pthread_mutex_unlock(&M);
    
      
   }
stringMenage();//faccio lo xor di due stringhe
 pthread_exit (0);

}

void stringMenage(){
printf("inizia la funzione xor!\n");
int len=27;
char *str = new char[len];
printf("stringa1:       ");
strcpy( str, "nos exaequat victoria caelo"); 
printf("%s\n",str); 
char *xorStr =new char[len];
strcpy( xorStr,"SJaLierGNmXfjnivufqWU0KTavo");
printf("stringa2:       ");
printf("%s\n",xorStr); 

xorForString(str,xorStr,len);
printf("stringa1 xor stringa2:  "); //qui i caratteri sono scelti a caso ma con lo xor possono venire fuori codici che non sono caratteri, quindi potrebbero venire strani simboli, ma anche comandi strani come \n che manda a capo, o altri che spostano e sovrappongono lettere
printf("%s\n",str); 

xorForString(str,xorStr,len);
printf("(stringa1 xor stringa2) xor stringa2:   ");
printf("%s\n",str); 


}


void xorForString(char *s1,char *s2,int n){
	int tmp1,tmp2;
	//per ogni carattere in s1, metti s1=s1 xor s2
		for(int i=0;i<n;i++){
			tmp1=s1[i];
			tmp2=s2[i];
			s1[i]=tmp1^tmp2;
		}
}

 

int main ()
{ 
//varoabili locali
pthread_t th1, th2,th3, th4;
t1=true;t2=t3=t4=false;
//inizializzo il mutex
pthread_mutex_init (&M, NULL);//non capisco..LG

//alloco i thread
pthread_create(&th1, NULL, thread1_process, NULL);
pthread_create(&th2, NULL,thread2_process,NULL);
pthread_create(&th3, NULL, thread3_process, NULL);
pthread_create(&th4, NULL,thread4_process,NULL);

//faccio eseguire al processo principale i thread
 pthread_join (th1, NULL);
 pthread_join (th2, NULL);
 pthread_join (th3, NULL);
 pthread_join (th4, NULL);
//distruggo il mutex per uscire dai thread
pthread_mutex_destroy(&M);

return 0;
}


//mi manca un po' di teoria su creazione thread,mutex ecc.