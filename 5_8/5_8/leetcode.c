#include<stdio.h>
#include<string.h>

char* replaceSpace(char* s) {
    char* ss = calloc(strlen(s) * 3 + 1, sizeof(char));

    int i = 0;
    int j = 0;
    while (s[j] != '\0')
    {
        if (s[j] == ' ')
        {
            ss[i++] = '%';           //ох╤аты╪с
            ss[i++] = '2';
            ss[i++] = '0';
            j++;
        }
        else
        {
            ss[i++] = s[j];
            j++;
        }

    }

    return ss;
}

int main()
{

}