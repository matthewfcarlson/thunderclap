#include "compat/ptr.h"
struct Entry_2e55a0 {
    int* begin;
    int* end;
    int pad;
};
class Obj_2e55a0 {
  public:
    char pad[0x14];
    Entry_2e55a0* entries;
    char Check(int, int*);
    hulk_intptr Count(int);
};
hulk_intptr Obj_2e55a0::Count(int index) {
    if (Check(index, &index) == 1) {
        Entry_2e55a0* e = entries + index;
        return (e->end - e->begin);
    }
    return 0;
}
