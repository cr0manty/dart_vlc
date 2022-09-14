#include <stdio.h>
#include <unistd.h>
#include <time.h>



char* get_timestamp() {
    char *timestamp = (char *)malloc(sizeof(char) * 16);
    time_t ltime;
    ltime=time(NULL);
    struct tm *tm;
    tm=localtime(&ltime);

    sprintf(timestamp,"%04d%02d%02d%02d%02d%02d", tm->tm_year+1900, tm->tm_mon, 
        tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
    return timestamp;
}

void print_to_file(const char* data) {
    char* filename = (char*)malloc(150 * sizeof(char));
    char* timestamp = get_timestamp();

    char cwd[100];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        return;
    }

    sprintf(filename,  "%s/logs/log_%s.txt", cwd, timestamp);

    FILE* file = fopen(filename, "a");

    if (!file) {
        printf("Ooops, file was not opened");
        return;
    }

    fprintf(file, "%s", data);
    printf("Write to file");

    free(filename);
    fclose(file);
}