// STATUS: equivalent (tools/equiv.py level 3: 37 inputs, branch coverage 18/20, incomplete)
// FUN_002e6270 @ 0x002e6270
void __cdecl FUN_0008d340(void*) throw();
namespace core { struct IRefCount { virtual void slot0() throw(); virtual void slot1() throw(); ~IRefCount() throw() {} }; }
struct Item_2e6270 { virtual void slot0() throw(); virtual void slot1() throw(); };
struct Group_2e6270 { Item_2e6270** begin; Item_2e6270** end; Item_2e6270** capacity; };
namespace pure3d {
struct VertexAnimKeyFrameList : core::IRefCount {
 unsigned int refs; int* begin; int* end; int* capacity;
 Group_2e6270* groups; Group_2e6270* groupsEnd; Group_2e6270* groupsCapacity;
 virtual void slot0() throw(); virtual void slot1() throw();
 ~VertexAnimKeyFrameList() throw();
};
VertexAnimKeyFrameList::~VertexAnimKeyFrameList() throw() {
 unsigned int count=(unsigned int)(end-begin);
 for(unsigned int i=0;i<count;++i) {
  unsigned int n=(unsigned int)(groups[i].end-groups[i].begin);
  for(unsigned int j=0;j<n;++j) {
   Item_2e6270** slot=&groups[i].begin[j];
   if(*slot) { (*slot)->slot1(); *slot=0; }
  }
 }
 Group_2e6270* p=groups;
 if(p) {
  Group_2e6270* stop=groupsEnd;
  while(p!=stop) { if(p->begin) FUN_0008d340(p->begin); ++p; }
  FUN_0008d340(groups);
 }
 if(begin) FUN_0008d340(begin);
}
}
