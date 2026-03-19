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
    char ln[] = "=";
    int ln_length;
    for (ln_length = 1; ln_length < 100; ln_length++)
    {
        printf("%s", ln);
    }
    int num_band;
    printf("\n# Select the number of band\n");
    printf("  [ 3 bands = 3\t\t  ]\n  [ 4 bands = 4\t\t  ]\n  [ 5 bands = 5\t\t  ]\n  [ 6 bands = 6\t\t  ]\n  [ exit    = 0\t\t  ]\n");
    printf("  > ");
    scanf("%d", &num_band);
    while (num_band)
    {
        while (num_band >= 0 && num_band <= 6)
        {
            if (num_band == 0)
            {
                printf("\nExit\n\n");
                break;
            }
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
                int band3_1;
                printf("\n# Enter 1st Band color > ");
                scanf("%d", &band3_1);
                while (band3_1 > 9 || band3_1 < 1)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", band3_1);
                    printf("  /_*_\\ 1st Band > ");
                    scanf("%d", &band3_1);
                }

                // 2st Bands Input menu
                int band3_2;
                printf("\n# Enter 2nd Band color > ");
                scanf("%d", &band3_2);
                while (band3_2 > 9 || band3_2 < 0)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", band3_2);
                    printf("  /_*_\\ 2nd Band > ");
                    scanf("%d", &band3_2);
                }

                // multiplier input menu
                int multi_3b;
                printf("\n# Enter 3rd Band color > ");
                scanf("%d", &multi_3b);
                while (multi_3b > 9 || multi_3b < -3 )
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", multi_3b);
                    printf("  /_*_\\ 3rd Band > ");
                    scanf("%d", &multi_3b);
                }

                // Convert into str
                char str_band3_1[10];
                char str_band3_2[10];
                sprintf(str_band3_1, "%d", band3_1);
                sprintf(str_band3_2, "%d", band3_2);

                // combine str_band3_2 into str_band3_1
                strcat(str_band3_1, str_band3_2);

                // convert str_band3_2 into int
                int combine_3b;
                sscanf(str_band3_1, "%d", &combine_3b);
                
                // make 10^multi_3b
                int power_3b = 1.0;
                int n;

                for (n = 1; n <= multi_3b; n++)
                {
                    power_3b = power_3b * 10;
                }

                // multiply the combine_3b with power_3b
                int result_3b = combine_3b * power_3b;
                //print out the 3 bands result
                char percent[] = "%";
                printf("\n-Result : %d ohm ± 20%s\n", result_3b, percent);
                printf("___________________________\n\n");    
            }

            int ln_length;
            for (ln_length = 1; ln_length < 100; ln_length++)
            {
                printf("%s", ln);
            }
            
            printf("\n# Select the number of band\n");
            printf("  [ 3 bands = 3\t\t  ]\n  [ 4 bands = 4\t\t  ]\n  [ 5 bands = 5\t\t  ]\n  [ 6 bands = 6\t\t  ]\n  [ exit    = 0\t\t  ]\n");
            printf("  > ");
            scanf("%d", &num_band);

        }
        while (num_band > 6 || num_band < 0)
        {
            for (ln_length = 1; ln_length < 100; ln_length++)
            {
                printf("%s", ln);
            }
            printf("\n(!) Not Include!\n");
            printf("# Select the number of band\n");
            printf("  [ 3 bands = 3\t\t  ]\n  [ 4 bands = 4\t\t  ]\n  [ 5 bands = 5\t\t  ]\n  [ 6 bands = 6\t\t  ]\n  [ exit    = 0\t\t  ]\n");
            printf("  > ");
            scanf("%d", &num_band);
        }
    }
}
