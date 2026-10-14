extern void* g_vftable_14d960[];
class Str_14d960 {
  public:
    void Init();
};
class Base_14d960 {
  public:
    void* vptr;
    char pad[12];
    Str_14d960 s;
    void Fin();
};
class Cond_14d960 : public Base_14d960 {
  public:
    ~Cond_14d960();
};
Cond_14d960::~Cond_14d960() {
    vptr = g_vftable_14d960;
    s.Init();
    Fin();
}
