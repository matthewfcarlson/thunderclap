// STATUS: equivalent (tools/equiv.py level 3: 18764 inputs, branch coverage 4/4)
// FUN_00305800 @ 0x00305800
struct Vec_305800 { float x,y,z; };
struct Object { void FUN_0022c1b0(); };
void __cdecl FUN_00305520(Vec_305800*, Object*);
void __cdecl FUN_00305800(const Vec_305800* input, Object* object, float divisor) {
 union Bits { float f; unsigned int u; } x,y,z;
 x.f=input->x; y.f=input->y; z.f=input->z;
 x.u &= 0x7fffffff; y.u &= 0x7fffffff; z.u &= 0x7fffffff;
 int count=(int)(__int64)(((double)z.f+y.f+x.f)/divisor)+1;
 double scale=1.0f/(double)count;
 Vec_305800 step;
 step.x=(float)(input->x*scale);
 step.y=(float)(input->y*scale);
 step.z=(float)(input->z*scale);
 for(int i=0;i<count;++i) FUN_00305520(&step,object);
 object->FUN_0022c1b0();
}
