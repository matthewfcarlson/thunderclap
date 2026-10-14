class C_1c3b80;
class D {
  public:
    void Use(int);
};
class C_1c3b80 {
  public:
    void* pad[3];
    int Get(int);
    void Finish(int);
};
class Obj_1c3b80 {
  public:
    char pad0[4];
    D* m4;
    char pad8[4];
    C_1c3b80* mC;
    void Target(int);
};
void Obj_1c3b80::Target(int arg) {
    int x = mC->Get(arg);
    if (x) {
        m4->Use(x);
        mC->Finish(arg);
    }
}