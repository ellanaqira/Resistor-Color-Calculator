#include <stdio.h>
#include <string.h>

int main()
{
    // title
    char title[500];
    FILE *hand;
    hand = fopen("title.txt", "r");
    while (fgets(title, 500, hand) != NULL)
    {
        printf("%s", title);
    }

    // choose type of band
    int num_band;
    printf("# Select the number of band\n");
    printf("  [ 3 bands = 3\t\t  ]\n  [ 4 bands = 4\t\t  ]\n  [ 5 bands = 5\t\t  ]\n  [ 6 bands = 6\t\t  ]\n");
    printf("  > ");
    scanf("%d", &num_band);

    if (num_band == 3)
    {
        // Open band1.txt file
        printf("\n    .--._____.--.");
        printf("\n--=(|| 3 Bands  |)=----------");
        printf("\n    '--'     '--'\n");
        
        char line1[2000];
        FILE *hand1;
        hand1 = fopen("band3.txt", "r");
        while (fgets(line1, 2000, hand1) != NULL)
        {
            printf("%s", line1);
        }

        // input warn
        printf("\n _\n(i) Input must be a number that include in the tabel!\n");

        // 1st Bands Input menu
        int band1;
        printf("\n# Enter 1st Band color > ");
        scanf("%d", &band1);
        while (band1 > 9 || band1 < 1)
        {
            printf("    _\n");
            printf("   /|\\  (%d) Not included!\n", band1);
            printf("  /_*_\\ 1st Band color > ");
            scanf("%d", &band1);
        }

        // 2st Bands Input menu
        int band2;
        printf("\n# Enter 2st Band color > ");
        scanf("%d", &band2);
        while (band2 > 9 || band2 < 0)
        {
            printf("    _\n");
            printf("   /|\\  (%d) Not included!\n", band2);
            printf("  /_*_\\ 2st Band color > ");
            scanf("%d", &band2);
        }

        // multiplier input menu
        int multi;
        printf("\n# Enter a Multiplier > ");
        scanf("%d", &multi);
        while (multi > 12 || multi < 0 )
        {
            printf("    _\n");
            printf("   /|\\  (%d) Not included!\n", multi);
            printf("  /_*_\\ Multiplier > ");
            scanf("%d", &multi);
        }
    }

    else
    {
        printf("Comming soon\n");
    }
}
