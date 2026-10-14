// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 12/12)
// FUN_00287e20 @ 0x00287e20
struct Node { unsigned FUN_00288960(unsigned,unsigned); };
struct Map_287e20 { Node* FUN_00288ad0(unsigned,unsigned); };
struct Group_287e20 { Map_287e20* FUN_00284f50(); char data[0x2c]; };
struct Key_287e20 { unsigned a,b; };
struct Keys_287e20 { char pad[0x24]; Key_287e20* entries; };
struct Info_287e20 { char pad[8]; Keys_287e20* keys; unsigned count; };
struct Result_287e20 { unsigned rotation,translation,other; };
struct Target_287e20 {
 char pad0[0x28]; unsigned count; Group_287e20 groups[5]; char pad1[8]; Info_287e20* info; char pad2[8]; Result_287e20* results[5]; unsigned char dirty;
 unsigned char FUN_00285340(); void update();
};
void Target_287e20::update() {
 dirty |= FUN_00285340();
 if (!dirty) return;
 dirty=0;
 for(unsigned i=0;i<count;++i) {
 Map_287e20* map=groups[i].FUN_00284f50();
 for(unsigned j=0;j<info->count;++j) {
 Node* node=map->FUN_00288ad0(info->keys->entries[j].a,info->keys->entries[j].b);
 if(node) {
 unsigned r=node->FUN_00288960(0x544f52,0x544f52);
 results[i][j].rotation=r;
 unsigned t=node->FUN_00288960(0x4e415254,0x54434556);
 results[i][j].translation=t;
 } else { results[i][j].rotation=0; results[i][j].translation=0; }
 }
 }
}
