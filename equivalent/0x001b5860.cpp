// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001b5860 @ 0x001b5860
struct Vec { unsigned int x,y,z; void FUN_0022dfe0(const Vec*,const Vec*,const Vec*); };
extern Vec DAT_004e2160;
struct Face { char pad[16]; unsigned short a,b,c; unsigned short pad2; };
struct Mesh { char pad[8]; Vec* vertices; char pad2[12]; Face* faces; };
struct Object { char pad[68]; Mesh* mesh; };
struct Manager { Object** objects; Vec* FUN_001b5860(Vec* out,unsigned int id); };
Vec* Manager::FUN_001b5860(Vec* out,unsigned int id) {
 Object* obj=objects[id >> 16];
 const Vec *a=&DAT_004e2160,*b=&DAT_004e2160,*c=&DAT_004e2160;
 if(obj) { Mesh* m=obj->mesh; Face* f=&m->faces[id & 65535]; a=&m->vertices[f->a]; b=&m->vertices[f->b]; c=&m->vertices[f->c]; }
 Vec result; result.FUN_0022dfe0(a,b,c);
 out->x=result.x; out->y=result.y; out->z=result.z;
 return out;
}