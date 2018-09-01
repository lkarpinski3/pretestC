#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void searchString(char *s1, char *s2, int e);

void main (int argc, char *argv[]){
  int i, j, jj;
  int len = 0;

  /* Find the largest length of the arrays */
  if(strlen(argv[1])<strlen(argv[2])){
    len = strlen(argv[2]);
  } else{
    len = strlen(argv[1]);
  }

  /* Define new arrays and pointers */
  char string1[len];
  char string2[len];
  char *s1_ptr;
  char *s2_ptr;

  /* Copy new orignal arguments to the new array variables */
  if(strlen(argv[1])<strlen(argv[2])){
    strcpy(string1,argv[1]);
    strcpy(string2,argv[2]);
  } else{
    strcpy(string1,argv[2]);
    strcpy(string2,argv[1]);
  }

  char str1_sub[len];
  char str2_sub[len];

  s1_ptr = string1;
  s2_ptr = string2;

  for (i = 0; i < strlen(string1); i++) {
    for(j =i; j < strlen(string1); j++){
      /*if(j < strlen(string1)){*/
        memcpy(str1_sub, s1_ptr+i,j+1);
        printf("%s\n", str1_sub);
        /*searchString(str1_sub,string2,2);*/
      /*}*/
    }

    /*printf("%d\n", strlen(string1));*/
  }
}

/* searchString function searches the string for the substring */
void searchString(char *s1, char *s2, int e){
  int ii;
  int s1len = strlen(s1);
  char substring[s1len];
  int flag0 = 0;
  int flag1 = 0;

  for(ii = 0; ii<strlen(s2); ii++){
    memcpy(substring, &s2[ii], s1len);
    if(strcmp(s1,substring) == 0){
      printf("%s\n",substring);
    }
  }
}
