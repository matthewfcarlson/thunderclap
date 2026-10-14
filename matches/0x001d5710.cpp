struct Vec_1d5710 {
    int first;
    int last;
};
struct Inner_1d5710 {
    char pad[0x1c];
    Vec_1d5710 v;
};
class Obj_1d5710 {
  public:
    char pad[0x90];
    Inner_1d5710* p;
    int Count();
};
int Obj_1d5710::Count() {
    Vec_1d5710* v = &p->v;
    return (v->last - v->first) >> 2;
}
