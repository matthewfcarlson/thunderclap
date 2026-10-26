#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/unknown.h"
// data: g_cnt = DAT_0052c288, g_shared = DAT_004ce410

extern void* g_vt_27bc90[];
void Free(void*) throw();
void Free2(void*) throw();
struct E28 {
    virtual ~E28();
    char p[0x24];
};
struct E18 {
    virtual ~E18();
    char p[0x14];
};
struct M2c {
    void Fin() throw();
};
class Entity_27bc90 {
  public:
    void* vptr;
    ~Entity_27bc90() throw();
};
class Skeleton_27bc90 : public Entity_27bc90 {
  public:
    char pad[0x2c - 4];
    M2c* m2c;
    void* m30;
    E18* m34;
    E18* m38;
    char pad2[0x44 - 0x3c];
    E28* m44;
    E28* m48;
    ~Skeleton_27bc90() throw();
};
Skeleton_27bc90::~Skeleton_27bc90() throw() {
    vptr = g_vt_27bc90;
    if (--(*(int*)&DAT_0052c288) == 0) {
        if (DAT_004ce410)
            Free(DAT_004ce410);
        DAT_004ce410 = 0;
    }
    Free2(m30);
    M2c* p = m2c;
    if (p) {
        p->Fin();
        Free(p);
    }
    E28* s = m44;
    if (s) {
        E28* e = m48;
        for (; s != e; s++)
            s->~E28();
        Free2(m44);
    }
    E18* u = m38;
    E18* t = m34;
    for (; t != u; t++)
        t->~E18();
    E18* b = m34;
    m38 = b;
    if (b)
        Free2(b);
}
