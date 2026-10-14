// STATUS: equivalent (tools/equiv.py level 3: 759 inputs, branch coverage 8/8)
// FUN_00025750 @ 0x00025750
struct Handle_25750 {
 unsigned int a,b;
 void FUN_0027af00();
 void FUN_0027af70(const void*);
 void FUN_0027af50();
};
struct Entry_25750 {
 char data[0x40];
 Handle_25750 first;
 Handle_25750 second;
 char gap[8];
 unsigned int valueFirst;
 unsigned int valueSecond;
 unsigned int kind;
 unsigned char useSecond;
 char tail[3];
};
struct Manager_25750 { void FUN_00283a40(Handle_25750*, Entry_25750*, unsigned int, unsigned int); };
struct Object {
 char pad[0x58c];
 int count;
 Entry_25750 entries[1];
 Manager_25750* FUN_0027f250();
 void FUN_00025750();
};
void Object::FUN_00025750() {
 Manager_25750* manager=FUN_0027f250();
 for(int i=0;i<count;++i) {
  Entry_25750* entry=&entries[i];
  Handle_25750 temp;
  temp.FUN_0027af00();
  unsigned int value;
  if(entry->useSecond) {temp.FUN_0027af70(&entry->second);value=entry->valueSecond;}
  else {temp.FUN_0027af70(&entry->first);value=entry->valueFirst;}
  if(temp.a | temp.b) manager->FUN_00283a40(&temp,entry,entry->kind,value);
  temp.FUN_0027af50();
 }
 count=0;
}
