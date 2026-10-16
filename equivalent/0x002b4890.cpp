// STATUS: equivalent (tools/equiv.py level 3: 93 inputs, branch coverage 4/4)
// FUN_002b4890 @ 0x002b4890
#include "decls/address.h"
struct Vertex_2b4890 { unsigned int x; float y,z; };
struct Triangle_2b4890 { unsigned short index[3]; char pad[6]; };
struct Indices { char pad[12]; unsigned int count; Triangle_2b4890* triangles; };
struct Positions { char pad[16]; Vertex_2b4890* vertices; };
struct Stream { char pad[8]; Vertex_2b4890* position; char pad2[4]; unsigned int* color; void FUN_0008ef00(); };
struct Gfx {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual Stream* v30(int,int,int,unsigned int,int); virtual void v31(Stream*);
};
struct Object { char pad[68]; Indices* indices; Positions* positions; void FUN_002b4890(); };
void Object::FUN_002b4890() {
 Indices* mesh=indices;
 Vertex_2b4890* vertices=positions->vertices;
 unsigned int count=mesh->count;
 Triangle_2b4890* tri=mesh->triangles;
 Stream* stream=DAT_0052c2a8->v30(0,0,0x2020,count*3,0);
 for(unsigned int i=0;i<count;++i,++tri) {
  for(int j=0;j<3;++j) {
   *stream->color=0xff0000ff;
   Vertex_2b4890* src=&vertices[tri->index[j]];
   unsigned int x=src->x;
   float z=src->z;
   float y=src->y;
   stream->position->x=x;
   stream->position->y=y;
   stream->position->z=z;
   stream->FUN_0008ef00();
  }
 }
 DAT_0052c2a8->v31(stream);
}
