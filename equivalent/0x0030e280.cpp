// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 4/4)
// FUN_0030e280 @ 0x0030e280
struct Item { int a,b,c,d,e; };
struct Obj {
 char pad0[4];
 Item* first;
 Item* last;
 char pad1[8];
 Item* begin;
 Item* end;
 Item* limit;
 Item* FUN_0030e280();
};
Item* Obj::FUN_0030e280() {
 Item* result = 0;
 if ((unsigned long)end < (unsigned long)limit) {
  Item* p = end;
  end = p + 1;
  if (p) { p->a=0; p->c=0; p->b=0; p->d=0; p->e=0; }
  result = end - 1;
 }
 first = begin;
 last = (Item*)((char*)begin + (((int)((char*)end-(char*)begin)/20)*20) - 20);
 return result;
}
