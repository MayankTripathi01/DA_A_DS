#include<string.h>
#include<stdio.h>

int top=-1;

void main() {

  int data;
  char s[100];
  int s1[100];
  int ans;
  
  void push(int s[],int x);
  int pop(int s[], char c);
  
  printf("Enter expression with single digit numbers only: ");
  scanf("%s",s);
  printf("Entered expression is %s\n",s);

  int n=strlen(s);
  int i=0;
  
  while(i<n) {
    if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') {
      ans=pop(s1,s[i]);
      //printf("Answer in if %d",ans);
      push(s1,ans);
    }
    else if(s[i]>=48&&s[i]<=57) {
      data=s[i]-48;
      printf("%d\n",data);
      push(s1,data);
    }
    i++;
  }//while

  printf("Answer is: %d\n", ans);
}//main

void push(int s1[], int x) {
  top=top+1;
  s1[top]=x;
}	

int pop(int s1[], char c) {
  int n2=s1[top];
  //printf("n2 is %d",n2);
  top--;
  int n1=s1[top];
  //printf("n2 is %d",n2);
  top--;
  if(c=='+')
    return (n1+n2);
  else if(c=='-')
    return (n1-n2);
  else if(c=='*')
    return(n1*n2);
  else 
    return(n1/n2);
}


