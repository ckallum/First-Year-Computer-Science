#include <stdio.h>
#include <stdlib.h> // For exit()

char *upper_string(char s[]) {
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
   return s;
}

int main()
{
    FILE *fptr1, *fptr2;
    char filename[100], c[100];

    printf("Enter the filename to open for reading \n");
    scanf("%s", filename);

    // Open one file for reading
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    printf("Enter the filename to open for writing \n");
    scanf("%s", filename);

    // Open another file for writing
    fptr2 = fopen(filename, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    // Read contents from file
    fgets(c,100,fptr1);
    while (!feof(fptr1))
    {
        fprintf(fptr2, c);
        fgets(c,100,fptr1);
    }

    printf("Contents copied to %s\n", filename);

    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
