class X {
  public:
    char pad[0x20];
    unsigned int flags;
    bool Fn(bool b);
};

bool X::Fn(bool b) {
    if (b)
        flags |= 2;
    else
        flags &= ~2;
    return true;
}
