#include "compat/ptr.h"
extern "C" void freeMem(void*);
extern "C" void* allocMem(hulk_uintptr);
extern "C" unsigned int strlen(const char*);
class Obj_1a3df0 {
    char pad[0xd0];
    char* text;

  public:
    char SetText(const char* s);
};
inline void copy(char* d, const char* s) {
    char c;
    do {
        c = *s;
        s++;
        *d = c;
        d++;
    } while (c);
}
char Obj_1a3df0::SetText(const char* s) {
    freeMem(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)allocMem(strlen(s) + 1);
    copy(text, s);
    return 1;
}