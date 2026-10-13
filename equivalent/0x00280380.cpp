// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_00280380 @ 0x00280380
struct Resource {
 virtual void AddRef();
 virtual void Release();
 unsigned FUN_002843a0(unsigned a, unsigned b);
};
struct Key { unsigned a,b; };
struct Matrix { unsigned words[16]; };
struct Slot {
 unsigned id;
 unsigned char flag;
 char pad[3];
 Matrix matrix;
 Resource* first;
 Resource* second;
 unsigned value1,value2,index,extra;
};
struct Manager {
 char pad[16];
 unsigned nextId;
 char pad2[4];
 Slot slots[100];
 unsigned FUN_00280380(Resource* first, Resource* second, const Key* key, const Matrix* matrix, unsigned extra);
};
unsigned Manager::FUN_00280380(Resource* first, Resource* second, const Key* key, const Matrix* matrix, unsigned extra) {
 int i;
 for(i=0;i<100;++i) if(!slots[i].first) break;
 if(i==100) return 0;
 Slot& s=slots[i];
 unsigned id=nextId;
 s.id=id;
 s.matrix=*matrix;
 if(first) first->AddRef();
 if(s.first) s.first->Release();
 s.first=first;
 if(second) second->AddRef();
 if(s.second) s.second->Release();
 s.second=second;
 s.index=65535;
 if(second) {
 if(key) s.index=second->FUN_002843a0(key->a,key->b);
 if(!key || s.index==65535) s.index=0;
 }
 s.value1=0;
 s.value2=0;
 s.flag=0;
 s.extra=extra;
 ++nextId;
 return id;
}
