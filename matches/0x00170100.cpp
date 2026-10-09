typedef unsigned int u32;
extern void __cdecl thunk_FUN_00267090(u32);
extern int SyncVftable;
struct Helper { void call(); };
class SyncToLocatorTrack {
public:
    int *vftable;
    char pad[0x28-4];
    u32 field;
    void f();
    void finish();
};
void SyncToLocatorTrack::f() {
    u32 x = field;
    vftable = &SyncVftable;
    thunk_FUN_00267090(x);
    ((Helper*)((char*)this + 0x20))->call();
    finish();
}