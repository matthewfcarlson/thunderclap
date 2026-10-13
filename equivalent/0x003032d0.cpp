// STATUS: equivalent (tools/equiv.py level 3: 1038 inputs, branch coverage 8/8)
// FUN_003032d0 @ 0x003032d0
struct Entry {
 unsigned int words[9];
 float priority;
 unsigned int tail[7];
 void FUN_002f7a90(const Entry* source);
};
extern void __cdecl FUN_00302fa0(Entry* entries, int hole, int start, Entry value);
void __cdecl FUN_003032d0(Entry* entries, int start, int count, Entry value) {
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
