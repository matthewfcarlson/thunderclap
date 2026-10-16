class Handler {
  public:
    void Fn(int, int, int, int);
};
class Obj {
  public:
    Handler* volatile handler;
};
void __cdecl FUN_0025ab10(Obj* p, int v) {
    Handler* h = p->handler;
    h->Fn(v, 1, 1, 1);
}