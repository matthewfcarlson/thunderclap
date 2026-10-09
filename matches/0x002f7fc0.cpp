typedef unsigned char byte;
class Ref { public: virtual void f0(); virtual void f1(); };
class Chunk { public: void init(); char pad[0x1c]; };
class physics_ImpulseBasedCollisionSolver {
public:
 virtual ~physics_ImpulseBasedCollisionSolver();
 virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
 Ref *r4; char pad1[0x8c]; Chunk c94; Chunk cb0; Chunk ccc; char pad2[0x14]; Ref *rfc;
};
void thunk_FUN_00267090(physics_ImpulseBasedCollisionSolver *);
physics_ImpulseBasedCollisionSolver::~physics_ImpulseBasedCollisionSolver() { if (r4) r4->f1(); if (rfc) rfc->f1(); ccc.init(); cb0.init(); c94.init(); }