class T_143200 {
  public:
    char pad[0x30];
    int m;
    bool Set(int x);
};
bool T_143200::Set(int x) {
    m = x;
    return true;
}
