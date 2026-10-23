// Same code shape as 0x00290790 (propagated; names are from that function)
#include "compat/ptr.h"
extern void* FUN_0008d6d0(hulk_uintptr);
extern void FUN_002e54a0(void*, unsigned int, void*);

class Buffer_2e5770 {
  public:
    int* begin;
    int* end;
    bool Create(unsigned int count, void* arg);
};

bool Buffer_2e5770::Create(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)FUN_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002e54a0(p, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}