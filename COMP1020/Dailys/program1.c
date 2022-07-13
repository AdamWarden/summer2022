#include <stdio.h>

char* reverse(char* word);

int main(int argc, char* argv[])
{
    char word[] = "Happy Birthday!";
    
    printf("%s\n", word);
    reverse(word);
    printf("%s\n", word);
    printf("%s\n", word);

    return 0;
}

char* reverse(char* word)
{

   int word_begin = 0;
   int word_end = 0;
   
   for(int i=0; word[i] != '\0'; i++)
   {
        word_end = i;
   }

   while(word_begin < word_end)
   {
    word[word_begin] ^= word[word_end]; //takes the value of word_begin and XOR's it with word_end
    word[word_end] ^= word[word_begin]; //XOR's word_end so now word_begin = word_end
    word[word_begin] ^= word[word_end]; //XOR's word_begin again so now word_end = word_begin and the values are swapped
    //printf("%s\n", word);

    word_begin++; // move on to next value from the start in array
    word_end--; //moves to the next value from the end in array
   }
    return word;
}