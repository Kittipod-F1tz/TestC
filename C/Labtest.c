#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    int id;
    float price;
} Data;

void SaveToFile(Data game)
{
    FILE *file = fopen("DataGame.txt", "a");
    if (file != NULL)
    {
        fprintf(file, "%s\t%d\t%f\n", game.name, game.id, game.price);
        fclose(file);
    }
}

void ReadFormFile()
{
    FILE *file = fopen("DataGame.txt", "r");
    if (file != NULL)
    {
        Data game;
        printf("------------------------\n");
        printf("ID\tName\tPrice\n");
        printf("------------------------\n");
        while (fscanf(file, "%s\t%d\t%f\n", game.name, &game.id, &game.price) == 3)
        {
            printf("%s\t%d\t%.2f฿\n", game.name, game.id, game.price);
        }
        printf("------------------------\n");
        fclose(file);
    }
    else
        printf("Not Found File\n");
}

void AddDataToFile()
{
    FILE *file = fopen("DataGame.txt", "a");
    if (file != NULL)
    {
        Data game;
        printf("Enter Data Game\n");
        printf("Enter ID Game :");
        scanf("%d", &game.id);
        printf("Enter Name Game : ");
        scanf("%s", game.name);
        printf("Enter Price ");
        scanf("%f", &game.price);
        SaveToFile(game);
        fclose(file);
        printf("\nAdd Success\n");
        printf("ID\tName\tPrice\n");
        printf("%s\t%d\t%.2f฿\n", game.name, game.id, game.price);
    }
    else
        printf("Not Found File\n");
}

void ReadSpecificData()
{
    int id;
    printf("Enter ID :");
    scanf("%d", &id);
    FILE *file = fopen("DataGame.txt", "r");
    if (file != NULL)
    {
        Data game;
        printf("ID\tName\tPrice\n");
        while (fscanf(file, "%s %d %f", game.name, &game.id, &game.price) == 3)
        {
            if (id == game.id)
            {
                printf("%s\t%d\t%.2f฿\n", game.name, game.id, game.price);
                fclose(file);
            }
        }
    }
    else
    {
        fclose(file);
        printf("Not Found Data");
    }
}

void SearchData()
{
    int type;
    printf("Choose field type for search (1: Name, 2: ID): ");
    scanf("%d", &type);
    Data game;
    if (type == 1)
    {
        char name[50];
        printf("Enter the name to search:");
        scanf("%s", name);
        FILE *file = fopen("DataGame.txt", "r");
        if (file != NULL)
        {
            while (fscanf(file, "%s %d %f", game.name, &game.id, &game.price) == 3)
            {
                if (strcmp(game.name, name) == 0)
                {
                    printf("---------------------------------\n");
                    printf("Name: %s\nID: %d\nPrice: %.2f฿\n", game.name, game.id, game.price);
                }
            }
            fclose(file);
        }
    }
    else if (type == 2)
    {
        int id;
        printf("Enter the ID to search:");
        scanf("%d", &id);
        FILE *file = fopen("DataGame.txt", "r");
        if (file != NULL)
        {
            while (fscanf(file, "%s %d %f", game.name, &game.id, &game.price) == 3)
            {
                if (id == game.id)
                {
                    printf("---------------------------------\n");
                    printf("Name: %s\nID: %d\nPrice: %.2f฿\n", game.name, game.id, game.price);
                }
            }
            fclose(file);
        }
    }
    else
        printf("Invalid Choice");
}

void DeleteDataSome()
{
    char name[50];
    ReadFormFile();
    printf("Enter Name For Delete\n");
    printf("Enter Name :");
    scanf("%s", name);
    FILE *file = fopen("DataGame.txt", "r");
    int count = 0;
    Data game[50];
    if (file != NULL)
    {
        while (fscanf(file, "%s %d %f", game[count].name, &game[count].id, &game[count].price) == 3)
        {
            count++;
        }
        fclose(file);
    }
    file = fopen("DataGame.txt", "w");
    if (file != NULL)
    {
        for (int i = 0; i < count; i++)
        {
            if (strcmp(game[i].name, name) != 0)
            {
                fprintf(file, "%s %d %.2f\n", game[i].name, game[i].id, game[i].price);
            }
        }
        printf("You Delete Name : %s Success\n", name);
        fclose(file);
    }
}

void DeleteAllData()
{
    int num;
    printf("1.Delete All Data\n");
    printf("2.Delete File\n");
    printf("Your Choice :");
    scanf("%d", &num);
    if (num == 1)
    {
        FILE *file = fopen("DataGame.txt", "w");
        fclose(file);
        printf("Delete Data Success\n");
    }
    else if (num == 2)
    {
        remove("DataGame.txt");
        printf("Remove File Success\n");
    }
    else
        printf("Invalid Choice");
}

void main()
{
    int choice;
    Data game1 = {"Apex", 101, 300.50};
    Data game2 = {"Sim3", 102, 790.75};
    // ข้อมูลตั้งต้น
    SaveToFile(game1);
    SaveToFile(game2);
    do
    {
        printf("---------------------------------\n");
        printf("1.Read All Data\n");
        printf("2.Read Specific Data\n");
        printf("3.Search Data\n");
        printf("4.Add Data\n");
        printf("5.Delete Some Data\n");
        printf("6.Delete All Data Or Delete File\n");
        printf("7.Exit\n");
        printf("---------------------------------\n");
        printf("Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ReadFormFile();
            break;
        case 2:
            ReadSpecificData();
            break;
        case 3:
            SearchData();
            break;
        case 4:
            AddDataToFile();
            break;
        case 5:
            DeleteDataSome();
            break;
        case 6:
            DeleteAllData();
            break;
        case 7:
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (choice != 7);
}