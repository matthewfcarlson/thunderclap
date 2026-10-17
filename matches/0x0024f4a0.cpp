extern "C" unsigned char __cdecl FUN_0025aad0(void*, const unsigned char*);

extern "C" unsigned char __cdecl FUN_0024f4a0(void* source, const unsigned char* data) {
    for (unsigned int block = 0; block < 16; ++block) {
        for (unsigned int byteIndex = 0; byteIndex < 4; ++byteIndex) {
            if (!FUN_0025aad0(source, data + block * 4 + byteIndex))
                return 0;
        }
    }
    return 1;
}