// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001b3040 @ 0x001b3040
#include "decls/data/game/global.h"

struct Matrix { float data[12]; unsigned int x,y,z; float last; void FUN_0022b980(); };
struct String { unsigned int value[2]; void FUN_0027b0e0(const char*); void FUN_0027af50(); };
struct Manager_1b3040 { unsigned int FUN_00283a40(String*, Matrix*, float, float); };
Manager_1b3040* __cdecl FUN_0027f250();
struct Entry_1b3040 { char first[64]; char second[64]; char reserved[48]; unsigned int value; };
struct Object { unsigned int x,y,z; int index; char pad10[8]; unsigned int value; unsigned int a; unsigned int untouched20; unsigned int b; unsigned int firstHandle,secondHandle,c,d;
void initialize(unsigned int,unsigned int,unsigned int,int);
};
void Object::initialize(unsigned int px,unsigned int py,unsigned int pz,int kind) {
 if(kind<0 || kind>=13) return;
 index=kind; value=((Entry_1b3040*)&DAT_004e1830)[kind].value; c=0; x=px;y=py;z=pz;a=0;b=0;d=0;firstHandle=0x10000;
 if(((Entry_1b3040*)&DAT_004e1830)[kind].first[0]) { Matrix m; m.FUN_0022b980(); m.x=x;m.y=y;m.z=z; String s; s.FUN_0027b0e0(((Entry_1b3040*)&DAT_004e1830)[kind].first); Manager_1b3040* manager=FUN_0027f250(); firstHandle=manager->FUN_00283a40(&s,&m,-1.0f,1.0f); s.FUN_0027af50(); }
 secondHandle=0x10000;
 if(((Entry_1b3040*)&DAT_004e1830)[kind].second[0]) { Matrix m; m.FUN_0022b980(); m.x=x;m.y=y;m.z=z; String s; s.FUN_0027b0e0(((Entry_1b3040*)&DAT_004e1830)[kind].second); Manager_1b3040* manager=FUN_0027f250(); secondHandle=manager->FUN_00283a40(&s,&m,-1.0f,1.0f); s.FUN_0027af50(); }
}
