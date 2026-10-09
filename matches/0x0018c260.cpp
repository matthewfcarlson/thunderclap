struct PropTrack { void Init(); unsigned char pad[0x18]; };
void* __cdecl Alloc(unsigned int);
class Factory { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual PropTrack* vfunc_5(); };
PropTrack* Factory::vfunc_5() {
    PropTrack* p = (PropTrack*)Alloc(0x18);
    if (p) {
        p->Init();
        p->pad[0x14] = 1;
        *(int*)(p->pad + 8) = 1;
        *(int*)p->pad = 0x41950c;
        *(int*)(p->pad + 0xc) = 0;
        *(int*)(p->pad + 0x10) = 0;
    }
    if (!p) return 0;
    return p;
}