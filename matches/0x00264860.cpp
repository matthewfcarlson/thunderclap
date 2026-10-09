class C {
  public:
    int pad;
    int value;
    void Set(int);
};
void C::Set(int x) {
    value = x;
}