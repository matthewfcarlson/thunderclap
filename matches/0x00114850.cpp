extern void* __cdecl FUN_0008d690(unsigned int);
class TrackBase { public: void Init(); };
class TrackTail { public: void Init(); };
class Factory { public: void* vf; char pad[0x28]; void* vfunc_5(); };
void* Factory::vfunc_5() {
    char* p = (char*)FUN_0008d690(0x28);
    if (p) {
        ((TrackBase*)p)->Init();
        *(unsigned int*)p = 0x40db84;
        *(unsigned int*)(p + 0xc) = 0;
        *(unsigned int*)(p + 0x10) = 0xbf800000;
        ((TrackTail*)(p + 0x18))->Init();
        p[0x20] = 0;
        p[0x21] = 0;
        *(unsigned int*)(p + 8) = 1;
        return p;
    }
    return (void*)0;
}