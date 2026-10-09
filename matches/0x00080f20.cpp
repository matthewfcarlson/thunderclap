class C {
    char pad[0xc8];

  public:
    int m;
    void Set(int);
};
void C::Set(int x) {
    m = x;
}