// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00301310 @ 0x00301310
struct Vec3 { float x,y,z; };
struct Shape {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual Vec3* position();
 char pad[0x40];
 Vec3 direction;
 float distance;
 unsigned int value;
 unsigned char special;
};
struct Context {
 char pad[0xc]; float a,b;
 void FUN_00317610(unsigned int, Shape*, Vec3*, unsigned int);
 void FUN_00315860(unsigned int, Shape*);
 void FUN_00319270(unsigned int, Shape*);
 void FUN_00315ca0(unsigned int, Shape*);
 void FUN_003160f0(unsigned int, Shape*);
 void target(unsigned int, Shape*);
};
void Context::target(unsigned int arg, Shape* s) {
 if (!s->special) {
  float d=s->distance;
  Vec3* p=s->position();
  Vec3 v;
  v.x=d*s->direction.x+p->x;
  v.y=d*s->direction.y+p->y;
  v.z=d*s->direction.z+p->z;
  FUN_00317610(arg,s,&v,s->value);
  d=-s->distance;
  p=s->position();
  v.x=d*s->direction.x+p->x;
  v.y=d*s->direction.y+p->y;
  v.z=d*s->direction.z+p->z;
  FUN_00317610(arg,s,&v,s->value);
 } else {
  FUN_00315860(arg,s);
  if(a==b) FUN_00319270(arg,s);
 }
 if(a==b) FUN_00315ca0(arg,s);
 FUN_003160f0(arg,s);
}
