class X_14c950 {
  public:
    bool Set(int a);
    char pad[0x28];
};

bool X_14c950::Set(int a) {
    *(int*)((char*)this + 0x28) = a;
    return true;
}
