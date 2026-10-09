struct Data {
    unsigned int a, b, c;
};
struct Buffer {
    char data[48];
    unsigned int a, b, c;
    char extra[4];
    void Init();
};
class Child {
  public:
    void Run(Buffer*);
};
class Obj {
  public:
    char pad[0x10];
    Child* m;
    void f(Data* p);
};
void Obj::f(Data* p) {
    if (m) {
        Buffer b;
        b.Init();
        b.a = p->a;
        b.b = p->b;
        b.c = p->c;
        m->Run(&b);
    }
}
