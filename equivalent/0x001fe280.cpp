// STATUS: equivalent (tools/equiv.py level 3: 201 inputs, branch coverage 14/14)
// FUN_001fe280 @ 0x001fe280
struct Vec { float x,y,z; };
struct Item {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual Vec* position(Vec*);
 char pad[60];
 const char* FUN_001fba60();
};
struct List { int count; Item* items; };
struct Lookup { void FUN_00026c30(Vec*, const char*); };
struct State { char pad[0x59c]; int key; };
struct Manager { State* FUN_000862a0(); };
struct Globals { char pad[0x20]; Lookup* lookup; char gap[0x30]; Manager* manager; };
extern Globals* DAT_004dd700;
extern "C" double __cdecl sqrt(double);
struct Target {
 char pad[0x20c]; List fallback; List* lists[6]; int* keys;
 int FUN_001fd390(int);
 const char* FUN_001fe280(int);
};
const char* Target::FUN_001fe280(int arg) {
 Vec origin; DAT_004dd700->lookup->FUN_00026c30(&origin,"hulk");
 int index=FUN_001fd390(arg);
 int count=0; Item* items=0;
 if(index<0) { count=fallback.count; items=fallback.items; }
 else { int key=DAT_004dd700->manager->FUN_000862a0()->key;
 for(int i=0;i<20;++i) if(keys[i]==key) { count=lists[index][i].count; items=lists[index][i].items; break; }
 }
 Item* selected=0;
 for(int n=0;n<count;++n) { Vec temp; Vec* p=items[n].position(&temp);
 double x=(double)origin.x-p->x, y=(double)origin.y-p->y, z=(double)origin.z-p->z;
 if(sqrt(z*z+y*y+x*x)<999999.0f) selected=&items[n];
 }
 if(selected) return selected->FUN_001fba60();
 return "none";
}