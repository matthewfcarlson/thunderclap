typedef unsigned short u16;
struct Obj { char pad[0x1c]; int a; int c; char gap[4]; int b; u16 d; };
void prep(Obj*, int);
void copy(void*, int, unsigned int, int);
void target(void* p, Obj* s) {
    prep(s, s->a);
    copy(p, s->b, ((unsigned int)s->d) << 4, 0);
    copy(p, s->a, ((unsigned int)s->c) << 3, 0);
    copy(p, (int)s, 0x58, 0);
}