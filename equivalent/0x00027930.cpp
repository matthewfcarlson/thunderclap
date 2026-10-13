// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 20/20)
// FUN_00027930 @ 0x00027930
struct Key {
 unsigned int first;
 void FUN_0027af00();
 void FUN_0027b040(const char* text);
};
extern Key DAT_004dc108;
extern unsigned int DAT_004dc10c;
extern unsigned int DAT_004dc110;
extern "C" void __cdecl FUN_00363b20();
extern "C" int __cdecl atexit(void (__cdecl*)());
struct Entry { unsigned int first, second; unsigned char active; char padding[7]; };
struct Owner {
 char padding[0x380];
 Entry entries[32];
 int count;
 bool FUN_00027930(char* destination, const char* suffix);
};
bool Owner::FUN_00027930(char* destination, const char* suffix) {
 if (!(DAT_004dc110 & 1)) {
  DAT_004dc110 |= 1;
  DAT_004dc108.FUN_0027af00();
  atexit(FUN_00363b20);
 }
 if (!destination || !suffix) return false;
 unsigned int length = 0;
 do { ++length; } while (suffix[length-1]);
 char* end = destination;
 while (*end) ++end;
 unsigned int words = length / 4;
 for (unsigned int j=0; j<words; ++j)
  reinterpret_cast<unsigned int*>(end)[j] = reinterpret_cast<const unsigned int*>(suffix)[j];
 for (unsigned int k=words*4; k<length; ++k) end[k]=suffix[k];
 DAT_004dc108.FUN_0027b040(destination);
 int oldCount = count;
 if (oldCount > 0) {
  unsigned int first = DAT_004dc108.first;
  unsigned int second = DAT_004dc10c;
  for (int i=0; i<count; ++i) {
   if (entries[i].first == first && entries[i].second == second) {
    entries[i].active=1;
    return true;
   }
  }
 }
 int next=oldCount+1;
 if (next < 32) {
  count=next;
  entries[next].active=1;
  int index=count;
  entries[index].first=DAT_004dc108.first;
  entries[index].second=DAT_004dc10c;
 }
 return false;
}
