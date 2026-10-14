// STATUS: equivalent (tools/equiv.py level 3: 2746 inputs, branch coverage 18/18)
// FUN_001e9960 @ 0x001e9960
extern "C" char *strcpy(char *, const char *);
extern "C" char *strcat(char *, const char *);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

struct IdPair {
    unsigned int lo;
    unsigned int hi;
};

struct Resource {
    IdPair *FUN_00243390();
};

struct Slot {
    char pad00[8];
    Resource *resource;
};

class Registry {
public:
    char pad00[0x4c0];
    Slot *slots[20];
    int count;

    Slot *FUN_001e9960(const char *name);
};

// Looks a slot up by its resource name hashed with a ".Mix" suffix.
Slot *Registry::FUN_001e9960(const char *name)
{
    struct Frame {
        char buf[0x20];
        unsigned int cookie;
    } fr = { "" };
    fr.cookie = DAT_004d9968;
    Registry *self = this;
    if (!name || *name == 0) {
        __security_check_cookie(fr.cookie);
        return 0;
    }
    strcpy(fr.buf, name);
    strcat(fr.buf, ".Mix");
    for (int i = 0; i < count; i++) {
        if (slots[i]) {
            unsigned __int64 id = FUN_002672f0(fr.buf, 0, 0);
            IdPair *found = slots[i]->resource->FUN_00243390();
            if (found->lo == (unsigned int)id && found->hi == (unsigned int)(id >> 32)) {
                __security_check_cookie(fr.cookie);
                return self->slots[i];
            }
        }
    }
    __security_check_cookie(fr.cookie);
    return 0;
}
