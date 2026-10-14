// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001ae1f0 @ 0x001ae1f0
struct Vec3 { float x,y,z; };
struct Item { Vec3* FUN_001b5a20(Vec3* result, unsigned int index); };
struct Manager { void FUN_001b6000(Vec3* position, Item** item, unsigned int* count); };
struct Global { char pad[16]; Manager* manager; };
extern Global* DAT_004dd700;
struct Query { Item* item; unsigned int type; unsigned int size; unsigned int option; unsigned int FUN_001adeb0(unsigned int argument, unsigned int count, int a, int b); };
bool __stdcall FUN_001ae1f0(const Vec3* position, unsigned int argument, Vec3* output, unsigned int option) {
 Vec3 copy = *position;
 Item* item = 0;
 unsigned int count = 0xffffffff;
 DAT_004dd700->manager->FUN_001b6000(&copy, &item, &count);
 if (!item) return false;
 Query query;
 query.item = item; query.type = 2; query.size = 0x4c; query.option = option;
 if (!count) return false;
 unsigned int index = query.FUN_001adeb0(argument, count, 1, 1);
 if (!index) return false;
 Vec3 temporary;
 Vec3* result = item->FUN_001b5a20(&temporary, index);
 output->x = result->x;
 output->y = result->y;
 output->z = result->z;
 return true;
}