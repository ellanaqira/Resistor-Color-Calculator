#include <stdio.h>
#include <string.h>

// flush input from scanf
void flush_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// resistor band title
void resistor_title(char title[]) {
    printf("\n    .--._____.--.");
    printf("\n--=(%s)=----------", title);
    printf("\n    '--'     '--'\n");
}

// function to read txt file
int read_txt(char fpath[]) {
    char line[5000];
    FILE *hand;
    hand = fopen(fpath, "r");
        if (hand == NULL) {
        printf("Error: cannot open file %s\n", fpath);
        return 1;
    }
    while (fgets(line, 5000, hand) != NULL) {
        printf("%s", line);
    }
    fclose(hand);
    printf("\n _\n(i) Input must be a number that include in the tabel!\n");
    return 0;
}

// functio to generate separator line
void sline() {
    int i;
    for (i = 1; i < 70; i++)
    {printf("=");}
}

// function for print warn ascii art
void not_include_warn(char n[]) {
    printf("     _\n");
    printf("    /|\\  Option not included!\n");
    printf("   /_*_\\ %s band color > ", n);
}

// input menu
void input_menu(int *band , char order[], int min, int max) {
    int input_band;
    printf("\n# Enter %s Band color > ", order);
    input_band = scanf("%d", band);

    while (*band < min || *band > max || input_band == 0) {
        flush_input_buffer();
        not_include_warn(order);
        input_band = scanf("%d", band);
    }
}

// calculate the exponent and print out the result
void power_and_result(int *multi_num, int *tolerance_num, int *combined_num) {
    float tolerance[] = {0, 1, 2, 0.05, 0.02, 0.5, 0.25, 0.1, 0.01, 5, 10, 20};
    int i;
    // if value of multi_num >= 0 and <= 9 (positive)
    if (*multi_num >= 0 && *multi_num <= 9 ) {
        long power = 1;
        for (i = 1; i <= *multi_num; i++) {
            power = power * 10;
        }
        // *multiply the combined_num with power
        long result_3b = *combined_num * power;
        // print out the result
        char percent[] = "%";
        printf("___________________________\n");
        printf("\n-Result = %li ohm ± %g%s\n\n", result_3b, tolerance[*tolerance_num], percent);
    }

    // if value of *multi_num >= -3 and < 0 (negative)
    else if (*multi_num >= -3 && *multi_num < 0) {
        float float_power = 1.0;
        for (i = 0; i < -*multi_num; i++)
        {
            float_power = float_power * 10;
        }
        // divided 1 with float_power
        float float_powmin = 1 / float_power;
        // multiply the combined_num with float_powmin
        float result_3b = *combined_num * float_powmin;
        //print out the result
        char percent[] = "%";
        printf("___________________________\n");
        printf("\n-Result = %g ohm ± %g%s\n\n", result_3b, tolerance[*tolerance_num], percent);
    }
}

// Main function
int main() {
    // title
    read_txt("title.txt");
    int input_band;
    int num_band;
    while (1) {
        // separator line
        sline();
        // choose type of band
        printf("\n# Select the number of band\n");
        printf("  [ 3 bands = 3\t\t  ]\n  [ 4 bands = 4\t\t  ]\n  [ 5 bands = 5\t\t  ]\n  [ 6 bands = 6\t\t  ]\n  [ Exit    = 0\t\t  ]\n");
        printf("  > ");
        input_band = scanf("%d", &num_band);

        if (num_band == 0) {
            printf("\nExit\n");
            break;
        }

        //if num_band input not include
        else if (num_band < 3 || num_band > 6 || input_band == 0) {
            // print out not include message
            flush_input_buffer();
            printf("  (!) Not Include!\n\n");
            continue;
        }

        else if (num_band == 3) {
            // 3 bands title
            resistor_title("|| 3 Bands  |");
            // print out 3band.txt
            read_txt("3bands.txt");

            // 1st 3 Bands Input menu
            int band3_1;
            input_menu(&band3_1, "1st", 1, 9);
            // 2st 3 Bands Input menu
            int band3_2;
            input_menu(&band3_2, "2nd", 0, 9);
            // multiplier 3 bands input menu
            int multi_3b;
            input_menu(&multi_3b, "3rd", -3, 9);

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

            int tolnum_3 = 11;
            power_and_result(&multi_3b, &tolnum_3, &combine_3b);
        }

        else if (num_band == 4) {
            // 4 bands title
            resistor_title("|| 4 Bands ||");
            // print out 4band.txt
            read_txt("4bands.txt");
            
            // 1st 4 Bands Input menu
            int band4_1;
            input_menu(&band4_1, "1st", 1, 9);
            // 2st 4 Bands Input menu
            int band4_2;
            input_menu(&band4_2, "2nd", 0, 9);
            // 3rd multiplier 4 bands input menu
            int multi_4b;
            input_menu(&multi_4b, "3rd", -3, 9);
            // 4th Tolerance 4 bands input menu
            int tolnum_4b;
            input_menu(&tolnum_4b, "4th", 1, 9);

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
            
            power_and_result(&multi_4b, &tolnum_4b, &combine_4b);
        }

        if (num_band == 5) {
            // 5 bands title
            resistor_title("|||5 Bands ||");
            // print out 5bands.txt
            read_txt("5bands.txt");
            
            // 1st 5 Bands Input menu
            int band5_1;
            input_menu(&band5_1, "1st", 1, 9);
            // 2st 5 Bands Input menu
            int band5_2;
            input_menu(&band5_2, "2nd", 0, 9);
            // 3rd 5 bands input menu
            int band5_3;
            input_menu(&band5_3, "3rd", 0, 9);
            // 4th multiplier 5 bands input menu
            int multi_5b;
            input_menu(&multi_5b, "4th", -3, 9);
            // 5th Tolerance 5 bands input menu
            int tolnum_5b;
            input_menu(&tolnum_5b, "5th", 1, 10);

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

            power_and_result(&multi_5b, &tolnum_5b, &combine_5b);
        }
    }
}