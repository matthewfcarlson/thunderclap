class Obj_85d70 {
  public:
    virtual void f();
    virtual void g();
};
extern Obj_85d70* globalObj_85d70;
void target() {
    if (globalObj_85d70) {
        globalObj_85d70->g();
        globalObj_85d70 = 0;
    }
}