// Same code shape as 0x0030ce90 (propagated; names are from that function)
namespace physics {
class PhysicsJoint { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void vfunc_15(void*); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); char pad[0xfc - 4]; };
class PhysicsJoint1D : public PhysicsJoint {};
void PhysicsJoint::vfunc_15(void* out) { unsigned int* p = (unsigned int*)out; p[0] = *(unsigned int*)((char*)this + 0xfc); p[1] = *(unsigned int*)((char*)this + 0x100); p[2] = *(unsigned int*)((char*)this + 0x104); }
}