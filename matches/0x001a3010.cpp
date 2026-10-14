extern void* g_vftable_1a3010[];
class Str_1a3010 {
  public:
    void Init();
};
class Base_1a3010 {
  public:
    void* vptr;
    char pad[12];
    Str_1a3010 s;
    void Fin();
};
class Cond_1a3010 : public Base_1a3010 {
  public:
    ~Cond_1a3010();
};
Cond_1a3010::~Cond_1a3010() {
    vptr = g_vftable_1a3010;
    s.Init();
    Fin();
}
