// STATUS: equivalent (tools/equiv.py level 3: 148 inputs, branch coverage 14/14)
// FUN_0027b570 @ 0x0027b570
extern void __cdecl FUN_0008d340(void*);
struct ResourceInfo {
 char pad0[16];
 unsigned int count;
 char pad1[48];
 char* begin;
 char* end;
};
struct Owner_27b570 {
 ResourceInfo* info;
 void* buffer;
 void** entries;
 unsigned int extraCount;
 void** extras;
 void** records;
 void cleanup();
};
void Owner_27b570::cleanup() {
 if (!info) return;
 unsigned int i;
 for (i=0; i<info->count; ++i) FUN_0008d340(entries[i]);
 for (i=0; i<extraCount; ++i) FUN_0008d340(extras[i]);
 for (i=0; i<(unsigned int)((int)(info->end-info->begin)/40); ++i) FUN_0008d340(records[i]);
 FUN_0008d340(buffer);
 FUN_0008d340(entries);
 FUN_0008d340(extras);
 FUN_0008d340(records);
}
