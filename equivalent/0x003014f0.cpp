// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003014f0 @ 0x003014f0
extern "C" double __cdecl sqrt(double);
struct Vec_3014f0 { float x,y,z; };
struct Body_3014f0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual Vec_3014f0* position();
 char pad[0x30]; float radius;
};
struct Contact_3014f0 {
 char pad[0x14]; Vec_3014f0 normal; char pad2[0xc]; float distance;
 void FUN_00314be0(Body_3014f0*,Vec_3014f0*,Body_3014f0*,Vec_3014f0*,float,Vec_3014f0*);
 void target(Body_3014f0*,Body_3014f0*);
};
void Contact_3014f0::target(Body_3014f0* a,Body_3014f0* b) {
 double root=sqrt(distance);
 distance=(float)root;
 double inv=1.0/root;
 normal.x=(float)(inv*normal.x);
 normal.y=(float)(inv*normal.y);
 normal.z=(float)(inv*normal.z);
 float ra=-a->radius;
 Vec_3014f0* p=a->position();
 Vec_3014f0 pa;
 pa.x=ra*normal.x+p->x;
 pa.y=ra*normal.y+p->y;
 pa.z=ra*normal.z+p->z;
 float rb=b->radius;
 p=b->position();
 Vec_3014f0 pb;
 pb.x=rb*normal.x+p->x;
 pb.y=rb*normal.y+p->y;
 pb.z=rb*normal.z+p->z;
 float separation=distance-(a->radius+b->radius);
 FUN_00314be0(a,&pa,b,&pb,separation,&normal);
}