class X {
  public:
    char pad[12];
    int m;
    bool Init(int arg);
};
bool X::Init(int arg) {
    m = arg;
    return true;
}
