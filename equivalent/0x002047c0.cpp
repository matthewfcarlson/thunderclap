// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002047c0 @ 0x002047c0
struct Resource { virtual void activate(); };
struct Helper { virtual void activate(); Helper* FUN_00266480(void*); };
extern void* __cdecl FUN_00266e00(int, int);
extern Resource* __cdecl FUN_0026cfa0(void*, int, int, const char*);
extern void __cdecl FUN_002670b0(int, int, Resource*);
extern int __cdecl FUN_00266da0(int);
extern void* __cdecl FUN_00263ea0(unsigned int);
struct Object {
 char prefix[5]; char name[33]; short id; short count; char pad[2]; void* context; Resource* resource; void* config; Helper* helper;
 void FUN_002047c0(const char* text, int identifier, int mode, int amount);
};
void Object::FUN_002047c0(const char* text, int identifier, int mode, int amount) {
 if(id != 0) return;
 id = (short)identifier;
 count = (short)amount;
 char* dest = name;
 do { *dest++ = *text; } while (*text++ != 0);
 if (!context) context = FUN_00266e00(amount, mode);
 resource = FUN_0026cfa0(context, mode, amount, name);
 resource->activate();
 FUN_002670b0(id, amount, resource);
 int old = FUN_00266da0(id);
 Helper* p = (Helper*)FUN_00263ea0(20);
 if(p) p = p->FUN_00266480(config);
 helper = p;
 helper->activate();
 FUN_00266da0(old);
}