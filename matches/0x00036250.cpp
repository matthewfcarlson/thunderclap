class C_36250 {
    char pad[0x1b28];
    int a;
    int b;

  public:
    void Set(int x);
};
void C_36250::Set(int x) {
    a = x;
    if (!x)
        b = x;
}