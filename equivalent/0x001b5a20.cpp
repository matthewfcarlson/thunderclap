// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001b5a20 @ 0x001b5a20
struct Vec3 { float x,y,z; };
extern Vec3 DAT_004e2160;
struct Triangle { char pad[16]; unsigned short a,b,c; char tail[2]; };
struct Mesh { char pad0[8]; Vec3* vertices; char pad1[12]; Triangle* triangles; };
struct Entry { char pad[68]; Mesh* mesh; };
struct Table { Entry** entries; Vec3* FUN_001b5a20(Vec3* output, unsigned int id); };
Vec3* Table::FUN_001b5a20(Vec3* output, unsigned int id) {
 Entry* entry = entries[id >> 16];
 Vec3 *a, *b, *c;
 if (entry) {
  Mesh* mesh=entry->mesh;
  Triangle* tri=&mesh->triangles[id & 65535];
  a=&mesh->vertices[tri->a]; b=&mesh->vertices[tri->b]; c=&mesh->vertices[tri->c];
 } else { a=b=c=&DAT_004e2160; }
 volatile float zpair=b->z+a->z;
 volatile float xsum=b->x+a->x+c->x;
 double ysum=(double)b->y+a->y+c->y;
 double zsum=(double)zpair+c->z;
 output->x=xsum*0.333333333333333333f;
 output->y=(float)(ysum*0.333333333333333333f);
 output->z=(float)(zsum*0.333333333333333333f);
 return output;
}