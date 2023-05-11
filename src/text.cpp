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
            next[j++] = k++;
        }
        else
        {
            k = next[k];
        }
    }
    return next;
}
int alp::Text::GetPatternPosition(std::string t,std::string p){
    
}