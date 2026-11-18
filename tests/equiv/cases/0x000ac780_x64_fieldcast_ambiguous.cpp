// eq64 must not be credited (integ2, D93 F5; 0x0019e910's shape): one void* field the body casts to two records by a
// type tag (a Node or an Actor). No one view says what is there: the object keeps its declared type and the run is
// unsupported, class view_ambiguous (it was built as the first cast's record, and the other branch read through it).
struct Node_ac780 {
    int a;
    int f4;
};
struct Actor_ac780 {
    void* vt;
    void* f4;
};
struct Holder_ac780 {
    int type;
    void* obj;
};
class Target_ac780 {
    char pad[0x14];

  public:
    int value;
    Holder_ac780* in;
    void Set(int x);
};
void Target_ac780::Set(int x) {
    if (in->type == 1)
        value = (((Actor_ac780*)in->obj)->f4 != 0) + x;
    else
        value = ((Node_ac780*)in->obj)->f4 + x;
}
