extern int a;
extern int b;
extern int __stdcall first(int);
extern void __cdecl second(int, int, int*, int*, int);
class Obj {
  public:
    void fn(int);
};
void Obj::fn(int x) {
    second(first(x), 0, &a, &b, 0);
}
