// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002dfe80 @ 0x002dfe80
struct Resource { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void* lock(); virtual void unlock(void*); char pad[12]; unsigned int value; };
struct Descriptor { unsigned int kind,width; unsigned char flags[8]; unsigned int count,resource; unsigned char a,b; unsigned short unused; unsigned int zero1,zero2; };
struct Manager { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual Resource* create(Descriptor*); }; extern Manager* DAT_0052c2a0;
struct Layout { char pad[64]; unsigned int f40,kind,width,count,index,f54; Resource* buffer; Resource* sourceResource; void FUN_002a5060(); };
struct Base { char pad[60]; unsigned int f40,kind,width,count,index,f54; Resource* buffer; Resource* sourceResource;
 Base(Layout* destination,Layout* source) { unsigned int w=source->width,n=source->count; destination->FUN_002a5060(); destination->kind=0; destination->f40=0; destination->width=w; destination->count=n; destination->index=~0u; }
};
namespace pure3d {
struct PrimGroupOptimized : Base { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void copy(void*); PrimGroupOptimized(PrimGroupOptimized* source); };
PrimGroupOptimized::PrimGroupOptimized(PrimGroupOptimized* source) : Base((Layout*)this,(Layout*)source) { buffer=0; kind=source->kind; Descriptor desc; desc.kind=kind; desc.width=width; for(int i=0;i<7;++i) desc.flags[i]=32; desc.count=count; desc.resource=source->sourceResource ? source->sourceResource->value : 0; desc.a=0; desc.b=0; desc.zero1=0; desc.zero2=0; buffer=DAT_0052c2a0->create(&desc); void* data=buffer->lock(); source->copy(data); buffer->unlock(data); buffer->s0(); }
}
