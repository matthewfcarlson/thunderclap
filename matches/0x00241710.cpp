float Target(int a, const void* p) {
    return *(const float*)((const char*)p + 0x24);
}