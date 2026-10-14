// STATUS: equivalent (tools/equiv.py level 3: 2963 inputs, branch coverage 4/4)
// FUN_0008c870 @ 0x0008c870
struct Resource_8c870 { virtual void slot0(); virtual void release(); };
struct Owner_8c870 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void reset(void*); };
struct Entry_8c870 {
 Owner_8c870* owner;
 Resource_8c870* resource;
 char data[0x54];
 int state;
 char pad60[12];
 unsigned char flag6c, flag6d;
 char pad6e[0x46];
 int enabled[5];
};
struct Manager_8c870 {
 char pad[8];
 Entry_8c870* entries;
 void reset(int index);
};
void Manager_8c870::reset(int index) {
 entries[index].state = 4;
 entries[index].flag6c = 0;
 entries[index].flag6d = 0;
 Resource_8c870** resource = &entries[index].resource;
 if (*resource) {
  (*resource)->release();
  *resource = 0;
 }
 entries[index].enabled[0] = 1;
 entries[index].enabled[1] = 1;
 entries[index].enabled[2] = 1;
 entries[index].enabled[3] = 1;
 entries[index].enabled[4] = 1;
 Entry_8c870* entry = &entries[index];
 if (entry->owner) entry->owner->reset(entry->data);
}
