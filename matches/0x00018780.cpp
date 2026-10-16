class Obj {
  public:
    virtual void a();
    virtual void b();
};
void FUN_00018780(Obj** p) {
    Obj* q = *p;
    if (q) {
        q->b();
        *p = 0;
    }
}