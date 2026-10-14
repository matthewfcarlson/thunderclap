// STATUS: equivalent (tools/equiv.py level 3: 104 inputs, branch coverage 8/8)
// FUN_0033c0f0 @ 0x0033c0f0
struct Buffer { unsigned char* current; unsigned char storage[520]; };
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl FUN_00212d70(void*);
extern "C" void __cdecl FUN_00339630(void*, Buffer*);
extern "C" int __cdecl FUN_00339f70(void*, int);
extern "C" void __cdecl FUN_00339c30(void*, int, const char*);
extern "C" void __cdecl FUN_00339470(Buffer*);
extern "C" void __cdecl FUN_00339540(Buffer*);
int __cdecl FUN_0033c0f0(void* input) {
 unsigned int cookie = DAT_004d9968;
 Buffer buffer;
 int count = FUN_00212d70(input);
 FUN_00339630(input, &buffer);
 for (int i=1; i<=count; ++i) {
  int value = FUN_00339f70(input, i);
  if ((unsigned char)value != value) FUN_00339c30(input, i, "invalid value");
  if (buffer.current >= buffer.storage + 520) FUN_00339470(&buffer);
  *buffer.current = (unsigned char)value;
  ++buffer.current;
 }
 FUN_00339540(&buffer);
 __security_check_cookie(cookie);
 return 1;
}