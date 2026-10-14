char Get(int* p, int* out) {
    *out = *(int*)((char*)p + 0x20) - *(int*)((char*)p + 0x24) + *(int*)((char*)p + 0x1c);
    return 1;
}