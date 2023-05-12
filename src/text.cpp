#include "text.h"

int *alp::Text::GetNextArray(std::string p)
{
    int *next = new int[p.length()];
    next[0] = -1;
    int j = 0;
    int k = -1;
    
    while (j < p.length() - 1)
    {
        if (k == -1 || p[j] == p[k])
        {
            if (next[++j] = next[k++])
                next[j] = next[k];
            else
                next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
    return next;
}
int alp::Text::GetPatternPosition(std::string t, std::string p)
{
    int i = 0;             // Pointer i points to string t(ext)
    int j = 0;             // Pointer j points to string p(attern)

    int lenp = p.length(); // Important! Use lenp variable or get -1 result. string::length() returns an unsigned integer
    int lent = t.length(); // which will be converted to ainteger so that the loop will never start.
    int *next = GetNextArray(p);

    while (i < lent && j < lenp)
    {
        if (j == -1 || t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j >= lenp)
        return i - lenp;
    else
        return -1;
}