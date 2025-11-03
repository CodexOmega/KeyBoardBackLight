#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    void *memset(void *s, int c, size_t n);
    int n = 10; // Set the size of the array
    int *array = malloc(n * sizeof(int)); // Allocate memory for the array

    // Checking the array for errors
    if (array == NULL) {
        perror("Memory alocation failed");
        return 1;}

    // Initialize the array with zeros
    memset(array, 0, n * sizeof(int));

    FILE *fp;

    while (1) // Runs the "brighnessctl" command to set the backlight, --> brightnessctl must be installed via pacman
    { 
        fp = popen("brightnessctl -d input7::scrolllock set 1", "w");
        if (fp == NULL) {
            perror("popen() failed");
            return 1;
        }
        pclose(fp); // Important to close the pipe
        sleep(2); // Wait 2 second before continuing
    }
    free(array); // Frees the memory
    return 0;
}