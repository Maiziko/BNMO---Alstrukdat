#include "set.h"

void CreateSet(Set *S){
    (*S).Length = Nil;
}

boolean isSetEmpty(Set S){
    return S.Length == Nil;
}

void addToSet(Set *S, Eltype e){
    if (!isInSet(*S, e)){
        (*S).buffer[(*S).Length] = e;
        (*S).Length += 1;
    }
}

void removeFromSet(Set *S, Eltype e){
    if (isInSet(*S, e)){
        int i = 0;
        boolean found = false;
        while (i < (*S).Length && !found)
        {
            if (IsKataSama((*S).buffer[i],e))
            {
                (*S).Length--;
                int j = i;
                while (j < (*S).Length)
                {
                    (*S).buffer[j] = (*S).buffer[j + 1];
                    j++;
                }
                found = true;
            }
            i++;
        }
    }
}

boolean isInSet(Set S, Eltype e){
    boolean found = false;
    int i = 0;
    while (i < S.Length && !found)
    {
        if (IsKataSama(S.buffer[i],e))
        {
            found = true;
        }
        i++;
    }
    return found;
}