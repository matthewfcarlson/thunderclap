// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// physics::CollisionSolverAgent::vfunc_8 @ 0x002f8850
struct Vec { float x,y,z; };
extern const float DAT_004d2c58;
struct Body {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual float s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(Vec*,Vec*,int);
 char pad[0x20]; int state;
};
struct Contact { char pad[0x50]; Vec velocity; char pad2[0x14]; Body* body; void FUN_002ef8b0(int); };
namespace physics {
struct CollisionSolverAgent {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual int vfunc_8(Contact*,int);
};
int CollisionSolverAgent::vfunc_8(Contact* c,int unused) {
 Body* b=c->body;
 if(!b || b->state) return 0;
 Vec v=c->velocity, a,d;
 b->s25(&a,&d,-1);
 float radius=b->s14();
 float rr=radius*radius;
 float vv=v.z*v.z+v.x*v.x+v.y*v.y;
 volatile float stored=vv;
 if(!(vv<rr)) rr=stored;
 float aa=a.z*a.z+a.y*a.y+a.x*a.x;
 if(DAT_004d2c58*rr<aa) { c->FUN_002ef8b0(1); return 1; }
 return 0;
}
}