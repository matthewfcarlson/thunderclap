struct Result { char pad[0x18]; };
struct Finder { char pad[0x28]; Result *find(int, int); };
struct Root { char pad[0x28]; Finder *finder; };
extern Root *gRoot;
extern int *gCompare;
struct Owner { void act(Result *, int); };
void __stdcall target(int arg) {
 Root *p = gRoot;
 Finder *f = p->finder;
 Result *r = f->find(arg, 0);
 if (r) {
  int *q = gCompare;
  if (*(int *)((char *)r + 0x14) == *q) {
   Owner *o = *(Owner **)((char *)r + 0x10);
   o->act(r, *(int *)((char *)r + 0xc));
  }
 }
}
