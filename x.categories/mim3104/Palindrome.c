#include <stdio.h>
#include <assert.h>

#include "../common/Bool.h"

typedef Bool (*CharEqual)( char a, char b );
typedef struct Result Result;

struct Result
{
  int start;
  int length;
};

int test_palindrome(
  char* source,
  int length,
  int start,
  Bool even,
  CharEqual cmp
)
{
  int i = even ? start : start-1;
  int j = start+1;
  while (i >= 0 && i < length && cmp( source[i], source[j] ))
  {
    i--;
    j++;
  }
  i++;
  j--;
  return 1+j-i;
}

Result longest_palindrome( char* source, CharEqual cmp )
{
  int n = strlen( source );
  Result r = { 0, 0 };
  int i;
  int is_even;
  for (i = 0; i + r.length/2 < n; i++)
    for (is_even = False; is_even <= True; is_even++)
    {
      int length = test_palindrome( source, n, i, is_even, cmp );
      if (length > r.length)
      {
        r.length = length;
        r.start  = is_even + i - length/2;
      }
    }
  return r;
}

/* ch_compares counts the number of compares performed
   a useful measure of how efficient your algorithm is */

int ch_compares;

Bool ch_equal( char a, char b )
{
  ch_compares++;
  return a == b;
}

int Peek( FILE* f )
{
  int ch = fgetc( f );
  if (ch != EOF) ungetc( ch, f );
  return ch;
}

void readline( FILE* f, char* buffer, int length )
{
  int i = 0;
  while (i < length && Peek( f ) != '\n')
    buffer[i++] = fgetc( f );
  if (i < length)
    fgetc( f ); /* get rid of newline */
  else
    i--;
  assert( i < length );
  buffer[i] = '\0';
}

void underline( FILE* f, Result r )
{
  int i;
  for (i = 0; i < r.start; i++)
    printf( " " );
  for (i = 0; i < r.length; i++)
    printf( "-" );
  printf( "\n" );
}

static const int BUFFER_SIZE = 100;

int main( int argc, char** argv )
{
  char buffer[BUFFER_SIZE];

  while (Peek( stdin ) != EOF)
  {
    readline( stdin, buffer, BUFFER_SIZE );
    printf( "%s\n", buffer );
    ch_compares = 0;
    underline( stdout, longest_palindrome( buffer, ch_equal ) );
  }
  return 0;
}
