// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00232c40..0x00234090 (kind game, layer engine, confidence high), dominant class fight::Branch
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f023bcd8 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f023bcd8 {} using namespace fn_f023bcd8;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f023bcd8 {
extern "C" int __cdecl FUN_00267760(char*, int, const char*, ...);
} // namespace fn_f023bcd8
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
#endif
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
namespace fn_f023bcd8 {
class Node {
public:
    char pad0[8];
    unsigned int idLo;
    unsigned int idHi;
    char pad10[4];
    Node *parent;
    char pad18[4];
    Node *firstChild;
    Node *nextSibling;
    Node *FUN_00233580(const char *path);
    Node *FUN_00233650(const char *path);
};
struct Branch;
struct Writer_233c50 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(unsigned __int64 key, char *buf, int size);
    virtual void v9();
    virtual void v10(unsigned __int64 key, int *out);
    virtual void v11(unsigned __int64 key, char *out);
    void FUN_00232c40(unsigned __int64 key, Branch *b);
};
extern void __cdecl FUN_00232cc0(Writer_233c50 *w, const char *msg);
struct Holder_233c50 {
    int FUN_00233b30(int index, Branch *b);
};
struct Finder_233c50 {
    Holder_233c50 *FUN_00233580(char *name);
};
struct Obj28_233c50 {
    char pad0[0x5c];
    Finder_233c50 *finder;
};
struct Ctx_233c50 {
    char pad0[0x28];
    Obj28_233c50 *p28;
};
struct Frame_233c50 {
    char pad[3];
    char flag;
    int count;
    char buf[0x400];
    int gap;
};
struct Branch {
    char pad0[0x14];
    Holder_233c50 *holder;
    char FUN_00233c50(Ctx_233c50 *ctx, Writer_233c50 *w, int index);
};

} // namespace fn_f023bcd8

// 0x00232cc0 FUN_00232cc0 (170 B): equivalent/0x00232cc0.cpp [wrapped: conflict: DAT_004e5bb0; DAT_004e5bb4]
// sym: ?FUN_00232cc0@fn_00232cc0@@YAXPAUReader@1@PBDZZ @f7be7f437ebd @w66b91802c946
namespace fn_00232cc0 {
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 4/4)
// FUN_00232cc0 @ 0x00232cc0
// cl-flags: /GS
struct Reader {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
 virtual const char* filename();
 virtual int line();
};
extern "C" int __cdecl FUN_00267730(char*, unsigned, const char*, char*);
extern "C++" __declspec(nothrow) int __cdecl FUN_00267760(char*, unsigned, const char*, ...);
extern void (__cdecl *DAT_004e5bb0)(const char*, Reader*, void*);
extern void* DAT_004e5bb4;
void __cdecl FUN_00232cc0(Reader* reader, const char* format, ...) {
 char message[1024];
 char fullMessage[1024];
#if defined(HULK_PTR64)
 __builtin_va_list va;
 __builtin_va_start(va, format);
 FUN_00267730(message, 1024, format, va);
#else
 FUN_00267730(message, 1024, format, (char*)(&format + 1));
#endif
 const char* name = reader->filename();
 if (!name) name = "";
 FUN_00267760(fullMessage, 1024, "fight::Reader ERROR\n%s(%d):  %s\n", name, reader->line(), message);
 if (DAT_004e5bb0) DAT_004e5bb0(fullMessage, reader, DAT_004e5bb4);
}
} // namespace fn_00232cc0


// 0x00233460 FUN_00233460 (259 B): equivalent/0x00233460.cpp
// sym: ?FUN_00233460@Node_233460@owners@@QAE_NPADH@Z @7a64d25d595b @wa5448ce8f5e7
// STATUS: equivalent (tools/equiv.py level 3: 13401 inputs, branch coverage 10/10)
// FUN_00233460 @ 0x00233460
bool owners::Node_233460::FUN_00233460(char* output, int capacity) {
 char temporary[1024];
 if ((low | high) == 0) { if (capacity > 0) output[0] = 0; }
 else FUN_00267760(output, capacity, "%08x%08x", high, low);
 owners::Node_233460* current = next;
 while (current) {
  if ((current->low | current->high) == 0)
   FUN_00267760(temporary, 1024, "%s%s", (*(const char**)&DAT_004ca248), output);
  else
   FUN_00267760(temporary, 1024, "%08x%08x%s%s", current->high, current->low, (*(const char**)&DAT_004ca248), output);
  FUN_00267760(output, capacity, "%s", temporary);
  current = current->next;
 }
 FUN_00267760(temporary, 1024, "%s%s", (*(const char**)&DAT_004ca248), output);
 FUN_00267760(output, capacity, "%s", temporary);
 return true;
}


