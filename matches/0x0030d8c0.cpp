struct Inner { char pad[0x6c]; unsigned int value; };
struct Param { char pad0[8]; Inner* p1; Inner* p2; char pad1[8]; unsigned int x,y,z; };
class CollisionAnalyser {
public:
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(Param*, int); virtual void vfunc_4();
 char pad[0x50]; unsigned int a,b,c,d,e,f;
};
bool CollisionAnalyser::vfunc_3(Param* p, int unused) {
 a=p->x; b=p->y; c=p->z; d=p->p1->value; e=p->p2->value; f=d|e; return f==0;
}