class O_2393e0 {
  public:
    char pad[0x20];
    bool Set(int v);
};

bool O_2393e0::Set(int v) {
    *(int*)((char*)this + 0x20) = v;
    return true;
}