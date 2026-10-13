class X {
  public:
    bool Set(int a);
    char pad[0x28];
};

bool X::Set(int a) {
    *(int*)((char*)this + 0x28) = a;
    return true;
}
