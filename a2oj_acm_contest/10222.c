#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *r0 = "`1234567890-=";
  char *r1 = "qwertyuiop[]\\";
  char *r2 = "asdfghjkl;'";
  char *r3 = "zxcvbnm,./";

  size_t len = 0;
  char *line = 0;

  while(1) {
    size_t n = getline(&line, &len, stdin);
    if (n == EOF) break;

    int i;
    for (i=0; i<n; ++i) {
      char c = line[i];
      if (c == ' ') {
        printf(" ");
        continue;
      }
      if (c == 10) {
        printf("\n");
        continue;
      }

      if (c >= 'A' && c <= 'Z')
        c += 32;

      int i0 = strchr(r0, c) - r0;
      int i1 = strchr(r1, c) - r1;
      int i2 = strchr(r2, c) - r2;
      int i3 = strchr(r3, c) - r3;

      if (i0 > 0)
        printf("%c", r0[i0-2 < 0 ? 0 : i0-2]);
      else if (i1 > 0)
        printf("%c", r1[i1-2 < 0 ? 0 : i1-2]);
      else if (i2 > 0)
        printf("%c", r2[i2-2 < 0 ? 0 : i2-2]);
      else if (i3 > 0)
        printf("%c", r3[i3-2 < 0 ? 0 : i3-2]);
    }
  }

  return 0;
}
