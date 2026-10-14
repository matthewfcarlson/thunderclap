// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 22/22)
// FUN_000b0cf0 @ 0x000b0cf0
struct Resource {
 virtual void slot0();
 virtual void release();
};
struct Record { Resource* resources[6]; char padding[24]; };
struct Group { Resource* resources[4]; };
void __cdecl FUN_000b0cf0(int groupCount, int recordCount, Group** groups, Record* records, Resource** single)
{
 if (single && *single) { (*single)->release(); *single = 0; }
 if (recordCount > 0) {
  for (int i = recordCount - 1; i >= 0; --i) {
   for (int j = 5; j >= 0; --j) {
    if (records[i].resources[j]) {
     records[i].resources[j]->release();
     records[i].resources[j] = 0;
    }
   }
  }
 }
 if (groupCount > 0) {
  for (int i = groupCount - 1; i >= 0; --i) {
   for (int j = 3; j >= 0; --j) {
    if (groups[i]->resources[j]) {
     groups[i]->resources[j]->release();
     groups[i]->resources[j] = 0;
    }
   }
  }
 }
}
