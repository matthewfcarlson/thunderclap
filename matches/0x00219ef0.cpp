#include "decls/data/engine/unknown.h"

extern int Find(void*, void*);
extern void Error(void*, const char*);
extern void* Finish(void*, void*, void*);
extern const float Zero_219ef0;

void* Target(void* a, void* b, int* c) {
    int r = Find(b, c);
    ((char*)b)[6] = 0;
    if (r == ((int)((char*)&DAT_00426824))) {
        if (*c == 0) {
            Error(a, "table index is nil");
        } else if (*c == 3) {
            float x = *(float*)((char*)c + 4);
            if (x != x)
                Error(a, "table index is NaN");
        }
        return Finish(a, b, c);
    }
    return (void*)r;
}