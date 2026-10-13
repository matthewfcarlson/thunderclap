// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 12/14, incomplete)
// FUN_00227f90 @ 0x00227f90
struct Item { char data[12]; };
struct Partition { Item* first; Item* second; };
extern void __cdecl FUN_00227a10(Partition*, Item*, Item*);
extern void __cdecl FUN_00227e20(Item*, Item*);
extern void __cdecl FUN_002277f0(Item*, Item*, int, int);
extern void __cdecl FUN_00227ef0(Item*, Item*);
void __cdecl FUN_00227f90(Item* first, Item* last, int budget) {
 int count = last-first;
 while (count > 32 && budget > 0) {
  Partition p;
  FUN_00227a10(&p, first, last);
  budget = budget/2 + (budget/2)/2;
  int right = last-p.second;
  int left = p.first-first;
  if (left < right) {
   FUN_00227f90(first,p.first,budget);
   first=p.second;
  } else {
   FUN_00227f90(p.second,last,budget);
   last=p.first;
  }
  count=last-first;
 }
 if(count <= 32) {
  if(count > 1) FUN_00227e20(first,last);
 } else {
  if(last-first > 1) FUN_002277f0(first,last,0,0);
  FUN_00227ef0(first,last);
 }
}
