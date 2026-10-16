// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0002b450 @ 0x0002b450
#include "decls/address.h"
typedef unsigned __int64 Key_2b450;

struct Vec3_2b450 {
    float x, y, z;
};
extern float __cdecl FUN_0002a380(Vec3_2b450* a, Vec3_2b450* b);

struct Child_2b450 {
    bool FUN_00059a50(Vec3_2b450* out);
};

struct Entry_2b450 {
    char pad[0x10];
    Child_2b450* child;
};

struct Owner_2b450 {
    Entry_2b450* FUN_00024280(Key_2b450 key);
    float FUN_0002b450(const char* nameA, const char* nameB);
};

float Owner_2b450::FUN_0002b450(const char* nameA, const char* nameB)
{
    struct {
        Vec3_2b450 b;
        Vec3_2b450 a;
    } v;
    Entry_2b450* first = FUN_00024280(FUN_002672f0(nameA, 0, 0));
    if (first) {
        Entry_2b450* second = FUN_00024280(FUN_002672f0(nameB, 0, 0));
        if (second && first->child->FUN_00059a50(&v.a) && second->child->FUN_00059a50(&v.b)) {
            return FUN_0002a380(&v.a, &v.b);
        }
    }
    return -1.0f;
}
