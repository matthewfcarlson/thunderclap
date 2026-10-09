class C {
    char pad[0x40];

  public:
    int value;
    void Update();
    void Set(int);
};
void C::Set(int x) {
    value = x;
    Update();
}