// STATUS: equivalent (tools/equiv.py level 3: 37 inputs, branch coverage 18/20, incomplete)
// FUN_002e6270 @ 0x002e6270
void __cdecl FUN_0008d340(void*) throw();
namespace core { struct IRefCount { virtual void slot0() throw(); virtual void slot1() throw(); ~IRefCount() throw() {} }; }
struct Item { virtual void slot0() throw(); virtual void slot1() throw(); };
struct Group { Item** begin; Item** end; Item** capacity; };
namespace pure3d {
struct VertexAnimKeyFrameList : core::IRefCount {
 unsigned int refs; int* begin; int* end; int* capacity;
 Group* groups; Group* groupsEnd; Group* groupsCapacity;
 virtual void slot0() throw(); virtual void slot1() throw();
 ~VertexAnimKeyFrameList() throw();
};
VertexAnimKeyFrameList::~VertexAnimKeyFrameList() throw() {
 unsigned int count=(unsigned int)(end-begin);
 for(unsigned int i=0;i<count;++i) {
  unsigned int n=(unsigned int)(groups[i].end-groups[i].begin);
  for(unsigned int j=0;j<n;++j) {
   Item** slot=&groups[i].begin[j];
   if(*slot) { (*slot)->slot1(); *slot=0; }
  }
 }
 Group* p=groups;
 if(p) {
  Group* stop=groupsEnd;
  while(p!=stop) { if(p->begin) FUN_0008d340(p->begin); ++p; }
  FUN_0008d340(groups);
 }
 if(begin) FUN_0008d340(begin);
}
}
