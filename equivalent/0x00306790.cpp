// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00306790 @ 0x00306790
struct Vec { float x,y,z; };
struct Shape {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual Vec* position(); virtual void slot5(); virtual int type();
 char padding[0x24];
 float extentX,extentY,extentZ;
};
// equiv-conv: FUN_00306650 esi edi stack
bool FUN_00306650(Shape*, Shape*, float);
// equiv-conv: FUN_00306790 eax ebx stack
bool FUN_00306790(Shape* a, Shape* b, float margin) {
 if(a->type()==8) return FUN_00306650(a,b,margin);
 if(b->type()==8) return FUN_00306650(b,a,margin);
 Vec* pb=b->position(); Vec* pa=a->position();
 union { float f; unsigned int u; } delta;
 delta.f=pb->x-pa->x; delta.u &= 0x7fffffff;
 if (a->extentX+b->extentX+margin < delta.f) return false;
 pb=b->position(); pa=a->position();
 delta.f=pb->z-pa->z; delta.u &= 0x7fffffff;
 if (a->extentZ+b->extentZ+margin < delta.f) return false;
 pb=b->position(); pa=a->position();
 delta.f=pb->y-pa->y; delta.u &= 0x7fffffff;
 return !(a->extentY+b->extentY+margin < delta.f);
}