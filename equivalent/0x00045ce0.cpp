// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00045ce0 @ 0x00045ce0
namespace core { struct IRefCount { virtual void slot0(); virtual void slot1(); }; }
struct Item { virtual void slot0(); virtual void slot1(); };
struct Block { char data[16]; void FUN_0027af50(); };
struct Small { char data[12]; void FUN_00234150(); };
struct Entry { Item* object; char data[36]; };
struct CCharacterTemplate : core::IRefCount {
 int unused; Item* a; Item* b;
 char pad[0xd0]; Small small[6]; char gap[0x90]; Entry entries[8]; char gap2[0x188]; Block blocks[14];
 virtual void slot0(); virtual void slot1(); ~CCharacterTemplate();
};
CCharacterTemplate::~CCharacterTemplate() {
 if(b) { b->slot1(); b=0; }
 if(a) { a->slot1(); a=0; }
 for(int i=13;i>=0;--i) blocks[i].FUN_0027af50();
 for(int j=7;j>=0;--j) if(entries[j].object) { entries[j].object->slot1(); entries[j].object=0; }
 for(int k=5;k>=0;--k) small[k].FUN_00234150();
 this->core::IRefCount::IRefCount();
}
