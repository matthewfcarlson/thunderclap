// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 48/48)
// physics::ImpulseBasedCollisionSolver::vfunc_1 @ 0x002f8a00
struct V3 {
    float x;
    float y;
    float z;
};

class Collider {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual char v24(V3* a, V3* b, int id);
};

class Body {
public:
    char pad00[0x6c];
    int state;
};

class World {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int v8(Body* body, int id);
};

class ImpulseBasedCollisionSolver {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual char vfunc_2(Collider* a, Collider* b, V3* p, V3* q, int ia, int ib);
    virtual void vfunc_3(Collider* c, int a, int b, unsigned char f);
    virtual void vfunc_4();
    World* world;               // 0x04
    char pad08[0x1c - 8];
    int idA;                    // 0x1c
    int idB;                    // 0x20
    V3 normal;                  // 0x24
    char pad30[4];
    unsigned int flags;         // 0x34
    V3 p38;
    V3 p44;
    V3 p50;
    V3 p5c;
    V3 p68;
    V3 p74;
    float t;                    // 0x80
    Body* bodyA;                // 0x84
    Body* bodyB;                // 0x88
    Collider* collA;            // 0x8c
    Collider* collB;            // 0x90
    V3 p94;
    char pad_a0[0xb0 - 0xa0];
    V3 pb0;
    char pad_bc[0xf0 - 0xbc];
    char f0;
    char f1;
    char f2;
    char sameObject;
    int FUN_002f8300();
    void FUN_002f7b70(Collider* a, Collider* b, V3* p, V3* q, int ia, int ib);
};

void ImpulseBasedCollisionSolver::vfunc_1()
{
    Collider* a = collA;
    Collider* b = collB;
    sameObject = (a == b);
    if (t >= -1.0e-6f)
        return;

    if (f1) {
        if (a != 0 && bodyA->state != 1 && idA == 0)
            collA = 0;
        if (b != 0 && bodyB->state != 1 && idB == 0)
            collB = 0;
        if (collA == 0 && collB == 0) {
            flags |= 1;
            return;
        }
    }

    FUN_002f7b70(collA, collB, &p38, &p94, idA, idB);
    FUN_002f7b70(collB, collA, &p44, &pb0, idB, idA);

    char firstA = f1;
    char firstB = f1;
    f0 = 0;
    for (;;) {
        if (FUN_002f8300() == 1) {
            flags |= 1;
            return;
        }
        char hit = vfunc_2(collA, collB, &p38, &p94, idA, idB);
        if (hit) {
            char ok = hit;
            if (firstA) {
                ok = world->v8(bodyA, idA) != 1;
                firstA = 0;
            }
            if (ok) {
                p50.x = p50.x * -1.0f;
                p50.y = p50.y * -1.0f;
                p50.z = p50.z * -1.0f;
                char hit2 = vfunc_2(collB, collA, &p44, &pb0, idB, idA);
                if (hit2) {
                    if (firstB) {
                        hit2 = world->v8(bodyB, idB) != 1;
                        firstB = 0;
                    }
                } else if (collB->v24(&p44, &p68, idB)) {
                    p74.x = p5c.x - p68.x;
                    p74.y = p5c.y - p68.y;
                    p74.z = p5c.z - p68.z;
                    t = normal.z * p74.z + normal.y * p74.y + normal.x * p74.x;
                }
                if (hit2)
                    break;
            }
        } else if (collA->v24(&p38, &p5c, idA)) {
            p74.x = p5c.x - p68.x;
            p74.y = p5c.y - p68.y;
            p74.z = p5c.z - p68.z;
            t = normal.z * p74.z + normal.y * p74.y + normal.x * p74.x;
        }
        if (flags & 1)
            break;
    }

    if (collA == collB) {
        vfunc_3(collA, idA, idB, f2);
        vfunc_3(collB, idB, idA, f2);
    } else {
        vfunc_3(collA, idA, -1, f2);
        vfunc_3(collB, idB, -1, f2);
    }
}
