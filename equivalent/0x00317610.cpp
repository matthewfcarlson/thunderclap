// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00317610 @ 0x00317610
struct Vec { float x,y,z; };
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual Vec* position(); virtual void slot5(); virtual int kind();
 char pad[0x44-4]; float nx,ny,nz,radius; char pad54[4]; unsigned char flag;
};
struct Controller {
 char pad0[0x10]; float margin; char pad14[0x35-0x14]; unsigned char flag;
 bool FUN_00313b70(void*,Vec*,Vec*,Vec*,float*,float,int);
 void FUN_00314be0(void*,Vec*,Object*,Vec*,float,Vec*);
 void target(void*,Object*,const Vec*,float);
};
void Controller::target(void* a,Object* obj,const Vec* input,float value) {
 Vec point=*input; Vec result,other;
 if (FUN_00313b70(a,&point,&result,&other,&value,value,1)) {
  bool skip=false;
  if(obj->kind()==2 && !flag && !obj->flag) {
   Vec* origin=obj->position();
   union {float f; unsigned int u;} dot;
   dot.f=(point.z-origin->z)*obj->nz+(point.y-origin->y)*obj->ny+(point.x-origin->x)*obj->nx;
   dot.u &= 0x7fffffff;
   skip=(obj->radius-margin)>dot.f;
  }
  if(!skip) FUN_00314be0(a,&result,obj,&point,value,&other);
 }
}