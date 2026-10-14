// STATUS: equivalent (tools/equiv.py level 3: 211 inputs, branch coverage 6/6)
// FUN_0033a970 @ 0x0033a970
struct Stream { char data[1]; };
extern Stream DAT_004d99f0;
extern Stream DAT_004d9a30;
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl FUN_00347eed(const char *, Stream *);
extern "C" char * __cdecl _fgets(char *, int, Stream *);
extern "C" void __cdecl FUN_00339c00(void *, const char *);
extern "C" void __cdecl FUN_00212d80(void *, int);
int __cdecl FUN_0033a970(void *state) {
 unsigned int cookie=DAT_004d9968;
 char line[250];
 FUN_00347eed("lua_debug> ", &DAT_004d9a30);
 while (_fgets(line,250,&DAT_004d99f0)) {
  const char *end="cont\n";
  int i;
  for(i=0;i<6;++i) if(line[i]!=end[i]) break;
  if(i==6) break;
  FUN_00339c00(state,line);
  FUN_00212d80(state,0);
  FUN_00347eed("lua_debug> ",&DAT_004d9a30);
 }
 __security_check_cookie(cookie);
 return 0;
}