class C;
class D {
  public:
    void Use(int);
};
class C {
  public:
    void* pad[3];
    int Get(int);
    void Finish(int);
};
class Obj {
  public:
    char pad0[4];
    D* m4;
    char pad8[4];
    C* mC;
    void Target(int);
};
void Obj::Target(int arg) {
    int x = mC->Get(arg);
    if (x) {
        m4->Use(x);
        mC->Finish(arg);
    }
}