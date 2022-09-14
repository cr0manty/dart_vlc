// #include <stdio.h>

// #include <time.h>



// char* get_timestamp() {
//     char *timestamp = (char *)malloc(sizeof(char) * 16);
//     time_t ltime;
//     ltime=time(NULL);
//     struct tm *tm;
//     tm=localtime(&ltime);

//     sprintf(timestamp,"%04d%02d%02d%02d%02d%02d", tm->tm_year+1900, tm->tm_mon, 
//         tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
//     return timestamp;
// }

// void print_to_file(const char* data) {
//     char* filename = (char*) malloc(100 * sizeof(char));
//     char* timestamp = get_timestamp();
//     strcat(filename, "logs_");
//     strcat(filename, timestamp);
//     strcat(filename, ".txt");


//     FILE* file = fopen(timestamp, "w");

//     if (!file) {
//         printf("Ooops, file was not opened");
//         return;
//     }

//     fprintf(file, data);
//     free(filename);
//     free(timestamp);
// }