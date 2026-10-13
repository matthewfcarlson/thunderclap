// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 22/22)
// FUN_0001b280 @ 0x0001b280
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int type(); virtual void v7(); virtual void v8(); virtual void update(); virtual void notify();
 char pad[0x44]; float x,y,z,radius;
};
void __cdecl FUN_0001b170(Object*, Object**, float*, int*);
void __stdcall FUN_0001b280(Object* source, float factor) {
 Object* target=0; float limit=0; int axis=-1;
 FUN_0001b170(source,&target,&limit,&axis);
 if (!target) return;
 int type=target->type();
 if (type==2) {
 double value=(double)factor*target->radius;
 if (value>limit) value=limit;
 target->radius=(float)value;
 target->update();
 } else if(type==5 && axis>=0) {
 if(axis!=0) { double value=(double)factor*target->x; if(value>limit) value=limit; target->x=(float)value; }
 if(axis!=1) { double value=(double)factor*target->y; if(value>limit) value=limit; target->y=(float)value; }
 if(axis!=2) { double value=(double)factor*target->z; if(value>limit) value=limit; target->z=(float)value; }
 target->update();
 }
 source->notify();
}
