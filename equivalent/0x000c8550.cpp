// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000c8550 @ 0x000c8550
struct Vector { float x,y,z; };
struct Key_c8550 { unsigned a,b; };
struct Position_c8550 { void FUN_00059a50(Vector* out); };
struct Found_c8550 { char pad[16]; Position_c8550* position; };
struct Lookup_c8550 { Found_c8550* FUN_00024280(unsigned a,unsigned b); };
struct Manager_c8550 { bool FUN_001dd7b0(Key_c8550* key); bool FUN_001dd5d0(Key_c8550* key, Vector* out); int FUN_001e3410(Key_c8550* key); };
struct Global_c8550 { char pad0[12]; Manager_c8550* manager; char pad1[16]; Lookup_c8550* lookup; };
extern Global_c8550* DAT_004dd700;
struct Entry_c8550 { unsigned unused; Vector position; char pad[24]; Key_c8550 key; int type; char tail[12]; };
struct Object { char pad[0x258]; Entry_c8550 entries[1]; bool FUN_000c8550(unsigned index,Vector* out); };
bool Object::FUN_000c8550(unsigned index,Vector* out) {
 Entry_c8550& e=entries[index];
 if(e.type==2) { out->x=e.position.x; out->y=e.position.y; out->z=e.position.z; return true; }
 if(e.type==0) { Found_c8550* f=DAT_004dd700->lookup->FUN_00024280(e.key.a,e.key.b); if(!f)return false; f->position->FUN_00059a50(out); return true; }
 if(e.type==1) { Manager_c8550* m=DAT_004dd700->manager; Key_c8550* k=&e.key; Vector temp; if(!m->FUN_001dd7b0(k))return false; if(!m->FUN_001dd5d0(k,&temp))return false; if(m->FUN_001e3410(k)<=0)return false; out->x=temp.x; out->y=temp.y; out->z=temp.z; return true; }
 return false;
}