// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001b5a20 @ 0x001b5a20
#include "decls/data/game/global.h"

struct Vec3_1b5a20 { float x,y,z; };
struct Triangle_1b5a20 { char pad[16]; unsigned short a,b,c; char tail[2]; };
struct Mesh_1b5a20 { char pad0[8]; Vec3_1b5a20* vertices; char pad1[12]; Triangle_1b5a20* triangles; };
struct Entry_1b5a20 { char pad[68]; Mesh_1b5a20* mesh; };
struct Table_1b5a20 { Entry_1b5a20** entries; Vec3_1b5a20* FUN_001b5a20(Vec3_1b5a20* output, unsigned int id); };
Vec3_1b5a20* Table_1b5a20::FUN_001b5a20(Vec3_1b5a20* output, unsigned int id) {
 Entry_1b5a20* entry = entries[id >> 16];
 Vec3_1b5a20 *a, *b, *c;
 if (entry) {
  Mesh_1b5a20* mesh=entry->mesh;
  Triangle_1b5a20* tri=&mesh->triangles[id & 65535];
  a=&mesh->vertices[tri->a]; b=&mesh->vertices[tri->b]; c=&mesh->vertices[tri->c];
 } else { a=b=c=((Vec3_1b5a20*)((char*)&DAT_004e215c + 4)); }
 volatile float zpair=b->z+a->z;
 volatile float xsum=b->x+a->x+c->x;
 double ysum=(double)b->y+a->y+c->y;
 double zsum=(double)zpair+c->z;
 output->x=xsum*0.333333333333333333f;
 output->y=(float)(ysum*0.333333333333333333f);
 output->z=(float)(zsum*0.333333333333333333f);
 return output;
}