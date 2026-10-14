// Same code shape as 0x00085d70 (propagated; names are from that function)
class Obj_2a3460 {
  public:
    virtual void f();
    virtual void g();
};
extern Obj_2a3460* globalObj_2a3460;
void target() {
    if (globalObj_2a3460) {
        globalObj_2a3460->g();
        globalObj_2a3460 = 0;
    }
}