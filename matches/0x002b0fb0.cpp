#include "compat/ptr.h"
extern void* Alloc(hulk_uintptr);
extern void Init(void*, unsigned int, void*);
class Buffer_2b0fb0 {
  public:
    int* begin;
    int* end;
    bool Make(unsigned int count, void* arg);
};
bool Buffer_2b0fb0::Make(unsigned int count, void* arg) {
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