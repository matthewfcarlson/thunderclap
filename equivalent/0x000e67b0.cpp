// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 21/22, incomplete)
// FUN_000e67b0 @ 0x000e67b0
struct Entry {
 char padding[0x18];
 char name[0x20];
 Entry* FUN_000fb470(const char* name);
};
void* __cdecl FUN_0008d690(unsigned int size);
struct Registry {
 char padding[0x160c];
 Entry* entries[64];
 Entry* findOrCreate(const char* name);
};
Entry* Registry::findOrCreate(const char* name) {
 for (int i = 0; i < 64; ++i) {
  Entry* entry = entries[i];
  if (entry) {
   const unsigned char* a = (const unsigned char*)name;
   const unsigned char* b = (const unsigned char*)entry->name;
   while (*a == *b && *a) { ++a; ++b; }
   if (*a == *b) return entries[i];
  }
 }
 for (int slot = 0; slot < 64; ++slot) {
  if (!entries[slot]) {
   Entry* memory = (Entry*)FUN_0008d690(0x38);
   Entry* result = memory ? memory->FUN_000fb470(name) : 0;
   entries[slot] = result;
   return result;
  }
 }
 return 0;
}
