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

    char ln[] = "=";
    int ln_length;

    // separator line
    for (ln_length = 1; ln_length < 70; ln_length++)
    {
        printf("%s", ln);
    }
    // choose type of band
    int num_band;
    printf("\n# Select the number of band\n");
    printf("  [ 3 bands = 3\t\t  ]\n  [ 4 bands = 4\t\t  ]\n  [ 5 bands = 5\t\t  ]\n  [ 6 bands = 6\t\t  ]\n  [ Exit    = Ctr + c\t  ]\n");
    printf("  > ");
    scanf("%d", &num_band);
    while (num_band != 0)
    {
        while (num_band >= 3 && num_band <= 6)
        {
            if (num_band == 3)
            {
                // Open 3bands.txt file
                printf("\n    .--._____.--.");
                printf("\n--=(|| 3 Bands  |)=----------");
                printf("\n    '--'     '--'\n");

                char line_3b[2000];
                FILE *hand_3b;
                hand_3b = fopen("3bands.txt", "r");
                while (fgets(line_3b, 2000, hand_3b) != NULL)
                {
                    printf("%s", line_3b);
                }
                // input warn
                printf("\n _\n(i) Input must be a number that include in the tabel!\n");

                // 1st 3 Bands Input menu
                int band3_1;
                printf("\n# Enter 1st Band color > ");
                scanf("%d", &band3_1);
                while (band3_1 < 1 || band3_1 > 9)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", band3_1);
                    printf("  /_*_\\ 1st Band > ");
                    scanf("%d", &band3_1);
                }
                // 2st 3 Bands Input menu
                int band3_2;
                printf("\n# Enter 2nd Band color > ");
                scanf("%d", &band3_2);
                while ( band3_2 < 0 || band3_2 > 9)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", band3_2);
                    printf("  /_*_\\ 2nd Band > ");
                    scanf("%d", &band3_2);
                }
                // multiplier 3 bands input menu
                int multi_3b;
                printf("\n# Enter 3rd Band color > ");
                scanf("%d", &multi_3b);
                while (multi_3b < -3 || multi_3b > 9)
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
                // if value of multi_3b >= 0 and <= 9 (positive)
                int i;
                if (multi_3b >= 0 && multi_3b <= 9 )
                {
                    long power_3b = 1;
                    for (i = 1; i <= multi_3b; i++)
                    {
                        power_3b = power_3b * 10;
                    }
                    // multiply the combine_3b with power_3b
                    long result_3b = combine_3b * power_3b;
                    // print out the 3 bands result
                    char percent[] = "%";
                    printf("___________________________\n");
                    printf("\n-Result = %li ohm ± 20%s\n\n", result_3b, percent);
                }

                // if value of multi_3b >= -3 and < 0 (negative)
                else if (multi_3b >= -3 && multi_3b < 0)
                {
                    float fpower_3b = 1.0;
                    for (i = 0; multi_3b < i; multi_3b++)
                    {
                        fpower_3b = fpower_3b * 10;
                    }
                    // divided 1 with fpower_3b
                    float fpowmin_3b = 1 / fpower_3b;
                    // multiply the combine_3b with fpowmin_3b
                    float result_3b = combine_3b * fpowmin_3b;
                    //print out the 3 bands result
                    char percent[] = "%";
                    printf("___________________________\n");
                    printf("\n-Result = %g ohm ± 20%s\n\n", result_3b, percent); 
                } 
            }

            if (num_band == 4)
            {
                // Open 4bands.txt file
                printf("\n    .--._____.--.");
                printf("\n--=(|| 4 Bands ||)=----------");
                printf("\n    '--'     '--'\n");

                char line_4b[2000];
                FILE *hand_4b;
                hand_4b = fopen("4bands.txt", "r");
                while (fgets(line_4b, 2000, hand_4b) != NULL)
                {
                    printf("%s", line_4b);
                }
                // input warn
                printf("\n _\n(i) Input must be a number that include in the tabel!\n");

                // 1st 4 Bands Input menu
                int band4_1;
                printf("\n# Enter 1st Band color > ");
                scanf("%d", &band4_1);
                while (band4_1 < 1 || band4_1 > 9)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", band4_1);
                    printf("  /_*_\\ 1st Band > ");
                    scanf("%d", &band4_1);
                }
                // 2st 4 Bands Input menu
                int band4_2;
                printf("\n# Enter 2nd Band color > ");
                scanf("%d", &band4_2);
                while ( band4_2 < 0 || band4_2 > 9)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", band4_2);
                    printf("  /_*_\\ 2nd Band > ");
                    scanf("%d", &band4_2);
                }
                // 3rd multiplier 4 bands input menu
                int multi_4b;
                printf("\n# Enter 3rd Band color > ");
                scanf("%d", &multi_4b);
                while (multi_4b < -3 || multi_4b > 9)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", multi_4b);
                    printf("  /_*_\\ 3rd Band > ");
                    scanf("%d", &multi_4b);
                }

                // 4th Tolerance 4 bands input menu
                float tolerance_4b[] = {0, 1, 2, 0.05, 0.02, 0.5, 0.25, 0.1, 0.01, 5, 10};
                int tolnum_4b;
                printf("\n# Enter 4th Band color > ");
                scanf("%d", &tolnum_4b);
                while (tolnum_4b < 1 || tolnum_4b > 10)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", tolnum_4b);
                    printf("  /_*_\\ 4th Band > ");
                    scanf("%d", &tolnum_4b);
                }

                // Convert into str
                char str_band4_1[10];
                char str_band4_2[10];
                sprintf(str_band4_1, "%d", band4_1);
                sprintf(str_band4_2, "%d", band4_2);

                // combine str_band4_2 into str_band4_1
                strcat(str_band4_1, str_band4_2);

                // convert str_band4_2 into int
                int combine_3b;
                sscanf(str_band4_1, "%d", &combine_3b);
                
                // make 10^multi_4b
                // if value of multi_4b >= 0 and <= 9 (positive)
                int i;
                if (multi_4b >= 0 && multi_4b <= 9 )
                {
                    long power_3b = 1;
                    for (i = 1; i <= multi_4b; i++)
                    {
                        power_3b = power_3b * 10;
                    }
                    // multiply the combine_3b with power_3b
                    long result_3b = combine_3b * power_3b;
                    // print out the 4 bands result
                    char percent[] = "%";
                    printf("___________________________\n");
                    printf("\n-Result = %li ohm ± %g%s\n\n", result_3b, tolerance_4b[tolnum_4b], percent);
                }

                // if value of multi_4b >= -3 and < 0 (negative)
                else if (multi_4b >= -3 && multi_4b < 0)
                {
                    float fpower_3b = 1.0;
                    for (i = 0; multi_4b < i; multi_4b++)
                    {
                        fpower_3b = fpower_3b * 10;
                    }
                    // divided 1 with fpower_3b
                    float fpowmin_3b = 1 / fpower_3b;
                    // multiply the combine_3b with fpowmin_3b
                    float result_3b = combine_3b * fpowmin_3b;
                    //print out the 4 bands result
                    char percent[] = "%";
                    printf("___________________________\n");
                    printf("\n-Result = %g ohm ± %g%s\n\n", result_3b, tolerance_4b[tolnum_4b], percent);
                } 
            }

            if (num_band == 5)
            {
                // Open 5bands.txt file
                printf("\n    .--._____.--.");
                printf("\n--=(|||5 Bands ||)=----------");
                printf("\n    '--'     '--'\n");

                char line_5b[2000];
                FILE *hand_5b;
                hand_5b = fopen("5bands.txt", "r");
                while (fgets(line_5b, 2000, hand_5b) != NULL)
                {
                    printf("%s", line_5b);
                }

                // input warn
                printf("\n _\n(i) Input must be a number that include in the tabel!\n");

                // 1st 5 Bands Input menu
                int band5_1;
                printf("\n# Enter 1st Band color > ");
                scanf("%d", &band5_1);
                while (band5_1 < 1 || band5_1 > 9)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", band5_1);
                    printf("  /_*_\\ 1st Band > ");
                    scanf("%d", &band5_1);
                }

                // 2st 5 Bands Input menu
                int band5_2;
                printf("\n# Enter 2nd Band color > ");
                scanf("%d", &band5_2);
                while ( band5_2 < 0 || band5_2 > 9)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", band5_2);
                    printf("  /_*_\\ 2nd Band > ");
                    scanf("%d", &band5_2);
                }

                // 3rd 5 bands input menu
                int band5_3;
                printf("\n# Enter 3rd Band color > ");
                scanf("%d", &band5_3);
                while (band5_3 < 0 || band5_3 > 9)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", band5_3);
                    printf("  /_*_\\ 3rd Band > ");
                    scanf("%d", &band5_3);
                }

                // 4th multiplier 5 bands input menu
                int multi_5b;
                printf("\n# Enter 4rd Band color > ");
                scanf("%d", &multi_5b);
                while (multi_5b < -3 || multi_5b > 9)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", multi_5b);
                    printf("  /_*_\\ 4th Band > ");
                    scanf("%d", &multi_5b);
                }

                // 5th Tolerance 5 bands input menu
                float tolerance_5b[] = {0, 1, 2, 0.05, 0.02, 0.5, 0.25, 0.1, 0.01, 5, 10};
                int tolnum_5b;
                printf("\n# Enter 5th Band color > ");
                scanf("%d", &tolnum_5b);
                while (tolnum_5b < 1 || tolnum_5b > 10)
                {
                    printf("    _\n");
                    printf("   /|\\  (%d) Not included!\n", tolnum_5b);
                    printf("  /_*_\\ 5th Band > ");
                    scanf("%d", &tolnum_5b);
                }

                // Convert into str
                char str_band5_1[10];
                char str_band5_2[10];
                char str_band5_3[10];
                sprintf(str_band5_1, "%d", band5_1);
                sprintf(str_band5_2, "%d", band5_2);
                sprintf(str_band5_3, "%d", band5_3);

                // combine str_band5_3 and str_band5_2 into str_band5_1
                strcat(str_band5_2, str_band5_3);
                strcat(str_band5_1, str_band5_2);
                // convert into int
                int combine_5b;
                sscanf(str_band5_1 ,"%d", &combine_5b);

                // make 10^multi_4b
                // if value of multi_4b >= 0 and <= 9 (positive)
                int i;
                if (multi_5b >= 0 && multi_5b <= 9 )
                {
                    long power_5b = 1;
                    for (i = 1; i <= multi_5b; i++)
                    {
                        power_5b = power_5b * 10;
                    }
                    // multiply the combine_5b with power_5b
                    long result_5b = combine_5b * power_5b;
                    // print out the 4 bands result
                    char percent[] = "%";
                    printf("___________________________\n");
                    printf("\n-Result = %li ohm ± %g%s\n\n", result_5b, tolerance_5b[tolnum_5b], percent);  
                }

                // if value of multi_5b >= -3 and < 0 (negative)
                else if (multi_5b >= -3 && multi_5b < 0)
                {
                    float fpower_5b = 1.0;
                    for (i = 0; multi_5b < i; multi_5b++)
                    {
                        fpower_5b = fpower_5b * 10;
                    }
                    // divided 1 with fpower_5b
                    float fpowmin_5b = 1 / fpower_5b;
                    // multiply the combine_5b with fpowmin_5b
                    float result_3b = combine_5b * fpowmin_5b;
                    //print out the 4 bands result
                    char percent[] = "%";
                    printf("___________________________\n");
                    printf("\n-Result = %g ohm ± %g%s\n\n", result_3b, tolerance_5b[tolnum_5b], percent); 
                }

            }

            // separator line
            int ln_length;
            for (ln_length = 1; ln_length < 70; ln_length++)
            {
                printf("%s", ln);
            }
            // choose type of band
            printf("\n# Select the number of band\n");
            printf("  [ 3 bands = 3\t\t  ]\n  [ 4 bands = 4\t\t  ]\n  [ 5 bands = 5\t\t  ]\n  [ 6 bands = 6\t\t  ]\n  [ Exit    = 0\t\t  ]\n");
            printf("  > ");
            scanf("%d", &num_band);

        }

        // if num_band input not include
        while (num_band > 6 || num_band < 3)
        {
	        printf("  (!) Not Include!\n\n");
            // separator line
            for (ln_length = 1; ln_length < 70; ln_length++)
            {
                printf("%s", ln);
            }
            // choose type of band
            printf("\n# Select the number of band\n");
            printf("  [ 3 bands = 3\t\t  ]\n  [ 4 bands = 4\t\t  ]\n  [ 5 bands = 5\t\t  ]\n  [ 6 bands = 6\t\t  ]\n  [ Exit    = 0\t\t  ]\n");
            printf("  > ");
            scanf("%d", &num_band);
        }
    }
}
