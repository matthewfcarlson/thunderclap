typedef unsigned int uint;
struct Sound_258f00 {
    char pad[0x7c];
    int buffer;
};
struct Config_258f00 {
    char pad[0x14];
    uint value;
};
struct Obj_258f00 {
    char pad20[0x20];
    Sound_258f00* sound;
    char pad24[0x3c];
    Config_258f00* config;
};
extern "C" void __stdcall GetCurrentPosition(int, unsigned int*, unsigned int);
int __cdecl FUN_00258f00(Obj_258f00* p) {
    unsigned int pos = 0;
    GetCurrentPosition(*(int*)((char*)p->sound + 0x7c), &pos, 0);
    return (((p->config->value >> 4) & 0x1f) * pos);
}
