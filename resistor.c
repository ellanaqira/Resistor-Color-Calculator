#include <stdio.h>
#include <string.h>

void flush_input_buffer()
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

// function to read txt file
int read_txt(fpath)
    char fpath[];
{
    char line[5000];
    FILE *hand;
    hand = fopen(fpath, "r");
    while (fgets(line, 5000, hand) != NULL)
    {
        printf("%s", line);
    }
}

// functio to generate separator line
int sline()
{
    int i;
    for (i = 1; i < 70; i++)
    {printf("=");}
}

// function for print warn ascii art
int not_include_warn(n)
    char n[];
{
    printf("     _\n");
    printf("    /|\\  Option not included!\n");
    printf("   /_*_\\ %s band color > ", n);
}

int main()
{
    // title
    read_txt("title.txt");
    
    int input_band;
    int num_band;

    while (1)
    {
        // separator line
        sline();
        // choose type of band
        printf("\n# Select the number of band\n");
        printf("  [ 3 bands = 3\t\t  ]\n  [ 4 bands = 4\t\t  ]\n  [ 5 bands = 5\t\t  ]\n  [ 6 bands = 6\t\t  ]\n  [ Exit    = 0\t\t  ]\n");
        printf("  > ");
        input_band = scanf("%d", &num_band);

        if (num_band == 0)
        {
            printf("\nExit\n");
            break;
        }

        //if num_band input not include
        else if (num_band < 3 || num_band > 6 || input_band == 0)
        {
            // print out not include message
            flush_input_buffer();
            printf("  (!) Not Include!\n\n");
            continue;
        }

        else if (num_band == 3)
        {
            // 3 bands title
            printf("\n    .--._____.--.");
            printf("\n--=(|| 3 Bands  |)=----------");
            printf("\n    '--'     '--'\n");

            // print out 3band.txt
            read_txt("3bands.txt");
            // input warn
            printf("\n _\n(i) Input must be a number that include in the tabel!\n");

            // 1st 3 Bands Input menu
            int input_band3_1;
            int band3_1;
            printf("\n# Enter 1st Band color > ");
            input_band3_1 = scanf("%d", &band3_1);
            while (band3_1 < 1 || band3_1 > 9 || input_band3_1 == 0)
            {
                flush_input_buffer();
                not_include_warn("1st");
                input_band3_1 = scanf("%d", &band3_1);
            }
        
            // 2st 3 Bands Input menu
            int input_band3_2;
            int band3_2;
            printf("\n# Enter 2nd Band color > ");
            input_band3_2 = scanf("%d", &band3_2);
            while ( band3_2 < 0 || band3_2 > 9 || input_band3_2 == 0)
            {
                flush_input_buffer();
                not_include_warn("2nd");
                input_band3_2 = scanf("%d", &band3_2);
            }
        
            // multiplier 3 bands input menu
            int input_multi_3b;
            int multi_3b;
            printf("\n# Enter 3rd Band color > ");
            input_multi_3b = scanf("%d", &multi_3b);
            while (multi_3b < -3 || multi_3b > 9 || input_multi_3b == 0)
            {
                flush_input_buffer();
                not_include_warn("3rd");
                input_multi_3b = scanf("%d", &multi_3b);
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

        else if (num_band == 4)
        {
            // 4 bands title
            printf("\n    .--._____.--.");
            printf("\n--=(|| 4 Bands ||)=----------");
            printf("\n    '--'     '--'\n");

            // print out 4band.txt
            read_txt("4bands.txt");
            // input warn
            printf("\n _\n(i) Input must be a number that include in the tabel!\n");

            // 1st 4 Bands Input menu
            int input_band4_1;
            int band4_1;
            printf("\n# Enter 1st Band color > ");
            input_band4_1 = scanf("%d", &band4_1);
            while (band4_1 < 1 || band4_1 > 9 || input_band4_1 == 0)
            {
                flush_input_buffer();
                not_include_warn("1st");
                input_band4_1 = scanf("%d", &band4_1);
            }
            // 2st 4 Bands Input menu
            int input_band4_2;
            int band4_2;
            printf("\n# Enter 2nd Band color > ");
            input_band4_2 = scanf("%d", &band4_2);
            while ( band4_2 < 0 || band4_2 > 9 || input_band4_2 == 0)
            {
                flush_input_buffer();
                not_include_warn("2nd");
                input_band4_2 = scanf("%d", &band4_2);
            }
            // 3rd multiplier 4 bands input menu
            int input_multi_4b;
            int multi_4b;
            printf("\n# Enter 3rd Band color > ");
            input_multi_4b = scanf("%d", &multi_4b);
            while (multi_4b < -3 || multi_4b > 9 || input_multi_4b == 0)
            {
                flush_input_buffer();
                not_include_warn("3rd");
                input_multi_4b = scanf("%d", &multi_4b);
            }
            // 4th Tolerance 4 bands input menu
            float tolerance_4b[] = {0, 1, 2, 0.05, 0.02, 0.5, 0.25, 0.1, 0.01, 5, 10};
            int input_tolnum_4b;
            int tolnum_4b;
            printf("\n# Enter 4th Band color > ");
            input_tolnum_4b = scanf("%d", &tolnum_4b);
            while (tolnum_4b < 1 || tolnum_4b > 10 || input_tolnum_4b == 0)
            {
                flush_input_buffer();
                not_include_warn("4th");
                input_tolnum_4b = scanf("%d", &tolnum_4b);
            }

            // Convert into str
            char str_band4_1[10];
            char str_band4_2[10];
            sprintf(str_band4_1, "%d", band4_1);
            sprintf(str_band4_2, "%d", band4_2);

            // combine str_band4_2 into str_band4_1
            strcat(str_band4_1, str_band4_2);

            // convert str_band4_2 into int
            int combine_4b;
            sscanf(str_band4_1, "%d", &combine_4b);
            
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
                // multiply the combine_4b with power_3b
                long result_3b = combine_4b * power_3b;
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
                // multiply the combine_4b with fpowmin_3b
                float result_3b = combine_4b * fpowmin_3b;
                //print out the 4 bands result
                char percent[] = "%";
                printf("___________________________\n");
                printf("\n-Result = %g ohm ± %g%s\n\n", result_3b, tolerance_4b[tolnum_4b], percent);
            } 
        }

        if (num_band == 5)
        {
            // 5 bands title
            printf("\n    .--._____.--.");
            printf("\n--=(|||5 Bands ||)=----------");
            printf("\n    '--'     '--'\n");
            // print out 5bands.txt
            read_txt("5bands.txt");
            // input warn
            printf("\n _\n(i) Input must be a number that include in the tabel!\n");

            // 1st 5 Bands Input menu
            int input_band5_1;
            int band5_1;
            printf("\n# Enter 1st Band color > ");
            input_band5_1 = scanf("%d", &band5_1);
            while (band5_1 < 1 || band5_1 > 9 || input_band5_1 == 0)
            {
                flush_input_buffer();
                not_include_warn("1st");   
                input_band5_1 = scanf("%d", &band5_1);
            }

            // 2st 5 Bands Input menu
            int input_band5_2;
            int band5_2;
            printf("\n# Enter 2nd Band color > ");
            input_band5_2 = scanf("%d", &band5_2);
            while ( band5_2 < 0 || band5_2 > 9 || input_band5_2 == 0)
            {
                flush_input_buffer();
                not_include_warn("2nd");
                input_band5_2 = scanf("%d", &band5_2);
            }

            // 3rd 5 bands input menu
            int input_band5_3;
            int band5_3;
            printf("\n# Enter 3rd Band color > ");
            input_band5_3 = scanf("%d", &band5_3);
            while (band5_3 < 0 || band5_3 > 9 || input_band5_3 == 0)
            {
                flush_input_buffer();
                not_include_warn("3rd");
                input_band5_3 = scanf("%d", &band5_3);
            }

            // 4th multiplier 5 bands input menu
            int input_multi_5b;
            int multi_5b;
            printf("\n# Enter 4rd Band color > ");
            input_multi_5b = scanf("%d", &multi_5b);
            while (multi_5b < -3 || multi_5b > 9 || input_multi_5b == 0)
            {
                flush_input_buffer();
                not_include_warn("4th");
                input_multi_5b = scanf("%d", &multi_5b);
            }

            // 5th Tolerance 5 bands input menu
            float tolerance_5b[] = {0, 1, 2, 0.05, 0.02, 0.5, 0.25, 0.1, 0.01, 5, 10};
            int input_tolnum_5b;
            int tolnum_5b;
            printf("\n# Enter 5th Band color > ");
            input_tolnum_5b = scanf("%d", &tolnum_5b);
            while (tolnum_5b < 1 || tolnum_5b > 10 || input_tolnum_5b == 0)
            {
                flush_input_buffer();
                not_include_warn("5th");
               input_tolnum_5b = scanf("%d", &tolnum_5b);
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

    }
    
}
