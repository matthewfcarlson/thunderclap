struct Arg {
    int a, b, c;
};
class Helper {
  public:
    int Fn(int, Arg);
};
class Obj {
    char pad[0x8c];

  public:
    Helper* p;
    int Fn(int, Arg);
};
int Obj::Fn(int x, Arg a) {
    int r = -1;
    if (p)
        r = p->Fn(x, a);
    return r;
}