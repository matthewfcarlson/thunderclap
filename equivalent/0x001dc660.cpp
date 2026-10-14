// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dc660 @ 0x001dc660
struct Vec_1dc660 { unsigned int x,y,z; };
struct Transform_1dc660 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void apply(void*, Vec_1dc660*, int);
};
struct Node {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void update(int);
 char pad4[12]; Transform_1dc660* transform; char pad14[132]; unsigned char data[1];
};
struct Result_1dc660 { char pad[112]; Node* node; };
struct Handle_1dc660 { Result_1dc660* FUN_001d72e0(); Vec_1dc660* FUN_001d77c0(); };
struct Record_1dc660 { char pad0[24]; Handle_1dc660* handle; char pad1[6]; short index; char pad2[4]; };
struct Flag_1dc660 { unsigned char bits; char pad[19]; };
struct Owner_1dc660 {
 union { struct { char pad[0x608]; Record_1dc660 records[4096]; } entries; Flag_1dc660 flags[65536]; };
 int FUN_001dbfe0(int);
 Vec_1dc660* target(Vec_1dc660*, int);
};
Vec_1dc660* Owner_1dc660::target(Vec_1dc660* out, int id) {
 Vec_1dc660 value; value.x=0; value.y=0; value.z=0;
 int i=FUN_001dbfe0(id);
 if(i>=0) {
  Record_1dc660* rec=&entries.records[i];
  if ((flags[rec->index+0x104e].bits&1) && rec->handle) {
   Node* node=rec->handle->FUN_001d72e0()->node;
   if(node) {
    node->update(0);
    node->transform->apply(node->data,&value,-1);
   } else {
    Vec_1dc660* p=rec->handle->FUN_001d77c0();
    value.x=p->x; value.y=p->y; value.z=p->z;
   }
  }
 }
 out->x=value.x; out->y=value.y; out->z=value.z;
 return out;
}