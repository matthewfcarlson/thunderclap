struct Obj;
typedef void (Obj::*Fn)(int,int,int,int,int,int,int);
struct Obj { int x; };
void __cdecl FUN_00094490(Obj *a, int *p, int b, Fn fn) {
  int *q = p;
  int v0 = *q; q++;
  int v1 = *q; q++;
  int v2 = *q; q++;
  int v3 = *q; q++;
  int v4 = *q; q++;
  int v5 = *q; q++;
  int v6 = *q;
  (a->*fn)(v0,v1,v2,v3,v4,v5,v6);
}
