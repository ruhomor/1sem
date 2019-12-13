#include <stdlib.h>
#include <stdio.h>

char    *convert(const char * str)
{
    char    *start = str;
    char    *end = str;
    int    ch = 0;
    char    *ans;
    char    *pans;
    char    *bufans;
    char    *bbufans;
    int    size = 0;
    char    digit[4];

    ans = (char*)malloc(sizeof(*ans));
    *ans = '\0';
    digit[3] = '\0';
    char v[8] = {'0', '1', '2', '3', '4', '5', '6', '7'};
    while (*end)
        end++;
    end--;
    while (end != start)
    {
        digit[ch++] = *end;
        end--;
        if (ch == 3)
        {
            size++;
            bbufans = (char*)malloc(sizeof(*bbufans) * (size + 1));
            bbufans[size] = '\0';
            bufans = bbufans;
            bufans++;
            if (size > 1)
            {
                pans = ans;
                while (*pans)
                {
                    *bufans = *pans;
                    bufans++;
                    pans++;
                }
            }
            if (strcmp(digit, "000") == 0)
                *bbufans = v[0];
            if (strcmp(digit, "100") == 0)
                *bbufans = v[1];
            if (strcmp(digit, "010") == 0)
                *bbufans = v[2];
            if (strcmp(digit, "110") == 0)
                *bbufans = v[3];
            if (strcmp(digit, "001") == 0)
                *bbufans = v[4];
            if (strcmp(digit, "101") == 0)
                *bbufans = v[5];
            if (strcmp(digit, "011") == 0)
                *bbufans = v[6];
            if (strcmp(digit, "111") == 0)
                *bbufans = v[7];
            free(ans);
            ans = bbufans;
            ch = 0;
        }
    }
    digit[ch++] = *start;
    size++;
    bbufans = (char*)malloc(sizeof(*bbufans) * (size + 1));
    bbufans[size] = '\0';
    bufans = bbufans;
    bufans++;
    if (size > 1)
    {
      pans = ans;
      while (*pans)
      {
        *bufans = *pans;
        bufans++;
        pans++;
      }
    }
    if (ch == 3)
    {
            if (strcmp(digit, "000") == 0)
                *bbufans = v[0];
            if (strcmp(digit, "100") == 0)
                *bbufans = v[1];
            if (strcmp(digit, "010") == 0)
                *bbufans = v[2];
            if (strcmp(digit, "110") == 0)
                *bbufans = v[3];
            if (strcmp(digit, "001") == 0)
                *bbufans = v[4];
            if (strcmp(digit, "101") == 0)
                *bbufans = v[5];
            if (strcmp(digit, "011") == 0)
                *bbufans = v[6];
            if (strcmp(digit, "111") == 0)
                *bbufans = v[7];
    }
    if (ch == 2)
    {
      digit[2] = '0';
      if (strcmp((digit), "000") == 0)
        *bbufans = v[0];
      if (strcmp((digit), "100") == 0)
        *bbufans = v[1];
      if (strcmp((digit), "010") == 0)
        *bbufans = v[2];
      if (strcmp((digit), "110") == 0)
        *bbufans = v[3];
    }
    if (ch == 1)
    {
      digit[1] = '0';
      digit[2] = '0';
      if (strcmp((digit), "000") == 0)
        *bbufans = v[0];
      if (strcmp((digit), "100") == 0)
        *bbufans = v[1];
    }
    free(ans);
    ans = bbufans;
    return (ans);
}

int	main()
{
	char *lol;
	printf("%s\n", lol = convert("1010011"));	// 123
	free(lol);
}
