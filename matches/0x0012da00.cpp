extern void* g_vftable[];
class Str {
  public:
    void Init();
};
class Base {
  public:
    void* vptr;
    char pad[12];
    Str s;
    void Fin();
};
class Cond : public Base {
  public:
    ~Cond();
};
Cond::~Cond() {
    vptr = g_vftable;
    s.Init();
    Fin();
}
