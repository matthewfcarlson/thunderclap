extern "C" void* __stdcall FUN_00059ba0(void*);
extern "C" unsigned int __stdcall FUN_00059c10(void* p) {
    void* q = FUN_00059ba0(p);
    if (q) return *(unsigned int*)((char*)q + 0x10);
    return 0;
}