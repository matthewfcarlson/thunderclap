// STATUS: equivalent (tools/equiv.py level 3: 151 inputs, branch coverage 4/4)
// FUN_0027c080 @ 0x0027c080
#include "compat/ptr.h"
namespace pure3d {
struct Skeleton {
 struct Partition {
  virtual void slot0();
  unsigned int reserved;
  unsigned int key;
  unsigned int value;
  unsigned int* bits;
  unsigned int extra;
 };
};
}
struct PartitionList {
 pure3d::Skeleton::Partition* begin;
 pure3d::Skeleton::Partition* end;
 pure3d::Skeleton::Partition* capacity;
 void FUN_0027bd70(int count, const pure3d::Skeleton::Partition* initial);
};
extern void* __cdecl FUN_0008d6d0(unsigned int size);
struct Object {
 char pad0[0x10];
 unsigned int bitCount;
 char pad14[0x20];
 PartitionList partitions;
 int FUN_0027b670(unsigned int key, unsigned int value);
 pure3d::Skeleton::Partition* target(unsigned int key, unsigned int value);
};
pure3d::Skeleton::Partition* Object::target(unsigned int key, unsigned int value) {
 if (FUN_0027b670(key,value)) return 0;
 hulk_intptr index = partitions.end - partitions.begin;
 pure3d::Skeleton::Partition initial;
 initial.bits = 0;
 partitions.FUN_0027bd70(index+1, &initial);
 partitions.begin[index].key = key;
 partitions.begin[index].value = value;
 unsigned int count = bitCount;
 unsigned int words = (count+31) >> 5;
 unsigned int* bits = (unsigned int*)FUN_0008d6d0(words*4+4);
 bits[0] = count;
 for(unsigned int i=0;i<words;++i) bits[i+1]=0;
 partitions.begin[index].bits = bits;
 return partitions.begin+index;
}
