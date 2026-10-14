extern void* g_vftable_165f80[];
class Str_165f80 {
  public:
    void Init();
};
class Base_165f80 {
  public:
    void* vptr;
    char pad[12];
    Str_165f80 s;
    void Fin();
};
class Cond_165f80 : public Base_165f80 {
  public:
    ~Cond_165f80();
};
Cond_165f80::~Cond_165f80() {
    vptr = g_vftable_165f80;
    s.Init();
    Fin();
}
