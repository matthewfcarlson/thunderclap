class Sink_264230 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f(int);
};
class Obj_264230 {
  public:
    char pad0[8];
    Sink_264230* sink;
    char padc[1];
    char flag;
    char padE[6];
    int pos;
    void target(int);
    void refresh();
};
void Obj_264230::target(int amount) {
    sink->f(pos + amount);
    pos += amount;
    if (flag)
        refresh();
}