extern void* g_vftable_165d30[];
class Str_165d30 {
  public:
    void Init();
};
class Base_165d30 {
  public:
    void* vptr;
    char pad[12];
    Str_165d30 s;
    void Fin();
};
class Cond_165d30 : public Base_165d30 {
  public:
    ~Cond_165d30();
};
Cond_165d30::~Cond_165d30() {
    vptr = g_vftable_165d30;
    s.Init();
    Fin();
}
