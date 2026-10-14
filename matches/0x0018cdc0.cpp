extern void* g_vftable_18cdc0[];
class Str_18cdc0 {
  public:
    void Init();
};
class Base_18cdc0 {
  public:
    void* vptr;
    char pad[12];
    Str_18cdc0 s;
    void Fin();
};
class Cond_18cdc0 : public Base_18cdc0 {
  public:
    ~Cond_18cdc0();
};
Cond_18cdc0::~Cond_18cdc0() {
    vptr = g_vftable_18cdc0;
    s.Init();
    Fin();
}
