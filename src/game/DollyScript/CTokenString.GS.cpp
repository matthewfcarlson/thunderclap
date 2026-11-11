// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f9870..0x000fb3b0 (kind game, layer game, confidence high), dominant class DollyScript::CTokenString
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5b5e0ac {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5b5e0ac {} using namespace fn_f5b5e0ac;
#include "game/DollyScript.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char*, const char*, ...);
#endif
namespace fn_f5b5e0ac {
extern void* __cdecl FUN_00263ea0(uint);
extern "C" void* __cdecl FUN_0008d6d0(uint);
struct Name_fa4b0 { void FUN_0027b040(const char*); };
struct Reader { virtual void slot0(); virtual void slot1(); Reader* FUN_00264430(const char*,uint,uint); uint FUN_00263fb0(); void FUN_002647e0(void*,uint,uint,uint); };
struct FUN_0027b070 { FUN_0027b070(); virtual void slot0(); virtual void slot1(); uint pad4; Name_fa4b0 name; char namepad[3]; uint padc; void* data; uint size; void* cursor; uint tail; };
namespace DollyScript {
struct CRawScript : FUN_0027b070 { virtual void slot0(); virtual void slot1(); };
}
struct Manager_fa4b0;
struct ManagerTable { void* slots[4]; void (__fastcall *insert)(Manager_fa4b0*,void*,unsigned __int64,DollyScript::CRawScript*); };
struct Manager_fa4b0 { ManagerTable* dispatch; };
} // namespace fn_f5b5e0ac
extern "C" unsigned char DAT_004e09f8[4];
extern "C" unsigned char DAT_004e09fc[4];
namespace fn_f5b5e0ac {
struct Item_faf80 {
    char pad0[4];
    Item_faf80 *next;
};
class Script_faf80;
struct TokState {
    char *tok;
    Script_faf80 *owner;
};
struct Head_faf80 {
    Item_faf80 *first;
    Item_faf80 *last;
};
class Lines {
public:
    bool FUN_000f99d0(char *out);
    char pad0[0x10];
    int mark10;
    char pad14[4];
    int mark18;
};
class Script_faf80 {
public:
    Head_faf80 *head;
    Item_faf80 *FUN_000fa5a0(TokState *state, char *line, int index, int lineNo, char *copy);
    bool FUN_000faa40(Item_faf80 *it);
    Head_faf80 *FUN_000faf80(Lines *lines);
};
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
char *__cdecl FUN_003465c6(char *s, const char *delims);
struct Frame_faf80 {
    int lineNo;
    TokState ts;
    char line[0x100];
    char copy[0x100];
};


// 0x000fa4b0 FUN_000fa4b0 (231 B): equivalent/0x000fa4b0.cpp
// sym: ?FUN_000fa4b0@fn_f5b5e0ac@@YGPAUCRawScript@DollyScript@1@PBD@Z @ddacf92fd5c6 @w56b47ac57895
// STATUS: equivalent (tools/equiv.py level 3: 16204 inputs, branch coverage 4/4)
// FUN_000fa4b0 @ 0x000fa4b0
DollyScript::CRawScript* __stdcall FUN_000fa4b0(const char* name) {
 char buffer[256]; sprintf(buffer,"%s",name);
 Reader* mem=(Reader*)FUN_00263ea0(0x48);
 Reader* reader=mem ? mem->FUN_00264430(buffer,0,0) : 0;
 uint size=reader->FUN_00263fb0(); void* data=FUN_0008d6d0(size);
 reader->FUN_002647e0(data,size,1,1); reader->slot1();
 DollyScript::CRawScript* raw=(DollyScript::CRawScript*)FUN_00263ea0(0x20);
 if(raw) { raw->DollyScript::CRawScript::CRawScript(); raw->data=data; raw->size=size; raw->cursor=data; }
 raw->name.FUN_0027b040(name);
 ManagerTable* dispatch=(*(Manager_fa4b0**)&DAT_004dd9cc)->dispatch;
 unsigned __int64 key=FUN_002672f0(name,0,0); dispatch->insert((*(Manager_fa4b0**)&DAT_004dd9cc),0,key,raw);
 return raw;
}


// 0x000faf80 FUN_000faf80 (399 B): equivalent/0x000faf80.cpp
// sym: ?FUN_000faf80@Script_faf80@fn_f5b5e0ac@@QAEPAUHead_faf80@2@PAVLines@2@@Z @621bd5b4d1ba @w272319c00128
// STATUS: equivalent (tools/equiv.py level 3: 16169 inputs, branch coverage 27/27)
// FUN_000faf80 @ 0x000faf80
Head_faf80 *Script_faf80::FUN_000faf80(Lines *lines)
{
    Frame_faf80 f;
    f.ts.owner = this;
    lines->mark18 = lines->mark10;
    Head_faf80 *h = (Head_faf80 *)FUN_0008d690((int)sizeof(Head_faf80));
    if (h) {
        h->first = 0;
        h->last = 0;
    }
    head = h;
    f.lineNo = 1;
    bool ok = lines->FUN_000f99d0(f.line);
    {
        int i = 0;
        char c;
        do {
            c = f.line[i];
            f.copy[i] = c;
            i++;
        } while (c);
    }
    if (ok) {
        do {
            int index = 1;
            f.ts.tok = FUN_003465c6(f.line, " \t\n\r");
            while (f.ts.tok) {
                Item_faf80 *it = FUN_000fa5a0(&f.ts, f.line, index, f.lineNo, f.copy);
                if (!it)
                    break;
                if (!FUN_000faa40(it)) {
                    if (!(*(unsigned char*)DAT_004e09fc & 1)) {
                        *(unsigned*)DAT_004e09fc |= 1;
                        *(Item_faf80**)DAT_004e09f8 = it;
                    }
                    Item_faf80 *&last = *(Item_faf80**)DAT_004e09f8;
                    Head_faf80 *hd = head;
                    if (hd->first == 0) {
                        hd->first = it;
                    } else if (last != it) {
                        if (last->next)
                            ((owners::Node_f9b40 *)(last->next))->FUN_000f9b40((owners::Node_f9b40 *)(Item_faf80 *)it);
                        else
                            last->next = it;
                    }
                    last = it;
                }
                index++;
            }
            ok = lines->FUN_000f99d0(f.line);
            {
                int i = 0;
                char c;
                do {
                    c = f.line[i];
                    f.copy[i] = c;
                    i++;
                } while (c);
            }
            f.lineNo++;
        } while (ok);
    }
    Head_faf80 *result = head;
    return result;
}

} // namespace fn_f5b5e0ac
