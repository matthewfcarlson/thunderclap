class Part_290470 {
  public:
    char x[8];
    void Clear();
};
class Obj_290470 {
  public:
    char pad[0x28];
    Part_290470 a, b, c, d;
    Obj_290470* Run(unsigned char flag);
};
void Free(Obj_290470*);
Obj_290470* Obj_290470::Run(unsigned char flag) {
    d.Clear();
    c.Clear();
    b.Clear();
    a.Clear();
    if (flag & 1)
        Free(this);
    return this;
}
