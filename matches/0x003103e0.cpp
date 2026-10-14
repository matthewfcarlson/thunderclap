extern int vtable_3103e0;
class Obj_3103e0 {
  public:
    virtual void Kill(int);
    virtual void Release();
};
extern void Free(void*);
class ArticulatedPhysicsObject {
  public:
    char pad0[0x1f8];
    Obj_3103e0** items;
    void* aux;
    int count;
    char pad204[4];
    Obj_3103e0* at208;
    char pad20c[0x14];
    Obj_3103e0* at220;
    void Destroy();
    void Tail();
};
void ArticulatedPhysicsObject::Destroy() {
    *(int*)this = (int)&vtable_3103e0;
    if (at220)
        at220->Release();
    if (at208)
        at208->Release();
    for (int i = 0; i < count; ++i) {
        Obj_3103e0* p = items[i];
        if (p)
            p->Kill(1);
    }
    Free(items);
    Free(aux);
    Tail();
}