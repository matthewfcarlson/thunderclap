// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001dc550 @ 0x001dc550
struct Matrix {
 float m[16];
 void FUN_0022b980();
 void FUN_0022be40(const Matrix*);
 void FUN_0022bc20(float,float,float);
};
struct Vector { float x,y,z; void FUN_0022b220(float,float,float); };
struct Rotation_1dc550 { char data[8]; void FUN_001db780(const Vector*); };
struct Node { Matrix* FUN_001d6b40(); void FUN_001d6b60(Matrix,int); };
struct Record_1dc550 { char pad[16]; Rotation_1dc550 rotation; Node* node; char pad2[6]; short id; char pad3[4]; };
struct Flag_1dc550 { unsigned char bits; char pad[19]; };
struct Object {
 union {
  struct { char pad[0x608]; Record_1dc550 records[1]; } entries;
  struct { char pad[0x14618]; Flag_1dc550 flags[1]; } status;
 };
 int FUN_001dbfe0(int);
 bool target(int key,float x,float y,float z);
};
bool Object::target(int key,float x,float y,float z) {
 int index=FUN_001dbfe0(key);
 if(index<0) return false;
 Record_1dc550* record=&entries.records[index];
 if((status.flags[record->id].bits&1) && record->node) {
  Matrix transform;
  transform.FUN_0022b980();
  transform.FUN_0022be40(record->node->FUN_001d6b40());
  transform.FUN_0022bc20(x*0.0174533f,y*0.0174533f,z*0.0174533f);
  record->node->FUN_001d6b60(transform,0);
 } else {
  Vector angles;
  angles.FUN_0022b220(x*0.0174533f,y*0.0174533f,z*0.0174533f);
  record->rotation.FUN_001db780(&angles);
 }
 return true;
}
