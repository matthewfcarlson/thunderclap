struct Inner_2d1650 {
    char pad[0x2c];
    int index;
};

struct Outer {
    char pad[0x1bc];
    Inner_2d1650* inner;
};

void __cdecl FUN_002d1650(void* unused, void* in, Outer* src, void* out) {
    int idx = src->inner->index;
    ((char*)out)[0x19] = ((char*)in)[idx];
}
