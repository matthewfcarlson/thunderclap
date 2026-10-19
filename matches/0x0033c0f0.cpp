// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 8/8)
// FUN_0033c0f0 @ 0x0033c0f0
// cl-flags: /GS
struct Buffer_33c0f0 { unsigned char* current; unsigned char storage[520]; };
extern "C" int __cdecl FUN_00212d70(void*);
extern "C" void __cdecl FUN_00339630(void*, Buffer_33c0f0*);
extern "C" int __cdecl FUN_00339f70(void*, int);
extern "C" void __cdecl FUN_00339c30(void*, int, const char*);
extern "C" void __cdecl FUN_00339470(Buffer_33c0f0*);
extern "C" void __cdecl FUN_00339540(Buffer_33c0f0*);
int __cdecl FUN_0033c0f0(void* input) {
 Buffer_33c0f0 buffer;
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
 return 1;
}