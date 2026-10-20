// Same code shape as 0x002b0fb0 (propagated; names are from that function)
#include "compat/ptr.h"
extern void* Alloc(hulk_uintptr);
extern void Init(void*, unsigned int, void*);
class Buffer_2f9b60 {
  public:
    int* begin;
    int* end;
    bool Make(unsigned int count, void* arg);
};
bool Buffer_2f9b60::Make(unsigned int count, void* arg) {
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