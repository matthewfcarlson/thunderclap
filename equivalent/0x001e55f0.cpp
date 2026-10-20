// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 12/14, incomplete)
// FUN_001e55f0 @ 0x001e55f0
#include "compat/ptr.h"
struct Item_1e55f0 { char data[20]; };
struct Partition { Item_1e55f0* first; Item_1e55f0* second; };
void __cdecl FUN_001e4490(Partition*, Item_1e55f0*, Item_1e55f0*);
void __cdecl FUN_001e4190(Item_1e55f0*, Item_1e55f0*);
void __cdecl FUN_001e2800(Item_1e55f0*, Item_1e55f0*, int, int);
void __cdecl FUN_001e46d0(Item_1e55f0*, Item_1e55f0*);
void __cdecl FUN_001e55f0(Item_1e55f0* begin, Item_1e55f0* end, int depth) {
 hulk_intptr count = end-begin;
 while (count > 32) {
  if (depth <= 0) {
   if (end-begin > 1) FUN_001e2800(begin,end,0,0);
   FUN_001e46d0(begin,end);
   return;
  }
  Partition p;
  FUN_001e4490(&p,begin,end);
  depth = depth/2 + (depth/2)/2;
  if (p.first-begin < end-p.second) {
   FUN_001e55f0(begin,p.first,depth);
   begin=p.second;
  } else {
   FUN_001e55f0(p.second,end,depth);
   end=p.first;
  }
  count=end-begin;
 }
 if(count>1) FUN_001e4190(begin,end);
}
