// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00026c30 @ 0x00026c30
#include "decls/address.h"
typedef unsigned __int64 Key_26c30;

struct Vec3_26c30 {
    float x, y, z;
};

struct Child_26c30 {
    void FUN_00059a50(Vec3_26c30* out);
};

struct Entry_26c30 {
    char pad[0x10];
    Child_26c30* child;
};

struct Owner_26c30 {
    Entry_26c30* FUN_00024280(Key_26c30 key);
    Vec3_26c30 FUN_00026c30(const char* name);
};

Vec3_26c30 Owner_26c30::FUN_00026c30(const char* name)
{
    Entry_26c30* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!entry) {
        Vec3_26c30 none = { 0.0f, 0.0f, 0.0f };
        return none;
    }
    Vec3_26c30 result = { 0.0f, 0.0f, 0.0f };
    entry->child->FUN_00059a50(&result);
    return result;
}
