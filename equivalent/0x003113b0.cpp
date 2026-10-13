// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// physics::ArticulatedPhysicsObject::vfunc_18 @ 0x003113b0
struct Vector { float x,y,z; };
struct Body {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual bool slot14(void*,Vector*,void*);
 char pad[0xeb]; unsigned char enabled;
};
namespace physics {
struct PhysicsObject {
 char pad[0x40]; float mass; char pad2[0x1b8]; Body** bodies; char pad3[0x14]; unsigned int state214,state218; unsigned char state21c;
 bool vfunc_18(void*,Vector*,void*,void*,int,int);
};
struct ArticulatedPhysicsObject : PhysicsObject {
 void FUN_00310b30(void*,int,int);
 bool vfunc_18(void*,Vector*,void*,void*,int,int);
};
}
bool physics::ArticulatedPhysicsObject::vfunc_18(void* a,Vector* v,void* c,void* d,int index,int last) {
 if (!(mass > 0.0f)) return false;
 if(index < 0 || !bodies[index]->enabled) return PhysicsObject::vfunc_18(a,v,c,d,-1,-1);
 Vector copy = *v;
 FUN_00310b30(d,index,last);
 bool result = bodies[index]->slot14(a,&copy,c);
 state218 = 0; state214 = 0; state21c = 0;
 if(result && (copy.z*copy.z + copy.x*copy.x + copy.y*copy.y > 1e-05f))
 return PhysicsObject::vfunc_18(a,&copy,c,d,-1,-1);
 return result;
}