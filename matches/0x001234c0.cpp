class PathFormationTrack { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual int vfunc_10(int,int,int); int build(PathFormationTrack*, int); };
extern int check(void*, int, const void*, const void*, int);
extern void* alloc(int);
extern int RTTI_A;
extern int RTTI_B;
int PathFormationTrack::vfunc_10(int a, int b, int c) {
    if (check((void*)c, 0, &RTTI_A, &RTTI_B, 0)) {
        PathFormationTrack* p = (PathFormationTrack*)alloc(0xd0);
        if (p) return p->build(this, c);
    }
    return 0;
}