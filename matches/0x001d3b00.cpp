#include "compat/ptr.h"
struct Blob {
    unsigned int x[174];
};
class Obj {
  public:
    char pad[8];
    unsigned int value;
    int Next(int, Blob, unsigned int);
    int Fn(hulk_intptr a, Blob b);
};
int Obj::Fn(hulk_intptr a, Blob b) {
    return Next(a, b, value);
}