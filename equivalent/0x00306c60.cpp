// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 21/22, incomplete)
// FUN_00306c60 @ 0x00306c60
void* __cdecl FUN_0008d690(unsigned int size);
struct CollisionSphere_306c60 { CollisionSphere_306c60* FUN_00306c00(); };
struct CollisionCylinder_306c60 { CollisionCylinder_306c60* FUN_00306b40(); };
struct CollisionOBB_306c60 { CollisionOBB_306c60* FUN_00306ba0(); };
struct CollisionWall_306c60 { CollisionWall_306c60* FUN_0030e700(); };
struct CollisionAABB_306c60 { CollisionAABB_306c60* FUN_00312900(); };
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual unsigned int type();
 virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13();
 virtual void attach(void* copy);
 void* clone();
};
void* Object::clone() {
 void* result = 0;
 void* memory;
 switch (type()) {
 case 1:
  memory = FUN_0008d690(0x44);
  if (memory) result = ((CollisionAABB_306c60*)memory)->FUN_00312900();
  break;
 case 2:
  memory = FUN_0008d690(0x8c);
  if (memory) result = ((CollisionCylinder_306c60*)memory)->FUN_00306b40();
  break;
 case 5:
  memory = FUN_0008d690(0xbc);
  if (memory) result = ((CollisionOBB_306c60*)memory)->FUN_00306ba0();
  break;
 case 7:
  memory = FUN_0008d690(0x48);
  if (memory) result = ((CollisionSphere_306c60*)memory)->FUN_00306c00();
  break;
 case 8:
  memory = FUN_0008d690(0x60);
  if (memory) result = ((CollisionWall_306c60*)memory)->FUN_0030e700();
  break;
 }
 if (result) attach(result);
 return result;
}