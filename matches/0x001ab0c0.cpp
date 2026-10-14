extern void* g_vftable_1ab0c0[];
class Str_1ab0c0 {
  public:
    void Init();
};
class Base_1ab0c0 {
  public:
    void* vptr;
    char pad[12];
    Str_1ab0c0 s;
    void Fin();
};
class Cond_1ab0c0 : public Base_1ab0c0 {
  public:
    ~Cond_1ab0c0();
};
Cond_1ab0c0::~Cond_1ab0c0() {
    vptr = g_vftable_1ab0c0;
    s.Init();
    Fin();
}
