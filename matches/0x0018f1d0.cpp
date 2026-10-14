extern void* g_vftable_18f1d0[];
class Str_18f1d0 {
  public:
    void Init();
};
class Base_18f1d0 {
  public:
    void* vptr;
    char pad[12];
    Str_18f1d0 s;
    void Fin();
};
class Cond_18f1d0 : public Base_18f1d0 {
  public:
    ~Cond_18f1d0();
};
Cond_18f1d0::~Cond_18f1d0() {
    vptr = g_vftable_18f1d0;
    s.Init();
    Fin();
}
