typedef unsigned int u32;
extern void* LocationVtable;
extern void __cdecl ReleaseThing(u32);
class Obj {
public:
    u32 x[7];
    void Finish();
};
void __fastcall FUN_0012e6e0(Obj* p) {
    p->x[0] = (u32)&LocationVtable;
    ReleaseThing(p->x[4]);
    ReleaseThing(p->x[6]);
    p->Finish();
}
