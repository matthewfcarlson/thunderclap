// Same code shape as 0x00085d70 (propagated; names are from that function)
class Obj_2b53f0 {
  public:
    virtual void f();
    virtual void g();
};
extern Obj_2b53f0* globalObj_2b53f0;
void target() {
    if (globalObj_2b53f0) {
        globalObj_2b53f0->g();
        globalObj_2b53f0 = 0;
    }
}