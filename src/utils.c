#include "utils.h"



void shift_removal(void **on, int from, int to){
    for (int i = from; i < to; i++)
    {
        on[i] = on[i+1];
    }
    
}