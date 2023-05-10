#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>


   
int main() {
  int n,c;  
  char verbe[200];
  char rep[3]; 
  char ter[2];
  char ter1[] = "èr";
  char ter2[] = "ès";
  char ter3[] = "èd";
  char ter6[] = "èg";
  char ter4[] = "ell";
  char ter42[] = "èl"; 
  char ter5[] = "ett";
  char ter52[] = "èt"; 
  char tr[] = "é";
  char apr [] = "'";
 
  char tmp[100];
  char tmp1[100]; 
  char verl3[100];
  char verl4[100];
  char ver[100];
  char ver2[100];
  char tp[100];
   
  char sjt[20][20] = {"Je", "Tu", "Il/Elle", "Nous", "Vous", "Ils/Elles"};
  char prm[20][20] = {"me", "te", "se", "nous", "vous", "se"};
  char prnm[20][20] = {"m'", "t'", "s'", "nous", "vous", "s'"};

  // Verbes en ayer et oyer //
  char pre1[20][20] = {"ie", "ies", "ie", "yons", "yez", "ient"};  // Présent de l'indicatif 
  char pre11[20][20] = {"ye", "yes", "ye", "yent"}; // Complément pour ayer
  char imp1[20][20] = {"yais", "yais", "yait", "yions", "yiez", "yaient"}; // Imparfait
  char pas1[20][20] = {"yai", "yas", "ya", "yâmes", "yâtes", "yèrent"}; // Passé simple
  char fut1[30][30] = {"ierai", "ieras", "iera", "yerons", "yerez", "ieront"}; // Futur simple 
  char fut11[30][30] = {"yerai", "yeras", "yera", "yeront"}; // Complément pour ayer

  // Verbes en érer, éder, eser, eler, eter  //
  char pre2[50][50] = {"e", "es", "e", "ons", "ez", "ent"};  // Présent de l'indicatif
  char imp2[50][50] = {"ais", "ais", "ait", "ions", "iez", "aient"}; // Imparfait
  char pas2[50][50] = {"ai", "as", "a", "âmes", "âtes", "èrent"}; // Passé simple
  char fut2[50][50] = {"erai", "eras", "era", "erons", "erez", "eront"}; // Futur simple 

  // Verbes en ger //
  char pre3[50][50] = {"e", "es", "e", "eons", "ez", "ent"};  // Présent de l'indicatif
  char imp3[50][50] = {"eais", "eais", "eait", "eions", "eiez", "eaient"}; // Imparfait
  char pas3[50][50] = {"eai", "eas", "ea", "eâmes", "eâtes", "èrent"}; // Passé simple
  char fut3[50][50] = {"erai", "eras", "era", "erons", "erez", "eront"}; // Futur simple 
    
  // Verbes en cer //
  char pre4[50][50] = {"e", "es", "e", "çons", "ez", "ent"};  // Présent de l'indicatif
  char imp4[50][50] = {"çais", "çais", "çait", "ions", "iez", "çaient"}; // Imparfait
  char pas4[50][50] = {"çai", "ças", "ça", "çâmes", "çâtes", "çèrent"}; // Passé simple
  char fut4[50][50] = {"erai", "eras", "era", "erons", "erez", "eront"}; // Futur simple 


  n = 0;
  c = 3;
 
 do {    
   printf("\nSaisir le verbe du premier groupe à conjuguer\n");
    printf("(Veuillez mettre un tiret entre le 'se' et le verbe dans le cas des verbes prénominaux: exemple(se-toucher))\n");
      scanf("%s", verbe);

   FILE* fbv = NULL;
   char ligne[200];
   
   fbv = fopen("Fverbe.txt", "r");
   int i,l, numl = 1;
   
   if (fbv == NULL) {
     printf("Impossible d'ouvrir le fichier\n");
     return 1;
   }
   else {
     while (fgets(ligne, 100, fbv) != NULL) {
       if (strstr(ligne, verbe) != NULL) {
         if(strlen(verbe) == (strlen(ligne) - 1)) {
           n = 1;
           printf("Ok\n");
             
           l = strlen(verbe); 
           strcpy(verl3, verbe);
           strcpy(verl4, verbe);
           strcpy(ver, verbe);
           strcpy(ver2, verbe);
           verbe[l - 2] = '\0';
           verl3[l - 3] = '\0';
           verl4[l - 4] = '\0';
           
           if (numl >= 108 && numl <= 436) {
            if (numl >= 108 && numl <= 225) {
              strcpy(ter, ter1);
            }
            else if (numl >= 227 && numl <= 230) {
              strcpy(ter, ter2);
            }
            else if (numl >= 232 && numl <= 251) {
              strcpy(ter, ter3);
            }
            else if (numl >= 253 && numl <= 329) {
              strcpy(ter, ter4);
            }
            else if (numl >= 331 && numl <= 342) {
              strcpy(ter, ter42);
            }
            else if (numl >= 344 && numl <= 354) {
             strcpy(ter, ter52);
            }
            else if (numl >= 356 && numl <= 436) {
             strcpy(ter, ter5);
            }

           }
           
           if (ver2[2] == '-') {
             strcpy(verbe, verbe+3);
             strcpy(ver, ver+3);
             strcpy(verl3, verl3+3);
           }
           if (ver2[1] == apr[0]) {
             strcpy(verbe, verbe+2);
             strcpy(ver, ver+2);
             strcpy(verl3, verl3+2);
           }

           if (ver2[2] == '-') {
             printf("\nAu présent de l'indicatif, le verbe se %s se conjugue: \n", ver);
           }
           else {
             printf("\nAu présent de l'indicatif, le verbe %s se conjugue: \n", ver);
           }
          
           if (numl>=1 && numl<=106) { // Conjugue les verbes en ayer et en oyer au présent
              if (numl>=1 && numl<=40) { // Cas des verbes en ayer
                if (ver2[2] == '-') { // Cas des verbes prénominaux en se
                  for (i=0; i<=2; i++) {
                  printf("%s %s %s%s / %s%s\n", sjt[i], prm[i], verl3, pre1[i], verl3, pre11[i]);
                  sleep(1);
                 }
                 for (i=3; i<=4; i++) {
                  printf("%s %s %s%s\n", sjt[i], prm[i], verl3, pre1[i]);
                  sleep(1);
                 }
                 printf("%s %s %s%s / %s%s\n", sjt[5], prm[i], verl3, pre1[5], verl3, pre11[3]);
                 sleep(1);
                }
                else if (ver2[1] == apr[0]) { // Cas des verbes prénominaux en s'
                  for (i=0; i<=2; i++) {
                  printf("%s %s%s%s / %s%s\n", sjt[i], prnm[i], verl3, pre1[i], verl3, pre11[i]);
                  sleep(1);
                 }
                 for (i=3; i<=4; i++) {
                  printf("%s %s %s%s\n", sjt[i], prnm[i], verl3, pre1[i]);
                  sleep(1);
                 }
                 printf("%s %s%s%s / %s%s\n", sjt[5], prnm[i], verl3, pre1[5], verl3, pre11[3]);
                 sleep(1);
                }
                else { // Cas des verbes simples
                 for (i=0; i<=2; i++) {
                   printf("%s %s%s / %s%s\n", sjt[i], verl3, pre1[i], verl3, pre11[i]);
                   sleep(1);
                 }
                 for (i=3; i<=4; i++) {
                   printf("%s %s%s\n", sjt[i], verl3, pre1[i]);
                   sleep(1);
                 }
                 printf("%s %s%s / %s%s\n", sjt[5], verl3, pre1[5], verl3, pre11[3]);
                 sleep(1);
               }
              }
              else { // Cas des verbes en oyer
                if (ver2[2] == '-') { // Cas des verbes prénominaux en se 
                  for (i=0; i<=5; i++) {
                   printf("%s %s %s%s\n", sjt[i], prm[i], verl3, pre1[i]);
                   sleep(1);
                 }
                }
                else if (ver2[1] == apr[0]) { // Cas des verbes prénominaux en s'
                  for (i=0; i<=5; i++) {
                   printf("%s %s %s%s\n", sjt[i], prnm[i], verl3, pre1[i]);
                   sleep(1);
                 }
                }
                else { // Cas des verbes normaux
                 for (i=0; i<=5; i++) {
                   printf("%s %s%s\n", sjt[i], verl3, pre1[i]);
                   sleep(1);
                 }
                }
              }  

              printf("\nA l'imparfait, ce verbe se conjugue: \n"); // Conjugue les verbes en ayer et oyer à l'imparfait
              if (ver2[2] == '-') { // Cas des verbes prénominaux en se 
               for (i=0; i<=5; i++) {
                 printf("%s %s %s%s\n", sjt[i], prm[i], verl3, imp1[i]);
                 sleep(1);
               }
              }
              else if (ver2[1] == apr[0]) { // Cas des verbes prénominaux en s'
                for (i=0; i<=5; i++) {
                 printf("%s %s %s%s\n", sjt[i], prnm[i], verl3, imp1[i]);
                 sleep(1);
               }
              }
              else { // Cas des verbes normaux
               for (i=0; i<=5; i++) {
                 printf("%s %s%s\n", sjt[i], verl3, imp1[i]);
                 sleep(1);
               }
              }

              printf("\nAu passé simple, ce verbe se conjugue: \n"); // Conjugue les verbes en ayer et oyer au passé simple
              if (ver2[2] == '-') { // Cas des verbes prénominaux en se 
                for (i=0; i<=5; i++) {
                 printf("%s %s %s%s\n", sjt[i], prm[i], verl3, pas1[i]);
                 sleep(1);
               }
              }
              else if (ver2[1] == apr[0]) { // Cas des verbes prénominaux en s'
                for (i=0; i<=5; i++) {
                 printf("%s %s %s%s\n", sjt[i], prnm[i], verl3, pas1[i]);
                 sleep(1);
               }
              }
              else { // Cas des verbes normaux
               for (i=0; i<=5; i++) {
                 printf("%s %s%s\n", sjt[i], verl3, pas1[i]);
                 sleep(1);
               }
              }
               
              printf("\nAu futur simple, ce verbe se conjugue: \n"); // Conjugue les verbes en ayer et oyer au futur simple
               if (numl>=1 && numl<=40) { // Cas des verbes en ayer
                if (ver2[2] == '-') { // Cas des verbes prénominaux en se
                  for (i=0; i<=2; i++) {
                  printf("%s %s %s%s / %s%s\n", sjt[i], prm[i], verl3, fut1[i], verl3, fut11[i]);
                  sleep(1);
                 }
                 for (i=3; i<=4; i++) {
                  printf("%s %s %s%s\n", sjt[i], prm[i], verl3, fut1[i]);
                  sleep(1);
                 }
                 printf("%s %s %s%s / %s%s\n", sjt[5], prm[i], verl3, fut1[5], verl3, fut11[3]);
                 sleep(1);
                }
                else if (ver2[1] == apr[0]) { // Cas des verbes prénominaux en s'
                  for (i=0; i<=2; i++) {
                  printf("%s %s%s%s / %s%s\n", sjt[i], prnm[i], verl3, fut1[i], verl3, fut11[i]);
                  sleep(1);
                 }
                 for (i=3; i<=4; i++) {
                  printf("%s %s %s%s\n", sjt[i], prnm[i], verl3, fut1[i]);
                  sleep(1);
                 }
                 printf("%s %s%s%s / %s%s\n", sjt[5], prnm[i], verl3, fut1[5], verl3, fut11[3]);
                 sleep(1);
                }
                else { // Cas des verbes simples
                 for (i=0; i<=2; i++) {
                   printf("%s %s%s / %s%s\n", sjt[i], verl3, fut1[i], verl3, fut11[i]);
                   sleep(1);
                 }
                 for (i=3; i<=4; i++) {
                   printf("%s %s%s\n", sjt[i], verl3, fut1[i]);
                   sleep(1);
                 }
                 printf("%s %s%s / %s%s\n", sjt[5], verl3, fut1[5], verl3, fut11[3]);
                 sleep(1);
               }
              }
              else { // Cas des verbes en oyer
                if (ver2[2] == '-') { // Cas des verbes prénominaux en se 
                  for (i=0; i<=5; i++) {
                   printf("%s %s %s%s\n", sjt[i], prm[i], verl3, fut1[i]);
                   sleep(1);
                 }
                }
                else if (ver2[1] == apr[0]) { // Cas des verbes prénominaux en s'
                  for (i=0; i<=5; i++) {
                   printf("%s %s %s%s\n", sjt[i], prnm[i], verl3, fut1[i]);
                   sleep(1);
                 }
                }
                else { // Cas des verbes normaux
                 for (i=0; i<=5; i++) {
                   printf("%s %s%s\n", sjt[i], verl3, fut1[i]);
                   sleep(1);
                 }
                }
              }  
              
           }

           else if (numl>=108 && numl<=436) { // Conjugue les verbes en érer, éder, erer, eler, eter au présent
             if (ver2[2] == '-') { // Cas des verbes prénominaux en se 
                  for (i=0; i<=5; i++) {
                   printf("%s %s %s%s%s\n", sjt[i], prm[i], verl4, ter, pre1[i]);
                   sleep(1);
                 }
             }
                else if (ver2[1] == apr[0]) { // Cas des verbes prénominaux en s'
                  for (i=0; i<=5; i++) {
                   printf("%s %s %s%s%s\n", sjt[i], prnm[i], verl4, ter, pre1[i]);
                   sleep(1);
                 }
                }
                else { // Cas des verbes normaux
                 for (i=0; i<=5; i++) {
                   printf("%s %s%s%s\n", sjt[i], verl4, ter, pre1[i]);
                   sleep(1);
                 }
                }
           }


       

           do {
             printf("\nVoulez vous conjuguer un verbe à nouveau?\n (oui)/(non)\n");
             scanf("%s", rep);
           } while ((strcmp(rep, "oui") != 0)  && (strcmp(rep, "non") != 0));   
         } 
         n = 0;
       }
        numl++;
     }
       
     if (strcmp(rep, "oui") == 0){
       printf("Ok\n");
       sleep(1);
     }
     else if (strcmp(rep, "non") == 0) {
       exit(0);        
     }
     else {
       if(n != 1) {
         printf("Ceci n'est pas un verbe\n");
       }
     }
     fclose(fbv);
   }
  } while ((n != 1) || (c == 2));
  return 0;
}
        
