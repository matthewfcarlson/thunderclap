// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 4/4)
// FUN_0030e280 @ 0x0030e280
#include "compat/ptr.h"
struct Item { int a,b,c,d,e; };
struct CollisionAnalyser_30e280 {
 char pad0[4];
 Item* first;
 Item* last;
 char pad1[8];
 Item* begin;
 Item* end;
 Item* limit;
 Item* FUN_0030e280();
};
Item* CollisionAnalyser_30e280::FUN_0030e280() {
 Item* result = 0;
 if ((hulk_ulongptr)end < (hulk_ulongptr)limit) {
  Item* p = end;
  end = p + 1;
  if (p) { p->a=0; p->c=0; p->b=0; p->d=0; p->e=0; }
  result = end - 1;
 }
 first = begin;
 last = (Item*)((char*)begin + (((int)((char*)end-(char*)begin)/20)*20) - 20);
 return result;
}
