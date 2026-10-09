class Part {
  public:
    char x[8];
    void Clear();
};
class Obj {
  public:
    char pad[0x28];
    Part a, b, c, d;
    Obj* Run(unsigned char flag);
};
void Free(Obj*);
Obj* Obj::Run(unsigned char flag) {
    d.Clear();
    c.Clear();
    b.Clear();
    a.Clear();
    if (flag & 1)
        Free(this);
    return this;
}
