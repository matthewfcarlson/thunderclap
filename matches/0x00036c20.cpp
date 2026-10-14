class Thing_36c20 {
    char pad[0x1e50];
    int a;
    int b;

  public:
    void Set(int x);
};
void Thing_36c20::Set(int x) {
    a = x;
    b = 0x3e800000;
}