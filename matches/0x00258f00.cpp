typedef unsigned int uint;
struct Sound { char pad[0x7c]; int buffer; };
struct Config { char pad[0x14]; uint value; };
struct Obj { char pad20[0x20]; Sound* sound; char pad24[0x3c]; Config* config; };
extern "C" void __stdcall GetCurrentPosition(int, unsigned int*, unsigned int);
int __cdecl FUN_00258f00(Obj* p) {
 unsigned int pos = 0;
 GetCurrentPosition(*(int*)((char*)p->sound + 0x7c), &pos, 0);
 return (((p->config->value >> 4) & 0x1f) * pos);
}
