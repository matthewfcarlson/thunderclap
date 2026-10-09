typedef unsigned int size_t;
extern "C" void* __cdecl Alloc(size_t);
struct Track { unsigned char pad[0x14]; void Init(); };
struct Factory { void* vfunc_5(); };
void* Factory::vfunc_5() {
    Track* p = (Track*)Alloc(0x14);
    if (p) {
        p->Init();
        *(unsigned int*)p = 0x41932c;
        *(unsigned int*)((char*)p + 0xc) = 0;
        *((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}
