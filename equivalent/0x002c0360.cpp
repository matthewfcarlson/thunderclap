// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 10/10)
// FUN_002c0360 @ 0x002c0360
// Copies a rectangle of 32-bit pixels, skipping those whose colour (low 24 bits) equals `key`.
// equiv-conv: FUN_002c0360 eax ecx edx stack stack stack stack
void __cdecl FUN_002c0360(int rows, int srcStride, unsigned int *dst, unsigned int *src, int width,
                          int dstStride, unsigned int key) {
    for (; rows > 0; rows--) {
        for (int x = 0; x < width; x++) {
            unsigned int pixel = src[x];
            if ((pixel & 0xffffff) != key) {
                dst[x] = pixel;
            }
        }
        src += srcStride;
        dst += dstStride;
    }
}
