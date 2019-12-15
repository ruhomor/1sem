#include <stdio.h>

int antcmp(char *n, char *m, int x)
{
    while(--x > 0)
    {
        if(n[x] != m[x])
            return 1;
    }
    return 0;
}
void princh(char c)
{
    int i;
    for(i = 3; i >= 0; i--)
    {
        printf((c >> (i+4)) % 2 == 0 ? "0" : "1");
    }
    printf(" ");
    
    for(i = 3; i >= 0; i--)
    {
        printf((c >> i) % 2 == 0 ? "0" : "1");
    }
    printf(" ");
}
union bytefloat
{
    char b[sizeof(float)];
    float i;
};
union bytedouble
{
    char b[sizeof(double)];
    double i;
};
union bytelong
{
    char b[sizeof(long double)];
    long double i;
};
int main()
{
    float f;
    double d;
    long double dd;
    char c;
    char w[7];
    int i = 0;
    for(i = 0; i < 7; i++)
        w[i] = '\0';
    i = 0;
    union bytefloat bi;
    union bytedouble bd;
    union bytelong bl;
    do
    {
        scanf("%c", &c);
        w[i] = c;
        i++;
    }
    while(c != ' ' && c != '\n');
    if(!antcmp(w, "float", 5))
    {            
        scanf("%f", &f);
        for(i = sizeof(float) - 1; i>=0;i--)
                bi.b[i] = 0;
        bi.i = f;
        for(i = sizeof(float) - 1; i>=0;i--)
            princh(bi.b[i]);
    }
    else if(!antcmp(w, "long", 4))
    {
        i = 0;
        do
        {
            scanf("%c", &c);
            w[i] = c;
            i++;
        }
        while(c != ' ' && c != '\n');
        if(!antcmp(w, "double", 6))
        {
            scanf("%Lf", &dd);
            for(i = sizeof(long double) - 1; i>=0;i--)
                bl.b[i] = 0;
            bl.i = dd;
            for(i = sizeof(long double) - 1; i>=0;i--)
                princh(bl.b[i]);        
        }
    }
    else if(!antcmp(w, "double", 6))
    {
        scanf("%lf", &d);
        for(i = sizeof(double) - 1; i>=0;i--)
            bd.b[i] = 0;
        bd.i = d;
        for(i = sizeof(double) - 1; i>=0;i--)
            princh(bd.b[i]);
    }
    
    printf("\n");
    return 0;
}
