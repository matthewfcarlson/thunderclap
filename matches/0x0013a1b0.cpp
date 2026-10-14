extern void* g_vftable_13a1b0[];
class Str_13a1b0 {
  public:
    void Init();
};
class Base_13a1b0 {
  public:
    void* vptr;
    void Fin();
};
class Track : public Base_13a1b0 {
  public:
    char pad[0x14];
    Str_13a1b0 s18;
    char pad2[0x1f];
    Str_13a1b0 s38;
    ~Track();
};
Track::~Track() {
    vptr = g_vftable_13a1b0;
    s38.Init();
    s18.Init();
    Fin();
}
