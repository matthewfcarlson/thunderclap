// STATUS: equivalent (tools/equiv.py level 3: 2359 inputs, branch coverage 23/24, incomplete)
// FUN_00025010 @ 0x00025010
typedef unsigned __int64 U64;
extern char DAT_003f335c[];
extern U64 __cdecl FUN_0027b020(const char*);
struct Info { char pad[0x9e]; unsigned char enabled; char pad2; U64 key; };
struct Item { char pad[0x1ca0]; Info* info; const char* FUN_00036d00(); };
struct Registry { Item* FUN_00059c10(int); };
struct Owner { char pad[0x44]; Registry* registry; };
struct Target { Owner* owner; char pad[8]; int count; int ids[1]; const char* FUN_00025010(const char* name,int occurrence); };
const char* Target::FUN_00025010(const char* name,int occurrence) {
 if (!name || !*name || occurrence<=0) return DAT_003f335c;
 for (int i=0;i<count;++i) {
  Item* item=owner->registry->FUN_00059c10(ids[i]);
  if(item && item->info && (char*)item->info+0x58 != 0 && item->info->enabled) {
   U64 key=item->info->key;
   if(key==FUN_0027b020(name) && --occurrence==0) return item->FUN_00036d00();
  }
 }
 return DAT_003f335c;
}