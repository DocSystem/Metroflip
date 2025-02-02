#include "stringtools.h"

char* get_token(char* psrc, const char* delimit, void* psave) {
    static char sret[512];
    register char* ptr = psave;
    memset(sret, 0, sizeof(sret));

    if(psrc != NULL) strcpy(ptr, psrc);
    if(ptr == NULL) return NULL;

    int i = 0, nlength = strlen(ptr);
    for(i = 0; i < nlength; i++) {
        if(ptr[i] == delimit[0]) break;
        if(ptr[i] == delimit[1]) {
            ptr = NULL;
            break;
        }
        sret[i] = ptr[i];
    }
    if(ptr != NULL) strcpy(ptr, &ptr[i + 1]);

    return sret;
}
