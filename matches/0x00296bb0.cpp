extern "C" void _ReadWriteBarrier();
extern void* g_vftable_0042d2dc[];
class Ref_296bb0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_296bb0 {
  public:
    void* vptr;
    void Fin_002a35f0();
};
class Obj_296bb0 : public Base_296bb0 {
  public:
    char pad[60];
    Ref_296bb0* m;
    ~Obj_296bb0();
};
Obj_296bb0::~Obj_296bb0() {
    vptr = g_vftable_0042d2dc;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_002a35f0();
}
