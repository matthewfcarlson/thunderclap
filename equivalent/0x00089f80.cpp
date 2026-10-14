// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_00089f80 @ 0x00089f80
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct InfoReader {
 bool FUN_001d2ba0(const char*, int, int);
 bool FUN_001d2c60(const char*, char*, int);
 void FUN_001d19d0(int);
};
InfoReader* __cdecl FUN_001d4c90();
unsigned __int64 __cdecl FUN_0027b020(const char*);
void __cdecl FUN_000964a0(char*, int, const char*, ...);
struct Entry_89f80 { unsigned int low, high; char text[16]; };
struct Manager_89f80 {
 char pad[0x158];
 Entry_89f80 entries[100];
 int FUN_00089400(const char*);
 void FUN_00089f80(const char*);
};
void Manager_89f80::FUN_00089f80(const char* name) {
 unsigned int cookie = DAT_004d9968;
 char info[64];
 int index = FUN_00089400(name);
 if (index == -1) {
  for(index = 0; index < 100; ++index) {
   if (entries[index].low == 0 && entries[index].high == 0) break;
  }
  if(index == 100) {
   __security_check_cookie(cookie);
   return;
  }
 }
 InfoReader* reader = FUN_001d4c90();
 if(reader && reader->FUN_001d2ba0(name,1,0)) {
  if(reader->FUN_001d2c60("info", info, 64)) {
   unsigned __int64 key = FUN_0027b020(name);
   entries[index].high = (unsigned int)(key >> 32);
   entries[index].low = (unsigned int)key;
   FUN_000964a0(entries[index].text,16,"%s",info);
  }
  reader->FUN_001d19d0(1);
 }
 __security_check_cookie(cookie);
}