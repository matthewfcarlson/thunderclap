extern float zero;
class A {
  public:
    void run(float, float);
};
struct Holder {
    A* p;
};
Holder* __cdecl get();
void __stdcall FUN(float a, float b) {
    if (a <= zero || b <= a)
        return;
    Holder* h = get();
    h->p->run(a, b);
}