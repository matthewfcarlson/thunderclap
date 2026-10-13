class C {
  public:
    char pad[12];
    int m;
    bool Init(int x);
};
bool C::Init(int x) {
    m = x;
    return true;
}
