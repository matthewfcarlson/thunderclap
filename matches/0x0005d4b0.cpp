class T {
  public:
    char pad[12];
    int m;
    bool Fn(int a);
};
bool T::Fn(int a) {
    m = a;
    return true;
}
