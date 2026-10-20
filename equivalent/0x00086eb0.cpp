// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Function2<float,float,float>::vfunc_2 @ 0x00086eb0
#include "gen/global.h"

struct Function_86eb0 { virtual void vfunc_0(); virtual void vfunc_1(); };  
template <> void Function2<float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; const float * args = (const float *)__p1; float * result = (float *)__p2;
 float value = (*(float (**)(float, float))&this->f_1c)(args[0], args[1]); if (result) *result = value; }
