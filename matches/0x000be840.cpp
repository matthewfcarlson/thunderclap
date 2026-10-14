class Base_be840 {
  public:
    Base_be840(void* a, int n);
    virtual void Call();
    char pad[0x0c];
};

class Method7 : public Base_be840 {
  public:
    Method7(void* a, int b);
    virtual void Call();
    char m10, m11, m12, m13, m14, m15, m16, m17;
    char m18;
    char pad2[3];
    int m1c;
};

extern "C" char __cdecl FUN_001d04d0(const char*);
extern const char s0_be840[];
extern const char s1_be840[];

Method7::Method7(void* a, int b) : Base_be840(a, 7) {
    m1c = b;
    m18 = FUN_001d04d0(s1_be840);
    m10 = FUN_001d04d0(s0_be840);
    m11 = FUN_001d04d0(s0_be840);
    m12 = FUN_001d04d0(s0_be840);
    m13 = FUN_001d04d0(s0_be840);
    m14 = FUN_001d04d0(s0_be840);
    m15 = FUN_001d04d0(s0_be840);
    m16 = FUN_001d04d0(s0_be840);
}
