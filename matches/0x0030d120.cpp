class physics_PhysicsJoint {
public:
    virtual void vfunc_0();
};

class physics_PhysicsJoint3D : public physics_PhysicsJoint {
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual bool IsFlagSet();
    virtual void vfunc_5();

    char mPad[0x14C];
    bool mFlag;
};

bool physics_PhysicsJoint3D::IsFlagSet() {
    return mFlag;
}