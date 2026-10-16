// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001ae1f0 @ 0x001ae1f0
#include "decls/address.h"
struct Vec3_1ae1f0 { float x,y,z; };
struct Item_1ae1f0 { Vec3_1ae1f0* FUN_001b5a20(Vec3_1ae1f0* result, unsigned int index); };
struct Manager_1ae1f0 { void FUN_001b6000(Vec3_1ae1f0* position, Item_1ae1f0** item, unsigned int* count); };
struct World { char pad[16]; Manager_1ae1f0* manager; };
struct Query_1ae1f0 { Item_1ae1f0* item; unsigned int type; unsigned int size; unsigned int option; unsigned int FUN_001adeb0(unsigned int argument, unsigned int count, int a, int b); };
bool __stdcall FUN_001ae1f0(const Vec3_1ae1f0* position, unsigned int argument, Vec3_1ae1f0* output, unsigned int option) {
 Vec3_1ae1f0 copy = *position;
 Item_1ae1f0* item = 0;
 unsigned int count = 0xffffffff;
 DAT_004dd700->manager->FUN_001b6000(&copy, &item, &count);
 if (!item) return false;
 Query_1ae1f0 query;
 query.item = item; query.type = 2; query.size = 0x4c; query.option = option;
 if (!count) return false;
 unsigned int index = query.FUN_001adeb0(argument, count, 1, 1);
 if (!index) return false;
 Vec3_1ae1f0 temporary;
 Vec3_1ae1f0* result = item->FUN_001b5a20(&temporary, index);
 output->x = result->x;
 output->y = result->y;
 output->z = result->z;
 return true;
}