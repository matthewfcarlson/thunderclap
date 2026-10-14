// STATUS: equivalent (tools/equiv.py level 3: 39 inputs, branch coverage 11/12, incomplete)
// FUN_00231690 @ 0x00231690
typedef unsigned int uint;
extern "C" void* __cdecl FUN_00266e00(uint, uint);
extern "C" void __cdecl FUN_00267090(void*);
struct Pair { uint first, second; };
struct Table {
 uint count, used, other;
 char padding[12];
 void** entries;
 Pair* pairs;
 char sentinel[4];
 void FUN_00231590(uint, uint, void*);
 void FUN_00231690();
};
void Table::FUN_00231690() {
 void** savedEntries = (void**)FUN_00266e00(1, count * 4);
 Pair* savedPairs = (Pair*)FUN_00266e00(1, count * 8);
 uint i;
 uint n = (count * 4) / 4;
 for (i=0; i<n; ++i) savedEntries[i] = entries[i];
 n = (count * 8) / 4;
 uint* dst = (uint*)savedPairs;
 uint* src = (uint*)pairs;
 for (i=0; i<n; ++i) dst[i] = src[i];
 other=0;
 used=0;
 for (i=0; i<count; ++i) {
 entries[i]=0;
 pairs[i].first=0;
 pairs[i].second=0;
 }
 for (i=0; i<count; ++i) {
 void* entry=savedEntries[i];
 if (entry && entry != sentinel)
 FUN_00231590(savedPairs[i].first, savedPairs[i].second, entry);
 }
 FUN_00267090(savedEntries);
 FUN_00267090(savedPairs);
}
