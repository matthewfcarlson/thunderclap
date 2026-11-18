// rev5 wrongview: the view has an extra pointer before name (+0x10 natively where the real object, whatever it is, is unknown)
// eq64 (integ2, D93, fieldcasts): a pointer field whose declared pointee is incomplete, read through the record the code
// casts it to. The object is generated as that view (past the declared type's end: here all of it), so the view's
// 64-bit offsets (name at +0xc after the 8-byte vftable pointer and the count) map to its 32-bit ones (+8).
// Equivalent; with EQ64_OFF=fieldcasts it reads untyped bytes at +8 / +0xc: a (false) difference.
struct Opaque_ac780;
struct View_ac780 {
    void* vt;
    int refs;
    void* bogus;
    int name;
};
struct Holder_ac780 {
    Opaque_ac780* obj;
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
