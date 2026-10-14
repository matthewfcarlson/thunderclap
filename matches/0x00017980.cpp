class A_17980 {
  public:
    void* f();
};
class B_17980 {
  public:
    void* f(int);
};
class C_17980 {
  public:
    void f();
};
extern A_17980* gGlobal_17980;
class CHapticEventAction {
  public:
    char pad[0x20];
    void* mEvent;
    void vfunc_4();
};
void CHapticEventAction::vfunc_4() {
    if (*((char*)mEvent + 0x1c)) {
        void* p = gGlobal_17980->f();
        B_17980* b = (B_17980*)p;
        C_17980* c = (C_17980*)b->f(0);
        c->f();
    }
}