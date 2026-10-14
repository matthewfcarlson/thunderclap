class O {
  public:
    char pad[0x20];
    bool Set(int v);
};

bool O::Set(int v) {
    *(int*)((char*)this + 0x20) = v;
    return true;
}