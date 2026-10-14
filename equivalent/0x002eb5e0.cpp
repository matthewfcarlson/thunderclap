// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 20/20)
// FUN_002eb5e0 @ 0x002eb5e0
struct Entry_2eb5e0 { int id; int value; const char* text; int length; };
struct List_2eb5e0 { char pad[0x30]; int count; int capacity; Entry_2eb5e0* entries; };
extern const char DAT_003f335c[];
extern void* __cdecl FUN_002e6c00(void*, unsigned int);
extern void __cdecl FUN_002e6c40(void*, void*);
void __cdecl FUN_002eb5e0(void* allocator, List_2eb5e0* list, Entry_2eb5e0* source, int count) {
 if (!allocator || !list || !count) return;
 int needed = list->count + count;
 int oldCapacity = list->capacity;
 if (needed > oldCapacity) {
  Entry_2eb5e0* old = list->entries;
  if (old) {
   list->capacity = needed + 8;
   Entry_2eb5e0* fresh = (Entry_2eb5e0*)FUN_002e6c00(allocator, (unsigned int)list->capacity * 16);
   list->entries = fresh;
   unsigned int words = ((unsigned int)oldCapacity * 16) / 4;
   unsigned int* dst = (unsigned int*)fresh;
   unsigned int* src = (unsigned int*)old;
   for (unsigned int j=0; j<words; ++j) dst[j]=src[j];
   FUN_002e6c40(allocator, old);
  } else {
   list->capacity = count + 8;
   list->count = 0;
   list->entries = (Entry_2eb5e0*)FUN_002e6c00(allocator, (unsigned int)list->capacity * 16);
  }
 }
 for (int i=0; i<count; ++i) {
  Entry_2eb5e0* dest = list->entries + list->count;
  if (!source[i].text) source[i].text = DAT_003f335c;
  const char* text = source[i].text;
  if (!*text) { dest->length=0; dest->id=-1; }
  else { int len=0; while (text[len]) ++len; dest->length=len; dest->id=source[i].id; }
  dest->text=source[i].text;
  dest->value=source[i].value;
  ++list->count;
 }
}
