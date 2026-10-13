// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0007de00 @ 0x0007de00
typedef unsigned __int64 U64;
struct Vec3 { float x,y,z; };
struct Name { void FUN_0027b0e0(const char*); };
extern Name DAT_004dd068;
extern unsigned DAT_004dd070;
extern U64 __cdecl FUN_0027b020(const char*);
extern void __cdecl FUN_00363c40();
extern int __cdecl _atexit(void (__cdecl*)());
struct Loaded { void FUN_001dd8e0(int,int); };
struct Container { char pad[12]; Loaded* loaded; };
struct Factory { void FUN_00011330(int); };
extern Factory* __cdecl FUN_000964d0();
struct Object { virtual void slot0(); virtual void slot1(); Object* FUN_000831c0(const char*,int,int,Vec3*,Vec3*); };
extern Object* __cdecl FUN_00263ea0(unsigned);
struct Manager {
 char pad[0x3800]; Object* objects[11]; Container* container;
 int FUN_0007abe0(U64);
 int FUN_000796e0(Name*,const char*,Vec3*,Vec3*,int,int,int);
 void FUN_0007cc40(Object*);
 void target(const char*,int,Vec3,Vec3);
};
void Manager::target(const char* name,int unused,Vec3 a,Vec3 b) {
 int index=FUN_0007abe0(FUN_0027b020(name));
 if(index>=0 && objects[index]) return;
 if(!(DAT_004dd070 & 1)) { DAT_004dd070 |= 1; DAT_004dd068.FUN_0027b0e0("cow_male_cow_male"); _atexit(FUN_00363c40); }
 int id=FUN_000796e0(&DAT_004dd068,name,&a,&b,0,0,1);
 if(id==-1) return;
 container->loaded->FUN_001dd8e0(id,1);
 FUN_000964d0()->FUN_00011330(3);
 Object* obj=FUN_00263ea0(0x50);
 if(!obj) return;
 obj=obj->FUN_000831c0(name,id,0,&a,&b);
 if(!obj) return;
 obj->slot0(); FUN_0007cc40(obj); obj->slot1();
}
