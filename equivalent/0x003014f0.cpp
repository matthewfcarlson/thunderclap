// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003014f0 @ 0x003014f0
extern "C" double __cdecl sqrt(double);
struct Vec { float x,y,z; };
struct Body {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual Vec* position();
 char pad[0x30]; float radius;
};
struct Contact {
 char pad[0x14]; Vec normal; char pad2[0xc]; float distance;
 void FUN_00314be0(Body*,Vec*,Body*,Vec*,float,Vec*);
 void target(Body*,Body*);
};
void Contact::target(Body* a,Body* b) {
 double root=sqrt(distance);
 distance=(float)root;
 double inv=1.0/root;
 normal.x=(float)(inv*normal.x);
 normal.y=(float)(inv*normal.y);
 normal.z=(float)(inv*normal.z);
 float ra=-a->radius;
 Vec* p=a->position();
 Vec pa;
 pa.x=ra*normal.x+p->x;
 pa.y=ra*normal.y+p->y;
 pa.z=ra*normal.z+p->z;
 float rb=b->radius;
 p=b->position();
 Vec pb;
 pb.x=rb*normal.x+p->x;
 pb.y=rb*normal.y+p->y;
 pb.z=rb*normal.z+p->z;
 float separation=distance-(a->radius+b->radius);
 FUN_00314be0(a,&pa,b,&pb,separation,&normal);
}