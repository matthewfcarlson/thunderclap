#include "gen/owners.h"
void owners::X_f9700::FUN_000f9700(int x) {
    if (count < 4) {
        ++count;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + count * 4) = x;
    }
}