// rev5 placeholderderived: an empty placeholder base and a made-up derived view: trusted outright?
// Must not be credited (integ2, F4): a locally declared derived view has no evidence of its own, so the run is
// unsupported, class view_trusted.
struct Base_ac780 {
};
struct Derived_ac780 : Base_ac780 {
    void* vt;
    void* bogus;
    int name;
};
struct Holder_ac780 {
    Base_ac780* obj;
};
class Target_ac780 {
    char pad[0x14];

  public:
    int value;
    Holder_ac780* in;
    void Set(int x);
};
void Target_ac780::Set(int x) {
    value = ((Derived_ac780*)in->obj)->name + x;
}
