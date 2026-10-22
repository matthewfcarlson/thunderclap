// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002fc990 @ 0x002fc990
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace physics {
class CollisionObject;
class PhysicsObject;
class ArticulatedPhysicsObject;
}

class Inventory_2fc990 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void *get(void *caster, unsigned int lo, unsigned int hi);
};

void *__cdecl FUN_0008d690(unsigned int size);

struct PhysicsInstance_2fc990 {
    char data[0x18];
    PhysicsInstance_2fc990 *FUN_002fc740(void *collision, void *physics, unsigned int a, unsigned int b);
};

PhysicsInstance_2fc990 *__cdecl FUN_002fc990(unsigned int lo, unsigned int hi, Inventory_2fc990 *inv, unsigned int extra)
{
    content::LoadInventory::DynamicCaster<physics::CollisionObject> collisionCaster;
    void *collision = inv->get(&collisionCaster, lo, hi);
    if (collision == 0)
        return 0;

    content::LoadInventory::DynamicCaster<physics::PhysicsObject> physicsCaster;
    void *physics = inv->get(&physicsCaster, lo, hi);
    if (physics == 0) {
        // the original asks again for an articulated object and drops the answer
        content::LoadInventory::DynamicCaster<physics::ArticulatedPhysicsObject> articulatedCaster;
        inv->get(&articulatedCaster, lo, hi);
    }

    PhysicsInstance_2fc990 *body = (PhysicsInstance_2fc990 *)FUN_0008d690(sizeof(PhysicsInstance_2fc990));
    if (body == 0)
        return 0;
    return body->FUN_002fc740(collision, physics, extra, 0);
}
