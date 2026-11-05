#include "compat/ptr.h"
struct Inner_1d56f0 {
    char pad[0x1c];
    int* data;
};
class C_1d56f0 {
  public:
    char pad[0x90];
    Inner_1d56f0* m;
    hulk_intptr f(int index);
};
hulk_intptr C_1d56f0::f(int index) {
    return m->data[index];
}