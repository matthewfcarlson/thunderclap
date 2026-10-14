class Obj_268490 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
};
extern Obj_268490* g_obj_268490;
void target() {
    if (g_obj_268490)
        g_obj_268490->f2(1);
    g_obj_268490 = 0;
}