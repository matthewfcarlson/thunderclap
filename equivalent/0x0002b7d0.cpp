// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0002b7d0 @ 0x0002b7d0
#include "gen/owners.h"
struct Item { unsigned char FUN_00035ab0(); };
struct Manager {  };
struct Owner { char pad[0x44]; Manager* manager; };
struct Target { Owner* owner; char pad[8]; int count; int entries[1]; void FUN_0002a4b0(int,int); unsigned char FUN_0002b7d0(); };
unsigned char Target::FUN_0002b7d0() { for(int i=0;i<count;++i) { Item* item=((Item *)((owners::ThisWrap_00059c10 *)(owner->manager))->FUN_00059c10((void *)(hulk_uintptr)(int)(entries[i]))); if(item && !item->FUN_00035ab0()) { FUN_0002a4b0(i,0); return 1; } } return 0; }