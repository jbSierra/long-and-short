#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

// convert to uppercase and write to first destination file
void function1(char *line, FILE *outFile1);

//  convert line to lowercase and write to second destination file
void function2(char *line, FILE *outFile2);

int main(int argc, char *argv[])
{
    // ensure filename and search term are entered
    if (argc != 4)
    {
        printf("must input source file and BOTH output files\n");
        exit(1);
    }

    // declarations
    char *srcFile = argv[1];
    char *outFile1 = argv[2];
    char *outFile2 = argv[3]; 
    char line[256];
    int lines1 = 0;
    int lines2 = 0;

    // open source file to read
    FILE *in = fopen(srcFile, "r");

    // error handling
    if (!in)
    {
        printf("Can't open source file for reading\n");
        exit(1);
    }

    // open output file 1 to write
    FILE *out1 = fopen(outFile1, "w");

    // error handling
    if (!out1)
    {
        printf("Can't open 1st output file for writing\n");
        exit(1);
    }

    // open output file 2 to write
    FILE *out2 = fopen(outFile2, "w");

    // error handling
    if (!out2)
    {
        printf("Can't open 2nd output file for writing\n");
        exit(1);
    }

    // iterate line by line through input file
    while (fgets(line, sizeof(line), in))
    {
        // if length of line <20
        if (strlen(line) <= 20)
        {
            // function1
            function1(line, out1);
            lines1++;
        }
        else
        {
            // function2
            function2(line, out2);
            lines2++;
        }
    }
    // print number of lines to each file 
    printf("%d lines written to %s\n", lines1, outFile1);
    printf("%d lines written to %s\n", lines2, outFile2);

    // close files
    fclose(in);
    fclose(out1);
    fclose(out2);
}

void function1(char *line, FILE *outFile1)
{
    for (int n = 0; line[n] != '\0'; n++)
    {    
        line[n] = toupper(line[n]);
    }
    fputs(line, outFile1);
}

void function2(char *line, FILE *outFile2)
{
    for (int n = 0; line[n] != '\0'; n++)
    {    
        line[n] = tolower(line[n]);
    }
    fputs(line, outFile2);
}