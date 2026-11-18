// eq64 must not be credited (integ2, D93 F4): a downcast to a locally declared derived record: "derived from the
// declared pointee" is no evidence of the object's layout (rev5's _wrongderived passed the same way), so the run is
// unsupported, class view_trusted. A gen record with RTTI evidence is taken outright (_gendowncast).
struct Base_ac780 {
    void* vt;
    int refs;
};
struct Derived_ac780 : Base_ac780 {
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
