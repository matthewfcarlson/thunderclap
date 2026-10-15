typedef long long I64;
extern "C" I64 __cdecl Parse(void*, int, int);
class Item {
  public:
    char A();
    char B();
};
class Holder {
  public:
    Item* Find(I64);
    char Check(void*);
};
char Holder::Check(void* p) {
    I64 v = Parse(p, 0, 0);
    Item* x = Find(v);
    if (x && x->A() && x->B())
        return 1;
    return 0;
}
