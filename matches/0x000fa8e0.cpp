typedef unsigned char u8;
struct CRawScript { void **vptr; char pad[0x0c]; void *member10; void *vfunc_2(u8); void Cleanup(); };
extern void __cdecl Release(void *);
void *CRawScript::vfunc_2(u8 param) {
    vptr = (void**)0x40ce8c;
    Release(member10);
    Cleanup();
    if (param & 1) Release(this);
    return this;
}