// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000bc1e0..0x000be1c0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/engine/content.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff542b10 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff542b10 {} using namespace fn_ff542b10;
#include "game/unknown.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strncpy(char*, const char*, unsigned int);
#endif
namespace fn_ff542b10 {
class Request {
  public:
    virtual void v0();
    virtual void Release();
    bool FUN_00266750();
    int FUN_00266700();
};
class Target_bc3c0 {
  public:
    void FUN_00266220(int value);
};
class Manager_bc3c0 {
  public:
    void FUN_00265810(const char* name, struct RequestState* state);
    int FUN_00264870();
};
struct RequestState {
    Request* request;
    char name[0x100];
    int field104;
    int field108;
    int arg;
    char field110;
};
int FUN_000964a0(char *buf, int size, const char *fmt, ...);
struct Label_bc6a0 {
    void FUN_00089810(const char *name);
    void FUN_00089300(const char *text);
};
struct Highlight {
    void FUN_00093c40(const char *name);
};
class Menu_bc6a0 {
public:
    char pad0[0x34];
    Label_bc6a0 *label;           // 0x34
    char pad38[0x4c - 0x38];
    Highlight *highlight;   // 0x4c
    void FUN_000bc6a0();
};
typedef unsigned short WideChar;
extern "C" unsigned int __cdecl FUN_00294b80(const WideChar* text);
struct Entry_bc900 { WideChar text[64]; };
struct Object {
 char padding[0x1884]; Entry_bc900 entries[1];
 bool FUN_000b77c0(int key, WideChar* output, int capacity, int mode);
 int FUN_000bc900(WideChar* output, int position, int key, int entryIndex);
};
struct Label_bc9f0 {
    char pad0[0x10];
};
struct Owner_bc9f0 {
    char pad0[0x18];
    Label_bc9f0 label;
};
Owner_bc9f0* FUN_000fc260(int id);
} // namespace fn_ff542b10
class Gfx {
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
    virtual void v24(int mode);
    virtual int v25();
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
    virtual void v54(int on);
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58(int on);
};
namespace fn_ff542b10 {
class Layer_bd050 {
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
    virtual void v16(int arg);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int arg);
};
class Viewport_bd050 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
};
class Label_bd050 {
  public:
    void FUN_000f7d60(char* text, int a, float b, int c, int d, int e);
};
class TextManager_bd050 {
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
    virtual Label_bd050* v44();
};
struct Canvas {
    Layer_bd050* layer;
    void FUN_00293d40(float x, float y, float z);
    void FUN_00293da0(float x, float y, float z);
};
extern "C" TextManager_bd050* FUN_000fc3d0();


// 0x000bc3c0 FUN_000bc3c0 (264 B): equivalent/0x000bc3c0.cpp
// sym: ?FUN_000bc3c0@fn_ff542b10@@YGXPBDPAVTarget_bc3c0@1@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 3566 inputs, branch coverage 8/8)
// FUN_000bc3c0 @ 0x000bc3c0
void __stdcall FUN_000bc3c0(const char* src, Target_bc3c0* target, int arg) {
    struct Frame {
        RequestState st;
    } frame;
    RequestState& st = frame.st;
    st.request = 0;
    st.name[0] = 0;
    st.field104 = 0;
    st.field108 = 0;
    st.arg = 0;
    st.field110 = 0;
    if (src != 0)
        strncpy(st.name, src, 0xff);
    st.arg = arg;
    st.field110 = 0;
    (*(Manager_bc3c0**)&DAT_00527c58)->FUN_00265810(st.name, &st);
    int saved = (*(Manager_bc3c0**)&DAT_00527c58)->FUN_00264870();
    ((owners::C_264860 *)((*(Manager_bc3c0**)&DAT_00527c58)))->FUN_00264860(0x3d090);
    if (!st.request->FUN_00266750()) {
        do {
            FUN_00087990();
        } while (!st.request->FUN_00266750());
    }
    ((owners::C_264860 *)((*(Manager_bc3c0**)&DAT_00527c58)))->FUN_00264860(saved);
    target->FUN_00266220(st.request->FUN_00266700());
    Request* r = st.request;
    if (r != 0)
        r->Release();
}


// 0x000bc6a0 FUN_000bc6a0 (163 B): matches/0x000bc6a0.cpp
// sym: ?FUN_000bc6a0@Menu_bc6a0@fn_ff542b10@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 10/10)
// FUN_000bc6a0 @ 0x000bc6a0
void Menu_bc6a0::FUN_000bc6a0()
{
    struct Frame {
        int b;
        int a;
        char name[0x10];
    } fr;
    if (label != 0) {
        ((owners::C_89880 *)label)->FUN_00089880((unsigned *)(&fr.a), (unsigned *)(&fr.b));
        if (fr.a > -1 && fr.b > -1) {
            FUN_000964a0(fr.name, 0x10, "c%02dm%02d", fr.a, fr.b);
            Item *item = ((Item *)((owners::NameTable_b4cf0 *)this)->FUN_000b4cf0(fr.name));
            if (item != 0) {
                if (highlight != 0)
                    highlight->FUN_00093c40(fr.name);
                ((owners::LevelName_895e0 *)label)->FUN_000895e0((const char *)(Item *)item);
                label->FUN_00089810(fr.name);
                label->FUN_00089300("story");
            }
        }
    }
}


