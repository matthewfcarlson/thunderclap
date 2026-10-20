#include "compat/ptr.h"
extern "C" unsigned int __cdecl strlen(const char*);
class Obj {
    char pad[0x83a];
    char text[1];

  public:
    char Match(const char*, const char*, hulk_intptr);
    char* Find(const char*);
};
char* Obj::Find(const char* name) {
    char* s = text;
    hulk_uintptr len = strlen(name);
    while (*s) {
        if (Match(name, s, len))
            return s;
        s += strlen(s) + 1;
    }
    return 0;
}