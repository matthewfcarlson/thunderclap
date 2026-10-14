// STATUS: equivalent (tools/equiv.py level 3: 658 inputs, branch coverage 4/4)
// pure3d::TranslucentTraversal::vfunc_6 @ 0x002a1ca0
struct Vector3_2a1ca0 { float x,y,z; };
struct Vector4 { float x,y,z,w; };
struct ItemData_2a1ca0 { char pad[0x2c]; Vector4 vector; };
struct Item_2a1ca0 { ItemData_2a1ca0* data; char pad[12]; };
struct Collection_2a1ca0 { char pad[0x48]; Item_2a1ca0* begin; Item_2a1ca0* end; };
struct Object { char pad[0x40]; Collection_2a1ca0* collection; void* extra; void FUN_0022c2b0(Vector4*, Vector3_2a1ca0*); };
struct Entry_2a1ca0 { float depth; float result; Object* object; Item_2a1ca0* item; Collection_2a1ca0* collection; void* extra; };
namespace pure3d {
struct TranslucentTraversal {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(Object*, unsigned, float);
 char pad[0x14]; unsigned count; Entry_2a1ca0* entries; char pad20[8]; Entry_2a1ca0** order;
};
void TranslucentTraversal::vfunc_6(Object* object, unsigned index, float depth) {
 if (!object->collection) return;
 unsigned size = (unsigned)(object->collection->end - object->collection->begin);
 if (index >= size) return;
 order[count] = &entries[count];
 entries[count].depth = depth;
 entries[count].object = object;
 entries[count].item = object->collection->begin + index;
 entries[count].collection = object->collection;
 entries[count].extra = object->extra;
 Vector4 v = entries[count].item->data->vector;
 Vector3_2a1ca0 out;
 object->FUN_0022c2b0(&v, &out);
 entries[count].result = out.z;
 ++count;
}
}