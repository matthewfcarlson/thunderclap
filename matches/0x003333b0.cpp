class X_3333b0 {
  public:
    char pad[0x2c];
    void Set(int v);
};

void X_3333b0::Set(int v) {
    *(int*)((char*)this + 0x2c) = v;
}