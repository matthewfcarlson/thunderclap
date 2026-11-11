// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000dc230..0x000dd6c0 (kind game, layer game, confidence high), dominant class FETextInput
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#define TREE_TU_BEGIN namespace fn_f0ffd6c9 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0ffd6c9 {} using namespace fn_f0ffd6c9;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0ffd6c9 {
struct Node {
    virtual void vfunc_0();
    virtual unsigned __int64 vfunc_1();
};
struct Handle_dc230 {
    virtual void vfunc_0();
};
struct Pool_dc230 {
    Handle_dc230 *FUN_000c6b20(const char *name);
};
struct Slot_dc230 {
    int a, b, c;
};
class Parser_dc230 {
public:
    bool FUN_000f9ef0();
    void FUN_000f9f30();
    char FUN_000f9e50();
    Node *FUN_000fb110();
    const char *FUN_000fad90();
    float FUN_000fad30();
    unsigned __int64 FUN_000faeb0();
    void FUN_000fa0a0();
    void FUN_000f9fb0();
};
class Sink_dc230 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void Store(const char *name, void *dest);
};
class Handler_dc230 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33();
    virtual bool Handle34(Parser_dc230 *p, Node *node, int flag);
    virtual bool Handle35(Parser_dc230 *p, Sink_dc230 *sink, void *owner, Node *node);
    virtual bool Handle36(Parser_dc230 *p, Sink_dc230 *sink, void *owner, Node *node);
};
void FUN_000964a0(char *buf, int size, const char *fmt, ...);
class Config_dc230 {
public:
    char pad0[0x154];
    char f154[0x24];
    Slot_dc230 slots[5];
    char f1b4[0xc];
    char f1c0[0xc];
    Handle_dc230 *f1cc;
    char pad1d0[0x3a8 - 0x1d0];
    char b3a8;
    char pad3a9[0x3e8 - 0x3a9];
    char b3e8;
    char pad3e9;
    char b3ea;

    bool FUN_000dc230(Parser_dc230 *parser, Handler_dc230 *handler, Sink_dc230 *sink);
};


// 0x000dc230 FUN_000dc230 (741 B): equivalent/0x000dc230.cpp
// sym: ?FUN_000dc230@Config_dc230@fn_f0ffd6c9@@QAE_NPAVParser_dc230@2@PAVHandler_dc230@2@PAVSink_dc230@2@@Z @48840ed200be @w41254c5e9acc
// STATUS: equivalent (tools/equiv.py level 3: 1893 inputs, branch coverage 52/52)
// FUN_000dc230 @ 0x000dc230
bool Config_dc230::FUN_000dc230(Parser_dc230 *parser, Handler_dc230 *handler, Sink_dc230 *sink)
{
    char bufA[0x40];
    char bufC[0x40];
    char bufB[0x40];
    char bufD[0x40];

    if (parser->FUN_000f9ef0()) {
        parser->FUN_000f9f30();
        while (parser->FUN_000f9e50()) {
            Node *node = parser->FUN_000fb110();
            unsigned __int64 key = node->vfunc_1();
            if (key == (*(unsigned __int64*)&DAT_004de670)) {
                const char *name = parser->FUN_000fad90();
                sink->Store(name, f154);
            } else if (key == (*(unsigned __int64*)&DAT_004de680)) {
                b3e8 = (int)parser->FUN_000fad30() != 0;
            } else if (key == (*(unsigned __int64*)&DAT_004de6c0)) {
                unsigned __int64 v = parser->FUN_000faeb0();
                if (v == (*(unsigned __int64*)&DAT_004de688)) {
                    b3a8 = 0;
                } else if (v == (*(unsigned __int64*)&DAT_004de690)) {
                    b3a8 = 0;
                    b3ea = 1;
                } else {
                    b3a8 = 1;
                }
            } else if (key == (*(unsigned __int64*)&DAT_004de678)) {
                FUN_000964a0(bufA, 0x40, "%s%d", parser->FUN_000fad90(), 1);
                Handle_dc230 *h = (*(Pool_dc230**)&DAT_004dd9cc)->FUN_000c6b20(bufA);
                if (h)
                    h->vfunc_0();
                f1cc = h;
            } else if (key == (*(unsigned __int64*)&DAT_004de6c8)) {
                FUN_000964a0(bufB, 0x40, "%s%d", parser->FUN_000fad90(), 1);
                sink->Store(bufB, f1b4);
            } else if (key == (*(unsigned __int64*)&DAT_004de6a0)) {
                FUN_000964a0(bufC, 0x40, "%s%d", parser->FUN_000fad90(), 1);
                sink->Store(bufC, f1c0);
            } else if (key == (*(unsigned __int64*)&DAT_004de698)) {
                const char *name = parser->FUN_000fad90();
                for (int i = 1; i <= 5; i++) {
                    FUN_000964a0(bufD, 0x40, "%s%d", name, i);
                    sink->Store(bufD, &slots[i - 1]);
                }
            } else {
                if (handler->Handle35(parser, sink, this, node))
                    continue;
                if (handler->Handle36(parser, sink, this, node))
                    continue;
                if (handler->Handle34(parser, node, 0))
                    continue;
                parser->FUN_000fa0a0();
                break;
            }
        }
        parser->FUN_000f9fb0();
    }
    return true;
}

} // namespace fn_f0ffd6c9

