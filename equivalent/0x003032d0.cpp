// STATUS: equivalent (tools/equiv.py level 3: 1038 inputs, branch coverage 8/8)
// FUN_003032d0 @ 0x003032d0
struct Entry_3032d0 {
 unsigned int words[9];
 float priority;
 unsigned int tail[7];
 void FUN_002f7a90(const Entry_3032d0* source);
};
extern void __cdecl FUN_00302fa0(Entry_3032d0* entries, int hole, int start, Entry_3032d0 value);
void __cdecl FUN_003032d0(Entry_3032d0* entries, int start, int count, Entry_3032d0 value) {
 int hole = start;
 int child = hole * 2 + 2;
 while (child < count) {
  if (entries[child].priority < entries[child-1].priority) --child;
  entries[hole] = entries[child];
  hole = child;
  child = child * 2 + 2;
 }
 if (child == count) {
  entries[hole].FUN_002f7a90(&entries[count-1]);
  hole = count-1;
 }
 FUN_00302fa0(entries, hole, start, value);
}
