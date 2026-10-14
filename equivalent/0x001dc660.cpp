// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dc660 @ 0x001dc660
struct Vec { unsigned int x,y,z; };
struct Transform {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void apply(void*, Vec*, int);
};
struct Node {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void update(int);
 char pad4[12]; Transform* transform; char pad14[132]; unsigned char data[1];
};
struct Result { char pad[112]; Node* node; };
struct Handle { Result* FUN_001d72e0(); Vec* FUN_001d77c0(); };
struct Record { char pad0[24]; Handle* handle; char pad1[6]; short index; char pad2[4]; };
struct Flag { unsigned char bits; char pad[19]; };
struct Owner {
 union { struct { char pad[0x608]; Record records[4096]; } entries; Flag flags[65536]; };
 int FUN_001dbfe0(int);
 Vec* target(Vec*, int);
};
Vec* Owner::target(Vec* out, int id) {
 Vec value; value.x=0; value.y=0; value.z=0;
 int i=FUN_001dbfe0(id);
 if(i>=0) {
  Record* rec=&entries.records[i];
  if ((flags[rec->index+0x104e].bits&1) && rec->handle) {
   Node* node=rec->handle->FUN_001d72e0()->node;
   if(node) {
    node->update(0);
    node->transform->apply(node->data,&value,-1);
   } else {
    Vec* p=rec->handle->FUN_001d77c0();
    value.x=p->x; value.y=p->y; value.z=p->z;
   }
  }
 }
 out->x=value.x; out->y=value.y; out->z=value.z;
 return out;
}