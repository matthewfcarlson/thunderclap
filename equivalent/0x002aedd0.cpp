// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 5/6, incomplete)
// FUN_002aedd0 @ 0x002aedd0
void* __cdecl FUN_00263ea0(unsigned int);
struct Resource_2aedd0 { virtual void slot0(); virtual void slot1(); Resource_2aedd0* FUN_00264430(void*, int, int); void FUN_00263fb0(); };
struct Link_2aedd0 { void FUN_0027b040(void*); };
struct Texture { char pad[8]; Link_2aedd0 link; };
namespace pure3d { struct TextureBuilder { virtual void slot0(); Texture* result; unsigned int f08,f0c,f10,f14,f18,f1c; unsigned int f20,f24,f28,f2c,f30; }; }
struct Loader_2aedd0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(Resource_2aedd0*, pure3d::TextureBuilder*); };
struct Owner_2aedd0 { char pad[0x8c]; unsigned int f8c,f90,f94,f98,f9c,fa0; Loader_2aedd0* FUN_002ae980(void*); Texture* target(void*); };
Texture* Owner_2aedd0::target(void* arg) {
 Resource_2aedd0* raw=(Resource_2aedd0*)FUN_00263ea0(0x48);
 Resource_2aedd0* resource=raw ? raw->FUN_00264430(arg,0,1) : 0;
 resource->slot0();
 Loader_2aedd0* loader=FUN_002ae980(arg);
 if (!loader) return 0;
 pure3d::TextureBuilder builder;
 builder.result=0; builder.f08=0; builder.f0c=0; builder.f10=0; builder.f14=0; builder.f18=0; builder.f1c=0;
 builder.f20=f94; builder.f24=f98; builder.f28=f9c; builder.f2c=fa0; builder.f30=f8c;
 resource->FUN_00263fb0();
 loader->v9(resource,&builder);
 Texture* result=builder.result;
 if(result) result->link.FUN_0027b040(arg);
 resource->slot1();
 return result;
}