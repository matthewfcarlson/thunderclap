// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/9)
// FUN_001df400 @ 0x001df400
// Arg is passed by value as a union: the original reuses the dead first argument slot as a
// bool local and pushes the whole dword (stale high bytes) to the final call.
union Arg {
    int id;
    unsigned char flag;
    unsigned int word;
};

class Target {
public:
    void FUN_001d74c0(int a, int b, int c, unsigned int flag);
};

class Registry {
public:
    int FUN_00106230(int a);
};

struct Globals {
    char pad0[0x18];
    Registry* registry;
};
extern Globals* DAT_004dd700;

class Manager {
public:
    Target* FUN_001def30(int id);
    bool FUN_001df400(Arg id, int a2, int a3, int a4, const char* mode);
};

bool Manager::FUN_001df400(Arg id, int a2, int a3, int a4, const char* mode) {
    Target* target = FUN_001def30(id.id);
    if (!target)
        return false;
    int value = DAT_004dd700->registry->FUN_00106230(a2);
    id.flag = 1;
    if (mode && (*mode == 'Z' || *mode == 'z'))
        id.flag = 0;
    target->FUN_001d74c0(value, a3, a4, id.word);
    return true;
}
