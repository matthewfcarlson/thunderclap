struct Val { char pad[0x18]; float value; };
struct Global { char pad[0x24]; Val* p; };
extern Global* g;
class Helper { public: int get(); };
class Other { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3a(); virtual int f4(); };
class Sub { public: int run(int); };
class Self { public: char p0[0x40]; int arg; char p1[0xa0-0x44]; Helper* a; char p2[0xec-0xa4]; Sub* d; char p3[0x11c-0xf0]; Other* b; };
int __fastcall target(Self* s) {
 float limit = g->p->value;
 int r;
 if (s->a) r = s->a->get() + 0x30;
 else r = ((Other*)s->b)->f4();
 if (*(float*)(r+4) < limit) return -10;
 int v = s->arg;
 Sub* d = s->d;
 return d->run(v);
}
