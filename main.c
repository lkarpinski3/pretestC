#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void searchArray(char *s1, char *s2, int len);

void main (int argc, char *argv[]){
  int i, j, jj;
  char string1[strlen(argv[1])];
  char string2[strlen(argv[2])];

  if(strlen(argv[1])<strlen(argv[2])){
    strcpy(string1,argv[1]);
    strcpy(string2,argv[2]);
  } else{
    strcpy(string1,argv[2]);
    strcpy(string2,argv[1]);
  }

  char str1_sub[strlen(string1)];
  char str2_sub[strlen(string1)];


  for (i = 0; i < strlen(string1); i++) {
    memcpy(str1_sub,&string1[i],i);
    printf("%s\n", str1_sub);
    printf("%d\n", i);
    for(j = 1; j < strlen(string1); j++) {
/*      strncpy(str1_sub,string1,j+1);
      str1_sub[j+1] = '\0';*/
      searchArray(str1_sub,string2, 2);
    }
  }
}


/* searchArray function searches the string for the substring */
void searchArray(char *s1, char *s2, int len){
  int ii;
  int s1len = strlen(s1);
  char substring[s1len];

  for(ii = 0; ii<strlen(s2); ii++){
    memcpy(substring, &s2[ii], s1len);
    /*printf("%s\n",substring);*/
    if(strcmp(s1,substring) == 0){
      printf("%s\n",substring);
    }
  }
}
