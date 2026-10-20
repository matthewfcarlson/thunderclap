#include "compat/ptr.h"
struct Helper_1dd930 {
    void Use(void*);
};
struct Entry_1dd930 {
    char pad[0x18];
    hulk_intptr ptr;
    char gap[6];
    short index;
    char tail[4];
};
struct Obj_1dd930 {
    char pad[0x608];
    Entry_1dd930 entries[0x800];
    bool Run(int index, Helper_1dd930* arg);
};
bool Obj_1dd930::Run(int index, Helper_1dd930* arg) {
    if (index < 0 || index >= 0x800)
        return false;
    Entry_1dd930* e = &entries[index];
    if ((((char*)this)[(e->index + 0x104e) * 0x14] & 1) && e->ptr != 0) {
        arg->Use((void*)(e->ptr + 8));
        return true;
    }
    arg->Use((void*)e);
    return true;
}
