// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 18/18)
// FUN_00027a50 @ 0x00027a50
struct Key_27a50 { unsigned int first, second; void FUN_0027af00(); void FUN_0027b040(const char*); };
extern Key_27a50 DAT_004dc118;
extern unsigned int DAT_004dc120;
extern void __cdecl FUN_00363b30();
extern int __cdecl atexit(void (__cdecl*)());
extern void* __cdecl memmove(void*, const void*, unsigned int);
struct Entry_27a50 { unsigned int first, second; char rest[8]; };
struct Object { char pad[0x380]; Entry_27a50 entries[32]; int count; bool FUN_00027a50(char* destination, const char* suffix); };
bool Object::FUN_00027a50(char* destination, const char* suffix) {
 if (!(DAT_004dc120 & 1)) { DAT_004dc120 |= 1; DAT_004dc118.FUN_0027af00(); atexit(FUN_00363b30); }
 if (!destination || !suffix) return false;
 unsigned int length=0; do { ++length; } while(suffix[length-1]);
 char* end=destination; while(*end) ++end;
 for(unsigned int j=0;j<length;++j) end[j]=suffix[j];
 DAT_004dc118.FUN_0027b040(destination);
 int oldCount=count;
 if(oldCount>0) {
 unsigned int first=DAT_004dc118.first, second=DAT_004dc118.second;
 for(int i=0;i<count;++i) { if(entries[i].first==first && entries[i].second==second) {
 count=oldCount-1;
 memmove(&entries[i], &entries[i+1], (count-i)*16);
 return true;
 } }
 }
 return false;
}