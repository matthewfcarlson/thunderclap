class Obj { public: void Act(int, int*); };
Obj* Get();
class Host { public: unsigned char target(int a, int b, int c, int d); };
unsigned char Host::target(int a, int b, int c, int d) {
    if (a < 0) return 0;
    Obj* p = Get();
    if (p) p->Act(a, &b);
    return 1;
}