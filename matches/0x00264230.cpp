class Sink {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f(int);
};
class Obj {
  public:
    char pad0[8];
    Sink* sink;
    char padc[1];
    char flag;
    char padE[6];
    int pos;
    void target(int);
    void refresh();
};
void Obj::target(int amount) {
    sink->f(pos + amount);
    pos += amount;
    if (flag)
        refresh();
}