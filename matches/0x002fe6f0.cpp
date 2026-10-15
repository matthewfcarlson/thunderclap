class Ref {
  public:
    virtual void add();
};
class Part {
  public:
    char pad[16];
    void copy(Part* src);
};
class Obj {
  public:
    char pad0[8];
    Part part;
    int value;
    Ref* ptr;
    void fn(Obj* dst, int x);
};
void Obj::fn(Obj* dst, int x) {
    *(int*)((char*)dst + 0x10) = x;
    dst->value = value;
    dst->ptr = ptr;
    *(int*)((char*)dst + 0x14) = 0;
    if (ptr)
        dst->ptr->add();
    dst->part.copy(&part);
}