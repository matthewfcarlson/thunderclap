extern "C" char DAT_0040449c[];
// Same code shape as 0x00091be0 (propagated; names are from that function)
class CUnlockable {
  public:
    int pad[6];
    void* m18;
    void Destroy();
};
extern void __cdecl thunk_FUN_00267090(void*);
struct Tail {
    void f();
};
void CUnlockable::Destroy() {
    *(void**)this = (void*)((int)DAT_0040449c);
    if (m18) {
        thunk_FUN_00267090(m18);
        m18 = 0;
    }
    ((Tail*)((char*)this + 0x10))->f();
}
