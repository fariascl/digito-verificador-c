/*  Author: Alejandro */
/*  E-mail: farias_io@pm.me */

#include <stdio.h>

int len(int rut){
  int cont = 0;
  while(rut>0){
    rut = rut/10;
    cont++;
  }
  return cont;
}

int calculo(int rut){
  /* Variables locales */
  int largo = len(rut), val[largo], cont = 2, sum = 0, res, i, mod_f, resta;
  float mod;
  /* Fin variables locales */

  for(i=0;i<=largo;i++){
    val[i]=rut%10*cont;
    cont = cont+1;
    if (cont == 8){
      cont = 2;
    }
    rut = rut/10;
  }

  for (i =0;i<largo;i++){
    sum = sum + val[i];
  }

  mod = sum/11; // Se obtiene el modulo
  mod_f= mod*11; // Se multiplica el modulo * 11
  resta = sum-mod_f; // Se resta la sumatoria - el modulo
  res = 11-resta; // Se resta 11 - la diferencia de la sumatoria - el modulo
  return res;
}

int main(void){
  int rut, digito;
  printf("Calcular digito verificador RUT\n");
  printf("Ingrese el RUT sin digito: ");
  scanf("%d", &rut);
  digito = calculo(rut);
  if (digito == 10){
    printf("El digito verificador es: K\n");
    printf("El RUT completo es: %d-K\n", rut);
  }
  else{
    printf("El digito vertificador es: %d\n", digito);
    printf("El RUT completo es: %d-%d\n", rut, digito);
  }
  return 0;
}
