typedef unsigned int U;
extern int g_count;
extern char g_registry;
extern void* __cdecl Alloc(unsigned);
extern void __cdecl Register(void*,void*,int);
extern const char t[],p[],d[],u[],mna[],mxa[],sd[],len[],mind[],maxd[],mins[],maxs[],dt[];
extern int F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,F11,F12,F13;
struct Flt{void Init(const char*);};
struct Vec{void Init(const char*);};
struct Int{void Init(const char*);};
struct Enum{void Init(const char*);};

#define ELEM(n,V,T,sz,str,vt,f) V=(T*)Alloc(sz); if(V){V->Init(str); *(U*)V=vt; ((U*)V)[4]=(U)&f; a[n]=(U)V;} else a[n]=0;

void FUN_001456b0(){
  if(!g_count){
    U a[13];
    Flt* pf; Vec* pv; Int* pi; Enum* pe;
    ELEM(0,pf,Flt,24,t,0x4131c4,F1)
    ELEM(1,pv,Vec,24,p,0x4131e4,F2)
    ELEM(2,pv,Vec,24,d,0x4131e4,F3)
    ELEM(3,pv,Vec,24,u,0x4131e4,F4)
    ELEM(4,pf,Flt,24,mna,0x4131c4,F5)
    ELEM(5,pf,Flt,24,mxa,0x4131c4,F6)
    ELEM(6,pf,Flt,24,sd,0x4131c4,F7)
    ELEM(7,pf,Flt,24,len,0x4131c4,F8)
    ELEM(8,pi,Int,24,mind,0x413204,F9)
    ELEM(9,pi,Int,24,maxd,0x413204,F10)
    ELEM(10,pf,Flt,24,mins,0x4131c4,F11)
    ELEM(11,pf,Flt,24,maxs,0x4131c4,F12)
    pe=(Enum*)Alloc(32);
    if(pe){pe->Init(dt); *(U*)pe=0x413224; ((U*)pe)[4]=0x4ad788; ((U*)pe)[5]=7; ((U*)pe)[6]=(U)&F13; a[12]=(U)pe;}
    else a[12]=0;
    Register(&g_registry,a,13);
  }
  ++g_count;
}
