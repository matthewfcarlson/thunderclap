// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002fdbd0 @ 0x002fdbd0
struct Vec { float x,y,z; };
struct Matrix { char pad[0x30]; Vec position; };
struct Node { Matrix* FUN_0030f100(); };
struct Owner { Node* FUN_0030edf0(); };
void __cdecl FUN_002ef760(Matrix*, Matrix*, float, void*, Vec*);
struct Object {
 Owner* owner;
 Vec base;
 Vec axis;
 unsigned char initialized;
 char pad[3];
 Matrix cached;
 char pad2[4];
 void* context;
 void FUN_002fdbd0(Vec* input, Vec* output);
};
void Object::FUN_002fdbd0(Vec* input, Vec* output) {
 if (!initialized) {
  void* c = context;
  initialized = 1;
  Matrix* m = owner->FUN_0030edf0()->FUN_0030f100();
  FUN_002ef760(&cached, m, 1.0f, c, &base);
 }
 Matrix* m = owner->FUN_0030edf0()->FUN_0030f100();
 double dx = (double)input->x - m->position.x;
 double dy = (double)input->y - m->position.y;
 double dz = (double)input->z - m->position.z;
 float y = (float)(dx * axis.z - dz * axis.x);
 float z = (float)(dy * axis.x - dx * axis.y);
 double x = dz * axis.y - dy * axis.z;
 output->y = y;
 output->z = z;
 output->x = (float)x;
 output->x = output->x + base.x;
 output->y = y + base.y;
 output->z = z + base.z;
}