// 0x000bc900 FUN_000bc900 (234 B): equivalent/0x000bc900.cpp
// sym: ?FUN_000bc900@Object@fn_ff542b10@@QAEHPAGHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 2/2)
// FUN_000bc900 @ 0x000bc900
int Object::FUN_000bc900(WideChar* output, int position, int key, int entryIndex) {
 struct Workspace { WideChar buffer[64];  } workspace;
 if (!FUN_000b77c0(key, workspace.buffer, 64, 1)) { return 0; }
 output[position++] = 32; output[position++] = 32;
 const WideChar* text = entries[entryIndex].text;
 unsigned int count = FUN_00294b80(text);
 unsigned int bytes = count * 2;
 unsigned int* dest = reinterpret_cast<unsigned int*>(output + position);
 const unsigned int* src = reinterpret_cast<const unsigned int*>(text);
 for (unsigned int i = 0; i < (bytes >> 2); ++i) dest[i] = src[i];
 if (bytes & 2) output[position + (bytes >> 1) - 1] = text[(bytes >> 1) - 1];
 position += count; output[position++] = 32;
 count = FUN_00294b80(workspace.buffer);
 bytes = count * 2;
 dest = reinterpret_cast<unsigned int*>(output + position);
 src = reinterpret_cast<const unsigned int*>(workspace.buffer);
 for (unsigned int j = 0; j < (bytes >> 2); ++j) dest[j] = src[j];
 if (bytes & 2) output[position + (bytes >> 1) - 1] = workspace.buffer[(bytes >> 1) - 1];
 position += count; output[position] = 0;
  return position;
}

} // namespace fn_ff542b10

// 0x000bc9f0 FUN_000bc9f0 (509 B): matches/0x000bc9f0.cpp
// sym: ?FUN_000bc9f0@MenuScreen_bc9f0@owners@@QAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 31/32, incomplete)
// FUN_000bc9f0 @ 0x000bc9f0
void owners::MenuScreen_bc9f0::FUN_000bc9f0(hulk_intptr id, int code)
{
    unsigned short text[0x100];
    Owner_bc9f0* owner = FUN_000fc260(((int)id));
    if (owner) {
        Label_bc9f0* label = &owner->label;
        if (label) {
            int pos = 0;
            if (code == 0) {
                text[0] = 0;
            } else if (code == 12) {
                pos = FUN_000bc900(text, 0, "TBS_MENU_CONFIRMATION_ACCEPT2", 0);
                FUN_000bc900(text, pos, "TBS_CANCEL", 1);
            } else if (code == 11) {
                pos = FUN_000bc900(text, 0, "TBS_MENU_CONFIRMATION_ACCEPT2", 0);
                FUN_000bc900(text, pos, "TBS_MENU_ITEM_BUTTON_BACK", 1);
            } else if (code == 10) {
                FUN_000bc900(text, 0, "TBS_MENU_CONFIRMATION_ACCEPT2", 0);
            } else if (code == 9) {
                pos = FUN_000bc900(text, 0, "TBS_MENU_ITEM_LS_LOAD", 0);
                FUN_000bc900(text, pos, "TBS_MENU_ITEM_BUTTON_BACK", 1);
            } else if (code == 8) {
                pos = FUN_000bc900(text, 0, "TBS_MENU_ITEM_CHALLENGE_FE_SAVE", 0);
                FUN_000bc900(text, pos, "TBS_MENU_ITEM_BUTTON_BACK", 1);
            } else if (code == 7) {
                pos = FUN_000bc900(text, 0, "TBS_FORMAT", 0);
                FUN_000bc900(text, pos, "TBS_MENU_ITEM_BUTTON_BACK", 1);
            } else if (code == 6) {
                pos = FUN_000bc900(text, 0, "TBS_MENU_ITEM_CHALLENGE_FE_SAVE", 0);
                pos = FUN_000bc900(text, pos, "TBS_MENU_ITEM_BUTTON_BACK", 1);
                FUN_000bc900(text, pos, "TBS_MENU_ITEM_CHALLENGE_FE_DELETE", 2);
            } else if (code == 5) {
                FUN_000bc900(text, 0, "TBS_MENU_CONFIRMATION_ACCEPT1", 0);
            } else if (code == 4) {
                FUN_000bc900(text, 0, "TBS_MENU_ITEM_OK", 0);
            } else {
                if (code == 1 || code == 3)
                    pos = FUN_000bc900(text, 0, "TBS_MENU_ITEM_BONUS_FEATURES_SELECT", 0);
                if (code == 1 || code == 2)
                    FUN_000bc900(text, pos, "TBS_MENU_ITEM_BUTTON_BACK", 1);
            }
            ((owners::Obj_f79a0 *)label)->FUN_000f79a0((const short *)text, (hulk_intptr)0);
        }
    }
}


// 0x000bd050 FUN_000bd050 (347 B): equivalent/0x000bd050.cpp
// sym: ?FUN_000bd050@MenuScreen_bd050@owners@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3023 inputs, branch coverage 0/0)
// FUN_000bd050 @ 0x000bd050
void owners::MenuScreen_bd050::FUN_000bd050() {
    char text[0x200];
    int saved = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(2);
    DAT_0052c2a8->v54(0);
    DAT_0052c2a8->v58(0);
    (*(Canvas**)&DAT_0052c2ac)->layer->v21(0);
    float width = (float)(*(Viewport_bd050**)&DAT_0052c2a4)->v7();
    float height = (float)(*(Viewport_bd050**)&DAT_0052c2a4)->v6() - 50.0f;
    FUN_000bc900(text, 0, "TBS_MENU_ITEM_BUTTON_BACK", 1);
    (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(width * 0.5f, height, 2.0f);
    (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(1.0f, -1.0f, 1.0f);
    FUN_000fc3d0()->v44()->FUN_000f7d60(text, 0, 1.4f, 1, 2, 0);
    DAT_0052c2a8->v54(1);
    DAT_0052c2a8->v58(1);
    (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
    DAT_0052c2a8->v24(saved);
}

