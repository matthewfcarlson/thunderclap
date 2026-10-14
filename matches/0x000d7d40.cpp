class Thing_d7d40 {
    char pad[0x30];

  public:
    char a;
    char pad2[7];
    char b;
    void Base();
    Thing_d7d40* Init();
};
Thing_d7d40* Thing_d7d40::Init() {
    Base();
    a = 0;
    b = 0;
    return this;
}