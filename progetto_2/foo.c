#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cmpStr(const char* str1, const char* str2)
{
    int ret = 0;
    if(str1 != NULL && str2 != NULL) {
        size_t maxLen = strlen(str1) >= strlen(str2) ? strlen(str1) : strlen(str2);
        for(size_t i = 0; !ret && i < maxLen; i++) {
            if(tolower(str1[i]) > tolower(str2[i])) {
                ret = 1;
            } else if (tolower(str1[i]) < tolower(str2[i])) {
                ret = -1;
            }
        }
    }
    return ret;
}

int main(void)
{
    const char* name = "paolo";
    const char* nome = "ppaolo";
    printf("%d\n", cmpStr(name, nome));
    return 0;
}
