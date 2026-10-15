extern "C" void* memcpy(void*, const void*, unsigned int);
struct Src {
    char pad[0x24];
    char* data;
};
struct Info {
    int size;
    int count;
    char pad[0x40];
    int stride;
    char pad2[4];
    char* dest;
};
void __stdcall FUN_002de5a0(Src* src, Info* info) {
    char* dst = info->dest;
    char* p = src->data;
    for (int i = 0; i < info->count; ++i) {
        memcpy(dst, p, info->size);
        p += info->size;
        dst += info->stride;
    }
}