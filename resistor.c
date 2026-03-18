#include <stdio.h>
#include <string.h>

int main()
{
    printf("    .----._____.----.\n");
    printf("___/ Resistor  Color \\___\n");
    printf("   \\ Code Calculator /\n");
    printf("    '----'     '----'\n");

    // Open band1.txt file
    char line1[500];
    FILE *hand1;
    hand1 = fopen("table.txt", "r");
    while (fgets(line1, 500, hand1) != NULL)
    {
        printf("%s", line1);
    }

    // 1st Bands Input menu
    printf("\nEnter 1st Band color > ");
    char band1[10];
    fgets(band1, 10, stdin);
    band1[strcspn(band1, "\n")] = '\0';

    // 2st Bands Input menu
    printf("Enter 2st Band color > ");
    char band2[10];
    fgets(band2, 10, stdin);
    band2[strcspn(band2, "\n")] = '\0';

    // multiplier input menu
    printf("Enter a multiplier > ");
    int multi;
    scanf("%d", &multi);

    // combine band2 into band1
    strcat(band1, band2);
    // convert band1 into int
    int combine;
    sscanf(band1, "%d", &combine);

    //get the value of 10^multi
    int n;
    int power = 1;
    for (n=1; n<=multi; n++)
    {
        power = power * 10;
    }

    // print out the result
    char percent[] = "%";
    int result = combine * power;
    printf("%d ohm ± 20%s\n", result, percent);

}
