// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002ecf60 @ 0x002ecf60
#include "decls/data/engine/physics.h"

extern "C" double __cdecl sqrt(double x);


class __declspec(novtable) Entity {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};

namespace physics {
class Environment : public Entity {
public:
    Environment();

    float gravityX;     // +0x10
    float gravityY;     // +0x14
    float gravityZ;     // +0x18
    float scaledX;      // +0x1c
    float scaledY;      // +0x20
    float scaledZ;      // +0x24
    float length;       // +0x28
    float damping;      // +0x2c
    float scaledDamping; // +0x30
};

Environment::Environment() {
    damping = 2.0f;
    scaledDamping = 2.0f;
    gravityY = -980.0f;
    gravityX = 0.0f;
    gravityZ = 0.0f;
    scaledX = DAT_004d287c * gravityX;
    scaledY = DAT_004d287c * gravityY;
    scaledZ = DAT_004d287c * gravityZ;
    length = (float)sqrt(scaledX * scaledX + scaledY * scaledY + scaledZ * scaledZ);
    scaledDamping = DAT_004d287c * damping;
}
}
