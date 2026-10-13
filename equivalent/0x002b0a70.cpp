// STATUS: equivalent (tools/equiv.py level 3: 42 inputs, branch coverage 14/14)
// FUN_002b0a70 @ 0x002b0a70
struct Item { unsigned char mode; char pad[3]; unsigned first; unsigned second; float x; float y; float z; };
struct Mapping { char pad[20]; unsigned* values; };
struct Entry { Item* item; Mapping* mapping; };
struct List { Entry* begin; Entry* end; unsigned capacity; float scale; bool FUN_002b07d0(); };
struct Output { void FUN_002d0e20(unsigned id, float value); };
union FloatBits { float f; unsigned bits; };
void __cdecl target(List* list, Output* output) {
 if (!list->FUN_002b07d0()) return;
 Entry* entries = list->begin;
 unsigned count = (unsigned)(list->end - entries);
 for (unsigned i=0; i<count; ++i) {
  Item* item = entries[i].item;
  FloatBits value, magnitude;
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
