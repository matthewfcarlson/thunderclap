extern int vtable;
class Obj {
  public:
    virtual void Kill(int);
    virtual void Release();
};
extern void Free(void*);
class ArticulatedPhysicsObject {
  public:
    char pad0[0x1f8];
    Obj** items;
    void* aux;
    int count;
    char pad204[4];
    Obj* at208;
    char pad20c[0x14];
    Obj* at220;
    void Destroy();
    void Tail();
};
void ArticulatedPhysicsObject::Destroy() {
    *(int*)this = (int)&vtable;
    if (at220)
        at220->Release();
    if (at208)
        at208->Release();
    for (int i = 0; i < count; ++i) {
        Obj* p = items[i];
        if (p)
            p->Kill(1);
    }
    Free(items);
    Free(aux);
    Tail();
}