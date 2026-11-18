// eq64 (integ2, D93, fieldcasts; rev5's review): a pointer field whose declared pointee is incomplete, read through the
// record the code casts it to. The object is generated as that view, but the view is taken on trust (any view passes:
// _wrongview), so the run is reported unsupported, class view_trusted: no clean --x64 equivalent.
// (With EQ64_OFF=fieldcasts it reads untyped bytes at +8 / +0xc: a false difference.)
struct Opaque_ac780;
struct View_ac780 {
    void* vt;
    int refs;
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
