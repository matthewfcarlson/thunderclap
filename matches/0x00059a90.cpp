struct Src_59a90 {
    int a, b, c;
};
class Obj_59a90 {
  public:
    virtual ~Obj_59a90() {}
    int a, b, c;
    char Set(Src_59a90* src);
};
char Obj_59a90::Set(Src_59a90* src) {
    a = src->a;
    b = src->b;
    c = src->c;
    return 1;
}
