#include <stdio.h>

/*
  Функция называется sv,
  a - переменную кладем в функцию
  Функция отдаст результат - обычное число = a*a
*/
float sv(float a){
    float kv;
    kv = a * a;
    return kv;
}


// команда - функция main
// запускает программу
int  main() {
    float a; 
    float k;
    
    // Получить a из консоли
    scanf("%f", &a);  ;
   
    /*
      Использовать sv:
      положить в sv переменную a
      результат положить в k
    */ 

    k=sv(a);

    printf("%f\n", k);
    
    return 0;
}
