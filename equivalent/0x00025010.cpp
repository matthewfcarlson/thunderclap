// STATUS: equivalent (tools/equiv.py level 3: 2359 inputs, branch coverage 23/24, incomplete)
// FUN_00025010 @ 0x00025010
#include "decls/address.h"
typedef unsigned __int64 U64_25010;
extern char DAT_003f335c[];
struct Info_25010 { char pad[0x9e]; unsigned char enabled; char pad2; U64_25010 key; };
struct Item_25010 { char pad[0x1ca0]; Info_25010* info; const char* FUN_00036d00(); };
struct Registry_25010 { Item_25010* FUN_00059c10(int); };
struct Owner_25010 { char pad[0x44]; Registry_25010* registry; };
struct Target_25010 { Owner_25010* owner; char pad[8]; int count; int ids[1]; const char* FUN_00025010(const char* name,int occurrence); };
const char* Target_25010::FUN_00025010(const char* name,int occurrence) {
 if (!name || !*name || occurrence<=0) return DAT_003f335c;
 for (int i=0;i<count;++i) {
  Item_25010* item=owner->registry->FUN_00059c10(ids[i]);
  if(item && item->info && (char*)item->info+0x58 != 0 && item->info->enabled) {
   U64_25010 key=item->info->key;
   if(key==FUN_0027b020(name) && --occurrence==0) return item->FUN_00036d00();
  }
 }
 return DAT_003f335c;
}