class Obj {
  public:
    char pad[0x0c];
    bool Set(unsigned int v);
};

bool Obj::Set(unsigned int v) {
    *(unsigned int*)((char*)this + 0x0c) = v;
    return true;
}
