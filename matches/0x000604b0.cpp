class T_604b0 {
  public:
    char pad[0x54];
    int m54;
    bool Set(int v);
};

bool T_604b0::Set(int v) {
    m54 = v;
    return true;
}
