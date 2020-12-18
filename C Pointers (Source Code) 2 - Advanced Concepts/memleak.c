#include <stdlib.h>
void callme() {
    char *ptr = malloc(100);
    ptr[0] = '\0'; // Use ptr in some way...
}
int main() {
    callme(); // After this call, a memory leak has occurred
    return 0;
}
