#include <stdio.h>
#include <math.h>

//10101000 -> 168

void decimal_to_binary(int num){
  int res=0, cont=0;
  while(num/2>0){ //Conversion to binary, but inverted (division by 2 loop)
    res=res*10;
    res+=num%2;
    num=num/2;
    cont++; //counter of binary digits, to optimize vector size
  }
  res=res*10;
  res+=num%2;
  num=num/2;
  cont++;

  int v[cont], looper=cont-1;
  for(int i=cont; i>0; i--){ //Inverts binary and writes in stdout
    v[i] = res%10;
    res=res/10;
    printf("%d",v[i]);
    if(looper%4==0)
      printf(" ");
    looper--;
  }
}

int binary_to_decimal(int num){
  int exp=0, soma=0;
  while(num/10>0){
    int dig = num%10;
    if(dig == 1){
      soma=soma+pow(2,exp);
    }
    num=num/10;
    exp++;
  }
  int dig = num%10;
  if(dig == 1){
    soma=soma+pow(2,exp);
  }
  return soma;
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
  if(num%10>1 && check==0){
      printf("\n----- INVALIDO! -----\n");
      check=1;
  }
  return check;
}

int main(void) {
  int function;
  // Ler numero
  do{
    printf("Binário (0) ou decimal (1)? ");
    scanf("%d",&function);
    if(function !=0 && function !=1)
      printf("\n----- INVALIDO! -----\n");
  }while(function !=0 && function !=1);
  int num;

  //Decimal
  if(function==1){  
    printf("Digite um número: \n");
    scanf("%d",&num);

    decimal_to_binary(num);
    
  }

  //Binario
  else{
    int check;
    do{
      printf("Introduza um número binário: ");
      scanf("%d",&num);
      check=binary_checker(num);
    }while(check==1);
    int result = binary_to_decimal(num);
    printf("%d", result);
  }
  
  return 0;
}