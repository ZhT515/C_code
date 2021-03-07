#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int BMI()      //º∆À„BMI
{
    int CM = 0;
    int KG = 0;
    float BMI = 0.f;
    while (scanf("%d %d", &KG, &CM) != EOF)
    {
        BMI = KG / (CM / 100.f * CM / 100.f);
        if (BMI < 18.5)
        {
            printf("Underweight\n");
        }
        else if (BMI >= 18.5 && BMI <= 23.9)
        {
            printf("Normal\n");
        }
        else if (BMI > 23.9 && BMI <= 27.9)
        {
            printf("Overweight\n");
        }
        else if (BMI > 27.9)
        {
            printf("Obese\n");
        }
    }
}

void line()//∑¥–±œﬂ
{
    int input = 0;
    int i, j;
    while (scanf("%d", &input) != EOF)
    {
        for (i = 0; i < input; i++)
        {
            for (j = 0; j < i; j++)
            {
                printf(" ");
            }
            printf("*");
            for (j = 0; j < input - i; j++)
            {
                printf(" ");
            }
            printf("\n");
        }
    }
}

void Square()
{
    int input;
    int i, j;
    while (scanf("%d", &input) != EOF)
    {
        for (i = 0; i < input; i++)
        {
            if (i == 0 || i == input - 1)
            {
                for (j = 0; j < input; j++)
                {
                    printf("* ");
                }
            }
            else
            {
                for (j = 0; j < input; j++)
                {
                    if (j == 0 || j == input - 1)
                    {
                        printf("* ");
                    }
                    else
                    {
                        printf("  ");
                    }
                }
            }
            printf("\n");
        }
    }
}

void num()
{
    int input,i;
    while (scanf("%d", &input) != EOF)
    {
        for (i = 0; i < input; i++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void x2()
{
    float a, b, c, d, x1, x2, j, i;
    while (scanf("%f %f %f", &a, &b, &c) != EOF)
    {
        if (a == 0)
        {
            printf("Not quadratic equation\n");
        }
        else
        {
            d = b * b - a * c * 4;
            if (d == 0)
            {
                x1 = (sqrt(d) - b) / (2 * a);
                printf("x1=x2=%.2f\n", x1);
            }
            else if (d > 0)
            {
                x2 = (sqrt(d) - b) / (2 * a);
                x1 = (- b -sqrt(d)) / (2 * a);
                printf("x1=%.2f;", x1);
                printf("x2=%.2f\n", x2);
            }
            else
            {
                j = -b / (2 * a);
                if (j == -0.0)
                {
                    j = 0;
                }
                i = sqrt(-d) / (2 * a);
                printf("x1=%.2f-%.2fi;", j, i);
                printf("x2=%.2f+%.2fi\n", j, i);
            }
        }
    }
}

void charint()
{
    char c;
    scanf("%c", &c);
    printf("%d", c);
}

int main()
{
    //BMI();
    //line();
    //Square();
   // num();
    charint();
    x2();
    return 0;
}