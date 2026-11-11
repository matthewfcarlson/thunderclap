// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00092120..0x000933a0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fce1eea0 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fce1eea0 {} using namespace fn_fce1eea0;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fce1eea0 {
int __cdecl FUN_00345475(int c);
class Sink_92390 {
public:
};
struct Item_92470 { char pad[8]; unsigned char state; };
struct Observer_92470 { void FUN_000c2c10(int); };
struct Table_92470 {
 Item_92470 *items[866];
 Observer_92470 *observer;
 bool FUN_00092470(int first, int last, const char *format, unsigned __int64 key, unsigned char state);
};


// 0x00092390 FUN_00092390 (116 B): equivalent/0x00092390.cpp
// sym: ?FUN_00092390@fn_fce1eea0@@YGXPAVSink_92390@1@PBDH@Z
// STATUS: equivalent (tools/equiv.py level 3: 7022 inputs, branch coverage 6/6)
// FUN_00092390 @ 0x00092390
void __stdcall FUN_00092390(Sink_92390 *sink, const char *src, int arg)
{
    struct Frame {
        char buf[0x40];
    } fr;
    const char *e = src;
    while (*e != 0)
        e++;
    hulk_intptr len = e - src;
    int i;
    for (i = 0; i < len; i++)
        fr.buf[i] = (char)FUN_00345475(src[i]);
    fr.buf[i] = 0;
    ((owners::Obj_1d1dd0 *)sink)->FUN_001d1dd0((hulk_intptr)(fr.buf), arg);
}


// 0x00092470 FUN_00092470 (207 B): equivalent/0x00092470.cpp
// sym: ?FUN_00092470@Table_92470@fn_fce1eea0@@QAE_NHHPBD_KE@Z
// STATUS: equivalent (tools/equiv.py level 3: 4486 inputs, branch coverage 15/16, incomplete)
// FUN_00092470 @ 0x00092470
bool Table_92470::FUN_00092470(int first, int last, const char *format, unsigned __int64 key, unsigned char state) {
 char buffer[256];
 bool found=false;
 for (int n=0; first+n <= last; ++n) {
  sprintf(buffer, format, n);
  if (FUN_0027b020(buffer) == key) {
   int index=first+n-1;
   if(index>=first && index<=last) {
    Item_92470 *item=items[index];
    if(item->state!=state) {
     item->state=state;
     if(observer) observer->FUN_000c2c10(index);
    }
   }
   found=true;
   break;
  }
 }
 return found;
}

} // namespace fn_fce1eea0
