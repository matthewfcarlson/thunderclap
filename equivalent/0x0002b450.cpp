// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0002b450 @ 0x0002b450
typedef unsigned __int64 Key;
extern Key __cdecl FUN_002672f0(const char*, int, int);

struct Vec3 {
    float x, y, z;
};
extern float __cdecl FUN_0002a380(Vec3* a, Vec3* b);

struct Child {
    bool FUN_00059a50(Vec3* out);
};

struct Entry {
    char pad[0x10];
    Child* child;
};

struct Owner {
    Entry* FUN_00024280(Key key);
    float FUN_0002b450(const char* nameA, const char* nameB);
};

float Owner::FUN_0002b450(const char* nameA, const char* nameB)
{
    struct {
        Vec3 b;
        Vec3 a;
    } v;
    Entry* first = FUN_00024280(FUN_002672f0(nameA, 0, 0));
    if (first) {
        Entry* second = FUN_00024280(FUN_002672f0(nameB, 0, 0));
        if (second && first->child->FUN_00059a50(&v.a) && second->child->FUN_00059a50(&v.b)) {
            return FUN_0002a380(&v.a, &v.b);
        }
    }
    return -1.0f;
}
