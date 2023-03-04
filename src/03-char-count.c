#include <stdio.h>

int getline(char line[], int max_line_length);

int main() {
  char str[101];
  int i;
  int size;
  int alpha_count = 0;
  int digit_count = 0;
  int special_count = 0;

  printf("\nEnter a string: \n");
  size = getline(str, sizeof(str));

  for (i = 0; i < size; ++i) {
    if (str[i] >= '0' && str[i] <= '9') {
      ++digit_count;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      ++alpha_count;
    } else if (str[i] >= 'a' && str[i] <= 'z') {
      ++alpha_count;
    } else {
      ++special_count;
    }
  }

  printf("\n\nEntered string is: \n\n\"%s\"", str);
  printf("\n\nNumber of Alphabets is:  %d", alpha_count);
  printf("\n\nNumber of Digits is:  %d", digit_count);
  printf("\n\nNumber of Special characters is:  %d", special_count);

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
