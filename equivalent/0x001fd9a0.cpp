// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 31/32, incomplete)
// FUN_001fd9a0 @ 0x001fd9a0
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
struct Reader {
    bool FUN_001d2ba0(const char*, int, int);
    bool FUN_001d2c60(const char*, char*, int);
    bool FUN_001d2da0(const char*, int*);
    bool FUN_001d2d40(const char*, float*);
    bool FUN_001d2e10(const char*, int*);
    bool FUN_001d2de0(const char*, int*);
    bool FUN_001d1bc0();
    bool FUN_001d1c10(int);
    bool FUN_001d19f0(char*, int, int);
    void FUN_001d1c70();
    void FUN_001d19d0(int);
    void FUN_001d1900(int);
};
Reader* __cdecl FUN_001d4c90();
struct Entry {
    char pad0[0x410];
    int f410;
    int f414;
    char pad1[0x458 - 0x418];
    int active;
    char pad2[0xc70 - 0x45c];
    void FUN_001f8720(int, int);
    void FUN_001f8f70(char*);
    void FUN_001f8f40(char*);
    void FUN_001f8710(float);
    void FUN_001f8760(int);
    void FUN_001f8790(int);
    void FUN_001fa500(int);
    void FUN_001f87c0(int);
    void FUN_001f87d0(int);
};
struct Manager {
    char pad[0x234];
    Entry* entries;
    int FUN_001fcff0(char*);
    int FUN_001fd390(char*);
    void FUN_001fd070(int);
    bool FUN_001fd9a0(const char* file);
};
bool Manager::FUN_001fd9a0(const char* file) {
    struct Frame {
        char pad[3];
        bool ok;
        int script;
        int onActivate;
        int priority;
        int resetOnDisable;
        float tick;
        char line[256];
        char name[256];
        unsigned int cookie;
    } f;
    f.cookie = DAT_004d9968;
    int slot = 0;
    Entry* e = entries;
    for (; slot < 8; slot++, e++) {
        if (e->active == 0)
            break;
    }
    if (slot == 8) {
        __security_check_cookie(f.cookie);
        return false;
    }
    if (slot == -1) {
        __security_check_cookie(f.cookie);
        return false;
    }
    Reader* reader = FUN_001d4c90();
    if (!reader) {
        __security_check_cookie(f.cookie);
        return false;
    }
    if (!reader->FUN_001d2ba0(file, 1, 0)) {
        __security_check_cookie(f.cookie);
        return false;
    }
    f.script = -1;
    f.onActivate = -1;
    f.priority = 1;
    if (!reader->FUN_001d2c60("name", f.name, 0x100) || !reader->FUN_001d2d40("tick", &f.tick) ||
        !reader->FUN_001d2e10("script", &f.script)) {
        f.ok = false;
    } else {
        reader->FUN_001d2e10("on_activate", &f.onActivate);
        reader->FUN_001d2de0("reset_on_disable", &f.resetOnDisable);
        reader->FUN_001d2da0("expendable_priority", &f.priority);
        if (FUN_001fcff0(f.name) != -1) {
            f.ok = false;
        } else {
            f.ok = reader->FUN_001d2ba0("locators", 0, 0);
            if (f.ok) {
                if (reader->FUN_001d1bc0()) {
                    while (reader->FUN_001d1c10(-2)) {
                        if (reader->FUN_001d19f0(f.line, 0x100, 1)) {
                            int idx = FUN_001fd390(f.line);
                            if (idx != -1)
                                entries[slot].FUN_001f8720(idx, 1);
                            else
                                entries[slot].FUN_001f8f70(f.line);
                        }
                    }
                    reader->FUN_001d1c70();
                }
                reader->FUN_001d19d0(1);
                entries[slot].FUN_001f8f40(f.name);
                entries[slot].FUN_001f8710(f.tick);
                entries[slot].FUN_001f8760(f.script);
                entries[slot].FUN_001f8790(f.onActivate);
                entries[slot].FUN_001fa500(2);
                entries[slot].FUN_001f87c0(f.resetOnDisable);
                entries[slot].FUN_001f87d0(f.priority);
                entries[slot].f414 = entries[slot].f410;
                FUN_001fd070(slot);
            }
        }
    }
    reader->FUN_001d19d0(1);
    bool ok = f.ok;
    if (!ok) {
        reader->FUN_001d1900(f.script);
        reader->FUN_001d1900(f.onActivate);
    }
    __security_check_cookie(f.cookie);
    return ok;
}
