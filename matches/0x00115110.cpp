class Body {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int x);
};

bool Body::Set(int x) {
    mValue = x;
    return true;
}
