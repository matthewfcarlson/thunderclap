// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 22/22)
// FUN_00027730 @ 0x00027730
struct Key { unsigned first, second; void FUN_0027af00(); void FUN_0027b040(const char*); };
extern Key DAT_004dc0e8;
extern unsigned DAT_004dc0f0;
extern void __cdecl FUN_00363b00();
extern int __cdecl _atexit(void (__cdecl*)());
struct Entry { unsigned first, second; unsigned char flag; char pad[7]; };
struct Object { char pad[0x380]; Entry entries[32]; int count; bool FUN_00027730(char* destination, const char* source); };
bool Object::FUN_00027730(char* destination, const char* source) {
 if (!(DAT_004dc0f0 & 1)) { DAT_004dc0f0 |= 1; DAT_004dc0e8.FUN_0027af00(); _atexit(FUN_00363b00); }
 if (!destination || !source) return false;
 const char* end=source; while (*end++) {}
 char* out=destination; while (*out) ++out;
 unsigned length=(unsigned)(end-source);
 for(unsigned j=0;j<length;++j) out[j]=source[j];
 DAT_004dc0e8.FUN_0027b040(destination);
 int oldCount=count;
 if(oldCount>0) { unsigned a=DAT_004dc0e8.first,b=DAT_004dc0e8.second; for(int i=0;i<count;++i) if(entries[i].first==a && entries[i].second==b) return entries[i].flag==0; }
 int next=oldCount+1;
 if(next<32) { count=next; entries[next].flag=0; entries[count].first=DAT_004dc0e8.first; entries[count].second=DAT_004dc0e8.second; }
 return true;
}