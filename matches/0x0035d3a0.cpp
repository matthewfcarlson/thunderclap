extern "C" struct Hash {
    void* p;
    unsigned int s;
} __cdecl FUN_0027b020(void*);
extern "C" void* g_hash_35d3a0;
extern "C" unsigned int g_size_35d3a0;
void __cdecl FUN_0035d3a0() {
    Hash h = FUN_0027b020((void*)0x40048c);
    g_hash_35d3a0 = h.p;
    g_size_35d3a0 = h.s;
}
