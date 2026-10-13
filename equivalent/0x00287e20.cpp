// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 12/12)
// FUN_00287e20 @ 0x00287e20
struct Node { unsigned FUN_00288960(unsigned,unsigned); };
struct Map { Node* FUN_00288ad0(unsigned,unsigned); };
struct Group { Map* FUN_00284f50(); char data[0x2c]; };
struct Key { unsigned a,b; };
struct Keys { char pad[0x24]; Key* entries; };
struct Info { char pad[8]; Keys* keys; unsigned count; };
struct Result { unsigned rotation,translation,other; };
struct Target {
 char pad0[0x28]; unsigned count; Group groups[5]; char pad1[8]; Info* info; char pad2[8]; Result* results[5]; unsigned char dirty;
 unsigned char FUN_00285340(); void update();
};
void Target::update() {
 dirty |= FUN_00285340();
 if (!dirty) return;
 dirty=0;
 for(unsigned i=0;i<count;++i) {
 Map* map=groups[i].FUN_00284f50();
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
