class Thing {
    char pad[0x1e50];
    int a;
    int b;

  public:
    void Set(int x);
};
void Thing::Set(int x) {
    a = x;
    b = 0x3e800000;
}