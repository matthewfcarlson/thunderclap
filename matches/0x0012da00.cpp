extern void* g_vftable_12da00[];
class Str_12da00 {
  public:
    void Init();
};
class Base_12da00 {
  public:
    void* vptr;
    char pad[12];
    Str_12da00 s;
    void Fin();
};
class Cond_12da00 : public Base_12da00 {
  public:
    ~Cond_12da00();
};
Cond_12da00::~Cond_12da00() {
    vptr = g_vftable_12da00;
    s.Init();
    Fin();
}