// 0x000dd350 FUN_000dd350 (825 B): equivalent/0x000dd350.cpp [wrapped: conflict: FUN_000964a0]
// sym: ?FUN_000dd350@Config_dd350@fn_000dd350@@QAE_NPAVParser_dd350@2@PAVHandler_dd350@2@PAVSink_dd350@2@@Z @ccf148283394 @w3a1c50912136
namespace fn_000dd350 {
// STATUS: equivalent (tools/equiv.py level 3: 1771 inputs, branch coverage 52/52)
// FUN_000dd350 @ 0x000dd350
// cl-flags: /GS


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" long __cdecl atol(const char* s);
#endif



struct Node {
    virtual void vfunc_0();
    virtual unsigned __int64 vfunc_1();
};

class Parser_dd350 {
public:
    bool FUN_000f9ef0();
    void FUN_000f9f30();
    char FUN_000f9e50();
    Node* FUN_000fb110();
    const char* FUN_000fad90();
    unsigned int FUN_000faeb0();
    void FUN_000fa0a0();
    void FUN_000f9fb0();
};

class Sink_dd350 {
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
    virtual void Store(const char* name, void* dest);
};
class Handler_dd350 {
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
    virtual bool Handle34(Parser_dd350* p, Node* node, int flag);
    virtual bool Handle35(Parser_dd350* p, Sink_dd350* sink, void* owner, Node* node);
    virtual bool Handle36(Parser_dd350* p, Sink_dd350* sink, void* owner, Node* node);
    virtual bool Handle37(Parser_dd350* p, Sink_dd350* sink, Node* node);
};

struct Slot_dd350 {
    int a, b, c;
};

int __cdecl FUN_000964a0(char* buf, int size, const char* fmt, ...);
void __cdecl FUN_0008d340(void* p);
extern "C" char* __cdecl FUN_0008d6d0(int size);

class Config_dd350 {
public:
    char pad0[0x150];
    int count;              // 0x150
    char pad154[0x15c - 0x154];
    Slot_dd350* slotsA;           // 0x15c
    Slot_dd350* slotsB;           // 0x160
    char** namesA;          // 0x164
    char** namesB;          // 0x168
    char pad16c[0x17c - 0x16c];
    char b17c;
    void FUN_000dc810(int v);
    bool FUN_000dd350(Parser_dd350* parser, Handler_dd350* handler, Sink_dd350* sink);
};

bool Config_dd350::FUN_000dd350(Parser_dd350* parser, Handler_dd350* handler, Sink_dd350* sink)
{
    struct Frame {
        const char *name;       // (the name pointer kept across the snprintf loop)
        char bufA[0x40];
        char bufB[0x40];        // (bufA is not always terminated: the length scan runs on into bufB)
    } f;
    if (parser->FUN_000f9ef0()) {
        parser->FUN_000f9f30();
        while (parser->FUN_000f9e50()) {
            Node* node = parser->FUN_000fb110();
            unsigned __int64 key = node->vfunc_1();
            if (key == (*(unsigned __int64*)&DAT_004de6e0)) {
                const char* name = parser->FUN_000fad90();
                if (name == 0) {
                    parser->FUN_000fa0a0();
                    break;
                }
                FUN_000dc810(atol(name));
            } else if (key == (*(unsigned __int64*)&DAT_004de700)) {
                f.name = parser->FUN_000fad90();
                for (int i = 0; i < count; i++) {
                    FUN_000964a0(f.bufA, 0x40, "%s_%02d", f.name, i + 1);
                    if (namesA[i] != 0) {
                        FUN_0008d340(namesA[i]);
                        namesA[i] = 0;
                    }
                    const char* s = f.bufA;
                    while (*s++ != 0) {
                    }
                    namesA[i] = FUN_0008d6d0(s - f.bufA);
                    char* dst = namesA[i];
                    const char* src = f.bufA;
                    do {
                        *dst = *src;
                        dst++;
                    } while (*src++ != 0);
                    sink->Store(f.bufA, (char*)slotsA + i * 12);
                }
            } else if (key == (*(unsigned __int64*)&DAT_004de708)) {
                f.name = parser->FUN_000fad90();
                for (int i = 0; i < count; i++) {
                    FUN_000964a0(f.bufB, 0x40, "%s_%02d", f.name, i + 1);
                    if (namesB[i] != 0) {
                        FUN_0008d340(namesB[i]);
                        namesB[i] = 0;
                    }
                    const char* s = f.bufB;
                    while (*s++ != 0) {
                    }
                    namesB[i] = FUN_0008d6d0(s - f.bufB);
                    char* dst = namesB[i];
                    const char* src = f.bufB;
                    do {
                        *dst = *src;
                        dst++;
                    } while (*src++ != 0);
                    sink->Store(f.bufB, (char*)slotsB + i * 12);
                }
            } else if (key == (*(unsigned __int64*)&DAT_004de6d8)) {
                b17c = parser->FUN_000faeb0() == 0x4dae9aac;
            } else {
                if (handler->Handle35(parser, sink, this, node))
                    continue;
                if (handler->Handle36(parser, sink, this, node))
                    continue;
                if (handler->Handle37(parser, sink, node))
                    continue;
                if (handler->Handle34(parser, node, 0))
                    continue;
                parser->FUN_000fa0a0();
                break;
            }
        }
        parser->FUN_000f9fb0();
    }
    return true;
}
} // namespace fn_000dd350

