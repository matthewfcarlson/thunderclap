extern int a;
extern int b;
struct This_first {
    int first(int);
};
extern int __cdecl second(int, int, int*, int*, int);
class Obj {
  public:
    int fn(int);
};
int Obj::fn(int x) {
    return second(((This_first*)this)->first(x), 0, &a, &b, 0);
}
