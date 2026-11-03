#include "gen/owners.h"
extern void Ensure(int);
extern void Copy(void*, const void*, unsigned int);
void owners::Target_b10a0::FUN_000b10a0(int index, const void* source) {
    if (count <= 0)
        Check(1);
    Copy(data + index * 32, source, 32);
}