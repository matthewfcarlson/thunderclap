// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 19/20, incomplete)
// FUN_00024f60 @ 0x00024f60
typedef unsigned __int64 U64_24f60;
extern U64_24f60 __cdecl FUN_0027b020(const char*);
struct Detail_24f60 { char pad[0x9e]; unsigned char enabled; char pad9f; unsigned low; unsigned high; };
struct Item_24f60 { char pad[0x1ca0]; Detail_24f60* detail; };
struct Manager_24f60 { Item_24f60* FUN_00059c10(unsigned id); };
struct Owner_24f60 { char pad[0x44]; Manager_24f60* manager; };
struct List_24f60 { Owner_24f60* owner; char pad[8]; int count; unsigned ids[1]; int FUN_00024f60(const char* text); };
int List_24f60::FUN_00024f60(const char* text) {
 if (!text || !*text) return 0;
 int matches=0;
 for(int i=0;i<count;++i) {
  Item_24f60* item=owner->manager->FUN_00059c10(ids[i]);
  if(item && item->detail) {
   Detail_24f60* d=item->detail;
   if ((char*)d+0x58 && d->enabled) {
    unsigned lo=d->low, hi=d->high;
    U64_24f60 value=FUN_0027b020(text);
    if(lo==(unsigned)value && hi==(unsigned)(value>>32)) ++matches;
   }
  }
 }
 return matches;
}
