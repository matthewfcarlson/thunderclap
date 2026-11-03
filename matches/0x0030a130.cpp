#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void* alloc(hulk_uintptr);
bool owners::Buffer_30a130::FUN_0030a130(int n) {
    if (n != 0) {
        int* p = (int*)alloc(n * 4);
        begin = p;
        if (p != 0) {
            limit = (int*)((char*)p + n * 4);
            end = p;
            return true;
        }
    } else {
        begin = 0;
    }
    end = 0;
    limit = 0;
    return false;
}