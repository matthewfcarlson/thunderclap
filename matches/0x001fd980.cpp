class O {
  public:
    char pad[0x238];
    int m;
    void Helper(int a, int b);
    int Fn(int a);
};
int O::Fn(int a) {
    Helper(a, 1);
    return m;
}
