extern void* g_vftable[];
class Str {
  public:
    void Init();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Track : public Base {
  public:
    char pad[0x14];
    Str s18;
    char pad2[0x1f];
    Str s38;
    ~Track();
};
Track::~Track() {
    vptr = g_vftable;
    s38.Init();
    s18.Init();
    Fin();
}
