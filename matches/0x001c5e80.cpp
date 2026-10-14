struct Data_1c5e80 {
    unsigned int a, b, c;
};
struct Buffer_1c5e80 {
    char data[48];
    unsigned int a, b, c;
    char extra[4];
    void Init();
};
class Child_1c5e80 {
  public:
    void Run(Buffer_1c5e80*);
};
class Obj_1c5e80 {
  public:
    char pad[0x10];
    Child_1c5e80* m;
    void f(Data_1c5e80* p);
};
void Obj_1c5e80::f(Data_1c5e80* p) {
    if (m) {
        Buffer_1c5e80 b;
        b.Init();
        b.a = p->a;
        b.b = p->b;
        b.c = p->c;
        m->Run(&b);
    }
}
