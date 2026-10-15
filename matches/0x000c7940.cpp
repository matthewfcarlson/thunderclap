struct V3 {
    int x, y, z;
};
struct V2 {
    int x, y;
};
class Obj {
    char pad[8];
    V3* a;
    char pad2[4];
    int* b;
    V2* c;

  public:
    void Set(const V3* p, int n, const V2* q);
    void Update();
};
void Obj::Set(const V3* p, int n, const V2* q) {
    V3* d = a;
    d->x = p->x;
    d->y = p->y;
    d->z = p->z;
    *b = n;
    *c = *q;
    Update();
}