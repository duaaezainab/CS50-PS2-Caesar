#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // int atoi(string s);
#include <ctype.h>  // isdigit - check whether a character is a digit

bool digital_key(string check_key);
char rotate(char c, int num);

int main(int argc, string argv[])

{
  // 1: Takes one comman-line-argument

  if (argc != 2) // if argument count on command line is not equal to 2 (./caesaer counts as 1st and key should ideally be 2nd argument)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  // 2: Calls the function 'digital_key'

  if (digital_key(argv[1])==false)
  {
   printf("Usage: ./caesar key\n");
   return 1;
  }

  else

  // 3: Converts argv[1] to an int

  {
   int n=atoi(argv[1]);
  }

  string plaintext = get_string("plaintext: ");

  int n = strlen(plaintext);
  char ciphertext=0;

  printf("ciphertext: ");

    for (int i = 0; i < n; i++)
  {
    ciphertext=rotate(plaintext[i], atoi(argv[1]));
    printf("%c", ciphertext);
  }
  printf("\n");

  return 0;
}


  // 4: Check if string key input is in digits

bool digital_key(string check_key)

{
    int n = strlen(check_key);

    for (int i = 0; i < n; i++)
  {
      bool check_for_digit=isdigit(check_key[i]);

      if (check_for_digit==0) // since isdigit returns a non-zero int if its argument is a decimal digit and 0 if it is not a decimal digit.
      {
        return false;
      }
  }
  return true;
}

  // 5: Rotate alphabet

char rotate(char c, int num)
  //  rotates that char by that many positions if it’s a letter (i.e., alphabetical),
  //wrapping around from Z to A (and from z to a) as needed.
  //If the char is not a letter, the function should instead return the same char unchanged.
{
  char rotatedx='0';
  char rotatedy='0';
  int x=0;
  int y=0;
   if (isalpha(c)== 0)
   {
    return c;
   }
   else
   if (islower(c) != 0)
   {
    x=  c- 97;
    rotatedx = (x + num)%26 + 97;
    return (char) rotatedx;
    }
    else
    if (isupper(c) != 0)
    {
    y = c - 65;
    rotatedy = (y + num) % 26 + 65;
    }
   return (char) rotatedy;
}
