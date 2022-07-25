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
        word_end = i; //sets word_end to the final position in array
   }

   while(word_begin < word_end)
   {
    word[word_begin] ^= word[word_end]; //takes the value of word_begin and XOR's it with word_end, stores result to word_begin
    word[word_end] ^= word[word_begin]; //takes the value of word_end and XOR's it with word_begin, sotres result in word_end
    word[word_begin] ^= word[word_end]; //XOR's word_begin again so now word_end = word_begin and the values are swapped
    /*
    a=1. b=2
    *a = 0001, *b = 0010
    *a = 0001 ^ 0010 = 0011
    *b = 0011 ^ 0010 = 0001
    *a = 0011 ^ 0001 = 0010
    */

    word_begin++; // move on to next value from the start in array
    word_end--; //moves to the next value from the end in array
   }
    return word;
}