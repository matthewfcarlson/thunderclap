// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000b1aa0 @ 0x000b1aa0
struct Resource { virtual void AddRef(); };
struct Manager { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual Resource* Find(const char*); };
extern Manager* __cdecl FUN_002684b0();
extern void __cdecl FUN_000b0a50(Resource*, int, int, void*, void*, void*, void*, void*, void*);
struct Object {
 char pad0[12]; unsigned char dirty; char padD[3]; Resource* resource; char name[252];
 char a110[0x58]; char a168[0x128]; char a290[0x68]; char a2f8[0x60]; char a358[0x2c]; char a384[0x60]; char a3e4[0x34]; char a418[0x60]; char a478[8]; char a480[8]; char a488[4]; char a48c[4];
 void FUN_000b0db0(); void Update();
};
void Object::Update() {
 if (dirty) { FUN_000b0db0(); dirty=0; }
 Manager* manager=FUN_002684b0();
 if (!manager) return;
 Resource* found=0;
 if (name[0]!=0) found=manager->Find(name);
 if (!found) { FUN_000b0db0(); return; }
 if (found==resource) return;
 if (resource) FUN_000b0db0();
 resource=found;
 found->AddRef();
 FUN_000b0a50(resource,11,2,a110,a168,a480,a358,a384,a48c);
 FUN_000b0a50(resource,13,2,a290,a2f8,a478,a3e4,a418,a488);
}