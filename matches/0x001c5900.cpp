typedef unsigned int u32;
struct Obj { virtual void f(); char pad[4]; Obj *Create(u32); bool Check(); };
struct Finder { Obj *Find(u32); };
struct Registry { void Register(void *, Obj *); };
struct Manager {
 char p0[8]; Registry registry;
 char p1[0x128-8-sizeof(Registry)]; Finder finder;
 char p2[0x248-0x128-sizeof(Finder)]; Obj *saved;
 Obj *Run(u32,u32);
};
Obj *Manager::Run(u32 a,u32 b) {
 Obj *p = finder.Find(b);
 if (p) {
  p = p->Create(a);
  p->f();
  registry.Register((char *)p + 8, p);
  if (p->Check()) saved = p;
  return p;
 }
 return 0;
}