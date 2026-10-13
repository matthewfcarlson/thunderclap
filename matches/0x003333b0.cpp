class X {
  public:
    char pad[0x2c];
    void Set(int v);
};

void X::Set(int v) {
    *(int*)((char*)this + 0x2c) = v;
}