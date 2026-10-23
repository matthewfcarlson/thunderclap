// STATUS: equivalent (tools/equiv.py level 3: 12579 inputs, branch coverage 20/20)
// FUN_000f5fa0 @ 0x000f5fa0
#include "decls/data/engine/content.h"
#include "decls/data/game/global.h"

extern "C" char *__cdecl strncpy(char *dst, const char *src, unsigned int n);
extern int __cdecl FUN_00266da0(int v);
extern void __cdecl FUN_0008d330(void *p);

struct Node {
    virtual void vfunc_0();
    virtual unsigned vfunc_1();
};

struct Slot_f5fa0 {
    int a, b, c, d;
};

struct Script_f5fa0 {
    void FUN_000f9a80();
};

struct Handle_f5fa0 {
    void *first;
    void *second;
    Script_f5fa0 *FUN_000fb240(const char *name);
};

struct Tail_f5fa0 {
    int f00;
    char pad04[0x0c];
    int f10;
    int f14;
    int f18;
    int f1c;
};

struct Table_f5fa0 {
    Slot_f5fa0 slots[0x80];
    void FUN_000f9d20();
};

namespace DollyScript {
class CScriptParser {
public:
    virtual ~CScriptParser() {
        table.FUN_000f9d20();
    }
    Script_f5fa0 *script;
    int a, b, c;
    unsigned char d, e;
    char pad16[2];
    Handle_f5fa0 handle;
    Table_f5fa0 table;
    Tail_f5fa0 tail;
    CScriptParser *FUN_000faa10(Script_f5fa0 *script);
    char FUN_000f9e50();
    Node *FUN_000fb110();
    int FUN_000fad90();
};
}

struct Obj266 {
    int FUN_00266700();
};

struct Sink_f5fa0 {
    void FUN_00266220(int v);
};

struct Loader_f5fa0 {
    void FUN_00265920(int v, Obj266 **out, int flag);
};


struct Frame_f5fa0 {
    Obj266 *w;
    char parser[0x840];
};

class Runner_f5fa0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64(int a, int b, int c);
    char pad04[0x2105 - 4];
    char name[0x100];
    char active;
    char pad2206[2];
    int count;
    int f220c;
    void FUN_000f5b20(DollyScript::CScriptParser *p, int a, int b, Node *node);
    void FUN_000f5fa0(const char *src, int arg);
};

void Runner_f5fa0::FUN_000f5fa0(const char *src, int arg)
{
    Frame_f5fa0 f;
    if (!active)
        f220c = arg;
    DollyScript::CScriptParser *p = (DollyScript::CScriptParser *)f.parser;
    for (Slot_f5fa0 *slot = p->table.slots; slot != p->table.slots + 0x80; slot++) {
        slot->a = 0;
        slot->b = 0;
        slot->c = 0;
    }
    p->tail.f10 = 0;
    p->tail.f00 = 0;
    p->tail.f14 = 0;
    p->tail.f18 = 0;
    strncpy(name, src, 0x100);
    int old = FUN_00266da0(10);
    Script_f5fa0 *script = p->handle.FUN_000fb240(name);
    FUN_00266da0(old);
    p->FUN_000faa10(script);
    if (active) {
        if (p->FUN_000f9e50()) {
            do {
                Node *node = p->FUN_000fb110();
                FUN_000f5b20(p, 0, 0, node);
            } while (p->FUN_000f9e50());
        }
    } else {
        if (p->FUN_000f9e50()) {
            do {
                Node *node = p->FUN_000fb110();
                if (node->vfunc_1() == 0x62deec48) {
                    int v = p->FUN_000fad90();
                    f.w = 0;
                    (*(Loader_f5fa0**)&DAT_00527c58)->FUN_00265920(v, &f.w, 0);
                    // MSVC evaluates the argument before loading the sink
                    int sinkArg = f.w->FUN_00266700();
                    (*(Sink_f5fa0**)&DAT_004dd9cc)->FUN_00266220(sinkArg);
                    count++;
                }
            } while (p->FUN_000f9e50());
        }
    }
    if (script) {
        script->FUN_000f9a80();
        FUN_0008d330(script);
    }
    if (active) {
        vfunc_6();
        active = 0;
    } else {
        vfunc_64(0, 0, 0);
    }
    p->DollyScript::CScriptParser::~CScriptParser();
}
