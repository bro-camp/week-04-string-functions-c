#include <stdio.h>

int getline(char line[], int max_line_length);

void string_copy(char source_str[], char destination_str[]);

int main() {
  char source_str[101];
  char destination_str[101];

  printf("\nEnter a string [max 100 characters]: \n");
  getline(source_str, sizeof(source_str));

  string_copy(source_str, destination_str);

  printf("\nCopied string is \"%s\"\n", destination_str);

  printf("\n\n\n");

  return 0;
}

/* getline() reads a line into s and returns length */
int getline(char s[], int limit) {
  int i;
  int c;

  // Use (limit - 2) for extra null character and upper bound
  for (i = 0; i <= (limit - 2) && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  s[i] = '\0';

  return i;
}

void string_copy(char source[], char dest[]) {
  int i;

  for (i = 0; source[i] != '\0'; ++i) {
    dest[i] = source[i];
  }

  dest[i] = '\0';
}
