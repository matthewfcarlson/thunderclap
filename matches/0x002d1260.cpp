class Target_2d1260 {
    char pad0[8];
    unsigned a;
    char pad1[12];
    unsigned b;

  public:
    void Set(unsigned x, unsigned y);
};
void Target_2d1260::Set(unsigned x, unsigned y) {
    a = x;
    b = y;
}