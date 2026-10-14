class X_1653f0 {
  public:
    char F(int);
};

char X_1653f0::F(int a) {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) = a;
    return 1;
}
