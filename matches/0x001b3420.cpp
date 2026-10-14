class Obj_1b3420 {
  public:
    virtual void f0();
    virtual void f1();
};
class Target_1b3420 {
  public:
    char pad[0x0c];
    volatile int state;
    char pad2[0x20];
    Obj_1b3420* volatile ptr;
    void Run();
};
void Target_1b3420::Run() {
    state = -1;
    Obj_1b3420* p = ptr;
    if (p) {
        p->f1();
        ptr = 0;
    }
}