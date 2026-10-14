// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// pure3d::d3dExtVertexProgram::vfunc_2 @ 0x00322440
struct VertexSource {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual unsigned int slot23();
 char padding[0x79];
 unsigned char temporary;
};
struct Device_322440 { void FUN_003290e0(unsigned int, unsigned int, unsigned int, unsigned int); };
struct Context { char padding[0x208]; Device_322440* device; };
namespace pure3d {
struct d3dExtVertexProgram {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(VertexSource*,unsigned int,unsigned int,unsigned int,unsigned char); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
 Context* context;
};
void d3dExtVertexProgram::vfunc_2(VertexSource* source,unsigned int a,unsigned int b,unsigned int c,unsigned char temporary) {
 if (temporary) source->temporary=1;
 unsigned int handle=source->slot23();
 context->device->FUN_003290e0(handle,a,b,c);
 if (temporary) source->temporary=0;
}
}
