struct Item { char pad[0x34]; void Destroy(); };
extern void __cdecl FreeArray(void *);
struct HairclubPhysicsObject {
    void *vptr;
    char pad[0x1f4];
    Item *items;
    void BaseDestroy();
    void Destroy();
};
void HairclubPhysicsObject::Destroy() {
    Item *p = items;
    vptr = (void *)0x431d1c;
    if (p) {
        int n = *((int *)p - 1);
        Item *q = p + n;
        while (--n >= 0) { q--; q->Destroy(); }
        FreeArray((char *)p - 4);
    }
    BaseDestroy();
}
