// eq64 must fail (integ2, D93; was _straddle): the declared pointee is complete and lays out the words the view reads, so
// the declared type wins over the view. The view is the 32-bit-sized one (`char pad[8]` before the name, wrong natively:
// the 8-byte vftable pointer and the count put the name at +0xc), so the 64-bit read lands on Decl's count, not its
// name: a difference (the object is never retyped by a view where its own type says what is there).
struct Decl_ac780 {
    void* vt;
    int refs;
    int name;
};
struct View_ac780 {
    char pad[8];
    int name;
};
struct Holder_ac780 {
    Decl_ac780* obj;
};
class Target_ac780 {
    char pad[0x14];

  public:
    int value;
    Holder_ac780* in;
    void Set(int x);
};
void Target_ac780::Set(int x) {
    value = ((View_ac780*)in->obj)->name + x;
}
