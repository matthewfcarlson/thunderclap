#include "gen/owners.h"
extern "C" void CopyBytes(void*, const void*, unsigned int);
struct Elem {
    int count;
    char* data;
};
class Obj {
  public:
    char pad[12];
    unsigned char changed;
    char pad2[0x290 - 13];
    Elem elems[13];
    bool Copy(int index, const void* src, int slot);
};
bool Obj::Copy(int index, const void* src, int slot) {
    if (index < 0 || index >= 13)
        return false;
    Elem* e = &elems[index];
    if (e->count <= 0)
        ((owners::StringTable_b1020 *)e)->FUN_000b1020(1);
    CopyBytes(e->data + slot * 32, src, 32);
    changed = 1;
    return true;
}