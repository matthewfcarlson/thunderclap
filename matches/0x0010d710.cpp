typedef unsigned char u8;
extern int cast(void *, int, const void *, const void *, int);
extern char type1[];
extern char type2[];
struct Helper1 { void *Get(); };
struct Helper2 { void *Get(); };
class Cond {
public:
 virtual void v0(); virtual void v1(); virtual void v2();
 virtual void v3(); virtual void v4(); virtual void v5();
 virtual bool vfunc_6(void *a, void *p, void *b);
 char pad[8];
 u8 value;
};
bool Cond::vfunc_6(void *a, void *p, void *b) {
 if (cast(p, 0, type1, type2, 0)) {
  void *x = ((Helper1 *)p)->Get();
  void *q = ((Helper2 *)x)->Get();
  if (q) {
   void *v = *(void **)((char *)q + 0x1ca0);
   if (v) {
    char *t = (char *)v + 0x58;
    if (t) return *(u8 *)((char *)v + 0x9e) == value;
   }
  }
 }
 return false;
}
