#include "stoub.h"
#include <stddef.h>

int stoub(const char *s, const unsigned short b, int *r) {
  int sign = 1;
  int num = 0;
  int i = 0;
  int ret = 0;
  if (b >= 2 && b <= 36) {

    while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
      i++;
    }

    // Asserzione: i contiene un valore H >= 0 tale che
    // s[0, H - 1] contiene solo spazi bianchi e s[H]
    // non è uno spazio

    if (s[i] == '-') {
      sign = -1;
      i++;
    }

    if (b <= 10) {
      for (; s[i] >= '0' && s[i] <= '0' + (b - 1); i++) {
        num = (num * b) + (s[i] - '0');
      }
    } else {
      for (; (s[i] >= '0' && s[i] <= '9') ||
             (s[i] >= 'A' && s[i] <= 'A' + (b - 10 - 1));
           i++) {
        if (s[i] >= '0' && s[i] <= '9') {
          num = (num * b) + (s[i] - '0');
        } else {
          num = (num * b) + (s[i] - 'A' + 10);
        }
      }
    }
    *r = num * sign;
    ret = 1;
  }
  return ret;
}
