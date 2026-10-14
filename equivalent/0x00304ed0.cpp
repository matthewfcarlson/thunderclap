// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00304ed0 @ 0x00304ed0
// equiv-map: ??0ObjectBase@@QAE@XZ = 0x0027b070

struct Name_304ed0 {
    int a;
    int b;
    void FUN_0027af00();
};

class ObjectBase {
public:
    ObjectBase() throw();
    virtual void vfunc_0();
    int f04, f08, f0c;
};

namespace physics {
class CollisionObject : public ObjectBase {
public:
    Name_304ed0 name;              // 0x10
    int f18, f1c, f20, f24, f28, f2c, f30;
    char b34, b35;
    char pad36[2];
    int f38, f3c, f40, f44, f48;
    char b4c, b4d;
    char pad4e[2];
    char b50, b51;
    char pad52[2];
    int f54, f58, f5c, f60, f64;
    char b68, b69, b6a, b6b;
    int f6c;
    char b70, b71, b72;
    CollisionObject() throw();
    virtual void vfunc_0();
};
}

physics::CollisionObject::CollisionObject() throw()
{
    name.FUN_0027af00();
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f30 = 0;
    b34 = 0;
    b35 = 0;
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    b4c = 0;
    b4d = 0;
    b50 = 0;
    f54 = 0;
    b51 = 1;
    f58 = 0;
    f5c = 0;
    f60 = 0;
    f64 = 0;
    b6b = 0;
    b71 = 0;
    b68 = 1;
    b69 = 1;
    b6a = 1;
    f6c = 0xf;
    b70 = 1;
    b72 = 1;
}
