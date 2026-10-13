// STATUS: equivalent (tools/equiv.py level 3: 287 inputs, branch coverage 119/144, incomplete)
// pure3d::OldCompositeDrawableLoader::vfunc_5 @ 0x0029a630
typedef unsigned __int64 UID;
inline void* operator new(unsigned int,void* p) { return p; }
struct Reader { void FUN_002647e0(void*,int,int,int); }; struct Chunk { char pad[0x284]; Reader* reader; bool FUN_002669f0(); int FUN_00266a30(); void FUN_00266be0(); };
namespace pure3d { class Geometry; class BillboardObject; class ParticleSystem; class Skeleton; class PolySkin; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; virtual void s0(); virtual void s1(); virtual void s2(); virtual void* find(void*,unsigned int,unsigned int); }; }
struct Name { void FUN_0027b040(char*); char bytes[0x38]; };
struct Object { virtual void add(); virtual void release(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void attach(Object*); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual int kind(); char pad[0x3c]; float visibility; void* owner; Object* FUN_0027b240(); };
struct Entry { int unused; int joint; Object* object; }; struct Group { virtual void add(); char p4[4]; unsigned char* starts; char pc[8]; unsigned char* counts; char p18[0x24]; Entry* entries; Group* FUN_00299cd0(int); void FUN_00298870(); };
namespace pure3d { struct CompositeDrawable { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void done(); char p4[4]; Name name; Object* skeleton; Group* group; int a,b,c; void FUN_002a3480(); }; struct OldCompositeDrawableLoader { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void vfunc_5(CompositeDrawable**,UID*,Chunk*,content::LoadInventory*); }; }
void* __cdecl FUN_00263ea0(int); void* __cdecl FUN_0008d690(int); void* __cdecl FUN_0008d6d0(int); void __cdecl FUN_0008d340(void*); UID __cdecl FUN_002672f0(char*,int,int); UID __cdecl FUN_0027b020(char*);
void pure3d::OldCompositeDrawableLoader::vfunc_5(CompositeDrawable** result,UID* uid,Chunk* chunk,content::LoadInventory* inventory) {
 struct Workspace {
 char unused[3]; unsigned char length; int geometryJoint; int remaining; float skinVisibility; Object** skins; char unused24[2]; unsigned char skinLength, geometryLength; int temporary; unsigned ng,ns; int* geometryJoints; unsigned nb; Object** geometries; int* particleJoints; Object** particles; int* billboardJoints; Object** billboards; unsigned np; CompositeDrawable* composite; char caster[4]; int skinCaster; int particleCount,skinCount; float particleVisibility; char fallback[4]; float geometryVisibility; int geometryCount,particleJoint,offset; int particleIgnored,skinIgnored,geometryIgnored; char name[128],skeleton[128]; } w;
 #define READ(p,n,s) chunk->reader->FUN_002647e0(p,n,s,1)
 READ(&w.length,1,1); int n=w.length; READ(w.name,n,1); w.name[n]=0; READ(&w.length,1,1); n=w.length; READ(w.skeleton,n,1); w.skeleton[n]=0;
 CompositeDrawable* composite=(CompositeDrawable*)FUN_00263ea0(0x58); if(composite) { composite->FUN_002a3480(); new(composite) CompositeDrawable; composite->skeleton=0; composite->group=0; composite->a=0; composite->b=0; composite->c=0; } w.composite=composite;
 composite->name.FUN_0027b040(w.name); *uid=FUN_002672f0(w.name,0,0);
 w.skins=0; w.geometries=0; w.particles=0; w.billboards=0; w.geometryJoints=0; w.particleJoints=0; w.billboardJoints=0; w.ns=0; w.ng=0; w.np=0; w.nb=0;
 while(chunk->FUN_002669f0()) {
 int type=chunk->FUN_00266a30();
 if(type==0x4513 || type==0x4514 || type==0x4517) {
 int* countAddress=type==0x4513?&w.skinCount:type==0x4514?&w.geometryCount:&w.particleCount; READ(countAddress,1,4); int count=*countAddress;
 if(type==0x4513) { if(!w.skins) w.skins=(Object**)FUN_0008d6d0(count*4); }
 if(type==0x4514) { if(!w.geometries) w.geometries=(Object**)FUN_0008d6d0(count*4); if(!w.billboards) w.billboards=(Object**)FUN_0008d6d0(count*4); if(!w.geometryJoints) w.geometryJoints=(int*)FUN_0008d6d0(count*4); if(!w.billboardJoints) w.billboardJoints=(int*)FUN_0008d6d0(count*4); }
 if(type==0x4517) { if(!w.particles) w.particles=(Object**)FUN_0008d6d0(count*4); if(!w.particleJoints) w.particleJoints=(int*)FUN_0008d6d0(count*4); }
 if(count>0) { int* remaining=type==0x4514?&w.temporary:&w.remaining; *remaining=count;
 do {
 if(chunk->FUN_002669f0()) {
 unsigned int si=w.ns,gi=w.ng,bi=w.nb,pi=w.np;
 if(type==0x4517) w.temporary=(char*)w.particleJoints-(char*)w.particles;
 if(type==0x4514) { w.remaining=(int)(w.billboardJoints+bi); w.offset=(char*)w.billboards-(char*)w.billboardJoints; w.skinCaster=(char*)w.geometries-(char*)w.geometryJoints; }
 do {
 int child=chunk->FUN_00266a30();
 if(child==(type==0x4513?0x4515:type==0x4514?0x4516:0x4518)) {
 unsigned char* lengthAddress=type==0x4513?&w.skinLength:type==0x4514?&w.geometryLength:&w.length; READ(lengthAddress,1,1); n=*lengthAddress; READ(w.name,n,1); w.name[n]=0;
 int* ignoredAddress=type==0x4513?&w.skinIgnored:type==0x4514?&w.geometryIgnored:&w.particleIgnored; READ(ignoredAddress,1,4);
 int* jointAddress=type==0x4514?&w.geometryJoint:&w.particleJoint; if(type!=0x4513) READ(jointAddress,1,4);
 Object* object; UID id;
 if(type==0x4513) { id=FUN_0027b020(w.name); void* caster=new(&w.skinCaster) content::LoadInventory::DynamicCaster<PolySkin>; object=(Object*)inventory->find(caster,(unsigned)id,(unsigned)(id>>32)); w.skins[si]=object; }
 else if(type==0x4517) { w.particleJoints[pi]=w.particleJoint; id=FUN_0027b020(w.name); void* caster=new(w.caster) content::LoadInventory::DynamicCaster<ParticleSystem>; object=(Object*)inventory->find(caster,(unsigned)id,(unsigned)(id>>32)); w.particles[pi]=object; }
 else { id=FUN_0027b020(w.name); void* caster=new(w.caster) content::LoadInventory::DynamicCaster<Geometry>; object=(Object*)inventory->find(caster,(unsigned)id,(unsigned)(id>>32)); if(!object) { id=FUN_0027b020(w.name); void* fallback=new(w.fallback) content::LoadInventory::DynamicCaster<BillboardObject>; object=(Object*)inventory->find(fallback,(unsigned)id,(unsigned)(id>>32)); } }
 if(object) {
 if(type==0x4514) { int k=object->kind(); if(k==1) { w.geometries[gi]=object; w.geometryJoints[gi++]=w.geometryJoint; ++w.ng; } else if(k==8) { w.billboards[bi]=object; w.billboardJoints[bi++]=w.geometryJoint; ++w.nb; w.remaining+=4; } }
 while(chunk->FUN_002669f0()) { if(chunk->FUN_00266a30()==0x4519) { float* visibilityAddress=type==0x4513?&w.skinVisibility:type==0x4514?&w.geometryVisibility:&w.particleVisibility; READ(visibilityAddress,1,4); float visibility=*visibilityAddress; if(!(visibility>=0.0f && visibility<=1.0f)) visibility=visibility>1.0f?1.0f:0.0f; if(type==0x4513) w.skins[si]->visibility=visibility; else if(type==0x4517) w.particles[pi]->visibility=visibility; else object->visibility=visibility; } chunk->FUN_00266be0(); }
 if(type==0x4513) { ++w.ns; ++si; } else if(type==0x4517) { ++w.np; ++pi; }
 }
 }
 chunk->FUN_00266be0();
 } while(chunk->FUN_002669f0());
 }
 } while(--*remaining);
 }
 }
 chunk->FUN_00266be0();
 }
 unsigned int total=w.ng+w.ns+w.np+w.nb; w.geometryJoint=0;
 UID id=FUN_0027b020(w.skeleton); void* caster=new(&w.skinVisibility) content::LoadInventory::DynamicCaster<Skeleton>; Object* skeleton=(Object*)inventory->find(caster,(unsigned)id,(unsigned)(id>>32));
 if(skeleton) { Object* replacement=skeleton->FUN_0027b240(); if(replacement) replacement->add(); if(composite->skeleton) composite->skeleton->release(); composite->skeleton=replacement; }
 Group* group=(Group*)FUN_0008d690(0x48); if(group) group=group->FUN_00299cd0(total); composite->group=group; group->add();
 unsigned int index=0;
 for(int category=0;category<4;++category) {
 unsigned int count=category==0?w.ng:category==1?w.ns:category==2?w.np:w.nb;
 composite->group->starts[category]=(unsigned char)index; composite->group->counts[category]=(unsigned char)count;
 Object** objects=category==0?w.geometries:category==1?w.skins:category==2?w.particles:w.billboards; int* joints=category==0?w.geometryJoints:category==2?w.particleJoints:w.billboardJoints;
 for(unsigned int i=0;i<count;++i) {
 if(category!=1) composite->group->entries[(unsigned char)index].joint=joints[i];
 Object** slot=&composite->group->entries[(unsigned char)index].object; Object* value=objects[i]; if(value) value->add(); if(*slot) (*slot)->release(); *slot=value;
 if(category==1) objects[i]->attach(composite->skeleton); objects[i]->owner=composite; ++index;
 }
 }
 composite->group->FUN_00298870(); composite->done(); FUN_0008d340(w.skins); FUN_0008d340(w.geometries); FUN_0008d340(w.particles); FUN_0008d340(w.billboards); FUN_0008d340(w.geometryJoints); FUN_0008d340(w.particleJoints); FUN_0008d340(w.billboardJoints); *result=composite;
}