struct Pair { int a; int b; };
class Target { public: char pad[8]; int x; int y; int z; int w; unsigned char q; void Init(int, int); void Set(Pair*, int, int, int, int, unsigned char); };
void Target::Set(Pair* p, int a, int b, int c, int d, unsigned char e) {
    Init(p->a, p->b);
    x = a; y = b; z = c; w = d; q = e;
}