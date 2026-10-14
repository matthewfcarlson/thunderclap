class O {
  public:
    char pad[0x22c8];
    int m1;
    int m2;
    int m3;
    void Set(int a, int b, int c);
};
void O::Set(int a, int b, int c) {
    m1 = a;
    m2 = b;
    m3 = c;
}
