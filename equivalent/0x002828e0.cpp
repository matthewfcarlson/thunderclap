// STATUS: equivalent (tools/equiv.py level 3: 236 inputs, branch coverage 12/12)
// FUN_002828e0 @ 0x002828e0
struct Key_2828e0 { unsigned a,b; };
struct Triple_2828e0 { unsigned a,b,c; };
struct Resource_2828e0 { virtual void AddRef(); virtual void Release(); unsigned FUN_002843a0(unsigned a,unsigned b); };
struct Object {
 char pad[0x40]; Resource_2828e0* first; Resource_2828e0* second; int count; float invC,invA,invB; unsigned x,y,z; char gap[4]; unsigned zeroA,zeroB,result; unsigned* indices; Triple_2828e0* triples; unsigned finalA; float finalB,invFinal;
 void FUN_002828e0(unsigned a,float b,Resource_2828e0* r2,Resource_2828e0* r1,const Key_2828e0* keys,const Triple_2828e0* data,int n,const Key_2828e0* key,unsigned x0,unsigned y0,unsigned z0,float f1,float f2,float f3);
};
void Object::FUN_002828e0(unsigned a,float b,Resource_2828e0* r2,Resource_2828e0* r1,const Key_2828e0* keys,const Triple_2828e0* data,int n,const Key_2828e0* key,unsigned x0,unsigned y0,unsigned z0,float f1,float f2,float f3) {
 if(r1) r1->AddRef();
 if(first) first->Release();
 first=r1;
 if(r2) r2->AddRef();
 if(second) second->Release();
 second=r2;
 count=n;
 invB=1.0f/f3; invA=1.0f/f1; invC=1.0f/f2;
 x=x0; y=y0; z=z0;
 result=r2->FUN_002843a0(key->a,key->b);
 zeroA=0; zeroB=0;
 for(int i=0;i<n;++i) {
 indices[i]=r2->FUN_002843a0(keys[i].a,keys[i].b);
 triples[i].a=data[i].a; triples[i].b=data[i].b; triples[i].c=data[i].c;
 }
 finalA=a; finalB=b; invFinal=1.0f/b;
}
