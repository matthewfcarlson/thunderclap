struct Src_165470 {
    int a;
    int b;
    int c;
};
class Obj_165470 {
  public:
    char pad[0x18];
    int m18;
    int m1c;
    int m20;
    bool Set(Src_165470* s);
};
bool Obj_165470::Set(Src_165470* s) {
    m18 = s->a;
    m1c = s->b;
    m20 = s->c;
    return true;
}
