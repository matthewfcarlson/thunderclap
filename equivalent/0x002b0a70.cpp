// STATUS: equivalent (tools/equiv.py level 3: 42 inputs, branch coverage 14/14)
// FUN_002b0a70 @ 0x002b0a70
struct Item_2b0a70 { unsigned char mode; char pad[3]; unsigned first; unsigned second; float x; float y; float z; };
struct Mapping { char pad[20]; unsigned* values; };
struct Entry_2b0a70 { Item_2b0a70* item; Mapping* mapping; };
struct List_2b0a70 { Entry_2b0a70* begin; Entry_2b0a70* end; unsigned capacity; float scale; bool FUN_002b07d0(); };
struct Output_2b0a70 { void FUN_002d0e20(unsigned id, float value); };
union FloatBits_2b0a70 { float f; unsigned bits; };
void __cdecl target(List_2b0a70* list, Output_2b0a70* output) {
 if (!list->FUN_002b07d0()) return;
 Entry_2b0a70* entries = list->begin;
 unsigned count = (unsigned)(list->end - entries);
 for (unsigned i=0; i<count; ++i) {
  Item_2b0a70* item = entries[i].item;
  FloatBits_2b0a70 value, magnitude;
  if (item->mode) {
   value.f = item->x * list->scale;
   magnitude.f = value.f; magnitude.bits &= 0x7fffffff;
   if (!(magnitude.f < 0.01f)) output->FUN_002d0e20(entries[i].mapping->values[item->first], value.f);
   value.f = item->y * list->scale;
   magnitude.f = value.f; magnitude.bits &= 0x7fffffff;
   if (!(magnitude.f < 0.01f)) output->FUN_002d0e20(entries[i].mapping->values[item->second], value.f);
  } else {
   magnitude.f = item->z; magnitude.bits &= 0x7fffffff;
   value.f = item->z * (magnitude.f * list->scale);
   magnitude.f = value.f; magnitude.bits &= 0x7fffffff;
   if (!(magnitude.f < 0.01f)) output->FUN_002d0e20(entries[i].mapping->values[item->first], value.f);
  }
  entries = list->begin;
  count = (unsigned)(list->end - entries);
 }
}
