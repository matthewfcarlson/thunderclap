class Obj_67f30 {
    char pad[12];

  public:
    bool Set(void* p);
};
bool Obj_67f30::Set(void* p) {
    *(void**)((char*)this + 12) = p;
    return true;
}
