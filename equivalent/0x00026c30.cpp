// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00026c30 @ 0x00026c30
typedef unsigned __int64 Key;
extern Key __cdecl FUN_002672f0(const char*, int, int);

struct Vec3 {
    float x, y, z;
};

struct Child {
    void FUN_00059a50(Vec3* out);
};

struct Entry {
    char pad[0x10];
    Child* child;
};

struct Owner {
    Entry* FUN_00024280(Key key);
    Vec3 FUN_00026c30(const char* name);
};

Vec3 Owner::FUN_00026c30(const char* name)
{
    Entry* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!entry) {
        Vec3 none = { 0.0f, 0.0f, 0.0f };
        return none;
    }
    Vec3 result = { 0.0f, 0.0f, 0.0f };
    entry->child->FUN_00059a50(&result);
    return result;
}
