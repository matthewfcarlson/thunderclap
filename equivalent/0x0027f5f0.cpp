// STATUS: equivalent (tools/equiv.py level 3: 188 inputs, branch coverage 6/6)
// FUN_0027f5f0 @ 0x0027f5f0
struct Vec3_27f5f0 { float x,y,z; };
struct Vertex_27f5f0 { Vec3_27f5f0 position; Vec3_27f5f0 normal; };
struct Geometry {
 Vec3_27f5f0* FUN_001b5860(Vec3_27f5f0* result, int index);
 Vec3_27f5f0* FUN_001b56a0(int index, int corner);
};
struct Context { char pad[0x594]; Geometry geometry; };
extern Context* __cdecl FUN_001b6580();
void __cdecl FUN_0027f5f0(int unused, int count, const int* indices, Vertex_27f5f0* vertices) {
 Geometry* geometry = &FUN_001b6580()->geometry;
 for (int i=0; i<count; ++i) {
  Vec3_27f5f0 temporary;
  Vec3_27f5f0 normal = *geometry->FUN_001b5860(&temporary, indices[i]);
  Vec3_27f5f0 offset;
  offset.x = normal.x * 0.03f;
  offset.y = normal.y * 0.03f;
  offset.z = normal.z * 0.03f;
  for (int j=0; j<3; ++j, ++vertices) {
   vertices->normal = normal;
   Vec3_27f5f0* position = geometry->FUN_001b56a0(indices[i], j);
   vertices->position.x = offset.x + position->x;
   vertices->position.y = offset.y + position->y;
   vertices->position.z = offset.z + position->z;
  }
 }
}