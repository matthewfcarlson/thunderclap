struct Vec {
    int first;
    int last;
};
struct Inner {
    char pad[0x1c];
    Vec v;
};
class Obj {
  public:
    char pad[0x90];
    Inner* p;
    int Count();
};
int Obj::Count() {
    Vec* v = &p->v;
    return (v->last - v->first) >> 2;
}
