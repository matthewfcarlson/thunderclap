// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001fc690..0x00201740 (kind game, layer game, confidence high), dominant class CTriggerVolumeManager
#include "tree_prelude.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_faf408b8 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_faf408b8 {} using namespace fn_faf408b8;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_faf408b8 {
struct Reader {
  public:
    bool FUN_001d2ba0(const char*,int,int);
    bool FUN_001d2da0(const char*,int*);
    bool FUN_001d2de0(const char*,int*);
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
struct Entry_1fdc90 {
 char pad[0x6e0]; int count; char tail[0xc70-0x6e4];
 int FUN_001f93e0(const char*,int,int,int,int,float,float,float,int,int);
};
struct Manager_1fdc90 {
 char pad[0x234]; Entry_1fdc90* entries;
 int FUN_001fcff0(int);
 bool FUN_001fdc90(int,const char*);
};


// 0x001fd9a0 FUN_001fd9a0 (737 B): equivalent/0x001fd9a0.cpp
// sym: ?FUN_001fd9a0@Manager_1fd9a0@fn_faf408b8@@QAE_NPBD@Z @8fec18ca25b7 @wd59816f8ffe0
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 31/32, incomplete)
// FUN_001fd9a0 @ 0x001fd9a0
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


// 0x001fdc90 FUN_001fdc90 (533 B): equivalent/0x001fdc90.cpp
// sym: ?FUN_001fdc90@Manager_1fdc90@fn_faf408b8@@QAE_NHPBD@Z @8b381d4cf464 @w083b2741bf9d
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 32/32)
// FUN_001fdc90 @ 0x001fdc90
bool Manager_1fdc90::FUN_001fdc90(int id,const char* file) {
 struct Parameters {
 int script; float kill; int locator,total; float deactivate; int maximum; float radius; int minimum,reset; char name[256];
 } p;
 int index=FUN_001fcff0(id);
 if(index==-1) { return false; }
 if(entries[index].count>=16) { return false; }
 Reader* reader=FUN_001d4c90();
 if(!reader) { return false; }
 if(!reader->FUN_001d2ba0(file,1,0)) { return false; }
 p.script=-1;
 bool ok=false;
 if(((owners::K_1d2c60 *)reader)->FUN_001d2c60((hulk_intptr)"template", (hulk_intptr)(p.name), 256) &&
 reader->FUN_001d2da0("min",&p.minimum) &&
 reader->FUN_001d2da0("max",&p.maximum) &&
 reader->FUN_001d2da0("total",&p.total) &&
 reader->FUN_001d2da0("locator_type",&p.locator) &&
 ((owners::Obj_1d2d40 *)reader)->FUN_001d2d40((hulk_intptr)"kill_distance", &p.kill) &&
 ((owners::Obj_1d2d40 *)reader)->FUN_001d2d40((hulk_intptr)"deactivate_distance", &p.deactivate) &&
 ((owners::Obj_1d2d40 *)reader)->FUN_001d2d40((hulk_intptr)"trigger_radius", &p.radius) &&
 ((owners::C_1d2e10 *)reader)->FUN_001d2e10((hulk_intptr)"script", &p.script) &&
 reader->FUN_001d2de0("reset_on_exit",&p.reset)) {
 ok=entries[index].FUN_001f93e0(p.name,p.minimum,p.maximum,p.total,p.locator,p.kill,p.deactivate,p.radius,p.script,p.reset)!=-1;
 }
 ((owners::Obj_1d19d0 *)reader)->FUN_001d19d0(1);
 if(!ok) ((owners::Obj_1d1900 *)reader)->FUN_001d1900((hulk_intptr)(p.script));
 return ok;
}

} // namespace fn_faf408b8
