// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_00280380 @ 0x00280380
struct Resource_280380 {
 virtual void AddRef();
 virtual void Release();
 unsigned FUN_002843a0(unsigned a, unsigned b);
};
struct Key_280380 { unsigned a,b; };
struct Matrix { unsigned words[16]; };
struct Slot_280380 {
 unsigned id;
 unsigned char flag;
 char pad[3];
 Matrix matrix;
 Resource_280380* first;
 Resource_280380* second;
 unsigned value1,value2,index,extra;
};
struct Manager_280380 {
 char pad[16];
 unsigned nextId;
 char pad2[4];
 Slot_280380 slots[100];
 unsigned FUN_00280380(Resource_280380* first, Resource_280380* second, const Key_280380* key, const Matrix* matrix, unsigned extra);
};
unsigned Manager_280380::FUN_00280380(Resource_280380* first, Resource_280380* second, const Key_280380* key, const Matrix* matrix, unsigned extra) {
 int i;
 for(i=0;i<100;++i) if(!slots[i].first) break;
 if(i==100) return 0;
 Slot_280380& s=slots[i];
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
