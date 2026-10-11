// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00089bf0 @ 0x00089bf0
extern "C" int __cdecl FUN_00267760(char*, unsigned int, const char*, ...);
struct Entry { int first, second; char reserved[16]; };
struct State {
 char text0[32], text1[32], text2[32], text3[32];
 int id0, index0; char pad88[32];
 int id1, index1; char padB0[32];
 int id2, index2; char name[32];
 int values[6];
 int handles[10];
 char text4[32];
 Entry entries[100];
 int mode;
 unsigned char flag0, flag1, flag2, flag3;
 int counters[4];
 State* FUN_00089bf0();
};
State* State::FUN_00089bf0() {
 id0 = index0 = -1;
 id1 = index1 = -1;
 id2 = index2 = -1;
 values[0] = values[1] = values[2] = 0;
 mode = 1;
 flag1 = 1;
 values[3] = values[4] = values[5] = 0;
 flag0 = flag2 = flag3 = 0;
 counters[0] = counters[1] = counters[2] = counters[3] = 0;
 text0[0] = text1[0] = text3[0] = text2[0] = text4[0] = 0;
 index0 = id0 = -1;
 index1 = id1 = -1;
 index2 = 1;
 id2 = 0;
 FUN_00267760(name, 32, "c%02dm%02d", 0, 1);
 for (int i = 0; i < 10; ++i) handles[i] = -1;
 for (int j = 0; j < 100; ++j) {
 entries[j].first = 0;
 entries[j].second = 0;
 }
 return this;
}
