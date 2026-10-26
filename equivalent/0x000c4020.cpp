// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 16/16)
// FUN_000c4020 @ 0x000c4020
// cl-flags: /GS
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"


struct Label_c4020 {
    int f00;
    char f04;
    char pad05[3];
    int f08;
    int f0c;
    char* f10;
    int f14;
    char f18;
    char pad19[3];
    float f1c;
    int f20;
    void FUN_000f7930();
    void FUN_000f8500(const char* text, void* manager, char flag);
    void FUN_000f7960();
};

class TextManager_c4020 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
};

class FEObject {
  public:
    virtual void v0();
};

class TextSelector : public FEObject {
  public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void vfunc_19(Label_c4020* label, int a, int b);
};

class Manager_c4020 {
  public:
    char pad[4];
};

class Ref_c4020 {
  public:
    virtual void v0();
    virtual void v1();
};

struct Handle_c4020 {
    void FUN_00294980(Ref_c4020* r);
};

struct FrontEnd_c4020 {
    void FUN_001c0ab0(const char* name);
};

struct Timer {
    void FUN_002665a0();
};

extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

int __cdecl FUN_00266da0(int mode);
TextManager_c4020* __cdecl FUN_000fc3d0();
FEObject* __cdecl FUN_000fc260(const char* name);
Manager_c4020* __cdecl FUN_000fc1b0();
void __cdecl FUN_000fc100(int a, int b);
int __cdecl FUN_000964a0(char* buf, int size, const char* fmt, ...);
int FUN_00345804(const char* str, const char* fmt, ...);

class MissionMenu {
  public:
    char pad0[8];
    char f08;
    char pad09[7];
    int f10;
    char pad14[0xc];
    Handle_c4020* f20;
    Ref_c4020* f24;
    char f28;
    char pad29[0x5c - 0x29];
    FrontEnd_c4020* f5c;
    char pad60[0x26c - 0x60];
    const char* names[0x80];
    char pad46c[0x1880 - 0x46c];
    int f1880;
    void FUN_000befc0(int a, int b, int c);
    void FUN_000b8f20();
    void FUN_000bb600();
    void FUN_000c3ea0();
    void FUN_000c4020(int a, int b);
};

void MissionMenu::FUN_000c4020(int a, int b)
{
    struct Frame {
        int mission;
        int chapter;
        int prev;
        Label_c4020 entry;
        char buf[0x20];
    } fr;
    fr.prev = FUN_00266da0(0xb);
    if (!f28) {
        TextManager_c4020* tm = FUN_000fc3d0();
        if (tm)
            tm->v66();
        if (f5c)
            f5c->FUN_001c0ab0("fe");
        f28 = 1;
        (*(Timer**)&DAT_004dd9cc)->FUN_002665a0();
        FUN_000befc0(DAT_0049f3bc, 0xb, 1);
        FUN_000befc0((*(hulk_intptr*)&DAT_0049f3c8), 0xb, 1);
        FUN_000befc0((*(hulk_intptr*)&DAT_0049f3cc), 0xb, 1);
        FUN_000befc0((*(hulk_intptr*)&DAT_0049f3d4), 0xb, 1);
        FUN_000befc0((*(hulk_intptr*)&DAT_0049f3d0), 0xb, 1);
        f20->FUN_00294980(f24);
        f10 = 3;
        if (!(*(char*)&DAT_0049fb3c) && f08) {
            f10 = 5;
        } else {
            f10 = 7;
            (*(char*)&DAT_0049fb3c) = 0;
        }
        FUN_000fc100((*(hulk_intptr*)&DAT_0049f3ac), 0);
        fr.entry.FUN_000f7930();
        TextSelector* sel = (TextSelector*)FUN_00344e74(FUN_000fc260("mission_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
        if (sel) {
            for (int i = 0; i < 0x80; i++) {
                if (!names[i])
                    break;
                fr.chapter = -1;
                fr.mission = -1;
                FUN_00345804(names[i], "c%dm%d", &fr.chapter, &fr.mission);
                FUN_000964a0(fr.buf, 0x20, "Chapter %d Mission %d", fr.chapter, fr.mission);
                fr.entry.FUN_000f8500(fr.buf, FUN_000fc1b0(), 0);
                sel->vfunc_19(&fr.entry, 0, 0);
            }
        }
        FUN_000b8f20();
        FUN_000bb600();
        FUN_000c3ea0();
        fr.entry.FUN_000f7960();
    }
    f1880 = 0;
    FUN_00266da0(fr.prev);
}
