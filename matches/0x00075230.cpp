extern "C" void* __cdecl alloc(unsigned int);
extern "C" void __cdecl finish(void* g, void** arr, int n);
struct Obj { unsigned vt; unsigned pad[3]; unsigned f10; unsigned f14; unsigned f18; void A(const char*); void B(const char*); void C(const char*); void D(const char*); };
extern unsigned counter;
extern char registry[];

#define E(i,sz,fn,name,V,F) p=(Obj*)alloc(sz); if(p){p->fn(name); p->vt=V; p->f10=F; a[i]=p;} else a[i]=0;
#define EE(i,fn,name,V,F,G,H) p=(Obj*)alloc(32); if(p){p->fn(name); p->vt=V; p->f10=F; p->f14=G; p->f18=H; a[i]=p;} else a[i]=0;

void target() {
    if (counter == 0) {
        Obj* p;
        Obj* a[27];
        E(0,24,A,"timeBegin",0x3fc764,0x68630)
        E(1,24,A,"timeEnd",0x3fc764,0x68640)
        E(2,24,B,"targetOffset",0x3fc784,0x68650)
        E(3,24,A,"noCamWeight",0x3fc764,0x686f0)
        E(4,24,C,"animation0",0x3fd73c,0x12080)
        E(5,24,A,"weight0",0x3fc764,0x68670)
        E(6,24,C,"animation1",0x3fd73c,0x120a0)
        E(7,24,A,"weight1",0x3fc764,0x68680)
        E(8,24,C,"animation2",0x3fd73c,0x120c0)
        E(9,24,A,"weight2",0x3fc764,0x68690)
        E(10,24,C,"animation3",0x3fd73c,0x120e0)
        E(11,24,A,"weight3",0x3fc764,0x686a0)
        E(12,24,C,"animation4",0x3fd73c,0x12100)
        E(13,24,A,"weight4",0x3fc764,0x686b0)
        E(14,24,C,"animation5",0x3fd73c,0x12120)
        E(15,24,A,"weight5",0x3fc764,0x686c0)
        E(16,24,C,"animation6",0x3fd73c,0x12140)
        E(17,24,A,"weight6",0x3fc764,0x686d0)
        E(18,24,C,"animation7",0x3fd73c,0x12160)
        E(19,24,A,"weight7",0x3fc764,0x686e0)
        E(20,24,D,"abortWhenInterrupted",0x3fc7a4,0x68700)
        EE(21,A,"blendInTransition",0x3fc7c4,0x496f9c,2,0x68710)
        EE(22,A,"blendInBlend",0x3fc7c4,0x496fa4,4,0x68720)
        E(23,24,A,"blendInDuration",0x3fc764,0x68730)
        EE(24,A,"blendOutTransition",0x3fc7c4,0x496f9c,2,0x68740)
        EE(25,A,"blendOutBlend",0x3fc7c4,0x496fa4,4,0x68750)
        E(26,24,A,"blendOutDuration",0x3fc764,0x68760)
        finish((void*)registry, (void**)a, 27);
    }
    ++counter;
}
