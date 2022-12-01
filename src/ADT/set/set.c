#include "set.h"

void CreateSet(Set *S){
    return (*S).Length = Nil;
}

boolean isSetEmpty(Set S){
    return S.Length == Nil;
}

void add(Set *S, Eltype e){
    if (!isIn(*S, e)){
        (*S).buffer[(*S).Length] = e;
        (*S).Length += 1;
    }
}

void remove(Set *S, Eltype e){
    if (isIn(*S, e)){
        int i = 0;
        boolean found = false;
        while (i < (*S).Length && !found)
        {
            if (IsKataSama((*S).buffer[(*S).Length],e))
            {
                (*S).Length--;
                while (i < (*S).Length)
                {
                    (*S).buffer[i] = (*S).buffer[i + 1];
                    i++;
                }
                found = true;
            }
            i++;
        }
    }
}

boolean isIn(Set S, Eltype e){
    boolean found = false;
    int i = 0;
    while (i < S.Length && !found)
    {
        if (IsKataSama(S.buffer[S.Length],e))
        {
            found = true;
        }
        i++;
    }
    return found;
}