// STATUS: equivalent (tools/equiv.py level 3: 658 inputs, branch coverage 4/4)
// pure3d::TranslucentTraversal::vfunc_6 @ 0x002a1ca0
#include "gen/pure3d.h"

struct Vector3_2a1ca0 { float x,y,z; };
struct Vector4 { float x,y,z,w; };
struct ItemData_2a1ca0 { char pad[0x2c]; Vector4 vector; };
struct Item_2a1ca0 { ItemData_2a1ca0* data; char pad[12]; };
struct Collection_2a1ca0 { char pad[0x48]; Item_2a1ca0* begin; Item_2a1ca0* end; };
struct Object_2a1ca0 { char pad[0x40]; Collection_2a1ca0* collection; void* extra; void FUN_0022c2b0(Vector4*, Vector3_2a1ca0*); };
struct Entry_2a1ca0 { float depth; float result; Object_2a1ca0* object; Item_2a1ca0* item; Collection_2a1ca0* collection; void* extra; };
namespace pure3d {

}
void pure3d::TranslucentTraversal::vfunc_6(void* __p0, unsigned int index, float depth) { Object_2a1ca0 * object = (Object_2a1ca0 *)__p0;

 if (!object->collection) return;
 unsigned size = (unsigned)(object->collection->end - object->collection->begin);
 if (index >= size) return;
 (*(Entry_2a1ca0 ** *)&this->f_28)[(*(unsigned int *)&this->f_18)] = &(*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)];
 (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].depth = depth;
 (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].object = object;
 (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].item = object->collection->begin + index;
 (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].collection = object->collection;
 (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].extra = object->extra;
 Vector4 v = (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].item->data->vector;
 Vector3_2a1ca0 out;
 object->FUN_0022c2b0(&v, &out);
 (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].result = out.z;
 ++(*(unsigned int *)&this->f_18);
}
