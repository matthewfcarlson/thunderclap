int __cdecl FUN_002dd230(void* p) {
    if (((char*)p)[0x11b]) {
        *(int*)((char*)p + 0x68) |= 2;
        return 7;
    }
    return 1;
}