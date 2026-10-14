// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 12/12)
// FUN_0030d4f0 @ 0x0030d4f0
// FUN_0030d4f0: PhysicsJoint factory: 0 -> 0D, 1 -> 1D, 3 -> 3D
// equiv-map: ??0PhysicsJoint@physics@@QAE@HHH@Z = 0x0030ca80
// equiv-map: ??0PhysicsJoint1D@physics@@QAE@HHH@Z = 0x0030cdb0
// equiv-map: ??0PhysicsJoint3D@physics@@QAE@HHH@Z = 0x0030d030
inline void *operator new(unsigned int, void *p) throw() { return p; }
void *__cdecl FUN_0008d690(unsigned int size);

namespace physics {

class PhysicsJoint {
public:
    PhysicsJoint(int a, int b, int c) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(void *);
    char pad04[0xf8 - 4];
};

class PhysicsJoint0D : public PhysicsJoint {
public:
    PhysicsJoint0D(int a, int b, int c) throw() : PhysicsJoint(a, b, c) {}
    virtual void f5(void *);
};

class PhysicsJoint1D : public PhysicsJoint {
public:
    PhysicsJoint1D(int a, int b, int c) throw();
    virtual void f5(void *);
    char pad[0x120 - 0xf8];
};

class PhysicsJoint3D : public PhysicsJoint {
public:
    PhysicsJoint3D(int a, int b, int c) throw();
    virtual void f5(void *);
    char pad[0x15c - 0xf8];
};

} // namespace physics

physics::PhysicsJoint *__cdecl FUN_0030d4f0(int type, int a, int b, int c)
{
    if (type == 0) {
        void *mem = FUN_0008d690(0xf8);
        if (mem)
            return new (mem) physics::PhysicsJoint0D(a, b, c);
        return 0;
    }
    if (type == 1) {
        void *mem = FUN_0008d690(0x120);
        if (mem)
            return new (mem) physics::PhysicsJoint1D(a, b, c);
        return 0;
    }
    if (type == 3) {
        void *mem = FUN_0008d690(0x15c);
        if (mem)
            return new (mem) physics::PhysicsJoint3D(a, b, c);
        return 0;
    }
    return 0;
}
