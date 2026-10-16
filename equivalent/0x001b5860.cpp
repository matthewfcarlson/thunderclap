// STATUS: equivalent (tools/equiv.py level 3: 19999 inputs, branch coverage 6/6)
// FUN_001b5860 @ 0x001b5860
struct Vec_1b5860 { unsigned int x,y,z; };
// FUN_0022dfe0 builds a plane (normal + distance, 16 bytes) from three points.
struct Plane_1b5860 { Vec_1b5860 n; unsigned int d; void FUN_0022dfe0(const Vec_1b5860*,const Vec_1b5860*,const Vec_1b5860*); };
extern Vec_1b5860 DAT_004e2160;
struct Face_1b5860 { char pad[16]; unsigned short a,b,c; unsigned short pad2; };
struct Mesh_1b5860 { char pad[8]; Vec_1b5860* vertices; char pad2[12]; Face_1b5860* faces; };
struct Object { char pad[68]; Mesh_1b5860* mesh; };
struct Manager_1b5860 { Object** objects; Vec_1b5860* FUN_001b5860(Vec_1b5860* out,unsigned int id); };
Vec_1b5860* Manager_1b5860::FUN_001b5860(Vec_1b5860* out,unsigned int id) {
 Object* obj=objects[id >> 16];
 const Vec_1b5860 *a=&DAT_004e2160,*b=&DAT_004e2160,*c=&DAT_004e2160;
 if(obj) { Mesh_1b5860* m=obj->mesh; Face_1b5860* f=&m->faces[id & 65535]; a=&m->vertices[f->a]; b=&m->vertices[f->b]; c=&m->vertices[f->c]; }
 Plane_1b5860 plane; plane.FUN_0022dfe0(a,b,c);
 out->x=plane.n.x; out->y=plane.n.y; out->z=plane.n.z;
 return out;
}