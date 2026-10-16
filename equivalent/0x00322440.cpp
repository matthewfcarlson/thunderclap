// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// pure3d::d3dExtVertexProgram::vfunc_2 @ 0x00322440
#include "gen/pure3d.h"

struct VertexSource {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual unsigned int slot23();
 char padding[0x79];
 unsigned char temporary;
};
struct Device_322440 { void FUN_003290e0(unsigned int, unsigned int, unsigned int, unsigned int); };
struct Context_322440 { char padding[0x208]; Device_322440* device; };
namespace pure3d {

}
void pure3d::d3dExtVertexProgram::vfunc_2(int __p0, int __p1, int __p2, int __p3, int __p4) { VertexSource * source = (VertexSource *)__p0; unsigned int a = (unsigned int)__p1; unsigned int b = (unsigned int)__p2; unsigned int c = (unsigned int)__p3; unsigned char temporary = (unsigned char)__p4;

 if (temporary) source->temporary=1;
 unsigned int handle=source->slot23();
 (*(Context_322440 * *)&this->f_04)->device->FUN_003290e0(handle,a,b,c);
 if (temporary) source->temporary=0;
}
