// rev5: a real straddle: the view's name is past Decl on 32-bit (+8 >= 8) and inside it on 64-bit (+0xc < 0x10, the
// padding after `a`). The view is not taken; the read must not pass silently.
struct Decl_ac780 {
    void* vt;
    int a;
};
struct View_ac780 {
    void* vt;
    int a;
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
