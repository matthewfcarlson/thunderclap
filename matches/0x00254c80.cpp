int resolve(int, int);
struct Seq {
    char pad[12];
    volatile int count;
    int unused;
    int a;
    int b;
};
class Base {
  public:
    virtual void f();
};
class Repeat : public Base {
  public:
    virtual void f();
    char pad[4];
    Seq* seq;
    int zero;
    int val;
    int count;
    Repeat(Seq*);
};
Repeat::Repeat(Seq* s) {
    seq = s;
    zero = 0;
    int index = s->a;
    int result;
    if (index == -1)
        result = ((int)s | index);
    else
        result = resolve(index, s->b);
    val = result;
    volatile int* p = &seq->count;
    int x = *p;
    count = x ? x - 4 : 0;
}