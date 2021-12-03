#include <stdio.h>
#include <math.h>

void decimal_to_binary(int *v, int num){
  int div=128;
  for(int i=0; i<8; i++){
    printf("|%d|%d|\n",num,div);
    if(num/div==1){
      v[i]=1;
      num=num%div;
    }
    div=div/2;
  }
}

int binary_to_decimal(int num){
  int result, exp=0, soma=0;
  while(num/10>0){
    printf(".");
    exp++;
    int dig = num%10;
    if(dig == 1){
      printf("-");
      soma=soma+pow(2,exp);
    }
    num=num/10;
  }
  exp++;
    int dig = num%10;
    if(dig == 1){
      printf("-");
      soma=soma+pow(2,exp);
    }
  return result;
}

int binary_checker(int num){
  int check=0;
  while(num/10>0){
    if(num%10>1){
      printf("\n----- INVALIDO! -----\n");
      check=1;
      break;
    }
    num=num/10;
  }
  return check;
}

int main(void) {
  int function;// Ler numero
  do{
    printf("Binário (0) ou decimal (1)? ");
    scanf("%d",&function);
    if(function !=0 && function !=1)
      printf("\n----- INVALIDO! -----\n");
  }while(function !=0 && function !=1);
  int num;

  //decimal
  if(function==1){  
    printf("Digite um número de 0 a 255: \n");
    scanf("%d",&num);

    int vec[8];//Vetor + tudo a zeros
    for(int i=0;i<8;i++){
      vec[i]=0;
    }

    decimal_to_binary(vec, num);

    for(int i=0;i<8;i++){
      printf("%d ",vec[i]);
    }
  }

  //binario
  else{
    int check;
    do{
      printf("Introduza um número binário até 1111 1111: ");
      scanf("%d",&num);
      check=binary_checker(num);
    }while(check==1);
    int result = binary_to_decimal(num);
    printf("%d", result);
  }
  
  return 0;
}