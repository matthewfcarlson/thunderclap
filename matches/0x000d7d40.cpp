class Thing {
    char pad[0x30];

  public:
    char a;
    char pad2[7];
    char b;
    void Base();
    Thing* Init();
};
Thing* Thing::Init() {
    Base();
    a = 0;
    b = 0;
    return this;
}