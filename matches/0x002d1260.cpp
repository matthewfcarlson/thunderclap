class Target {
    char pad0[8];
    unsigned a;
    char pad1[12];
    unsigned b;

  public:
    void Set(unsigned x, unsigned y);
};
void Target::Set(unsigned x, unsigned y) {
    a = x;
    b = y;
}