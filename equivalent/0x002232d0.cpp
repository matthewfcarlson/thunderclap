// STATUS: equivalent (tools/equiv.py level 3: 44 inputs, branch coverage 12/12)
// FUN_002232d0 @ 0x002232d0
struct Ref_2232d0 {
 virtual void AddRef();
 virtual void Release();
 virtual void Slot2();
 virtual void Slot3();
 virtual void Slot4();
 virtual Ref_2232d0* Clone();
};
struct BasePart_2232d0 { char data[0x54]; void FUN_00221be0(BasePart_2232d0*); };
struct Entry_2232d0 { Ref_2232d0* object; unsigned value; unsigned char flag; char pad[3]; unsigned a,b,c,d,e,f,g; };
struct Puppet_2232d0 {
 char prefix[0x10]; BasePart_2232d0 base; Ref_2232d0* ref; unsigned count; Entry_2232d0 entries[1];
 Puppet_2232d0* assign(Puppet_2232d0* source);
};
Puppet_2232d0* Puppet_2232d0::assign(Puppet_2232d0* source) {
 base.FUN_00221be0(&source->base);
 Ref_2232d0* incoming=source->ref;
 if(incoming) incoming->AddRef();
 if(ref) ref->Release();
 ref=incoming;
 int last=(int)(count-1);
 if(last>=0) {
 Entry_2232d0* current=&entries[last];
 unsigned remaining=(unsigned)last+1;
 do { current->object->Release(); --current; } while(--remaining);
 }
 count=0;
 count=source->count;
 for(unsigned i=0;i<count;++i) {
 Entry_2232d0* from=&source->entries[i];
 Entry_2232d0* to=&entries[i];
 Ref_2232d0* cloned=from->object->Clone();
 to->object=cloned;
 cloned->AddRef();
 to->value=from->value;
 to->flag=from->flag;
 to->a=from->a;
 to->b=from->b;
 to->c=from->c;
 to->d=from->d;
 to->e=from->e;
 to->f=from->f;
 to->g=from->g;
 }
 return this;
}