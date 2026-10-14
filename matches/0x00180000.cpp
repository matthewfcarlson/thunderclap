class T_180000 {
  public:
    char pad[0x48];
    int m48;
    bool Fn(int a);
};

bool T_180000::Fn(int a) {
    m48 = a;
    return true;
}
