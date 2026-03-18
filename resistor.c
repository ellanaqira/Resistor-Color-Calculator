#include <stdio.h>
#include <string.h>

int main()
{
    printf("     .----._____.----.\n");
    printf("____/ Resistor  Color \\____\n");
    printf("    \\ Code Calculator /\n");
    printf("     '----'     '----'\n");

    // Open band1.txt file
    char line1[500];
    FILE *hand1;
    hand1 = fopen("table.txt", "r");
    while (fgets(line1, 500, hand1) != NULL)
    {
        printf("%s", line1);
    }

    // 1st Bands Input menu
    int band1;
    printf("\n# Enter 1st Band color > ");
    scanf("%d", &band1);
    while (band1 > 9 || band1 < 1)
    {
        printf("  _\n");
        printf(" /|\\  (%d) Not included!\n", band1);
        printf("/_*_\\ 1st Band color > ");
        scanf("%d", &band1);
    }

    // 2st Bands Input menu
    int band2;
    printf("\n# Enter 2st Band color > ");
    scanf("%d", &band2);
    while (band2 > 9 || band2 < 0)
    {
        printf("  _\n");
        printf(" /|\\  (%d) Not included!\n", band2);
        printf("/_*_\\ 2st Band color > ");
        scanf("%d", &band2);
    }

    // multiplier input menu
    int multi;
    printf("\n# Enter a Multiplier > ");
    scanf("%d", &multi);
    while (multi > 12 || multi < 0 )
    {
        printf("  _\n");
        printf(" /|\\  (%d) Not included!\n", multi);
        printf("/_*_\\ Multiplier > ");
        scanf("%d", &multi);
    }

}
