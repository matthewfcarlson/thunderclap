// STATUS: equivalent (tools/equiv.py level 3: 134 inputs, branch coverage 16/16)
// FUN_0010b1c0 @ 0x0010b1c0
struct Item;
struct Vector { float x,y,z; };
struct Collection_10b1c0 { char pad[12]; int count; Item* FUN_00024190(int index); bool FUN_00025d30(Item* item); };
struct Owner_10b1c0 { char pad[32]; Collection_10b1c0* collection; };
float __cdecl FUN_0010ac60(Item*, Item*, int, Vector*);
float __cdecl FUN_0010b1c0(Owner_10b1c0* owner, Item* subject, int flags, Vector* output)
{
 int count = owner->collection->count;
 float best = -1.0f;
 output->z = 0.0f; output->y = 0.0f; output->x = 0.0f;
 for(int i=0;i<count;++i) {
  Item* item=owner->collection->FUN_00024190(i);
  if(item && !owner->collection->FUN_00025d30(item) && item != subject) {
   Vector contribution;
   float value=FUN_0010ac60(subject,item,flags,&contribution);
   output->x = contribution.x + output->x;
   output->y = contribution.y + output->y;
   output->z = contribution.z + output->z;
   if(best < 0.0f || (value > 0.0f && value < best)) best=value;
  }
 }
 return best;
}