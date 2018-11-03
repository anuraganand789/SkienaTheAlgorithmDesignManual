#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare function

void main() {
  // set string
  char *sentence = "I Am Anurag Anand";
  char *word;

  int len = strlen(sentence);
  printf("word length is %d", len);
  printf("\n");
  int last = len - 1;

  for(int i =len-1; i>=0; --i) {
    if(sentence[i] == ' ') {
      //+1 to make space for null charachter
      word = malloc((last-i+1) * sizeof(char));
      strncpy(word, sentence + (i+1) , (last - i));
      word[last-i+1] = '\0';
      printf("%s\n", word);
      //Update to point to last next non- space charchter
      last = i-1;
      free(word);
    }
  }
  //for the first word
    word = malloc(2 * sizeof(char));
    strncpy(word, sentence, 1);
    word[2] = '\0';
    printf("%s\n", word);
    free(word);
}
