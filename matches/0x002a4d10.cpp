#include "compat/ptr.h"
struct E_2a4d10 {
    char b[16];
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern "C" void __cdecl Init(void*, unsigned int, void*);
class Buffer_2a4d10 {
  public:
    E_2a4d10* data;
    E_2a4d10* end;
    char Create(unsigned int count, void* arg);
};
char Buffer_2a4d10::Create(unsigned int count, void* arg) {
    if (data)
        return 0;
    if (count > 0) {
        data = (E_2a4d10*)Alloc(count * sizeof(E_2a4d10));
        if (data) {
            end = data + count;
            Init(data, count, arg);
            return 1;
        }
    }
    data = 0;
    end = 0;
    return 0;
}
