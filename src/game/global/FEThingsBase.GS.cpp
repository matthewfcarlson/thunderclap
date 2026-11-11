// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e4330..0x000e8490 (kind game, layer game, confidence high), dominant class FEThingsBase
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fcae020b {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fcae020b {} using namespace fn_fcae020b;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
#endif
namespace fn_fcae020b {
class Node {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual void _m_vf15();
    virtual void _m_vf16();
    virtual void _m_vf17();
    virtual void _m_vf18();
    virtual void _m_vf19();
    virtual void _m_vf20();
    virtual void _m_vf21();
    virtual void _m_vf22();
    virtual void _m_vf23();
    virtual void _m_vf24();
    virtual void _m_vf25();
    virtual void _m_vf26();
    virtual void _m_vf27();
    virtual void _m_vf28();
    virtual void _m_vf29();
    virtual void _m_vf30();
    virtual void _m_vf31();
    virtual void _m_vf32();
    virtual void _m_vf33();
    virtual void _m_vf34();
    virtual void _m_vf35();
    virtual void* find(const char* name);
    virtual int Lookup(const char *name);
};
class Registry_e70d0 {
  public:
    char pad0[0xc];
    Node* groupA[0x40];
    Node* groupB[0x40];
    Node* groupC[0x100];
    char pad1[0x175c - 0x60c];
    Node* primaryA;
    Node* primaryC;
    char pad2[0x2218 - 0x1764];
    Node* primaryB;
    Node* FUN_000e6410(const char* name);
    Node* FUN_000e6490(const char* name);
    void* FUN_000e70d0(const char* name);
};
class Registry_e7260 {
public:
    int FUN_000e7260(const char *name);
    Node *FUN_000e6490(const char *name);
    Node *FUN_000e6410(const char *name);

    char pad0[0xc];
    Node *groupA[0x40];
    Node *groupC[0x40];
    Node *groupB[0x100];
    char pad1[0x175c - 0x60c];
    Node *defaultA;
    Node *defaultB;
    char pad2[0x2218 - 0x1764];
    Node *defaultC;
};
struct Frame_e7260 {
    char buf[0x40];
};


// 0x000e70d0 FUN_000e70d0 (391 B): equivalent/0x000e70d0.cpp
// sym: ?FUN_000e70d0@Registry_e70d0@fn_fcae020b@@QAEPAXPBD@Z @6518c7d5ae17 @wf753f823b3a7
// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 42/42)
// FUN_000e70d0 @ 0x000e70d0
void* Registry_e70d0::FUN_000e70d0(const char* name) {
    const char* dot = strchr(name, '.');
    if (dot != 0) {
        hulk_intptr length = dot - name;
        if (length >= 0x40)
            return 0;
        char prefix[0x40];
        memcpy(prefix, name, length);
        prefix[length] = 0;
        Node* node = FUN_000e6490(prefix);
        if (node == 0)
            node = FUN_000e6410(prefix);
        return node->find(dot + 1);
    }

    void* result;
    if (primaryA != 0) {
        result = primaryA->find(name);
        if (result != 0)
            return result;
    }
    if (primaryC != 0) {
        result = primaryC->find(name);
        if (result != 0)
            return result;
    }
    if (primaryB != 0) {
        result = primaryB->find(name);
        if (result != 0)
            return result;
    }
    for (int i = 0; i < 0x40; ++i) {
        Node* node = groupA[i];
        if (node != primaryA && node != 0) {
            result = node->find(name);
            if (result != 0)
                return result;
        }
    }
    for (int i = 0; i < 0x100; ++i) {
        Node* node = groupC[i];
        if (node != primaryC && node != 0) {
            result = node->find(name);
            if (result != 0)
                return result;
        }
    }
    for (int i = 0; i < 0x40; ++i) {
        Node* node = groupB[i];
        if (node != primaryB && node != 0) {
            result = node->find(name);
            if (result != 0)
                return result;
        }
    }
    return 0;
}


// 0x000e7260 FUN_000e7260 (408 B): equivalent/0x000e7260.cpp
// sym: ?FUN_000e7260@Registry_e7260@fn_fcae020b@@QAEHPBD@Z @631d465665ff @wdda7d434beb1
// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 44/44)
// FUN_000e7260 @ 0x000e7260
int Registry_e7260::FUN_000e7260(const char *name)
{
    Frame_e7260 f;
    int result;
    if (name == 0) {
        result = 0;
    } else {
        const char *dot = strchr(name, '.');
        if (dot != 0) {
            hulk_intptr len = dot - name;
            if (len >= 0x40) {
                result = 0;
            } else {
                memcpy(f.buf, name, len);
                f.buf[len] = 0;
                Node *n = FUN_000e6490(f.buf);
                if (n == 0)
                    n = FUN_000e6410(f.buf);
                result = n->Lookup(dot + 1);
            }
        } else {
            result = 0;
            if (defaultA != 0)
                result = defaultA->Lookup(name);
            if (result == 0 && defaultB != 0)
                result = defaultB->Lookup(name);
            if (result == 0 && defaultC != 0)
                result = defaultC->Lookup(name);
            for (int i = 0; i < 0x40 && result == 0; i++) {
                Node *n = groupA[i];
                if (n != defaultA && n != 0)
                    result = n->Lookup(name);
            }
            for (int i = 0; i < 0x100 && result == 0; i++) {
                Node *n = groupB[i];
                if (n != defaultB && n != 0)
                    result = n->Lookup(name);
            }
            for (int i = 0; i < 0x40 && result == 0; i++) {
                Node *n = groupC[i];
                if (n != defaultC && n != 0)
                    result = n->Lookup(name);
            }
        }
    }
    return result;
}

} // namespace fn_fcae020b
