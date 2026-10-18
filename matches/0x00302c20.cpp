// FUN_00302c20 @ 0x00302c20
class Entity;

struct EntityList_302c20 {
    Entity **begin;
    Entity **end;
};

class Entity {
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
    virtual bool CanCollide(Entity *other, int mask);
    char pad04[0x10];
    EntityList_302c20 *children;
};

class Collider_302c20 {
public:
    char pad0[0xc];
    int mask;
    void FUN_00302b70(Entity *a, Entity *b);
    void FUN_00302c20(Entity *a, Entity *b);
};

void Collider_302c20::FUN_00302c20(Entity *a, Entity *b)
{
    EntityList_302c20 *listA = a->children;
    EntityList_302c20 *listB = b->children;
    if (listA != 0) {
        if (listB != 0) {
            for (unsigned int i = 0; i < (unsigned int)(listA->end - listA->begin); i++) {
                if (b->CanCollide(listA->begin[i], mask)) {
                    for (unsigned int j = 0; j < (unsigned int)(listB->end - listB->begin); j++) {
                        if (a->CanCollide(listB->begin[j], mask))
                            FUN_00302b70(listA->begin[i], listB->begin[j]);
                    }
                }
            }
        } else {
            for (unsigned int i = 0; i < (unsigned int)(listA->end - listA->begin); i++) {
                if (b->CanCollide(listA->begin[i], mask))
                    FUN_00302b70(b, listA->begin[i]);
            }
        }
    } else {
        for (unsigned int j = 0; j < (unsigned int)(listB->end - listB->begin); j++) {
            if (a->CanCollide(listB->begin[j], mask))
                FUN_00302b70(a, listB->begin[j]);
        }
    }
}