// 0x00233580 FUN_00233580 (199 B): equivalent/0x00233580.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_00233580@PathNode@fn_00233580@@QAEPAV12@PBD@Z @507581d0b2d8 @w597c60b198fb
namespace fn_00233580 {
// STATUS: equivalent (tools/equiv.py level 3: 18200 inputs, branch coverage 22/22)
// FUN_00233580 @ 0x00233580
// cl-flags: /GS
// FUN_00233580 @ 0x00233580


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif


struct HashKey {
    int lo, hi;
};

HashKey __cdecl FUN_002672f0(const char* s, int a, int b);

class PathNode {
public:
    char pad0[8];
    HashKey key;            // 0x8
    char pad10[0x1c - 0x10];
    PathNode* firstChild;   // 0x1c
    PathNode* nextSibling;  // 0x20
    PathNode* FUN_00233580(const char* path);
};

// Finds the descendant named by a delimiter-separated path.
PathNode* PathNode::FUN_00233580(const char* path)
{
    // The /GS cookie sits directly above the buffer, as in the original.
    struct Frame {
        char buf[0x40];
    } f;
    char* buf = f.buf;
    char delim = *(*(char**)&DAT_004ca248);
    if (*path == delim)
        path++;
    const char* end = path;
    while (*end != 0 && *end != delim)
        end++;
    hulk_intptr len = end - path;
    hulk_intptr n = 0;
    if (len > 0) {
        memcpy(buf, path, len);
        n = len;
    }
    buf[n] = 0;
    HashKey k = FUN_002672f0(buf, 0, 0);
    PathNode* result = 0;
    if (k.lo == key.lo && k.hi == key.hi) {
        if (*end == 0) {
            result = this;
        } else {
            for (PathNode* c = firstChild; c != 0; c = c->nextSibling) {
                result = c->FUN_00233580(end);
                if (result != 0)
                    break;
            }
        }
    }
    return result;
}
} // namespace fn_00233580

namespace fn_f023bcd8 {

// 0x00233650 FUN_00233650 (364 B): equivalent/0x00233650.cpp
// sym: ?FUN_00233650@Node@fn_f023bcd8@@QAEPAV12@PBD@Z @6c8da7c944d8 @wa7b9fd739d3d
// STATUS: equivalent (tools/equiv.py level 3: 17050 inputs, branch coverage 37/38, incomplete)
// FUN_00233650 @ 0x00233650
Node *Node::FUN_00233650(const char *path)
{
    struct {
        char name[0x40];
    } f;
    if (path == 0 || *path == 0) {
        return this;
    }
    char sep = *(*(const char**)&DAT_004ca248);
    if (*path == sep) {
        Node *root = this;
        for (Node *p = parent; p != 0; p = p->parent)
            root = p;
        Node *r = 0;
        if (root != 0)
            r = root->FUN_00233580(path);
        return r;
    }
    const char *end = path;
    while (*end != sep && *end != 0)
        end++;
    int len = (int)(end - path);
    if (len > 0) {
        memcpy(f.name, path, len);
    } else {
        len = 0;
    }
    f.name[len] = 0;
    unsigned __int64 hash = FUN_002672f0(f.name, 0);
    unsigned int lo = (unsigned int)hash;
    unsigned int hi = (unsigned int)(hash >> 32);
    if (*end != 0)
        end++;
    Node *r = 0;
    if (lo == DAT_004e5b28 && hi == DAT_004e5b2c) {
        if (parent != 0)
            r = parent->FUN_00233650(end);
    } else if (lo == DAT_004e5b00 && hi == DAT_004e5b04) {
        r = FUN_00233650(end);
    } else {
        for (Node *c = firstChild; c != 0; c = c->nextSibling) {
            if (c->idLo == lo && c->idHi == hi) {
                r = c->FUN_00233650(end);
                break;
            }
        }
    }
    return r;
}


// 0x00233c50 FUN_00233c50 (314 B): equivalent/0x00233c50.cpp
// sym: ?FUN_00233c50@Branch@fn_f023bcd8@@QAEDPAUCtx_233c50@2@PAUWriter_233c50@2@H@Z @23d757769927 @wa346a21233fc
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 14/14)
// FUN_00233c50 @ 0x00233c50
char Branch::FUN_00233c50(Ctx_233c50 *ctx, Writer_233c50 *w, int index)
{
    Frame_233c50 f;
    w->FUN_00232c40(FUN_002672f0((*(const char**)&DAT_004ca26c), 0, 0), this);
    f.buf[0] = 0;
    for (int i = 1; i < 0x400; i++)
        f.buf[i] = 0;
    w->v8(FUN_002672f0((*(const char**)&DAT_004ca270), 0, 0), f.buf, 0x400);
    f.count = 0;
    w->v10(FUN_002672f0((*(const char**)&DAT_004ca278), 0, 0), &f.count);
    char ok = w->v3();
    if (!ok) {
        f.flag = ok;
        w->v11(FUN_002672f0((*(const char**)&DAT_004ca29c), 0, 0), &f.flag);
    }
    Holder_233c50 *h = holder;
    if (f.buf[0] != 0 && ctx->p28 != 0) {
        Holder_233c50 *found = ctx->p28->finder->FUN_00233580(f.buf);
        if (found != 0)
            h = found;
    }
    char result = 0;
    if (h != 0) {
        result = h->FUN_00233b30(index, this) >= 0;
        if (!result)
            FUN_00232cc0(w, "Failed to insert branch into parent branch.");
    }
    return result;
}

} // namespace fn_f023bcd8
