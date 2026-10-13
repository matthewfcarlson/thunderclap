// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 18/18)
// FUN_00300410 @ 0x00300410
struct State { char pad[0x19]; unsigned char enabled; };
struct Item { char pad0[0x20]; State* state; char pad1[0x2c]; unsigned char flag50; char pad2[0x17]; unsigned char flag68; unsigned char flag69; char pad3; unsigned char flag6b; };
struct Entry { Item* first; Item* second; char pad[12]; void FUN_002f8e80(); };
struct Owner { char pad[0x30]; Entry* begin; Entry* end; char pad2[8]; unsigned int current; unsigned int previous; void FUN_00300410(unsigned int flags); };
void Owner::FUN_00300410(unsigned int flags) {
 previous = current;
 unsigned int count = (unsigned int)(((char*)end-(char*)begin)/20);
 if (!count) return;
 unsigned int i=0;
 do {
  if(flags & 4) {
   Item* p=begin[i].first;
   if(!p->flag50 && !p->flag6b) { p->state->enabled=0; p->flag68=1; p->flag69=1; }
   p=begin[i].second;
   if(!p->flag50 && !p->flag6b) { p->state->enabled=0; p->flag68=1; p->flag69=1; }
  }
  begin[i].FUN_002f8e80();
  ++i;
 } while(i < (unsigned int)(((char*)end-(char*)begin)/20));
}
