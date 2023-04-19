#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRINGS 5

// Function to count the number of vowels or consonants in a string
void count_chars(char *str, char comparison_type, int *counts) {
    int i;
    int len = strlen(str);
    char c;

    for (i = 0; i < len; i++) {
        c = str[i];

        if (comparison_type == 'V') {
            switch (c) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                
                    counts[c]++;
                    break;
                default:
                    break;
            }
        }
        else {
            if (c >= 'a' && c <= 'z') {
                counts[c - 'a']++;
            }
            }
    }
}

int main() {
    int num_strings;
    char comparison_type;
    char input_str[100];
    int i, j;
    int counts[26] = {0};
    char *strings[MAX_STRINGS];


    printf("No.of strings to be compared: "); //Input is entered 
    scanf("%d", &num_strings);

    while (num_strings < 2 || num_strings > MAX_STRINGS) {
        printf("Enter the valid number of strings (minimum 2, maximum %d): ", MAX_STRINGS);
        scanf("%d", &num_strings);
    }

   
    for (i = 0; i < num_strings; i++)  // Input provided for each string
    {
        printf("Enter string #%d: ", i+1);
        scanf("%s", input_str);
        strings[i] = strdup(input_str);
    }

    
    printf("Do you want to compare by vowels or consonants? (V/C) ");  // Ask user whether they want to compare vowels or consonants from provided strings
    scanf(" %c", &comparison_type);

    while (comparison_type != 'V' && comparison_type != 'C')  // Check if comparison is valid or provide required input
    {
        printf("Please enter a valid comparison type (V for vowels, C for consonants): ");
        scanf(" %c", &comparison_type);
    }

    
    for (i = 0; i < num_strings; i++) // Loop through each of the provided string and count the vowels or consonants from the given string
    {
        count_chars(strings[i], comparison_type, counts);
    }

    // Display the counts
    for (i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            printf("Number of %c: %d\n", 'a'+i, counts[i]);
        }
    }

   

    return 0;
}
