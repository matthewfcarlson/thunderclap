extern void* g_vftable_18cd40[];
class Str_18cd40 {
  public:
    void Init();
};
class Base_18cd40 {
  public:
    void* vptr;
    char pad[12];
    Str_18cd40 s;
    void Fin();
};
class Cond_18cd40 : public Base_18cd40 {
  public:
    ~Cond_18cd40();
};
Cond_18cd40::~Cond_18cd40() {
    vptr = g_vftable_18cd40;
    s.Init();
    Fin();
}
