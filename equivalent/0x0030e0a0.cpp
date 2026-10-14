// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 14/16, incomplete)
// FUN_0030e0a0 @ 0x0030e0a0
struct Item_30e0a0 { char pad[0x94]; float time; bool FUN_00319d20(); void FUN_0031a400(); void FUN_00319ef0(); };
struct Entry_30e0a0 { char pad[16]; Item_30e0a0* item; };
extern float DAT_003f5d00;
void __cdecl FUN_0030dbd0(Entry_30e0a0*,Entry_30e0a0*,Entry_30e0a0*);
struct Manager_30e0a0 { char pad[4]; Entry_30e0a0* first; Entry_30e0a0* last; float cutoff; char pad10[4]; Entry_30e0a0* storage; Entry_30e0a0* end; char pad1c[12]; Item_30e0a0** out; Item_30e0a0** outEnd; void target(); };
void Manager_30e0a0::target() {
 Entry_30e0a0* p=last;
 if ((unsigned)first>(unsigned)p) return;
 for (;;) {
  if(p->item->FUN_00319d20()) {
   p->item->FUN_0031a400();
   Item_30e0a0** dest=out;
   if((unsigned)dest<(unsigned)outEnd) { out=(Item_30e0a0**)((unsigned)dest+4); if(dest) *dest=p->item; }
   int index=((int)((unsigned)p-(unsigned)first))/20;
   Entry_30e0a0* e=storage+index;
   FUN_0030dbd0(e+1,end,e);
   end=(Entry_30e0a0*)((unsigned)end-20);
  }
  Entry_30e0a0* prev=p; p=(Entry_30e0a0*)((unsigned)p-20);
  if(prev==first) break;
 }
 int count=((int)((unsigned)end-(unsigned)storage))/20;
 if(!count) { last=0; first=(Entry_30e0a0*)20; return; }
 p=storage; first=p; last=p+count-1;
 for(;;) {
  if((double)p->item->time+(double)DAT_003f5d00 <= (double)cutoff) p->item->FUN_00319ef0();
  Entry_30e0a0* prev=p; p=(Entry_30e0a0*)((unsigned)p+20);
  if(prev==last) break;
 }
}