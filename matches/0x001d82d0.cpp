#include "compat/ptr.h"
struct Node {
    char pad[0x6c];
    int field6c;
};
struct Holder_1d82d0 {
    char pad[0x10];
    Node* node;
};
class Manager_1d82d0 {
  public:
    bool Check(void*);
    int Find(void*);
    void Use(int);
};
struct Root_1d82d0 {
    char pad[0x4c];
    Manager_1d82d0* manager;
};
extern Root_1d82d0* gRoot_1d82d0;
class Obj_1d82d0 {
  public:
    char pad0[0xa0];
    Holder_1d82d0* holder;
    char padA4[0xa8];
    unsigned char active;
    void Prepare();
    int Run();
};
int Obj_1d82d0::Run() {
    if (!active)
        return -1;
    hulk_intptr x;
    if (holder)
        x = (hulk_intptr)holder->node;
    else
        x = 0;
    if (*(int*)(x + 0x6c))
        return -1;
    Prepare();
    Manager_1d82d0* m = gRoot_1d82d0->manager;
    void* q = (char*)this + 8;
    if (!m->Check(q))
        return -1;
    int r = m->Find(q);
    if (r != -1)
        m->Use(r);
    return r;
}