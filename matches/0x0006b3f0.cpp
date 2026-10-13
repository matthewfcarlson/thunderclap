class A {
    char pad[0x34];

  public:
    bool Set(int x);
};

bool A::Set(int x) {
    *(int*)((char*)this + 0x34) = x;
    return true;
}
