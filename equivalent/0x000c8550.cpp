// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000c8550 @ 0x000c8550
struct Vector { float x,y,z; };
struct Key { unsigned a,b; };
struct Position { void FUN_00059a50(Vector* out); };
struct Found { char pad[16]; Position* position; };
struct Lookup { Found* FUN_00024280(unsigned a,unsigned b); };
struct Manager { bool FUN_001dd7b0(Key* key); bool FUN_001dd5d0(Key* key, Vector* out); int FUN_001e3410(Key* key); };
struct Global { char pad0[12]; Manager* manager; char pad1[16]; Lookup* lookup; };
extern Global* DAT_004dd700;
struct Entry { unsigned unused; Vector position; char pad[24]; Key key; int type; char tail[12]; };
struct Object { char pad[0x258]; Entry entries[1]; bool FUN_000c8550(unsigned index,Vector* out); };
bool Object::FUN_000c8550(unsigned index,Vector* out) {
 Entry& e=entries[index];
 if(e.type==2) { out->x=e.position.x; out->y=e.position.y; out->z=e.position.z; return true; }
 if(e.type==0) { Found* f=DAT_004dd700->lookup->FUN_00024280(e.key.a,e.key.b); if(!f)return false; f->position->FUN_00059a50(out); return true; }
 if(e.type==1) { Manager* m=DAT_004dd700->manager; Key* k=&e.key; Vector temp; if(!m->FUN_001dd7b0(k))return false; if(!m->FUN_001dd5d0(k,&temp))return false; if(m->FUN_001e3410(k)<=0)return false; out->x=temp.x; out->y=temp.y; out->z=temp.z; return true; }
 return false;
}