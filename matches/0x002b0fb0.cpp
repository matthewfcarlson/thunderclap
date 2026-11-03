#include "compat/ptr.h"
#include "gen/owners.h"
extern void* Alloc(hulk_uintptr);
extern void Init(void*, unsigned int, void*);
bool owners::Buffer_2b0fb0::FUN_002b0fb0(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        begin = (int*)Alloc(count * 8);
        if (begin != 0) {
            end = (int*)((char*)begin + count * 8);
            Init(begin, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}