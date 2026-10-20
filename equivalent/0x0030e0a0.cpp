// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 15/16, incomplete)
// FUN_0030e0a0 @ 0x0030e0a0
// FUN_0030e0a0 @ 0x0030e0a0
#include "compat/ptr.h"
#include "decls/data/game/global.h"

struct Item_30e0a0 { char pad[0x94]; float time; bool FUN_00319d20(); void FUN_0031a400(); void FUN_00319ef0(); };
struct Entry_30e0a0 { char pad[16]; Item_30e0a0* item; };
void __cdecl FUN_0030dbd0(Entry_30e0a0*,Entry_30e0a0*,Entry_30e0a0*);
struct Manager_30e0a0 { char pad[4]; Entry_30e0a0* first; Entry_30e0a0* last; float cutoff; char pad10[4]; Entry_30e0a0* storage; Entry_30e0a0* end; char pad1c[12]; Item_30e0a0** out; Item_30e0a0** outEnd; void target(); };
void Manager_30e0a0::target() {
 Entry_30e0a0* p=last;
 if ((hulk_uintptr)first>(hulk_uintptr)p) return;
 for (;;) {
  if(p->item->FUN_00319d20()) {
   p->item->FUN_0031a400();
   Item_30e0a0** dest=out;
   if((hulk_uintptr)dest<(hulk_uintptr)outEnd) { out=(Item_30e0a0**)((hulk_uintptr)dest+4); if(dest) *dest=p->item; }
   int index=((int)((hulk_uintptr)p-(hulk_uintptr)first))/20;
   Entry_30e0a0* e=storage+index;
   FUN_0030dbd0(e+1,end,e);
   end=(Entry_30e0a0*)((hulk_uintptr)end-20);
  }
  Entry_30e0a0* prev=p; p=(Entry_30e0a0*)((hulk_uintptr)p-20);
  if(prev==first) break;
 }
 int count=((int)((hulk_uintptr)end-(hulk_uintptr)storage))/20;
 if(!count) { last=0; first=(Entry_30e0a0*)20; return; }
 p=storage; first=p; last=p+count-1;
 for(;;) {
  if((double)p->item->time+(double)(*(float*)&DAT_003f5d00) < (double)cutoff) p->item->FUN_00319ef0();
  Entry_30e0a0* prev=p; p=(Entry_30e0a0*)((hulk_uintptr)p+20);
  if(prev==last) break;
 }
}
