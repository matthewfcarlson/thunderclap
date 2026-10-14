// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 19/20, incomplete)
// FUN_00024f60 @ 0x00024f60
typedef unsigned __int64 U64;
extern U64 __cdecl FUN_0027b020(const char*);
struct Detail { char pad[0x9e]; unsigned char enabled; char pad9f; unsigned low; unsigned high; };
struct Item { char pad[0x1ca0]; Detail* detail; };
struct Manager { Item* FUN_00059c10(unsigned id); };
struct Owner { char pad[0x44]; Manager* manager; };
struct List { Owner* owner; char pad[8]; int count; unsigned ids[1]; int FUN_00024f60(const char* text); };
int List::FUN_00024f60(const char* text) {
 if (!text || !*text) return 0;
 int matches=0;
 for(int i=0;i<count;++i) {
  Item* item=owner->manager->FUN_00059c10(ids[i]);
  if(item && item->detail) {
   Detail* d=item->detail;
   if ((char*)d+0x58 && d->enabled) {
    unsigned lo=d->low, hi=d->high;
    U64 value=FUN_0027b020(text);
    if(lo==(unsigned)value && hi==(unsigned)(value>>32)) ++matches;
   }
  }
 }
 return matches;
}
