#include <stdio.h>
#include <math.h>
struct Direction {
    int x;                  // сдвиг по оси Х
    int y;                  // сдвиг по оси Y
};
struct Point {             // название структуры
    int x;                 // х координата точки
    int y;                 // y координата точки
};
struct Line {               // название структуры
   struct Point start;      // поля структуры
   struct Point finish;
};
void readLine  (struct Line * pa);          // читает отрезок
void printLine (struct Line a);             // печатает отрезок
float  lengthLine(struct Line a);             // длина отрезка
void moveLineX (struct Line * pa, int dx);  // двигает отрезок на dx
void moveLine  (struct Line * pa, struct Direction d);  // двигает отрезок на d

int main() {
    struct Line a;           // объявили переменную a типа struct Line
    struct Direction  d;

    readLine(&a);            // в функцию передается выражение типа struct Line *
    scanf("%d", &(d.x));    // в функцию передается выражение типа int *
    scanf("%d", &(d.y));    // в функцию передается выражение типа int *

    printf("%f\n", lengthLine(a));
    moveLine(&a, d);            // передаем a по адресу, d по значению
    printLine(a);

    return 0;
}
void readPoint (struct Point * p)
{
    scanf("%d%d", &(p->x), &(p->y));
}
void printPoint(struct Point p) {
    printf("%d %d ", p.x, p.y);
}

void readLine(struct Line * pa) {
    // функция должна изменить значение переданного объекта,
    // поэтму объект в функцию передается по адресу
    readPoint( &(pa->start) );
    readPoint( &(pa->finish) );
}
void printLine(struct Line a) {
    // функция НЕ должна изменить значение переданного объекта,
    // поэтму объект в функцию можно передать по значению
    printPoint(a.start);
    printPoint(a.finish);
    printf("\n");
}
float lengthLine(struct Line a) {
    int dx = a.finish.x - a.start.x;
    int dy = a.finish.y - a.start.y;
    return sqrt(dx*dx + dy*dy);
}
void moveLineX(struct Line * pa, int dx) {
    // функция должна изменить значение переданного объекта,
    // поэтму объект в функцию передается по адресу
    pa->start.x = pa->start.x + dx;
    pa->finish.x += dx;
}
void moveLine(struct Line * pa, struct Direction d) {
    pa->start.x += d.x;
    pa->start.y += d.y;
    pa->finish.x += d.x;
    pa->finish.y += d.y;
}
