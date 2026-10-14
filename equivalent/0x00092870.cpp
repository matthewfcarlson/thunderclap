// STATUS: equivalent (tools/equiv.py level 3: 2980 inputs, branch coverage 12/12)
// FUN_00092870 @ 0x00092870
extern "C" char DAT_0049dab8[];
extern "C" char DAT_0049dafc[];
extern "C" char DAT_0049db1c[];
extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);

// equiv-map: ?FUN_000c21b0@Env@@QAEXH@Z = 0x000c2c10
struct Env {
    void FUN_000c21b0(int id);
};

struct Flagged_92870 {
    char pad0[0x20];
    char flag;      // 0x20
};

class Container_92870 {
public:
    void* items[0x362];     // 0x000
    Env* env;               // 0xd88
    void FUN_00092870(int index, char flag);
};

// Sets the flag byte on the two kinds of object held at items[index] and notifies the env on change.
void Container_92870::FUN_00092870(int index, char flag)
{
    bool changed = false;
    Flagged_92870* a = (Flagged_92870*)FUN_00344e74(items[index], 0, DAT_0049dab8, DAT_0049dafc, 0);
    if (a && a->flag != flag) {
        a->flag = flag;
        changed = true;
    }
    Flagged_92870* b = (Flagged_92870*)FUN_00344e74(items[index], 0, DAT_0049dab8, DAT_0049db1c, 0);
    if (b && b->flag != flag) {
        b->flag = flag;
        changed = true;
    }
    if (changed && env)
        env->FUN_000c21b0(index);
}
