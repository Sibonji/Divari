#include <stdio.h>

int main()
    {
    char a[100] = {'\0'};

    FILE *fp = fopen("7_10.txt", "w");

    int i = 0;

    for(i = 0; i < 10; i++)
        {
        fprintf(fp,"%5d", 10);
        }

    ftell(fp);

    fseek(fp, 0L, SEEK_SET);

    ftell(fp);

    fgets(a, 100, fp);

    fputs(a, stdin);

    printf("%d\n", 5 * 10);

    fseek(fp, 15L, SEEK_SET);

    char a2[100] = {'\0'};

    fgets(a2, 100, fp);

    fputs(a2, stdin);

    fclose(fp);

    return 0;
    }
