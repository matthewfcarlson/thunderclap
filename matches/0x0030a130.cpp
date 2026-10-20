#include "compat/ptr.h"
extern "C" void* alloc(hulk_uintptr);
class Buffer_30a130 {
  public:
    int* begin;
    int* end;
    int* limit;
    bool Init(int n);
};
bool Buffer_30a130::Init(int n) {
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