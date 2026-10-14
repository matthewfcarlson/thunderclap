// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 20/20)
// FUN_00027850 @ 0x00027850
struct Key_27850 { unsigned int first; unsigned int second; void FUN_0027af00(); void FUN_0027b040(const char*); };
extern Key_27850 DAT_004dc0f8;
extern unsigned int DAT_004dc100;
extern void __cdecl FUN_00363b10();
extern int __cdecl _atexit(void (__cdecl*)());
struct Entry_27850 { unsigned int first, second; unsigned char enabled; char pad[7]; };
struct Object { char pad[0x380]; Entry_27850 entries[32]; int count; bool FUN_00027850(char* destination, const char* source); };
bool Object::FUN_00027850(char* destination, const char* source) {
 if (!(DAT_004dc100 & 1)) { DAT_004dc100 |= 1; DAT_004dc0f8.FUN_0027af00(); _atexit(FUN_00363b10); }
 if (!destination || !source) return false;
 const char* end = source; while (*end) ++end;
 unsigned int length = (unsigned int)(end-source)+1;
 char* append = destination; while (*append) ++append;
 unsigned int words=length/4;
 unsigned int* out=(unsigned int*)append;
 const unsigned int* in=(const unsigned int*)source;
 for(unsigned int j=0;j<words;++j) out[j]=in[j];
 char* tail=append+words*4; const char* rest=source+words*4;
 for(unsigned int k=0;k<(length&3);++k) tail[k]=rest[k];
 DAT_004dc0f8.FUN_0027b040(destination);
 for(int i=0;i<count;++i) { if(entries[i].first==DAT_004dc0f8.first && entries[i].second==DAT_004dc0f8.second) return entries[i].enabled != 0; }
 return false;
}