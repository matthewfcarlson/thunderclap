// STATUS: equivalent (tools/equiv.py level 3: 44 inputs, branch coverage 12/12)
// FUN_002232d0 @ 0x002232d0
struct Ref {
 virtual void AddRef();
 virtual void Release();
 virtual void Slot2();
 virtual void Slot3();
 virtual void Slot4();
 virtual Ref* Clone();
};
struct BasePart { char data[0x54]; void FUN_00221be0(BasePart*); };
struct Entry { Ref* object; unsigned value; unsigned char flag; char pad[3]; unsigned a,b,c,d,e,f,g; };
struct Container {
 char prefix[0x10]; BasePart base; Ref* ref; unsigned count; Entry entries[1];
 Container* assign(Container* source);
};
Container* Container::assign(Container* source) {
 base.FUN_00221be0(&source->base);
 Ref* incoming=source->ref;
 if(incoming) incoming->AddRef();
 if(ref) ref->Release();
 ref=incoming;
 int last=(int)(count-1);
 if(last>=0) {
 Entry* current=&entries[last];
 unsigned remaining=(unsigned)last+1;
 do { current->object->Release(); --current; } while(--remaining);
 }
 count=0;
 count=source->count;
 for(unsigned i=0;i<count;++i) {
 Entry* from=&source->entries[i];
 Entry* to=&entries[i];
 Ref* cloned=from->object->Clone();
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