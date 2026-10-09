typedef unsigned int uint;
extern "C" void* FUN_0021add0(void* a, void* b, uint c, uint d);
void* FUN_0021a6b0(void* p1, void** p2, uint p3) {
    if (p3 > (uint)p2[2]) {
        if (p3 < 0x20)
            p3 = 0x20;
        p2[0] = FUN_0021add0(p1, p2[0], (uint)p2[2], p3);
        p2[2] = (void*)p3;
    }
    return p2[0];
}