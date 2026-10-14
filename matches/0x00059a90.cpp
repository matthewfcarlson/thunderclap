struct Src {
    int a, b, c;
};
class Obj {
  public:
    virtual ~Obj() {}
    int a, b, c;
    char Set(Src* src);
};
char Obj::Set(Src* src) {
    a = src->a;
    b = src->b;
    c = src->c;
    return 1;
}
