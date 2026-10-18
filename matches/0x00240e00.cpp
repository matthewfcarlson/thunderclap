extern "C" {
struct S_240e00 {
    char pad[0x98];
    float value;
};
extern S_240e00* g_240e00;
void __cdecl FUN_00240e00(float x) {
    g_240e00->value = x;
}
}