// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 31/32, incomplete)
// FUN_001fd9a0 @ 0x001fd9a0
// cl-flags: /GS
#include "gen/owners.h"
struct Reader {
    bool FUN_001d2ba0(const char*, int, int);
    bool FUN_001d2da0(const char*, int*);
    bool FUN_001d2de0(const char*, int*);
    bool FUN_001d19f0(char*, int, int);
    void FUN_001d1c70();
};
extern "C" Reader* __cdecl FUN_001d4c90();
struct Entry_1fd9a0 {
    char pad0[0x410];
    int f410;
    int f414;
    char pad1[0x458 - 0x418];
    int active;
    char pad2[0xc70 - 0x45c];
    void FUN_001f8720(int, int);
    void FUN_001f8f70(char*);
    void FUN_001f8710(float);
    void FUN_001f8760(int);
    void FUN_001fa500(int);
    void FUN_001f87c0(int);
};
struct Manager_1fd9a0 {
    char pad[0x234];
    Entry_1fd9a0* entries;
    int FUN_001fcff0(char*);
    int FUN_001fd390(char*);
    void FUN_001fd070(int);
    bool FUN_001fd9a0(const char* file);
};
bool Manager_1fd9a0::FUN_001fd9a0(const char* file) {
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
    } f;
    int slot = 0;
    Entry_1fd9a0* e = entries;
    for (; slot < 8; slot++, e++) {
        if (e->active == 0)
            break;
    }
    if (slot == 8) {
        return false;
    }
    if (slot == -1) {
        return false;
    }
    Reader* reader = FUN_001d4c90();
    if (!reader) {
        return false;
    }
    if (!reader->FUN_001d2ba0(file, 1, 0)) {
        return false;
    }
    f.script = -1;
    f.onActivate = -1;
    f.priority = 1;
    if (!((owners::K_1d2c60 *)reader)->FUN_001d2c60((hulk_intptr)"name", (hulk_intptr)(f.name), 0x100) || !((owners::Obj_1d2d40 *)reader)->FUN_001d2d40((hulk_intptr)"tick", &f.tick) ||
        !((owners::C_1d2e10 *)reader)->FUN_001d2e10((hulk_intptr)"script", &f.script)) {
        f.ok = false;
    } else {
        ((owners::C_1d2e10 *)reader)->FUN_001d2e10((hulk_intptr)"on_activate", &f.onActivate);
        reader->FUN_001d2de0("reset_on_disable", &f.resetOnDisable);
        reader->FUN_001d2da0("expendable_priority", &f.priority);
        if (FUN_001fcff0(f.name) != -1) {
            f.ok = false;
        } else {
            f.ok = reader->FUN_001d2ba0("locators", 0, 0);
            if (f.ok) {
                if (((owners::Obj_1d1bc0 *)reader)->FUN_001d1bc0()) {
                    while (((owners::C_1d1c10 *)reader)->FUN_001d1c10(-2)) {
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
                ((owners::Obj_1d19d0 *)reader)->FUN_001d19d0(1);
                ((owners::Target_1f8f40 *)&(entries[slot]))->FUN_001f8f40((const char *)(f.name));
                entries[slot].FUN_001f8710(f.tick);
                entries[slot].FUN_001f8760(f.script);
                ((owners::C_1f8790 *)&(entries[slot]))->FUN_001f8790(f.onActivate);
                entries[slot].FUN_001fa500(2);
                entries[slot].FUN_001f87c0(f.resetOnDisable);
                ((owners::C_1f87d0 *)&(entries[slot]))->FUN_001f87d0(f.priority);
                entries[slot].f414 = entries[slot].f410;
                FUN_001fd070(slot);
            }
        }
    }
    ((owners::Obj_1d19d0 *)reader)->FUN_001d19d0(1);
    bool ok = f.ok;
    if (!ok) {
        ((owners::Obj_1d1900 *)reader)->FUN_001d1900((hulk_intptr)(f.script));
        ((owners::Obj_1d1900 *)reader)->FUN_001d1900((hulk_intptr)(f.onActivate));
    }
    return ok;
}
