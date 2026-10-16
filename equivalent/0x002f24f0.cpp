// STATUS: equivalent (tools/equiv.py level 3: 390 inputs, branch coverage 16/16)
// FUN_002f24f0 @ 0x002f24f0
#include "decls/data/game/global.h"

struct Item_2f24f0 { union { float value; unsigned int bits; }; unsigned int second; unsigned int third; };
struct Vector { float x,y,z; };
struct List_2f24f0 { int count; int capacity; Item_2f24f0* data; void FUN_00201cd0(int capacity); void FUN_002f2470(int index, const Item_2f24f0* item); };
void __cdecl FUN_002f24f0(List_2f24f0* list, const Item_2f24f0* item, const Vector* direction, Vector* output, float* valueOut) {
 if ((*(unsigned char*)&DAT_00554c1c)) {
  if (list->count == 0) {
   if (list->capacity <= 0) list->FUN_00201cd0(list->capacity * 2);
   ++list->count;
   Item_2f24f0* dest = &list->data[list->count-1];
   dest->bits = item->bits; dest->second = item->second; dest->third = item->third;
  } else {
   Item_2f24f0* dest = list->data;
   if (item->value < dest->value) { dest->bits = item->bits; dest->second = item->second; dest->third = item->third; }
  }
  float value = item->value;
  *valueOut = value;
  output->x = value * direction->x;
  output->y = value * direction->y;
  output->z = value * direction->z;
 } else {
  int oldCount = list->count;
  if (oldCount > 0) {
   Item_2f24f0* cursor = list->data;
   for (int i=0; i<list->count; ++i, ++cursor) {
    if (item->value < cursor->value) { list->FUN_002f2470(i, item); return; }
   }
  }
  if (oldCount >= list->capacity) list->FUN_00201cd0(list->capacity * 2);
  ++list->count;
  Item_2f24f0* dest = &list->data[list->count-1];
  dest->bits = item->bits; dest->second = item->second; dest->third = item->third;
 }
}
