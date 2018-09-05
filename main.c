#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Global variable*/

int lenStr1 = 0;
int bufferLen = 0;
int arrayLen = 0;


/* Function declaration*/
void searchString(char *s1, char *s2, int e);

/* Main function */
void main (int argc, char *argv[]){
  int i, j, jj, col, row;
  int len = 0;
  int arrayIndex = 0;

  if(argc == 3){
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

    /* Make sure the strings are Null-terminated */
    string1[strlen(string1)] = '\0';
    string2[strlen(string2)] = '\0';

    char str1_sub[len];
    char str2_sub[len];

    /* Create new array list for checking what we currently printed */
    /* First find the length of String1 */
    lenStr1 = strlen(string1);
    bufferLen = lenStr1;
    for(i = 0; i < bufferLen; i++){
      arrayLen += lenStr1;
      lenStr1--;
    }
    (const int)arrayLen;
    (const int)bufferLen;
    char arrayList[arrayLen][bufferLen];


    s1_ptr = string1;
    s2_ptr = string2;

    printf("String 1:\t%s\n",string1);

    for (i = 0; i < strlen(string1); i++) {
      for(j = 0; j+i != strlen(string1); j++){
        memcpy(str1_sub, s1_ptr+i,j+1);
        str1_sub[j+1] = '\0';
        for(col = 0; col < j+1; col++){
          arrayList[arrayIndex][col] = str1_sub[col];
        }
        arrayList[strlen(str1_sub)]  = '\0';
        printf("\tsent:\t%s \n", arrayList[arrayIndex]);
        /*searchString(str1_sub,string2,1);*/
        arrayIndex+=1;
      }


    }
    for (i = 0; i < arrayLen; i++) {
/*      for(j = 0; j < bufferLen; j++){
        if(arrayList[i][j] != '\0'){
          printf("%c",arrayList[i][j]);
        }
      }
      printf("\n");*/
      printf("%s\n",arrayList[i]);
    }
  } else {
    printf("Please enter two strings: ./a.out string1 string2\n");
  }
}



/* searchString function searches the string for the substring */
void searchString(char *s1, char *s2, int e){
  int ii;
  int s1len = strlen(s1);
  char substring[s1len];
  int flag = 0;


  for(ii = 0; ii<strlen(s2); ii++){
    memcpy(substring, &s2[ii], s1len);
    substring[s1len] = '\0';
    /*printf("search:\t%s\n",substring);*/
    if(strcmp(s1,substring) == 0){
      if(!flag){
        printf("%s\n",substring);
        flag = 1;
      }
    }
  }
}
