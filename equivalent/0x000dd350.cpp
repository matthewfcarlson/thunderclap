// STATUS: equivalent (tools/equiv.py level 3: 1771 inputs, branch coverage 52/52)
// FUN_000dd350 @ 0x000dd350
// cl-flags: /GS
#include "decls/data/game/global.h"

extern "C" long __cdecl atol(const char* s);


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
char* __cdecl FUN_0008d6d0(int size);

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
