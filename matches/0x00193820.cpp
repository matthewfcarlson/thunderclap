struct Src_193820;
class Obj_193820 {
  public:
    char pad[0x1c];
    int m1c;
    int m20;
    int m24;
    bool Set(const struct Src_193820* s);
};

struct Src_193820 {
    int a;
    int b;
    int c;
};

bool Obj_193820::Set(const struct Src_193820* s) {
    m1c = s->a;
    m20 = s->b;
    m24 = s->c;
    return true;
}
