// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 8/8)
// FUN_0029bea0 @ 0x0029bea0
void* __cdecl FUN_0008d6d0(unsigned int size);
struct FUN_0027b070 {
 virtual void slot0();
 char padding[12];
 FUN_0027b070();
};
namespace pure3d {
struct DisplayList : FUN_0027b070 {
 virtual void slot0();
 unsigned int field10, field14, field18;
 unsigned int* entries;
 char* entriesEnd;
 unsigned int field24;
 unsigned char* records;
 unsigned char* recordsEnd;
 DisplayList(unsigned int count, unsigned int recordCount);
};
DisplayList::DisplayList(unsigned int count, unsigned int recordCount) {
 field10=0; field14=0; field18=0;
 if(count>0) {
  unsigned int bytes=count*4;
  entries=(unsigned int*)FUN_0008d6d0(bytes);
  if(entries) entriesEnd=(char*)entries+bytes;
  else {entries=0; entriesEnd=0;}
 } else {entries=0; entriesEnd=0;}
 if(recordCount>0) {
  unsigned int bytes=recordCount*72;
  records=(unsigned char*)FUN_0008d6d0(bytes);
  if(records) recordsEnd=records+bytes;
  else {records=0; recordsEnd=0;}
 } else {records=0; recordsEnd=0;}
 unsigned int bytes=recordCount*72;
 unsigned int* destination=(unsigned int*)records;
 for(unsigned int i=0;i<bytes/4;++i) destination[i]=0;
 destination=entries;
 for(unsigned int j=0;j<count;++j) destination[j]=0;
}
}
