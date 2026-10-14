// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0033a430 @ 0x0033a430
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl FUN_00212f00(void*, int);
extern "C" void* __cdecl FUN_00213290(void*, int);
extern "C" int __cdecl FUN_00339f70(void*, int);
extern "C" int __cdecl FUN_00213fc0(void*, int, void*);
extern "C" int __cdecl FUN_00339c30(void*, int, const char*);
extern "C" void __cdecl FUN_00339dc0(void*, int);
extern "C" void __cdecl FUN_00212d80(void*, int);
extern "C" void __cdecl FUN_00212cb0(void*, void*, int);
extern "C" int __cdecl FUN_002140c0(void*, void*, int);
extern "C" void __cdecl FUN_002133d0(void*, int);
int __cdecl FUN_0033a430(void* state) {
 unsigned int cookie = DAT_004d9968;
 char buffer[96];
 int offset = 0;
 void* object = state;
 if (FUN_00212f00(state, 1) == 8) {
  offset = 1;
  object = FUN_00213290(state, 1);
 }
 int level = offset + 1;
 int value = FUN_00339f70(state, level);
 if (!FUN_00213fc0(object, value, buffer)) {
  int result = FUN_00339c30(state, level, "level out of range");
  __security_check_cookie(cookie);
  return result;
 }
 level = offset + 3;
 FUN_00339dc0(state, level);
 FUN_00212d80(state, level);
 FUN_00212cb0(state, object, 1);
 value = FUN_00339f70(state, offset + 2);
 int result = FUN_002140c0(object, buffer, value);
 FUN_002133d0(state, result);
 __security_check_cookie(cookie);
 return 1;
}