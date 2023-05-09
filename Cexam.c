#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>


   
int main() {
  int n,c;  
  char verbe[200]; 
  char ter[2];
  char ter1[] = "èr";
  char ter2[] = "ès";
  char ter3[] = "èd";
  char ter4[] = "èg";
  char ter5[] = "ç";
  char ter6[] = "l";
  char ter62[] = "èl"; 
  char ter7[] = "t";
  char ter72[] = "èt"; 
  char ver[3];
  char ver1[] = "érer";
  char ver2[] = "eser";
  char ver3[] = "éder";
  char ver4[] = "éger";
  char ver5[] = "cer";
  char ver6[] = "eler";
  char ver7[] = "eter";
  char tr[] = "é";
 
  char tmp[100];
  char tmp1[100]; 
  char tm[100];
  char tm1[100];
  char ttm[100];
   
  n = 0;
  c = 3;
 
 do {    
   printf("\nSaisir le verbe du premier groupe à conjuguer\n");
    printf("(Veuillez mettre un tiret entre le 'se' et le verbe dans le cas des verbes prénominaux: exemple(se-toucher))\n");
      scanf("%s", verbe);

   FILE* fbv = NULL;
   char ligne[200];
   
   fbv = fopen("Fverbe.txt", "r");
   int i,l,ll, numl = 1;
   
   if (fbv == NULL) {
     printf("Impossible d'ouvrir le fichier\n");
     return 1;
   }
   else {
       while(fgets(ligne, 100, fbv) != NULL) {
         if (strstr(ligne, verbe) != NULL) {
        
           if(strlen(verbe) == (strlen(ligne) - 1)) {
             n = 1;
             printf("Ok\n");
             
             l  = strlen(verbe); 
             strcpy(tm, verbe);
             strcpy(tm1, tm);
             strcpy(ttm,verbe);
             verbe[l - 2] = '\0';      
               
             if(verbe[2] == '-') {
               strcpy(verbe, verbe+3);
               strcpy(ttm, tm+3);
             }
             
             if ((numl>=108 && numl<=251) || (numl>=495 && numl<=854)) {
               if (numl>=108 && numl<=225){
                 strcpy(ter, ter1);
                 strcpy(ver, ver1);
               }
               else if (numl>=227 && numl<=230) {
                 strcpy(ter, ter2);
                 strcpy(ver, ver2);
               }
               else if (numl>=232 && numl<=251) {
                 strcpy(ter, ter3);
                 strcpy(ver, ver3);
               }
               else if (numl>=495 && numl<=510) {
                 strcpy(ter, ter4);
                 strcpy(ver, ver4);
               }
               else if (numl>=512 && numl<=669) {
                 strcpy(ter, ter5);
                 strcpy(ver, ver5);
               }
               else if (numl>=671 && numl<=747) {
                 strcpy(ter, ter6);
                 strcpy(ver, ver6);
               }
               else if (numl>=749 && numl<=760) {
                 strcpy(ter, ter62);
                 strcpy(ver, ver6);
               }
               else if (numl>=762 && numl<=772) {
                 strcpy(ter, ter72);
                 strcpy(ver, ver7);
               }
               else if (numl>=774 && numl<=854) {
                 strcpy(ter, ter7);
                 strcpy(ver, ver7);
               }
               char *ptr = strstr(verbe, ver);
               if (ptr) {
                 strncpy(tmp, verbe, ptr - verbe);
                 tmp[ptr - verbe] = '\0';
                 strcat(tmp, ter);
                 strcat(tmp, ptr + strlen(ver)); 
               }
               if (numl>=512 && numl<=669) {
                 strcpy(tmp1, tmp);
               }
             }
             
             if (tm1[2] == '-') {
               printf("\nAu présent de l'indicatif, le verbe se %s se conjugue : \n", ttm);
               sleep(2);
               
             }
             else {
               printf("\nAu présent de l'indicatif, le verbe %s se conjugue : \n", tm);
               sleep(2);
             }
             
             if ((numl>=1 && numl<=40) || (numl>=42 && numl<=106) ) {
               tm[l - 3] = '\0';     
               sleep(1);

               if (numl>=1 && numl<=40) { 
                 
                 if(tm1[2] == '-') {
                    strcpy(tm, tm+3);
                   
                   if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                     printf("Je m'%sye / %sie\n", tm, tm);
                     sleep(1);
                   }
                   else {
                     printf("Je me %sye / %sie\n", tm, tm);
                     sleep(1);
                   }
                   printf("Tu te %syes / %sies\n", tm, tm);
                   sleep(1);
                   printf("Il/Elle se %sye / %sie\n", tm, tm);
                   sleep(1);
                   printf("Nous nous %syons\n", tm);
                   sleep(1);
                   printf("Vous vous %syez\n", tm);
                   sleep(1);
                   printf("Ils/Elles se %syent / %sient\n", tm, tm);
                   sleep(1);
                 }
                 else {
                 if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("J'%sye / %sie\n", tm, tm);
                   sleep(1);
                 }
                 else {
                   printf("Je %sye / %sie\n", tm, tm);
                   sleep(1);
                 }
                 printf("Tu %syes / %sies\n", tm, tm);
                 sleep(1);
                 printf("Il/Elle %sye / %sie\n", tm, tm);
                 sleep(1);
                 printf("Nous %syons\n", tm);
                 sleep(1);
                 printf("Vous %syez\n", tm);
                 sleep(1);
                 printf("Ils/Elles %syent / %sient\n", tm, tm);
                 sleep(1);
                 }
               }  
               else if (numl>=42 && numl<=106) {
                 if(tm1[2] == '-') {
                    strcpy(tm, tm+3);
                   
                   if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                     printf("Je m'%sie\n", tm);
                     sleep(1);
                   }
                   else {
                     printf("Je me %sie\n", tm);
                     sleep(1);
                   }
                   printf("Tu te %sies\n", tm);
                   sleep(1);
                   printf("Il/Elle se %sie\n", tm);
                   sleep(1);
                   printf("Nous nous %syons\n", tm);
                   sleep(1);
                   printf("Vous vous %syez\n", tm);
                   sleep(1);
                   printf("Ils/Elles se %sient\n", tm);
                   sleep(1);
                 }
                 else {
                 if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("J'%sie\n", tm);
                   sleep(1);
                 }
                 else {
                   printf("Je %sie\n", tm);
                   sleep(1);
                 }
                 printf("Tu %sies\n", tm);
                 sleep(1);
                 printf("Il/Elle %sie\n", tm);
                 sleep(1);
                 printf("Nous %syons\n", tm);
                 sleep(1);
                 printf("Vous %syez\n", tm);
                 sleep(1);
                 printf("Ils/Elles %sient\n", tm);
                 sleep(1);
               }
               }
             }
             else if ((numl>=108 && numl<=251) || (numl>=495 && numl<=510) || (numl>=671 && numl<=854)) {
               if(tm1[2] == '-') { 
                 if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("Je m'%se\n", tmp);
                   sleep(1);
                 }
                 else {
                   printf("Je me %se\n", tmp);
                   sleep(1);
                 } 
                 printf("Tu te %ses\n", tmp);
                 sleep(1);
                 printf("Il/Elle se %se\n", tmp);
                 sleep(1);
                 if (numl>495 && numl<=510) {
                   printf("Nous nous %seons\n", verbe);
                   sleep(1);
                 }
                 printf("Nous nous %sons\n", verbe);
                 sleep(1);
                 printf("Vous vous %sez\n", verbe);
                 sleep(1);
                 printf("Ils/Elles se %sent\n", tmp);
                 sleep(1);
               }

               else {
               if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                 printf("J'%se\n", tmp);
                 sleep(1);
               }
               else {
                 printf("Je %se\n", tmp);
                 sleep(1);
               } 
               printf("Tu %ses\n", tmp);
               sleep(1);
               printf("Il/Elle %se\n", tmp);
               sleep(1);
               if (numl>495 && numl<=510) {
                 printf("Nous %seons\n", verbe);
                 sleep(1);
               }
               printf("Nous %sons\n", verbe);
               sleep(1);
               printf("Vous %sez\n", verbe);
               sleep(1);
               printf("Ils/Elles %sent\n", tmp);
               sleep(1);
             }
             }     
             
             else {
               if (tm1[2] == '-') {
                 if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("Je m'%se\n", verbe);
                   sleep(1);
                 }
                 else {
                   printf("Je me %se\n", verbe);
                   sleep(1);
                 }
                 printf("Tu te %ses\n", verbe);
                 sleep(1);
                 printf("Il/Elle se %se\n", verbe);
                 sleep(1);
                  
                 if (numl>253 && numl<=493) {
                   printf("Nous nous %seons\n", verbe);
                   sleep(1);
                 }
                 else if (numl>=512 && numl<=669){
                   printf("Nous nous %sons\n", tmp1);
                   sleep(1);
                 }
                 else {
                   printf("Nous nous %sons\n", verbe);
                   sleep(1);
                 }
                 printf("Vous vous %sez\n", verbe);
                 sleep(1);
                 printf("Ils/Elles se %sent\n", verbe);
                 sleep(1);
               }
               else {
               if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                 printf("J'%se\n", verbe);
                 sleep(1);
               }
               else {
                 printf("Je %se\n", verbe);
                 sleep(1);
               }
               printf("Tu %ses\n", verbe);
               sleep(1);
               printf("Il/Elle %se\n", verbe);
               sleep(1);
                 
               if (numl>253 && numl<=493) {
                 printf("Nous %seons\n", verbe);
                 sleep(1);
               }
               else if (numl>=512 && numl<=669){
                 printf("Nous %sons\n", tmp1);
                 sleep(1);
               }
               else {
                 printf("Nous %sons\n", verbe);
                 sleep(1);
               }
               printf("Vous %sez\n", verbe);
               sleep(1);
               printf("Ils/Elles %sent\n", verbe);
               sleep(1);
             }
             }
             
               printf("\nA l'imparfait de l'indicatif, ce verbe se conjugue : \n"); // Conjugue les verbes à l'imparfait
               sleep(1);
               if (numl>253 && numl<=510) { // Ajoute un 'e' après le 'g' pour les vbs se terminant par 'ger'
                 if (tm1[2] == '-') {
                   if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                     printf("Je m'%seais\n", verbe);
                     sleep(1);
                   }
                   else {
                     printf("Je me %seais\n", verbe);
                     sleep(1);
                   }
                   printf("Tu te %seais\n", verbe);
                   sleep(1);
                   printf("Il/Elle se %seait\n", verbe);
                   sleep(1);
                   printf("Nous nous %seions\n", verbe);
                   sleep(1);
                   printf("Vous vous %seiez\n", verbe);
                   sleep(1);
                   printf("Ils/Elles se %seaient\n", verbe);
                   sleep(1);
                 }
                 else {
                 if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("J'%seais\n", verbe);
                   sleep(1);
                 }
                 else {
                   printf("Je %seais\n", verbe);
                   sleep(1);
                 }
                 printf("Tu %seais\n", verbe);
                 sleep(1);
                 printf("Il/Elle %seait\n", verbe);
                 sleep(1);
                 printf("Nous %seions\n", verbe);
                 sleep(1);
                 printf("Vous %seiez\n", verbe);
                 sleep(1);
                 printf("Ils/Elles %seaient\n", verbe);
                 sleep(1);
               }
               }
               else if (numl>=512 && numl<=669){
                 if (tm1[2] == '-') {
                   if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("J'%sais\n", tmp1);
                   sleep(1);
                 }
                 else {
                   printf("Je %sais\n", tmp1);
                   sleep(1);
                 }
                 printf("Tu %sais\n", tmp1);
                 sleep(1);
                 printf("Il/Elle %sait\n", verbe);
                 sleep(1);
                 printf("Nous %sions\n", verbe);
                 sleep(1);
                 printf("Vous %siez\n", verbe);
                 sleep(1);
                 printf("Ils/Elles %saient\n", tmp1);
                 sleep(1);
                 }
                 else {
                 if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("J'%sais\n", tmp1);
                   sleep(1);
                 }
                 else {
                   printf("Je %sais\n", tmp1);
                   sleep(1);
                 }
                 printf("Tu %sais\n", tmp1);
                 sleep(1);
                 printf("Il/Elle %sait\n", verbe);
                 sleep(1);
                 printf("Nous %sions\n", verbe);
                 sleep(1);
                 printf("Vous %siez\n", verbe);
                 sleep(1);
                 printf("Ils/Elles %saient\n", tmp1);
                 sleep(1);
               }
               }
               else { // Conjugue à l'imparfait les autres verbes normalement
                 if (tm1[2] == '-') {
                   if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("Je m'%sais\n", verbe);
                   sleep(1);
                 }
                 else {
                   printf("Je me %sais\n", verbe);
                   sleep(1);
                 }
                 printf("Tu te %sais\n", verbe);
                 sleep(1);
                 printf("Il/Elle se %sait\n", verbe);
                 sleep(1);
                 printf("Nous nous %sions\n", verbe);
                 sleep(1);
                 printf("Vous vous %siez\n", verbe);
                 sleep(1);
                 printf("Ils/Elles se %saient\n", verbe);
                 sleep(1);
                 } 
                 else {
                 if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("J'%sais\n", verbe);
                   sleep(1);
                 }
                 else {
                   printf("Je %sais\n", verbe);
                   sleep(1);
                 }
                 printf("Tu %sais\n", verbe);
                 sleep(1);
                 printf("Il/Elle %sait\n", verbe);
                 sleep(1);
                 printf("Nous %sions\n", verbe);
                 sleep(1);
                 printf("Vous %siez\n", verbe);
                 sleep(1);
                 printf("Ils/Elles %saient\n", verbe);
                 sleep(1);
               }
               }
             
               printf("\nAu passé simple de l'indicatif, ce verbe se conjugue : \n");
               sleep(1);
               if (numl>253 && numl<=510) { // Ajoute un 'e' après le 'g' pour les vbs se terminant par 'ger'
                 if (tm1[2] == '-') {
                   if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("Je m'%seai\n", verbe);
                   sleep(1);
                 }
                 else {
                   printf("Je me %seai\n", verbe);
                   sleep(1);
                 }
                 printf("Tu te %seas\n", verbe);
                 sleep(1);
                 printf("Il/Elle se %sea\n", verbe);
                 sleep(1);
                 printf("Nous nous %seâmes\n", verbe);
                 sleep(1);
                 printf("Vous vous %seâtes\n", verbe);
                 sleep(1);
                 printf("Ils/Elles se %sèrent\n", verbe);
                 sleep(1);
                 }
                 else {
                 if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("J'%seai\n", verbe);
                   sleep(1);
                 }
                 else {
                   printf("Je %seai\n", verbe);
                   sleep(1);
                 }
                 printf("Tu %seas\n", verbe);
                 sleep(1);
                 printf("Il/Elle %sea\n", verbe);
                 sleep(1);
                 printf("Nous %seâmes\n", verbe);
                 sleep(1);
                 printf("Vous %seâtes\n", verbe);
                 sleep(1);
                 printf("Ils/Elles %sèrent\n", verbe);
                 sleep(1);
               }
               }
               else if (numl>=512 && numl<=669){
                 if (tm1[2] == '-') {
                   if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("Je m'%sai\n", tmp1);
                   sleep(1);
                 }
                 else {
                   printf("Je me %sai\n", tmp1);
                   sleep(1);
                 }
                 printf("Tu te %sas\n", tmp1);
                 sleep(1);
                 printf("Il/Elle se %sa\n", tmp1);
                 sleep(1);
                 printf("Nous nous %sâmes\n", tmp1);
                 sleep(1);
                 printf("Vous vous %sâtes\n", tmp1);
                 sleep(1);
                 printf("Ils/Elles se %sèrent\n", verbe);
                 sleep(1);
                 }  
                 else {
                 if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("J'%sai\n", tmp1);
                   sleep(1);
                 }
                 else {
                   printf("Je %sai\n", tmp1);
                   sleep(1);
                 }
                 printf("Tu %sas\n", tmp1);
                 sleep(1);
                 printf("Il/Elle %sa\n", tmp1);
                 sleep(1);
                 printf("Nous %sâmes\n", tmp1);
                 sleep(1);
                 printf("Vous %sâtes\n", tmp1);
                 sleep(1);
                 printf("Ils/Elles %sèrent\n", verbe);
                 sleep(1);
               }
               }
               else {
                 if (tm1[2] == '-') {
                   if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("Je m'%sai\n", verbe);
                   sleep(1);
                 }
                 else {
                   printf("Je me %sai\n", verbe);
                   sleep(1);
                 }
                 printf("Tu te %sas\n", verbe);
                 sleep(1);
                 printf("Il/Elle se %sa\n", verbe);
                 sleep(1);
                 printf("Nous nous %sâmes\n", verbe);
                 sleep(1);
                 printf("Vous vous %sâtes\n", verbe);
                 sleep(1);
                 printf("Ils/Elles se %sèrent\n", verbe);
                 sleep(1);
                 }
                 else {
                 if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("J'%sai\n", verbe);
                   sleep(1);
                 }
                 else {
                   printf("Je %sai\n", verbe);
                   sleep(1);
                 }
                 printf("Tu %sas\n", verbe);
                 sleep(1);
                 printf("Il/Elle %sa\n", verbe);
                 sleep(1);
                 printf("Nous %sâmes\n", verbe);
                 sleep(1);
                 printf("Vous %sâtes\n", verbe);
                 sleep(1);
                 printf("Ils/Elles %sèrent\n", verbe);
                 sleep(1);
               }
               }
               
                 // Conjugue les verbes au futur simple
                printf("\nAu futur simple de l'indicatif, ce verbe se conjugue : \n");
                sleep(1);
               if (numl>=1 && numl<=40) { 
                if (tm1[2] == '-') {
                  if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                 printf("Je m'%syerai / %sierai\n", tm, tm);
                 sleep(1);
                 }
                 else {
                   printf("Je me %syerai / %sierai\n", tm, tm);
                   sleep(1);
                 }
                 printf("Tu te %syeras / %sieras\n", tm, tm);
                 sleep(1);
                 printf("Il/Elle se %syera / %siera\n", tm, tm);
                 sleep(1);
                 printf("Nous nous %syerons\n", tm);
                 sleep(1);
                 printf("Vous vous %syerez\n", tm);
                 sleep(1);
                 printf("Ils/Elles se %syeront / %sieront\n", tm, tm);
                 sleep(1); 
                }
                else {
                 if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                 printf("J'%syerai / %sierai\n", tm, tm);
                 sleep(1);
                 }
                 else {
                   printf("Je %syerai / %sierai\n", tm, tm);
                   sleep(1);
                 }
                 printf("Je %syerai / %sierai\n", tm, tm);
                 sleep(1);
                 printf("Tu %syeras / %sieras\n", tm, tm);
                 sleep(1);
                 printf("Il/Elle %syera / %siera\n", tm, tm);
                 sleep(1);
                 printf("Nous %syerons\n", tm);
                 sleep(1);
                 printf("Vous  %syerez\n", tm);
                 sleep(1);
                 printf("Ils/Elles %syeront / %sieront\n", tm, tm);
                 sleep(1); 
                }
               }
               else if ((numl>=108 && numl<=251) || (numl>=495 && numl<=510) || (numl>=671 && numl<=854)) {
                  if (tm1[2] == '-') {
                     if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("J'%serai\n", tmp);
                   sleep(1);
                 }
                  else {
                   printf("Je %serai\n", tmp);
                   sleep(1);
                 }
                  printf("Tu %seras\n", tmp);
                  sleep(1);
                  printf("Il/Elle %sera\n", tmp);
                  sleep(1);
                  if (numl>=671 && numl<=747) {
                    printf("Nous %serons\n", verbe);
                    sleep(1);
                    printf("Vous %serez\n", verbe);
                    sleep(1);
                  }
                  else {
                   printf("Nous %serons\n", verbe);
                   sleep(1);
                   printf("Vous %serez\n", verbe);
                   sleep(1);
                  }
                  printf("Ils/Elles %seront\n", tmp);
                  sleep(1); 
                }
                else {
                  if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("J'%serai\n", tmp);
                   sleep(1);
                 }
                  else {
                   printf("Je %serai\n", tmp);
                   sleep(1);
                 }
                  printf("Tu %seras\n", tmp);
                  sleep(1);
                  printf("Il/Elle %sera\n", tmp);
                  sleep(1);
                  if (numl>=671 && numl<=747) {
                    printf("Nous %serons\n", verbe);
                    sleep(1);
                    printf("Vous %serez\n", verbe);
                    sleep(1);
                  }
                  else {
                   printf("Nous %serons\n", verbe);
                   sleep(1);
                   printf("Vous %serez\n", verbe);
                   sleep(1);
                  }
                  printf("Ils/Elles %seront\n", tmp);
                  sleep(1); 
               }
               } 
           
               else { 
                 if (tm1[2] == '-') {
                   if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("Je m'%serai\n", verbe);
                   sleep(1);
                 }
                 else {
                   printf("Je me %serai\n", verbe);
                   sleep(1);
                 }
                 printf("Tu te %seras\n", verbe);
                 sleep(1);
                 printf("Il/Elle se %sera\n", verbe);
                 sleep(1);
                 
                 printf("Nous nous %serons\n", verbe);
                 sleep(1);
                 printf("Vous vous %serez\n", verbe);
                 sleep(1);
                 printf("Ils/Elles se %seront\n", verbe);
                 sleep(1);
                }
                else {
                 if(verbe[0] == 'e' || verbe[0] == 'a' || verbe[0] == 'h' || verbe[0] == ver[0]) {
                   printf("J'%serai\n", verbe);
                   sleep(1);
                 }
                 else {
                   printf("Je %serai\n", verbe);
                   sleep(1);
                 }
                 printf("Tu %seras\n", verbe);
                 sleep(1);
                 printf("Il/Elle %sera\n", verbe);
                 sleep(1);
                 
                 printf("Nous %serons\n", verbe);
                 sleep(1);
                 printf("Vous %serez\n", verbe);
                 sleep(1);
                 printf("Ils/Elles %seront\n", verbe);
                 sleep(1);
                }
               }
             
               
             do {
             printf("\nVoulez vous conjuguer un verbe à nouveau?\n 2(oui)/0(non)\n");
             scanf("%d", &c);
             } while (c!=0 && c!=2);   
           } 
          n = 0;
         }
        numl++;
       }
       
       if(c == 2) {
         printf("Ok\n");
         sleep(1);
       }
       else if (c == 0){
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
        
