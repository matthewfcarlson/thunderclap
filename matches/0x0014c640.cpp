class Obj_14c640 {
  public:
    char pad[0x0c];
    bool Set(unsigned int v);
};

bool Obj_14c640::Set(unsigned int v) {
    *(unsigned int*)((char*)this + 0x0c) = v;
    return true;
}
