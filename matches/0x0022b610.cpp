struct V { float x,y,z,w; };
struct C { int dummy; void Target(int a, V* p); };
extern void __cdecl Helper(C* self, int a, V* q);
void C::Target(int a, V* p) {
    V q;
    q.x = -p->x;
    q.y = -p->y;
    q.z = -p->z;
    q.w = p->w;
    Helper(this, a, &q);
}
