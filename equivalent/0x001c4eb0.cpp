// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001c4eb0 @ 0x001c4eb0
struct Resource_1c4eb0 {
 virtual void AddRef(); virtual void Release();
 virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
 virtual Resource_1c4eb0* GetResource();
 char padding[0x28]; unsigned int values[4];
};
struct Handle_1c4eb0 { char data[8]; void FUN_0027af30(void*); };
struct Matrix { char data[0x40]; void FUN_0022b980(); };
extern unsigned int DAT_004e234c;
namespace Render {
struct Object {
 virtual void slot0();
 unsigned int field4; Handle_1c4eb0 handle;
 Resource_1c4eb0* primary; unsigned int field14; Resource_1c4eb0* secondary; unsigned int field1c;
 unsigned char flags[4]; char padding24[12]; Matrix matrix;
 unsigned int values[4]; unsigned int field80, field84, field88;
 unsigned char field8c; char padding8d[3]; unsigned int field90, field94, field98;
 char padding9c[4]; unsigned int fielda0, fielda4;
 unsigned char fielda8, fielda9; char paddingaa[2]; unsigned int id;
 Object(void* arg, Resource_1c4eb0* source);
};
Object::Object(void* arg, Resource_1c4eb0* source) {
 field4=0; handle.FUN_0027af30(arg);
 primary=0; secondary=0;
 flags[0]=0; flags[1]=0; flags[2]=0; flags[3]=0;
 field80=0; field84=0; field88=0; field8c=0;
 field90=0; field94=0; field98=0; fielda0=0; fielda4=0;
 fielda8=1; fielda9=0; id=0;
 matrix.FUN_0022b980();
 volatile bool present=source!=0;
 values[0]=source->values[0]; values[1]=source->values[1]; values[2]=source->values[2]; values[3]=source->values[3];
 field1c=0; field14=0; secondary=0; primary=0;
 if(present) {
 source->AddRef();
 if(primary) primary->Release();
 primary=source;
 Resource_1c4eb0* other=source->GetResource();
 if(other) other->AddRef();
 if(secondary) secondary->Release();
 secondary=other;
 }
 unsigned int next=DAT_004e234c;
 id=next;
 DAT_004e234c=next+1;
}
}
