class A_61f60 {
  public:
    char pad[0x10];
    int m;
    bool Set(int v);
};
bool A_61f60::Set(int v) {
    m = v;
    return true;
}