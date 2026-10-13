// STATUS: equivalent (tools/equiv.py level 3: 456 inputs, branch coverage 17/18, incomplete)
// FUN_0030fda0 @ 0x0030fda0
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
struct Item {
 virtual void retain();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v4();
 virtual int key1();
 virtual int key2();
};
struct Container {
 char pad[16];
 int groupCount;
 int capacity;
 int* counts;
 Item*** groups;
 bool insert(int group, Item* item);
};
bool Container::insert(int group, Item* item) {
 if (!item || group < 0 || group >= groupCount || counts[group] >= capacity) return false;
 int first = item->key1();
 int second = item->key2();
 int pos = 0;
 while (pos < counts[group]) {
  Item* current = groups[group][pos];
  int key = current->key1();
  if (first < key) break;
  if (first == key && second < current->key2()) break;
  ++pos;
 }
 Item** at = groups[group] + pos;
 memmove(at + 1, at, (counts[group] - pos) * 4);
 ++counts[group];
 groups[group][pos] = item;
 groups[group][pos]->retain();
 return true;
}
