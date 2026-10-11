extern "C" unsigned char GetValue(const char*);
extern char g_a[], g_b[], g_c[];
extern void* g_vftable;
class Base {
  public:
    void Init(void*, int);
};
class SoundObj {
  public:
    SoundObj(void* p, int x);
    void* vptr;
    char pad4[12];
    unsigned char m10, m11, m12, m13, m14, m15;
    char pad16[2];
    unsigned char m18;
    char pad19[3];
    int m1c;
};
SoundObj::SoundObj(void* p, int x) {
    ((Base*)this)->Init(p, 6);
    vptr = &g_vftable;
    m1c = x;
    m18 = GetValue(g_a);
    m10 = GetValue(g_b);
    m11 = GetValue(g_b);
    m12 = GetValue(g_b);
    m13 = GetValue(g_c);
    m14 = GetValue(g_c);
    m15 = GetValue(g_c);
}
