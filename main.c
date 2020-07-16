//Listing 17.2 Equivalence of fprintf to file and stdout

#include <stdio.h>
#include <stdlib.h>

//void clear_kb(void);

int main (void)
{
    FILE *fp;
    float data[5];
    int count;
    char filename[20];

    puts("\nEnter 5 floating-point numerical values. ");

    for(count=0; count<5; count++)
        scanf("%f", &data[count]);

    //get filename and open the file... first clear stdin of any extra characters
    //clear kb();
    fflush(stdin);

    puts("\nEnter a name for the file.");
    gets(filename);

    if((fp = fopen(filename, "w")) == NULL)
    {
        fprintf(stderr, "Error opening file %s.", filename);
        exit(1);
    }
    //write the numerical data to the file and to stdout
    for(count=0; count<5; count++)
    {
        fprintf(fp,"\ndatat[%d] = %f",count, data[count]);
        fprintf(stdout,"\ndatat[%d] = %f",count, data[count]);
    }
    fclose(fp);
    printf("\n");
    return(0);
}

//void clear kb(void)
//{
//    //clears stdin of any waiting characters - can use fflush also
//    char junk[80];
//    gets(junk);
//}

