class Base {
  public:
    char pad[0x3c];
    int m3c;
    bool Init(int x);
};

bool Base::Init(int x) {
    m3c = x;
    return true;
}
