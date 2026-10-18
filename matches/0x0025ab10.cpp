class Handler {
  public:
    int Fn(int, int, int, int);
};
class Obj {
  public:
    Handler* volatile handler;
};
int __cdecl FUN_0025ab10(Obj* p, int v) {
    Handler* h = p->handler;
    return h->Fn(v, 1, 1, 1);
}