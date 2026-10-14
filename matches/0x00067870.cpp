class Base_67870 {
  public:
    float Compute();
};
class Obj_67870 {
  public:
    char p[4];
    Base_67870* base;
    char q[0x34c];
    float value;
    void Tick(int);
    void Do(float*, int);
};
class B_67870 {
  public:
    char p[0x10];
    void Run(float*);
};
class A_67870 {
  public:
    char p[0x10];
    B_67870* y;
};
class Manager_67870 {
  public:
    char p[0x124];
    A_67870* a;
};
class Root_67870 {
  public:
    char p[0x20];
    Manager_67870* m;
};
extern Root_67870* gRoot_67870;
void Obj_67870::Tick(int arg) {
    value = base->Compute();
    float v[3] = {0, 0, 0};
    B_67870* b = gRoot_67870->m->a->y;
    b->Run(v);
    Do(v, arg);
}
