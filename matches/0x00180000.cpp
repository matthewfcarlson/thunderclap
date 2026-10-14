class T {
  public:
    char pad[0x48];
    int m48;
    bool Fn(int a);
};

bool T::Fn(int a) {
    m48 = a;
    return true;
}
