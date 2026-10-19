struct ThisWrap_00059c10 {
    void* FUN_00059ba0(void*);
    unsigned int FUN_00059c10(void* p);
};
unsigned int ThisWrap_00059c10::FUN_00059c10(void* p) {
    void* q = this->FUN_00059ba0(p);
    if (q)
        return *(unsigned int*)((char*)q + 0x10);
    return 0;
}