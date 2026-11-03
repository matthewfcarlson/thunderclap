#include "gen/owners.h"
int owners::Stack_f9720::FUN_000f9720() {
    int n = count;
    if (n <= 0)
        return 0;
    int v = ((int*)this)[n];
    count = n - 1;
    return v;
}