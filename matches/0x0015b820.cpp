extern void* g_vftable_15b820[];
class Str_15b820 {
  public:
    void Init();
};
class Base_15b820 {
  public:
    void* vptr;
    char pad[12];
    Str_15b820 s;
    void Fin();
};
class Cond_15b820 : public Base_15b820 {
  public:
    ~Cond_15b820();
};
Cond_15b820::~Cond_15b820() {
    vptr = g_vftable_15b820;
    s.Init();
    Fin();
}
