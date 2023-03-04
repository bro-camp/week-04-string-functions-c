#include <stdio.h>

int getline(char line[], int max_line_length);

void exit_();
int string_length(char str[]);
int string_concatenation(char str_1[], char str_2[], char concatenated_str[]);
void string_reverse(char str[], char reversed_str[]);

int exit_flag = 1;

int main() {
  char choice;
  char str_1[101];
  char str_2[101];
  char concatenated_str[201];

  do {
    printf("\n 1. Exit");
    printf("\n 2. String Length");
    printf("\n 3. String Concatenation");
    printf("\n 4. String Reverse");

    printf("\n\nEnter a number from 1-4 to choose an operation: ");
    scanf("%c", &choice);

    /*
     * String input will not work because scanf() creates a '\n' in buffer.
     * Use getchar() to read that '\n' character.
     */
    getchar();

    if (choice == '1') {
      printf("\nExiting!!!\n");
      exit_();

    } else if (choice == '2') {
      printf("\nEnter a string [max 100 characters]: \n");
      getline(str_1, sizeof(str_1));
      printf("\nLength of the string is %d\n", string_length(str_1));

    } else if (choice == '3') {
      printf("\nEnter first string [max 100 characters]: \n");
      getline(str_1, sizeof(str_1));
      printf("\nEnter second string [max 100 characters]: \n");
      getline(str_2, sizeof(str_2));
      string_concatenation(str_1, str_2, concatenated_str);
      printf("\nConcatenated string is \"%s\"\n", concatenated_str);

    } else if (choice == '4') {
      printf("\nEnter a string [max 100 characters]: \n");
      getline(str_1, sizeof(str_1));
      string_reverse(str_1, str_2);
      printf("\nReversed string is \"%s\"\n", str_2);

    } else {
      printf("\nWrong input!!!\n");
    }

    printf("\n");

  } while (exit_flag);

  printf("\n\n\n");

  return 0;
}

void exit_(void) { exit_flag = 0; }

/* getline() reads a line into s and returns length */
int getline(char s[], int limit) {
  int i;
  int c;

  /* Use (limit - 2) for extra null character and upper bound */
  for (i = 0; i <= (limit - 2) && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  s[i] = '\0';

  return i;
}

int string_length(char str[]) {
  int i = 0;

  while (str[i] != '\0')
    ++i;

  return i;
}

/* string_concatenation() concatenates two strings and returns length */
int string_concatenation(char str_1[], char str_2[], char c_str[]) {
  int i;
  int j = 0;

  for (i = 0; str_1[i] != '\0'; ++i, ++j) {
    c_str[j] = str_1[i];
  }

  for (i = 0; str_2[i] != '\0'; ++i, ++j) {
    c_str[j] = str_2[i];
  }

  c_str[j] = '\0';

  return j;
}

void string_reverse(char str[], char reversed_str[]) {
  int i;
  int j;
  int length = string_length(str);

  for (i = 0, j = length - 1; str[i] != '\0'; ++i, --j) {
    reversed_str[j] = str[i];
  }

  reversed_str[i] = '\0';
}
