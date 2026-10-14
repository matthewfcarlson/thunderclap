// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_00036d90 @ 0x00036d90
struct Key_36d90 { unsigned int low, high; };
struct Entry_36d90 {
 unsigned int low, high;
 unsigned int value, extra;
 char FUN_0027af90(Key_36d90* key);
 void FUN_0027af70(Key_36d90* key);
};
struct Cache_36d90 {
 char padding[0x2150];
 Entry_36d90 entries[16];
 int next;
 int FUN_00036d90(Key_36d90* key);
};
int Cache_36d90::FUN_00036d90(Key_36d90* key) {
 if ((key->low | key->high) == 0) return -1;
 for (int i=0;i<16;++i) {
  if (entries[i].FUN_0027af90(key)) return i;
 }
 int chosen=next;
 entries[chosen].FUN_0027af70(key);
 entries[chosen].value=0;
 for (int j=0;j<16;++j) {
  if ((entries[j].low | entries[j].high)==0) {
   next=j;
   return chosen;
  }
 }
 next=(chosen+1)%16;
 return chosen;
}
