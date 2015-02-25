#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX_LEN 1000

void invert_words(char sentence[])
{
    int i,j,k;

    for(i=0 ; i<MAX_LEN ; i++)
    {
        j = i;

        /**
        *First i have to find out the words's length
        **/
        while(sentence[j] != ' ' && sentence[j] != '\0' )
        {
            j++;
        }

        j--; //i don't need the ' ' character

        /**
        *Then i invert the word
        **/

        if(j-i > 0) //if more than a letter
        {
            for(k=i ; k< (j-i+1)/2 + i ; k++) // from start to middle
            {
                sentence[k] += sentence[j - (k-i)];                       //invert
                sentence[j - (k-i)] = sentence[k] - sentence[j - (k-i)];  // characters
                sentence[k] = sentence[k]-sentence[j - (k-i)];            // with sum
            }
        }
        i = j+1;
        if(sentence[i] == '\0') break;
    }
}

int main()
{
    char sentence[MAX_LEN];

    cout << "+ --------------------------------------------------------- +" << endl;
    cout << "| This program inverts every word within a sentence without |" << endl;
    cout << "| using any additional strings or characters.               |" << endl;
    cout << "+ --------------------------------------------------------- +" << endl;

    cout << "\nInput  : ";

    gets(sentence);
    invert_words(sentence);

    cout <<"Output : " << sentence << endl;

    return 0 ;
}
