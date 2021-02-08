#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

///////////////////////////////////////////////////////////////////////////////////////////

struct hashnode {
    int key;
    char * data;
    struct hashnode * next;
};

void PrintRules ();
void add_elem (char * str, struct hashnode ** list, int size);
void get_elem (char * str, struct hashnode ** list, int size);
void del_elem (char * str, struct hashnode ** list, int size);

///////////////////////////////////////////////////////////////////////////////////////////

int main () {
    int size = 100;

    struct hashnode * list[size];

    assert (list != NULL);

    int i = 0;

    for (i = 0; i < size; i++)
    {
        list[i] = NULL;
    }

    char str[50];

    PrintRules ();

    int cmd;
    scanf ("%d", &cmd);

    int num = 0;

    while(cmd != 4)
    {
        scanf ("%s", str);

        if (cmd == 1)
        {
            printf ("Add element\n");
            add_elem (str, list, size); //заменить на switch
        }
        else if (cmd == 2) get_elem (str, list, size);
        else if (cmd == 3) del_elem (str, list, size);

        scanf("%d", &cmd);
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////

void PrintRules () {
    printf("Вы работаете с программой написанной для урока к Хеш-таблицам.\n"
                  "Данная программа является записной книжкой с номерами телефонов и фамилиями людей.\n\n"
                  "Чтобы записать номер нажмите 1 и запишите фамилию на английском и номер, пример:\n"
                  "1 Sidorov 89171111111\n\n"
                  "Чтобы получить номер нажмите 2 и запишите номер телефона, пример:\n"
                  "2 89171111111\n\n"
                  "Чтобы удалить номер нажмите 3 и запишите номер телефона, пример:\n"
                  "3 89171111111\n\n"
                  "Чтобы закончить выполнение программы нажмите 4, пример:\n"
                  "4\n\n");

    return;
}

///////////////////////////////////////////////////////////////////////////////////////////

void add_elem (char * str, struct hashnode ** list, int size) {
    int i = 0;

    char num[20];

    while (str[i] != ' ') i++;
    while (str[i] == ' ') i++;

    assert(i != 0);

    int j = 0;

    while (str[i] != '\0' && str[i] != ' ')
    {
        num[j] = str[i];

        j++;
        i++;
    }

    int key = 0;

    for (i = 0; i < j; i++)
    {
        key += (num[j] - '0') * i;
    }

    int Hk = key % size;

    struct hashnode * cell = list[Hk];

    if (cell == NULL)
    {
        list[Hk] = (struct hashnode *) calloc (1, sizeof (struct hashnode));
        cell = list[Hk];
    }
    else
    {
        while (cell -> next == NULL)
        {
           cell = cell -> next;
        }
    }

    cell -> next = (struct hashnode *) calloc (1, sizeof (struct hashnode));

    cell -> key = key;
    cell -> data = (char *) calloc(50, sizeof(char));

    for (i = 0; i < 50 && str[i] != ' '; i++)
    {
        cell -> data[i] = str[i];
    }

    cell -> data[i + 1] = '\0';

    return;
}

///////////////////////////////////////////////////////////////////////////////////////////

void get_elem (char * str, struct hashnode ** list, int size) {
    int i = 0;

    char num[20];

    while (str[i] != ' ')
    {
        printf ("%c", str[i]);
        ++i;
    }
    while (str[i] == ' ')
    {
        printf ("%c", str[i]);
        ++i;
    }

    assert(i != 0);

    int j = 0;

    while (str[i] != '\0' || str[i] != ' ')
    {
        num[j] = str[i];

        j++;
        i++;
    }

    int key = 0;

    for (i = 0; i < j; i++)
    {
        key += (num[j] - '0') * i;
    }

    int Hk = key % size;

    struct hashnode * cell = list[Hk];

    int check = 0;

    while (check == 0)
    {
        if (cell -> key != key)
        {
            cell = cell -> next;
        }
        else check = 1;
    }

    printf ("%s", cell -> data);

    return;
}

///////////////////////////////////////////////////////////////////////////////////////////

void del_elem (char * str, struct hashnode ** list, int size) {
    return;
}