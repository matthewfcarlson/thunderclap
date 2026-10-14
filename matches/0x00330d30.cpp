class T {
  public:
    char pad[0xe8];
    int m;
    void Set(int x);
};

void T::Set(int x) {
    m = x;
}
