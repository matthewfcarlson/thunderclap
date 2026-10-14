struct Src_61ea0 {
    int a;
    int b;
    int c;
};
class Obj_61ea0 {
  public:
    char pad[0x1c];
    int m1;
    int m2;
    int m3;
    bool Set(const Src_61ea0* s);
};
bool Obj_61ea0::Set(const Src_61ea0* s) {
    m1 = s->a;
    m2 = s->b;
    m3 = s->c;
    return true;
}
