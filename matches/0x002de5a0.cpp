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
extern "C" void __stdcall FUN_002de5a0(void * src, void * info) {
    char* dst = ((Info *)info)->dest;
    char* p = ((Src *)src)->data;
    for (int i = 0; i < ((Info *)info)->count; ++i) {
        memcpy(dst, p, ((Info *)info)->size);
        p += ((Info *)info)->size;
        dst += ((Info *)info)->stride;
    }
}