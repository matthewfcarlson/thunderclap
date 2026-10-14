// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00059510 @ 0x00059510
struct Resource {
 virtual void unused();
 virtual void release();
};
struct State {
 unsigned field00, field04;
 unsigned position[3];
 unsigned char flag14; char pad15[3];
 unsigned vector18[3];
 unsigned char enabled; char pad25[3];
 unsigned vector28[3];
 unsigned char flag34; char pad35[3];
 unsigned vector38[3];
 unsigned char flag44; char pad45[7];
 Resource *resource4c, *resource50;
 unsigned field54, field58, field5c;
 Resource *resource60;
 unsigned field64, field68;
 Resource *resource6c, *resource70;
 unsigned field74, field78, field7c, field80;
 Resource *resource84;
 unsigned field88, field8c;
 unsigned char flag90, flag91;
 void FUN_00059510();
};
void State::FUN_00059510() {
 if (resource4c) { resource4c->release(); resource4c = 0; }
 if (resource50) { resource50->release(); resource50 = 0; }
 if (resource6c) { resource6c->release(); resource6c = 0; }
 if (resource70) { resource70->release(); resource70 = 0; }
 if (resource84) { resource84->release(); resource84 = 0; }
 if (resource60) { resource60->release(); resource60 = 0; }
 field74 = 0;
 position[2] = position[1] = position[0] = 0;
 vector18[2] = vector18[1] = vector18[0] = 0;
 vector38[2] = vector38[1] = vector38[0] = 0;
 field00 = 0; field04 = 0;
 field54 = 0; field58 = 0; field5c = 0;
 enabled = 1;
 vector28[2] = vector28[1] = vector28[0] = 0;
 field64 = 0; field68 = 0;
 field78 = 0; field7c = 0; field80 = 0;
 field88 = 0; field8c = 0;
 flag14 = 0; flag34 = 0; flag90 = 0; flag44 = 0; flag91 = 0;
}
