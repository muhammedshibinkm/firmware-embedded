#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>

#define MAX_SIZE 100


void search(const char *filename, const char* pattern)
{
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL) {
        perror("file open");
        exit(-1);
    }
    char line[MAX_SIZE];
    while(fgets(line,MAX_SIZE,fptr))
    {
        if(strstr(line,pattern))
        {
            printf("pattern found: %s\n",line);
            return;
            fclose(fptr);
        }
    }
    printf("Pattern not found\n");
    fclose(fptr);
    return;
}

void read_file(const char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL) {
        perror("file open");
        exit(-1);
    }
    char line[MAX_SIZE];
    while(fgets(line, MAX_SIZE, fptr))
    {
        printf("%s\n",line);
    }
    fclose(fptr);
}


void write_file(const char *filename, const char *content)
{
    FILE *fptr = fopen(filename,"w");
    if(fptr == NULL) {
        perror("file open\n");
        exit(1);
    }
    fprintf(fptr,"%s",content);
    fclose(fptr);
}
void copy_file(const char *file1,const char* file2)
{
    FILE* fptr1 = fopen(file1, "r");
    FILE* fptr2 = fopen(file2, "w");
    if(fptr1 == NULL || fptr2 == NULL) {
        perror("file open\n");
        exit(1);
    }
#if 0
    char c;
    while((c = fgetc(fptr1)) !=EOF)
    {
        fputc(c, fptr2);
    }
#else 
    char data[1024];
    size_t bytes_read;
    while((bytes_read = fread(data, 1, sizeof(data),fptr1))> 0)
    {
        fwrite(data, 1, bytes_read, fptr2);
    }
#endif
 /*   if(remove(file1) != 0)
    {
        perror("file removal\n");
        exit(-1);

    }*/
    fclose(fptr1);
    fclose(fptr2);
    return;

}
int count_words(const char *filename)
{
    int count = 0;
    FILE* fptr = fopen(filename,"r");
    if(fptr == NULL) {
        perror("file open\n");
        exit(-1);
    }
    char ch;
    while((ch = fgetc(fptr)) !=EOF)
    {
        if(ch !=' ' || ch !='\0'){
            count++;
        }
    }
    return count;
}


int main()
{
    const char *filename = "text.txt";
    const char *file2 = "test2.txt";//copy_file1_to_file_2
    const char *content = "This is a test file.\n"
                          "content is related to c programming.\n"
                          "C is a mid level,procedural language.\n";
    const char *pattern = "procedural language.";

    write_file(filename,content);
    printf("Read file 1\n:");
    read_file(filename);
    copy_file(filename,file2);
 //   search(filename,pattern);
   
    printf("Read file 2\n:");
    read_file(filename);
 //  printf("no.of words in the file: %d\n",count_words(filename));

}
