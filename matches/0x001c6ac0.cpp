extern "C" unsigned char gFlagByte;
extern "C" unsigned int gFlagWord;
extern "C" unsigned char gBuffer;
struct Obj {
    char pad[0x10];
    int value;
};
extern "C" void* __fastcall FUN_001c6ac0(Obj* self, void*) {
    if (self->value)
        return (void*)(self->value + 0x14);
    unsigned char c = gFlagByte;
    unsigned int one = 1;
    if ((one & c) == 0)
        gFlagWord |= one;
    return &gBuffer;
}