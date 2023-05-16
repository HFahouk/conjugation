#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
   
int main() {
  int l, n = 0;  
  char rep[3]; 
  char ter[2];
  char ver[3];
  char tpar[30][30] = {"yer", "i", "érer", "èr", "eser", "ès", "éder", "èd", "éger", "èg", "cer", "ç", "eler", "ell", " èl", "eter", "ett", "èt"};
 /* char ter11[] = "i";
  char ter1[] = "èr";
  char ter2[] = "ès";
  char ter3[] = "èd";
  char ter4[] = "èg";
  char ter5[] = "ç";
  char ter6[] = "ell";
  char ter62[] = "èl"; 
  char ter7[] = "ett";
  char ter72[] = "èt"; 
  char ver11[] = "yer";
  char ver1[] = "érer";
  char ver2[] = "eser";
  char ver3[] = "éder";
  char ver4[] = "éger";
  char ver5[] = "cer";
  char ver6[] = "eler";
  char ver7[] = "eter";*/
  char tr[] = "é";
  char apr [] = "'";

  char verbe[200];
  char verbe2[200];
  char vert[100];
  char verp[100];
  char verp2[100];  
  char verg[100];
  char verb[100];
   
  char sjt[20][20] = {"Je ", "Tu ", "Il/Elle ", "Nous ", "Vous ", "Ils/Elles ", "J'"};
  char prm[20][20] = {"me", "te", "se", "nous", "vous", "se"};
  char prnm[20][20] = {"m'", "t'", "s'", "nous ", "vous ", "s'"};

  // Terminaisons des verbes du premier groupe
  char pre[50][50] = {"e", "es", "e", "ons", "ez", "ent"};  // Présent de l'indicatif
  char imp[50][50] = {"ais", "ais", "ait", "ions", "iez", "aient"}; // Imparfait
  char pas[50][50] = {"ai", "as", "a", "âmes", "âtes", "èrent"}; // Passé simple
  char fut[50][50] = {"erai", "eras", "era", "erons", "erez", "eront"}; // Futur simple 

  // Terminaisons des verbes du deuxième groupe
  char pre2[50][50] = {"is", "is", "it", "issons", "issez", "issent"};  // Présent de l'indicatif
  char imp2[50][50] = {"issais", "issais", "issait", "issions", "issiez", "issaient"}; // Imparfait
  char pas2[50][50] = {"is", "is", "it", "îmes", "îtes", "irent"}; // Passé simple
  char fut2[50][50] = {"irai", "iras", "ira", "irons", "irez", "iront"}; // Futur simple 

  
 do {    
   FILE *fbv = NULL, *fbv2 = NULL, *fbv3 = NULL;
   char ligne[200];
   char ligne2[200];
   char ligne3[200];

   fbv = fopen("Fverbe.txt", "r");
   fbv2 = fopen("Fverbe2.txt", "r");
   fbv3 = fopen("Fverbe3.txt", "r");

   int i, numl = 1, numl2 = 1, numl3 = 1;

   printf("\nSaisir le verbe à conjuguer\n");
    printf("(Veuillez mettre un tiret entre le 'se' et le verbe dans le cas des verbes prénominaux: exemple(se-toucher))\n");
    scanf("%s", verbe);

    l = strlen(verbe); 
    strcpy(vert, verbe); // Récupère le verbe pour garder le radical infinitif 
    strcpy(verb, verbe); // Récupère le verbe sans subir de changement dans le code (pour les conditions)
    if (verb[2] == '-') {
     strcpy(verbe, verbe+3);
     strcpy(vert, vert+3);      
    }
    if (verb[1] == apr[0]) {
     strcpy(verbe, verbe+2);
    }
    if (verb[0] == 'e' || verb[0] == 'a' || verb[0] == 'h' || verb[0] == tr[0]) {
     strcpy(sjt[0], sjt[6]);
    }
    verbe[l - 2] = '\0';
            
   if (fbv == NULL || fbv2 == NULL || fbv3 == NULL) {
     printf("Impossible d'ouvrir le fichier\n");
     return 1;
   }
   else {
     //                                          Conjugue les verbes du premier groupe                                      // 
     while (fgets(ligne, 100, fbv) != NULL) {
       if (strstr(ligne, verb) != NULL) {
         if(strlen(verb) == (strlen(ligne) - 1)) {
           n = 1;

           if (verb[2] == '-') {
             printf("\nLe verbe se %s est un verbe du premier groupe.\n", vert);
           }
           else {
             printf("\nLe verbe %s est un verbe du premier groupe.\n", vert);
           }
           sleep(1);
             
           strcpy(verp, verbe); // Récupère le verbe pour le traitement des verbes particuliers
           strcpy(verg, verbe); // Récupère le verbe pour le traitement des verbes particuliers en ger
           verg[l - 1] = '\0';
           
          if ((numl>=1 && numl<=251) || (numl>=495 && numl<=854)) {
               if (numl>=1 && numl<=114){
                 strcpy(ver, tpar[0]);
                 strcpy(ter, tpar[1]);
               }
               if (numl>=116 && numl<=233){
                 strcpy(ver, tpar[2]);
                 strcpy(ter, tpar[3]);
               }
               else if (numl>=235 && numl<=238) {
                 strcpy(ver, tpar[4]);
                 strcpy(ter, tpar[5]);
               }
               else if (numl>=240 && numl<=259) {
                 strcpy(ver, tpar[6]);
                 strcpy(ter, tpar[7]);
               }
               else if (numl>=503 && numl<=518) {
                 strcpy(ver, tpar[8]);
                 strcpy(ter, tpar[9]);
               }
               else if (numl>=520 && numl<=677) {
                 strcpy(ver, tpar[10]);
                 strcpy(ter, tpar[11]);
               }
               else if (numl>=679 && numl<=755) {
                 strcpy(ver, tpar[12]);
                 strcpy(ter, tpar[13]);
               }
               else if (numl>=757 && numl<=768) {
                 strcpy(ver, tpar[12]);
                 strcpy(ter, tpar[14]);
               }
               else if (numl>=770 && numl<=780) {
                 strcpy(ver, tpar[15]);
                 strcpy(ter, tpar[16]);
               }
               else if (numl>=782 && numl<=862) {
                 strcpy(ver, tpar[15]);
                 strcpy(ter, tpar[17]);
               }
             
              char *ptr = strstr(verb, ver);
              if (ptr) {  
              strncpy(verp, verb, ptr - verb);
              verp[ptr - verb] = '\0';
              strcat(verp, ter);
              strcat(verp, ptr + strlen(ver));
              }
             }
             
             if (verb[2] == '-') {
             strcpy(verp, verp+3); 
             strcpy(verg, verg+3);
             }
             if (verb[1] == apr[0]) {
             strcpy(verp, verp+2);
             strcpy(verg, verg+2);
            }
            strcpy(verbe2, verbe);
            strcpy(verp2, verp);  

            //                            Conjugue les verbes particuliers au présent                                         //
            printf("\nAu présent de l'indicatif, ce verbe se conjugue: \n");
            if ((numl>=1 && numl<=251) || (numl>=503 && numl<=518) || (numl>=679 && numl<=862) || (verb[l - 4] == 'e')) { 
              if (verb[2] == '-') { // Cas des verbes prénominaux en se
                  for (i=0; i<=5; i++) {
                   if (i == 3) {
                     if (numl >= 495 && numl<= 510) {
                       strcpy(verp, verg);
                     }
                     else
                       strcpy(verp, verbe);
                   }
                   if (i == 4) {
                     strcpy(verp, verbe);
                   }
                   if (i == 5) {
                     strcpy(verp, verp2);
                   }
                   printf("%s%s %s%s\n", sjt[i], prm[i], verp, pre[i]);
                   sleep(1);
                 }
                }
                else if (verb[1] == apr[0]) { // Cas des verbes prénominaux en s'
                  for (i=0; i<=5; i++) {
                    if (i == 3) {
                     if (numl >= 495 && numl<= 510) {
                       strcpy(verp, verg);
                     }
                     else
                       strcpy(verp, verbe);
                   }
                   if (i == 4) {
                     strcpy(verp, verbe);
                   }
                   if (i == 5) {
                     strcpy(verp, verp2);
                   }
                   printf("%s%s%s%s\n", sjt[i], prnm[i], verp, pre[i]);
                   sleep(1);
                 } 
                }
                else { // Cas des verbes non prénominaux
                 
                 for (i=0; i<=5; i++) {
                   if (i == 3) {
                     if (numl >= 495 && numl<= 510) {
                       strcpy(verp, verg);
                     }
                     else
                       strcpy(verp, verbe);
                   }
                   if (i == 4) {
                     strcpy(verp, verbe);
                   }
                   if (i == 5) {
                     strcpy(verp, verp2);
                   }
                   printf("%s%s%s\n", sjt[i], verp, pre[i]);
                   sleep(1);
                 }
               }
           }  
           //                                  Conjugue les verbes normaux au présent                                     //
           else {
            if (verb[2] == '-') { // Cas des verbes prénominaux en se
                  for (i=0; i<=5; i++) {
                   if (i == 3) {
                  if (numl >= 261 && numl<= 501) {
                   strcpy(verbe, verg);
                 } 
                 else if (numl >= 520 && numl<= 677) {
                  strcpy(verbe, verp);
                 }
               }
                if (i == 4) {
                     strcpy(verbe, verbe2);
                   }
                   printf("%s%s %s%s\n", sjt[i], prm[i], verbe, pre[i]);
                   sleep(1);
                 }
                }
                else if (verb[1] == apr[0]) { // Cas des verbes prénominaux en s'
                  for (i=0; i<=5; i++) {
                   if (i == 3) {
                  if (numl >= 261 && numl<= 501) {
                   strcpy(verbe, verg);
                 } 
                 else if (numl >= 520 && numl<= 677) {
                  strcpy(verbe, verp);
                 }
               }
                if (i == 4) {
                     strcpy(verbe, verbe2);
                   }
                   printf("%s%s%s%s\n", sjt[i], prnm[i], verbe, pre[i]);
                   sleep(1);
                 } 
                }    
                else { // Cas des verbes non prénominaux     
                 for (i=0; i<=5; i++) {
                   if (i == 3) {
                  if (numl >= 261 && numl<= 501) {
                   strcpy(verbe, verg);
                 } 
                 else if (numl >= 520 && numl<= 677) {
                  strcpy(verbe, verp);
                 }
               }
                if (i == 4) {
                     strcpy(verbe, verbe2);
                   }
                   printf("%s%s%s\n", sjt[i], verbe, pre[i]);
                   sleep(1);
                 }
               }
           }

           if (numl >= 520 && numl<= 677) {
             strcpy(verbe, verp);
           }
           else if (numl >= 261 && numl<= 518) {
             strcpy(verbe, verg);
           } 
            //                                           Conjugue les verbes à l'imparfait                                           //
              printf("\nA l'imparfait, ce verbe se conjugue: \n"); 
              if (verb[2] == '-') { // Cas des verbes prénominaux en se 
               for (i=0; i<=5; i++) {
                 printf("%s%s %s%s\n", sjt[i], prm[i], verbe, imp[i]);
                 sleep(1);
               }
              }
              else if (verb[1] == apr[0]) { // Cas des verbes prénominaux en s'
                for (i=0; i<=5; i++) {
                 printf("%s%s%s%s\n", sjt[i], prnm[i], verbe, imp[i]);
                 sleep(1);
               }
              }
              else { // Cas des verbes normaux
               for (i=0; i<=5; i++) {
                 printf("%s%s%s\n", sjt[i], verbe, imp[i]);
                 sleep(1);
               }
              }
             //                                       Conjugue les verbes au passé simple                                               //
              printf("\nAu passé simple, ce verbe se conjugue: \n"); 
              if (verb[2] == '-') { // Cas des verbes prénominaux en se 
                for (i=0; i<=5; i++) {
                 if (i ==5) {
                  if (numl >= 261 && numl<= 518) { // Condition des verbes en ger (prend le verbe sans er)
                   strcpy(verbe, verbe2);
                  }
                 }
                 printf("%s%s %s%s\n", sjt[i], prm[i], verbe, pas[i]);
                 sleep(1);
               }
              }
              else if (verb[1] == apr[0]) { // Cas des verbes prénominaux en s'
                for (i=0; i<=5; i++) {
                 if (i ==5) {
                  if (numl >= 261 && numl<= 518) { // Condition des verbes en ger (prend le verbe sans er)
                   strcpy(verbe, verbe2);
                  }
                 }
                 printf("%s%s%s%s\n", sjt[i], prnm[i], verbe, pas[i]);
                 sleep(1);
               }
              }
              else { // Cas des verbes non prénominaux
               for (i=0; i<=5; i++) {
                 if (i ==5) {
                  if (numl >= 261 && numl<= 518) { // Condition des verbes en ger (prend le verbe sans er)
                   strcpy(verbe, verbe2);
                  }
                 }
                 printf("%s%s%s\n", sjt[i], verbe, pas[i]);
                 sleep(1);
               }
              }

              printf("\nAu futur simple, ce verbe se conjugue: \n"); 
               //                                             Conjugue les verbes particuliers au futur simple                                      //
               if ((numl>=1 && numl<=251) || (numl>=503 && numl<=518) || (numl>=679 && numl<=862)) { 
               if (verb[2] == '-') { // Cas des verbes prénominaux en se
                  for (i=0; i<=5; i++) {
                   if (i == 3) {
                     if (numl >= 495 && numl<= 510) {
                       strcpy(verp, verg);
                     }
                     else
                       strcpy(verp, verbe);
                   }
                   if (i == 4) {
                     strcpy(verp, verbe);
                   }
                   if (i == 5) {
                     strcpy(verp, verp2);
                   }
                   printf("%s%s %s%s\n", sjt[i], prm[i], verp, fut[i]);
                   sleep(1);
                 }
                }
                else if (verb[1] == apr[0]) { // Cas des verbes prénominaux en s'
                  for (i=0; i<=5; i++) {
                    if (i == 3) {
                     if (numl >= 495 && numl<= 510) {
                       strcpy(verp, verg);
                     }
                     else
                       strcpy(verp, verbe);
                   }
                   if (i == 4) {
                     strcpy(verp, verbe);
                   }
                   if (i == 5) {
                     strcpy(verp, verp2);
                   }
                   printf("%s%s%s%s\n", sjt[i], prnm[i], verp, fut[i]);
                   sleep(1);
                 } 
                }
                else { // Cas des verbes particuliers non prénonminaux
                 for (i=0; i<=5; i++) {
                   if (i == 3) {
                     if (numl >= 495 && numl<= 510) {
                       strcpy(verp, verg);
                     }
                     else
                       strcpy(verp, verbe);
                   }
                   if (i == 4) {
                     strcpy(verp, verbe);
                   }
                   if (i == 5) {
                     strcpy(verp, verp2);
                   }
                   printf("%s%s%s\n", sjt[i], verp, fut[i]);
                   sleep(1);
                 }
               }
             }
             //                                             Conjugue les verbes normaux au futur simple                                      //
             else { 
             if (verb[2] == '-') { // Cas des verbes prénominaux en se
                  for (i=0; i<=5; i++) {
                   printf("%s%s %s%s\n", sjt[i], prm[i], verbe, fut[i]);
                   sleep(1);
                 }
                }
                else if (verb[1] == apr[0]) { // Cas des verbes prénominaux en s'
                  for (i=0; i<=5; i++) {
                   printf("%s%s%s%s\n", sjt[i], prnm[i], verbe, fut[i]);
                   sleep(1);
                 } 
                }
                else { // Cas des verbes non prénonminaux
                 for (i=0; i<=5; i++) {
                   printf("%s%s%s\n", sjt[i], verbe, fut[i]);
                   sleep(1);
                 }
               }
             }
         } 
       }
        numl++;
     }
     //                                        Conjugue les verbes du deuxième groupe                                             //
     while (fgets(ligne2, 100, fbv2) != NULL) {
       if (strstr(ligne2, verb) != NULL) {
         if(strlen(verb) == (strlen(ligne2) - 1)) {
           n = 1;           
           if (verb[2] == '-') {
             printf("\nLe verbe se %s est un verbe du deuxième groupe.\n", vert);
           }
           else {
             printf("\nLe verbe %s est un verbe du deuxième groupe.\n", vert);
           }
           sleep(1);
             
          //                            Conjugue les verbes au présent                                         //
          printf("\nAu présent de l'indicatif, ce verbe se conjugue: \n");
          if (verb[2] == '-') { // Cas des verbes prénominaux en se
           for (i=0; i<=5; i++) {
             printf("%s%s %s%s\n", sjt[i], prm[i], verbe, pre2[i]);
             sleep(1);
           }
          }
          else if (verb[1] == apr[0]) { // Cas des verbes prénominaux en s'
           for (i=0; i<=5; i++) {
             printf("%s%s%s%s\n", sjt[i], prnm[i], verbe, pre2[i]);
             sleep(1);
           } 
          }    
          else { // Cas des verbes non prénominaux     
           for (i=0; i<=5; i++) {
             printf("%s%s%s\n", sjt[i], verbe, pre2[i]);
             sleep(1);
           }
          }

          //                            Conjugue les verbes à l'imparfait                                         //
          printf("\nA l'imparfait, ce verbe se conjugue: \n");
          if (verb[2] == '-') { // Cas des verbes prénominaux en se
           for (i=0; i<=5; i++) {
             printf("%s%s %s%s\n", sjt[i], prm[i], verbe, imp2[i]);
             sleep(1);
           }
          }
          else if (verb[1] == apr[0]) { // Cas des verbes prénominaux en s'
           for (i=0; i<=5; i++) {
             printf("%s%s%s%s\n", sjt[i], prnm[i], verbe, imp2[i]);
             sleep(1);
           } 
          }    
          else { // Cas des verbes non prénominaux     
           for (i=0; i<=5; i++) {
             printf("%s%s%s\n", sjt[i], verbe, imp2[i]);
             sleep(1);
           }
          }

          //                            Conjugue les verbes au passé simple                                       //
          printf("\nAu passé simple, ce verbe se conjugue: \n");
          if (verb[2] == '-') { // Cas des verbes prénominaux en se
           for (i=0; i<=5; i++) {
             printf("%s%s %s%s\n", sjt[i], prm[i], verbe, pas2[i]);
             sleep(1);
           }
          }
          else if (verb[1] == apr[0]) { // Cas des verbes prénominaux en s'
           for (i=0; i<=5; i++) {
             printf("%s%s%s%s\n", sjt[i], prnm[i], verbe, pas2[i]);
             sleep(1);
           } 
          }    
          else { // Cas des verbes non prénominaux     
           for (i=0; i<=5; i++) {
             printf("%s%s%s\n", sjt[i], verbe, pas2[i]);
             sleep(1);
           }
          }

          //                            Conjugue les verbes au futur simple                                       //
          printf("\nAu futur simple, ce verbe se conjugue: \n");
          if (verb[2] == '-') { // Cas des verbes prénominaux en se
           for (i=0; i<=5; i++) {
             printf("%s%s %s%s\n", sjt[i], prm[i], verbe, fut2[i]);
             sleep(1);
           }
          }
          else if (verb[1] == apr[0]) { // Cas des verbes prénominaux en s'
           for (i=0; i<=5; i++) {
             printf("%s%s%s%s\n", sjt[i], prnm[i], verbe, fut2[i]);
             sleep(1);
           } 
          }    
          else { // Cas des verbes non prénominaux     
           for (i=0; i<=5; i++) {
             printf("%s%s%s\n", sjt[i], verbe, fut2[i]);
             sleep(1);
           }
          }
       

             
         } 
       }
        numl2++;
     }
     while (fgets(ligne3, 100, fbv3) != NULL) {
       if (strstr(ligne3, verb) != NULL) {
         if(strlen(verb) == (strlen(ligne3) - 1)) {
           n = 1;
           if (verb[2] == '-') {
             printf("\nLe verbe se %s est un verbe du troisième groupe.\n", vert);
           }
           else {
             printf("\nLe verbe %s est un verbe du troisième groupe.\n", vert);
           }
           sleep(1);
             
          
       

          
         } 
       }
        numl3++;
     }
     if (n == 1) {
       do {
       printf("\nVoulez vous conjuguer un verbe à nouveau?\n (oui)/(non)\n");
       scanf("%s", rep);
      } while ((strcmp(rep, "oui") != 0)  && (strcmp(rep, "non") != 0));     
     if (strcmp(rep, "oui") == 0){
       printf("Ok\n");
       sleep(1);
     }
     else if (strcmp(rep, "non") == 0) {
       exit(0);        
     }
     }  
     else  {
       printf("Ceci n'est pas un verbe\n");
      }
     fclose(fbv);
     fclose(fbv2);
     fclose(fbv3);
   }
  } while ((n != 1) || (strcmp(rep, "oui") == 0));
  return 0;
}
        
