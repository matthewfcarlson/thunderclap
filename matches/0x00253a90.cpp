#include "compat/ptr.h"
extern "C" void first(char*);
extern "C" __int64 second(char*, int, int);
class Thing {
  public:
    __int64 value;
    Thing(char* s);
};
Thing::Thing(char* s) {
    char buf[256];
    hulk_intptr offset = buf - s;
    char c;
    do {
        c = *s;
        s[offset] = c;
        ++s;
    } while (c);
    first(buf);
    value = second(buf, 0, 0);
}