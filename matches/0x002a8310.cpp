class C_2a8310 {
    char pad[0x40];

  public:
    int value;
    void Update();
    void Set(int);
};
void C_2a8310::Set(int x) {
    value = x;
    Update();
}