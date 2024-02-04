/*
writer.c requirements:

Accepts the following arguments: the first argument is a full 
path to a file (including filename) on the filesystem, referred 
to below as writefile; the second argument is a text string which 
will be written within this file, referred to below as writestr

Exits with value 1 error and print statements if any of the 
arguments above were not specified

Creates a new file with name and path writefile with content 
writestr, overwriting any existing file and assume the path 
exist. Exits with value 1 and error print statement if the 
file could not be created.
*/
#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    openlog("Z-Writer", LOG_PID, LOG_USER);

    // check if the correct number of arguments is provided
    if (argc != 3) {
        printf("Usage: %s <path-including_filename> <text-to-be-written>\n", argv[0]);
        syslog(LOG_ERR, "Invalid number of arguments.");
        return 1; //Return an error code
    }

    char *path = argv[1];
    char *text = argv[2];

    FILE *file = fopen(path, "w");
    fprintf(file, "%s", text);

    // return error code if failed to write file
    if (file == NULL) {
        printf("error writing file");
        syslog(LOG_ERR, "Had an issue writing to %s", path);
        fclose(file);
        return 2;
    }

    // close the file
    fclose(file);
    printf("File written to %s successfully.\n", path);

    syslog(LOG_DEBUG, "Writing %s to %s.\n", text, path);
    closelog();

    return 0;
}