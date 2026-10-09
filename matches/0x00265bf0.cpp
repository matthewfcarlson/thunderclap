extern "C" void Init(void*);
extern "C" void AddRef(void*);
extern "C" void Release(void*);
char gData[16];
struct Obj { char pad0[1]; unsigned char flag; char pad2[0x12]; void* m14; void* m18; void* m1c; char pad20[4]; char pad24[4]; void* m28; void* m2c; void* m30; };
void __fastcall Target(Obj* self) {
 self->flag=1;
 Init(&gData);
 void* p=self->m30;
 self->m28=p; self->m2c=p;
 if(p) AddRef(p);
 p=self->m1c;
 self->m14=p; self->m18=p;
 if(p) AddRef(p);
 Release(self);
}
