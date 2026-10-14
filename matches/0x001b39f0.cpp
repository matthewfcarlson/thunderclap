// Same code shape as 0x001b3420 (propagated; names are from that function)
class Obj_1b39f0 {
  public:
    virtual void f0();
    virtual void f1();
};
class Target_1b39f0 {
  public:
    char pad[0x0c];
    volatile int state;
    char pad2[0x20];
    Obj_1b39f0* volatile ptr;
    void Run();
};
void Target_1b39f0::Run() {
    state = -1;
    Obj_1b39f0* p = ptr;
    if (p) {
        p->f1();
        ptr = 0;
    }
}