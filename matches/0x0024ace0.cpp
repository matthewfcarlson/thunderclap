struct Obj { int Do(int,int,int,int,int,int); };
extern "C" int __cdecl GetThing(void*);
extern "C" int __cdecl FUN_0024ace0(int a,int b,int c,int d,int e,int f) {
    Obj* p=(Obj*)GetThing((void*)0x4e5fa8);
    if (p) return p->Do(a,b,c,d,e,f);
    return 0;
}