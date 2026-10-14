extern void* g_vftable_1663f0[];
class Str_1663f0 {
  public:
    void Init();
};
class Base_1663f0 {
  public:
    void* vptr;
    char pad[12];
    Str_1663f0 s;
    void Fin();
};
class Cond_1663f0 : public Base_1663f0 {
  public:
    ~Cond_1663f0();
};
Cond_1663f0::~Cond_1663f0() {
    vptr = g_vftable_1663f0;
    s.Init();
    Fin();
}
