class A_6b3f0 {
    char pad[0x34];

  public:
    bool Set(int x);
};

bool A_6b3f0::Set(int x) {
    *(int*)((char*)this + 0x34) = x;
    return true;
}
