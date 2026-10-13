class Obj {
    char pad[12];

  public:
    bool Set(void* p);
};
bool Obj::Set(void* p) {
    *(void**)((char*)this + 12) = p;
    return true;
}
