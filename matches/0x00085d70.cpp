class Obj {
  public:
    virtual void f();
    virtual void g();
};
extern Obj* globalObj;
void target() {
    if (globalObj) {
        globalObj->g();
        globalObj = 0;
    }
}