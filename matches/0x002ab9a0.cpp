// Same code shape as 0x00290790 (propagated; names are from that function)
#include "compat/ptr.h"
extern void* Alloc(hulk_uintptr);
extern void Init(void*, unsigned int, void*);

class Buffer_2ab9a0 {
  public:
    int* begin;
    int* end;
    bool Create(unsigned int count, void* arg);
};

bool Buffer_2ab9a0::Create(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            Init(p, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}