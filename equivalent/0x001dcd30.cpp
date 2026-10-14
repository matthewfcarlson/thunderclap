// STATUS: equivalent (tools/equiv.py level 3: 2546 inputs, branch coverage 18/18)
// FUN_001dcd30 @ 0x001dcd30
struct Entry_1dcd30 { char pad[22]; short active; char pad2[10]; short recordIndex; char pad3[4]; };
struct Record_1dcd30 { char pad[16]; unsigned short flags; char pad2[2]; };
struct Manager_1dcd30 {
 char pad[0x608];
 Entry_1dcd30 entries[2048];
 Record_1dcd30 records[2048];
 int cursor;
 char tail[0x64c];
 int count;
 void FUN_001e5bc0(int index);
 void FUN_001dcd30(int index);
};
void Manager_1dcd30::FUN_001dcd30(int index) {
 if (index < 0 || index > 2048) return;
 if (count >= 64) {
  int removed = 0;
  for (int i = 0; i < 2048; ++i) {
   int slot = (int)((unsigned int)cursor + (unsigned int)i) % 2048;
   if (entries[slot].active != 0) {
    unsigned short flags = records[entries[slot].recordIndex].flags;
    if ((flags & 0x2000) && !(flags & 1)) {
     FUN_001e5bc0(slot);
     ++removed;
    }
   }
   if (removed >= 5) break;
  }
 }
 records[entries[index].recordIndex].flags |= 0x2000;
 ++count;
}