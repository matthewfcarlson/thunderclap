// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000e7620 @ 0x000e7620
extern "C" int __cdecl strcmp(const char*, const char*);

class Named {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char* GetName();
};

class Registry {
public:
    char pad0[0x10c];
    Named* entries[0x40];
    Named* FUN_000e7620(const char* name);
};

Named* Registry::FUN_000e7620(const char* name) {
    for (int i = 0; i < 0x40; i++) {
        Named* e = entries[i];
        if (e && strcmp(name, e->GetName()) == 0)
            return entries[i];
    }
    return 0;
}
