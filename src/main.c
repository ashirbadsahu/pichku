#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode_rle(FILE *src, FILE *dest) {
  fseek(src, 0, SEEK_END);
  size_t file_len = ftell(src); // get length of the file
  fseek(src, 0, SEEK_SET);

  char *temp_src = (char *)malloc(
      file_len + 1); // buffer to store source content temporarily
  fread(temp_src, 1, file_len, src);
  temp_src[file_len] = '\0';

  char temp_dest[2048]; // temporary destination
  temp_dest[0] = '\0';

  size_t i = 0;
  while (i < file_len) {
    char key = temp_src[i];
    int count = 1;

    while (i + 1 < file_len && temp_src[i + 1] == key) {
      count++;
      i++;
    }
    char buf[20];
    snprintf(buf, sizeof(buf), "%c%d", key, count);
    strcat(temp_dest, buf);
    i++;
  }
  fprintf(dest, "%s", temp_dest);
  free(temp_src);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  FILE *src; // source file
  src = fopen(argv[1], "rb");
  if (src == NULL) {
    perror("failed to open input file.");
    return 1;
  }

  FILE *dest; // destination file
  dest = fopen(argv[2], "w");
  if (dest == NULL) {
    perror("failed to create output file.");
    fclose(src);
    return 1;
  }

  encode_rle(src, dest);
  fclose(src);
  fclose(dest);
  return 0;
}
