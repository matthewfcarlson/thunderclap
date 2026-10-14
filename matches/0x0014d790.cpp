extern void* g_vftable_14d790[];
class Str_14d790 {
  public:
    void Init();
};
class Base_14d790 {
  public:
    void* vptr;
    char pad[12];
    Str_14d790 s;
    void Fin();
};
class Cond_14d790 : public Base_14d790 {
  public:
    ~Cond_14d790();
};
Cond_14d790::~Cond_14d790() {
    vptr = g_vftable_14d790;
    s.Init();
    Fin();
}
