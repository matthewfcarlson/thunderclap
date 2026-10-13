// STATUS: equivalent (tools/equiv.py level 3: 658 inputs, branch coverage 4/4)
// pure3d::TranslucentTraversal::vfunc_6 @ 0x002a1ca0
struct Vector3 { float x,y,z; };
struct Vector4 { float x,y,z,w; };
struct ItemData { char pad[0x2c]; Vector4 vector; };
struct Item { ItemData* data; char pad[12]; };
struct Collection { char pad[0x48]; Item* begin; Item* end; };
struct Object { char pad[0x40]; Collection* collection; void* extra; void FUN_0022c2b0(Vector4*, Vector3*); };
struct Entry { float depth; float result; Object* object; Item* item; Collection* collection; void* extra; };
namespace pure3d {
struct TranslucentTraversal {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(Object*, unsigned, float);
 char pad[0x14]; unsigned count; Entry* entries; char pad20[8]; Entry** order;
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
 Vector3 out;
 object->FUN_0022c2b0(&v, &out);
 entries[count].result = out.z;
 ++count;
}
}