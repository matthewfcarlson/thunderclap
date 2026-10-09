typedef unsigned int U;
struct MetaTypeAttribBase { void *vptr; char pad[0x10]; U a; U b; MetaTypeAttribBase *init(void *, U, U); };
void __cdecl FUN_0025f450(void *, MetaTypeAttribBase *, U *);
MetaTypeAttribBase * MetaTypeAttribBase::init(void *p, U c, U d) {
 a=d; vptr=(void *)0x429420; b=c; d=c;
 FUN_0025f450((char *)p+0x14,this,&d); return this;
}