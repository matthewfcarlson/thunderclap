#include "gen/owners.h"
extern "C" int strcmp(const char*, const char*);
void ReleaseThing(void*);
void owners::Obj_f8c30::FUN_000f8c30(const char* name) {
    int i;
    for (i = 0; i < 128; ++i) {
        void* p = items[i];
        if (p) {
            const char* s = (const char*)((char*)p + 0x18);
            if (strcmp(s, name) == 0) {
                ReleaseThing(items[i]);
                items[i] = 0;
                return;
            }
        }
    }
}