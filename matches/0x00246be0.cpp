// Same code shape as 0x00246bb0 (propagated; names are from that function)
extern "C" void __cdecl FUN_00345880();
extern "C" bool __cdecl target(unsigned int a, unsigned int b, unsigned int index) {
    volatile char buffer[0x1004];
    buffer[index & 0xfff] = 0;
    return true;
}