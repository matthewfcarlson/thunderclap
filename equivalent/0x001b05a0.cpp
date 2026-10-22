// STATUS: equivalent (tools/equiv.py level 3: 20127 inputs, branch coverage 133/134, incomplete)
// FUN_001b05a0 @ 0x001b05a0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

struct V3_1b05a0 {
    float x, y, z;
    float FUN_0022d180();
};
float __cdecl FUN_000186b0(float* v, float* lo, float* hi);
void __cdecl FUN_00224d70(float angle, V3_1b05a0* axis);
static float AbsF(float v) {
    union {
        float f;
        unsigned int u;
    } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}
struct Tri_1b05a0 {
    char pad00[0x16];
    unsigned char b16;
    char pad17[1];
};
struct Mesh44 {
    char pad00[0x18];
    Tri_1b05a0* tris;
};
struct Geo {
    char pad00[0x44];
    Mesh44* f44;
    void FUN_001af890(V3_1b05a0* out, int idx);
};
struct Entity;
struct Info_1b05a0 {
    char pad00[0x18];
    void* f18;
};
struct Contact_1b05a0 {
    char pad00[0xc];
    Info_1b05a0* info;
    char pad10[4];
    int f14;
    V3_1b05a0 n;
    int f24;
    char pad28[4];
    V3_1b05a0 p;
    V3_1b05a0 q;
    char FUN_002f8e10(Geo** geo, unsigned int* idx);
};
struct Ent114Body {
    char pad00[8];
    unsigned int f8, fc;
    char pad10[0x12c - 0x10];
    int f12c;
    char pad130[0x138 - 0x130];
    int f138;
    void FUN_00038e80(int a, void* hit, int b, V3_1b05a0* p, V3_1b05a0* n, int c);
};
struct Ent114 {
    char pad00[8];
    Ent114Body* f8;
    int kind;
};
struct Reg4c {
    char FUN_00079950(void* pos);
    int FUN_00079800(void* pos);
    void FUN_0007ba60(int i);
    float FUN_0007a820(int i);
    struct Sparks* FUN_0007ad00(void* pos);
};
struct Sparks {
    void FUN_00083320(V3_1b05a0* q, V3_1b05a0* n, int c, int d, V3_1b05a0* z, int e);
};
struct Grid38 {
    void FUN_001f6cd0(Tri_1b05a0* tri, Geo* geo, V3_1b05a0* q, V3_1b05a0* n, V3_1b05a0* dir, int mode,
                      float r1, float r2, int* out, int z);
};
struct Grid34 {
    void FUN_001ebea0(int a, Entity* e);
};
struct World {
    char pad00[0x20];
    struct Holder_1b05a0* f20;
    char pad24[0x34 - 0x24];
    Grid34* f34;
    Grid38* f38;
    char pad3c[0x4c - 0x3c];
    Reg4c* f4c;
};
struct Holder_1b05a0 {
    char pad00[0x124];
    Entity* cur;
};
struct HitObj_1b05a0 {
    char pad00[0xc];
    int kind;
};
struct Body72 {
    char pad00[0x20];
    float f20;
    char pad24[0x34 - 0x24];
    float f34;
};
struct Obj1d72_1b05a0 {
    char pad00[0x50];
    V3_1b05a0 v50;
    char pad5c[0x6c - 0x5c];
    int f6c;
    struct Ob70* f70;
    struct Ob74* f74;
};
struct Ob74 {
    char pad00[0x20];
    Body72* f20;
};
struct Ob70 {
    void FUN_0016fc60(V3_1b05a0* out);
};
struct Chk {
    char FUN_001d4e40();
    int FUN_001d5e80(int a);
};
struct Dummy964 {
    float FUN_000787e0(int a, float b);
};
Dummy964* __cdecl FUN_000964d0();
struct Entity {
    char pad00[8];
    char pos8[0x38];
    int f40;
    char pad44[0xec - 0x44];
    Chk* fec;
    char padf0[0x114 - 0xf0];
    Ent114* f114;
    char pad118[0x12c - 0x118];
    int f12c;
    char pad130[0x134 - 0x130];
    int f134;
    char pad138[0x148 - 0x138];
    Entity* other;
    char b14c, b14d;
    char pad14e[0x1c9 - 0x14e];
    char b1c9;
    char pad1ca[0x1fc - 0x1ca];
    int f1fc;
    char pad200[0x218 - 0x200];
    float f218;
    char pad21c[0x248 - 0x21c];
    int f248;
    char pad24c[0x334 - 0x24c];
    Entity *ign334, *ign338;
    void FUN_001d6ac0(int a);
    char FUN_001d6a80();
    int FUN_001d64a0();
    char FUN_001d6980();
    V3_1b05a0* FUN_001d6b40();
    V3_1b05a0* FUN_001d6b30();
    void FUN_00035660(V3_1b05a0* out);
    char FUN_000373d0();
    Obj1d72_1b05a0* FUN_001d72e0();
    void FUN_001d6ad0(V3_1b05a0* p);
    float FUN_001d8160();
    void FUN_0027d4f0(int a);
    void FUN_001d69f0(V3_1b05a0* out);
    void FUN_001d8cd0();
    void FUN_001d7510();
    void FUN_001d6ec0(int a, int b, int c);
    void FUN_00038e80(int a, HitObj_1b05a0* hit, int b, V3_1b05a0* p, V3_1b05a0* n, int c);
};
char __stdcall FUN_001b05a0(Entity* self, HitObj_1b05a0* hit, Contact_1b05a0* c) {
#define world DAT_004dd700
    // Scratch vectors are reused by the contact, particle, and collision queries.
    struct Scratch {
        float upper;
        union {
            unsigned int triangleIndex;
            int particleResult;
        } index;
        float lower;
        float radius;
        V3_1b05a0 direction;
        V3_1b05a0 normal;
        V3_1b05a0 point;
    } s;
    if (AbsF(c->n.y) <= 1e-05f) {
        if (c->q.y <= 0.2f) {
            Geo* geo = 0;
            s.index.triangleIndex = 0;
            if (!c->FUN_002f8e10(&geo, &s.index.triangleIndex))
                return 1;
            Tri_1b05a0* tri = &geo->f44->tris[(unsigned short)s.index.triangleIndex];
            s.upper = 1000.0f;
            hulk_freg maximum = -1000.0f;
            unsigned short* vertices = (unsigned short*)((char*)tri + 0x10);
            for (int k = 0; k < 3; ++k) {
                geo->FUN_001af890(&s.normal, vertices[k]);
                if (s.normal.y < s.upper)
                    s.upper = s.normal.y;
                if (s.normal.y > maximum)
                    maximum = s.normal.y;
            }
            if (!(maximum - s.upper > 1.0f))
                return 1;
        } else
            self->FUN_001d6ac0(1);
    }
    if (self->FUN_001d6a80())
        return 1;
    Entity* current = world->f20->cur;
    Entity* other = self->other;
    bool checkTriangle = other ? (other != current && other->ign338 != current && other->ign334 != current)
                               : !self->fec->FUN_001d4e40();
    if (checkTriangle) {
        Geo* geo = 0;
        unsigned int index = 0;
        if (c->FUN_002f8e10(&geo, &index)) {
            Tri_1b05a0* tri = &geo->f44->tris[(unsigned short)index];
            if (tri->b16 & 8)
                return 1;
        }
    }
    if (other && other->FUN_000373d0()) {
        if (hit != c->info->f18) {
            s.direction.x = c->n.x * -1.0f;
            s.direction.y = c->n.y * -1.0f;
            s.direction.z = c->n.z * -1.0f;
            s.normal = c->q;
        } else {
            s.normal = c->p;
            s.direction = c->n;
        }
        other->FUN_00038e80(other->f12c, hit, c->f14, &s.normal, &s.direction, c->f24);
        return 1;
    }
    if (self->f114 && self->f134 == 0 && self->FUN_001d64a0() != 5) {
        Ent114* owner = self->f114;
        if (owner->kind == 1) {
            Ent114Body* body = owner->f8;
            if (body->f8 == (*(unsigned int*)&DAT_004dc0e0) &&
                body->fc == (*(unsigned int*)((char*)&DAT_004dc0e0 + 4)) && !(body->f138 > 0))
                body->FUN_00038e80(body->f12c, hit, c->f14, &c->q, &c->n, c->f24);
        }
    }
    bool tryParticle = true;
    if (!self->f114) {
        if (self->b14d)
            tryParticle = false;
        else if (self->FUN_001d6980())
            tryParticle = false;
    }
    if (tryParticle) {
        Ent114Body* body = 0;
        if (self->f114 && self->f114->kind == 1) {
            body = self->f114->f8;
            if (body->f8 != (*(unsigned int*)&DAT_004dc0e0) ||
                body->fc != (*(unsigned int*)((char*)&DAT_004dc0e0 + 4)))
                body = 0;
        }
        char registered = 0;
        if (self->b14c)
            registered = world->f4c->FUN_00079950(&self->pos8);
        if (body || !registered) {
            V3_1b05a0* previous = self->FUN_001d6b40();
            V3_1b05a0* position = self->FUN_001d6b30();
            s.direction.x = position->x - previous->x;
            s.direction.y = position->y - previous->y;
            s.direction.z = position->z - previous->z;
            hulk_freg threshold = 15.0f;
            double speedSquared;
            if (body) {
                ((Entity*)body)->FUN_00035660(&s.normal);
                speedSquared = s.normal.z * s.normal.z + s.normal.y * s.normal.y + s.normal.x * s.normal.x;
                threshold = 64.0f;
            } else {
                Obj1d72_1b05a0* state = self->FUN_001d72e0();
                V3_1b05a0* velocity = &state->v50;
                speedSquared =
                    velocity->x * velocity->x + velocity->y * velocity->y + velocity->z * velocity->z;
            }
            if (speedSquared > threshold && s.direction.z * s.direction.z + s.direction.y * s.direction.y +
                                                    s.direction.x * s.direction.x >
                                                2.0f) {
                Geo* geo = 0;
                unsigned int index = 0;
                if (c->FUN_002f8e10(&geo, &index)) {
                    Tri_1b05a0* tri = &geo->f44->tris[(unsigned short)index];
                    if (tri && !(tri->b16 & 8)) {
                        self->FUN_001d6ad0(self->FUN_001d6b40());
                        s.upper = 2.0f;
                        s.lower = 0.5f;
                        s.radius = self->FUN_001d8160() * 0.01f;
                        s.lower = FUN_000186b0(&s.radius, &s.lower, &s.upper);
                        s.point = c->q;
                        s.normal = c->n;
                        if (self->fec->FUN_001d5e80(self->f40) == 3) {
                            s.radius = FUN_000964d0()->FUN_000787e0(0, 360.0f);
                            s.direction.x = (*(float*)&DAT_004c3754);
                            s.direction.y = (*(float*)&DAT_004c3758);
                            s.direction.z = (*(float*)&DAT_004c375c);
                            FUN_00224d70(s.radius, &s.direction);
                        } else {
                            if (body)
                                ((Entity*)body)->FUN_00035660(&s.direction);
                            else
                                s.direction = self->FUN_001d72e0()->v50;
                            s.direction.FUN_0022d180();
                        }
                        s.index.particleResult = 0;
                        world->f38->FUN_001f6cd0(tri, geo, &s.point, &s.normal, &s.direction, 8, s.lower,
                                                 s.lower, &s.index.particleResult, 0);
                        world->f34->FUN_001ebea0(s.index.particleResult, self);
                    }
                }
            }
        }
    }
    if (self->b1c9 && self->f1fc != 0 && self->fec->FUN_001d5e80(self->f40) == 4 && !(self->f218 < 10.0f))
        self->FUN_0027d4f0(9);
    if (hit->kind != 5 && self->b1c9) {
        Obj1d72_1b05a0* state = self->FUN_001d72e0();
        V3_1b05a0* velocity = &state->v50;
        if (velocity->x * velocity->x + velocity->y * velocity->y + velocity->z * velocity->z > 25.0f) {
            bool activate = false;
            if (self->fec->FUN_001d5e80(self->f40) != 3)
                activate = true;
            else {
                Obj1d72_1b05a0* state2 = self->FUN_001d72e0();
                s.normal.x = s.normal.y = s.normal.z = 0;
                if (state2->f70)
                    state2->f70->FUN_0016fc60(&s.normal);
                else
                    self->FUN_001d69f0(&s.normal);
                hulk_freg height = 0.0f;
                if (state2->f74 && state2->f74->f20)
                    height = state2->f74->f20->f34;
                hulk_freg contactHeight = (void*)state2 == c->info->f18 ? c->q.y : c->p.y;
                hulk_freg delta = contactHeight - (s.normal.y - height);
                if (!(height * 0.75f > delta) && !(AbsF(c->n.y) > 0.3f))
                    activate = true;
            }
            if (activate) {
                self->f248 = 1;
                self->FUN_001d8cd0();
            }
        }
    }
    if (self->b14c && world->f4c->FUN_00079950(&self->pos8)) {
        if (!(AbsF(c->n.y - 1.0f) <= 1e-05f)) {
            self->FUN_001d7510();
            Reg4c* registry = world->f4c;
            int id = registry->FUN_00079800(&self->pos8);
            if (id != -1) {
                registry->FUN_0007ba60(id);
                if (registry->FUN_0007a820(id) > DAT_004c3734)
                    self->FUN_001d6ec0((int)DAT_004c372c, 0, 0);
            }
        }
    }
    if (self->b14d) {
        void* contactOwner = c->info->f18;
        s.normal = (void*)self->FUN_001d72e0() == contactOwner ? c->q : c->p;
        Sparks* sparks = world->f4c->FUN_0007ad00(&self->pos8);
        if (sparks) {
            s.point.x = s.point.y = s.point.z = 0;
            sparks->FUN_00083320(&s.normal, &c->n, c->f24, 0, &s.point, 0);
            if (self->FUN_001d72e0()->f6c == 0)
                return 1;
        }
    }
    self->FUN_0027d4f0(8);
    return 0;
}
