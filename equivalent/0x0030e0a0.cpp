// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 14/16, incomplete)
// FUN_0030e0a0 @ 0x0030e0a0
struct Item { char pad[0x94]; float time; bool FUN_00319d20(); void FUN_0031a400(); void FUN_00319ef0(); };
struct Entry { char pad[16]; Item* item; };
extern float DAT_003f5d00;
void __cdecl FUN_0030dbd0(Entry*,Entry*,Entry*);
struct Manager { char pad[4]; Entry* first; Entry* last; float cutoff; char pad10[4]; Entry* storage; Entry* end; char pad1c[12]; Item** out; Item** outEnd; void target(); };
void Manager::target() {
 Entry* p=last;
 if ((unsigned)first>(unsigned)p) return;
 for (;;) {
  if(p->item->FUN_00319d20()) {
   p->item->FUN_0031a400();
   Item** dest=out;
   if((unsigned)dest<(unsigned)outEnd) { out=(Item**)((unsigned)dest+4); if(dest) *dest=p->item; }
   int index=((int)((unsigned)p-(unsigned)first))/20;
   Entry* e=storage+index;
   FUN_0030dbd0(e+1,end,e);
   end=(Entry*)((unsigned)end-20);
  }
  Entry* prev=p; p=(Entry*)((unsigned)p-20);
  if(prev==first) break;
 }
 int count=((int)((unsigned)end-(unsigned)storage))/20;
 if(!count) { last=0; first=(Entry*)20; return; }
 p=storage; first=p; last=p+count-1;
 for(;;) {
  if((double)p->item->time+(double)DAT_003f5d00 <= (double)cutoff) p->item->FUN_00319ef0();
  Entry* prev=p; p=(Entry*)((unsigned)p+20);
  if(prev==last) break;
 }
}