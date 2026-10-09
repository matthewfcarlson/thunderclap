class Ret {
  public:
    void Last(bool);
};
class Sub {
  public:
    void First(int);
    int a;
    int b;
};
class Mid {
  public:
    char pad[0x54];
    Ret* Get();
};
class Root {
  public:
    char pad[0x54];
    Mid* m;
};
class Manager {
  public:
    char pad[0xd0];
    Sub sub;
    void Target(int p);
};
extern Root* g;
void Manager::Target(int p) {
    Sub* s = &sub;
    s->First(p);
    Ret* r = g->m->Get();
    bool f = s->a != -1 && s->b != -1;
    r->Last(f);
}
