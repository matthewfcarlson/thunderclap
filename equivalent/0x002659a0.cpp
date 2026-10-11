// STATUS: equivalent (tools/equiv.py level 3: 13 inputs, branch coverage 8/8)
// FUN_002659a0 @ 0x002659a0
struct Node { virtual void slot0(); virtual void slot1(); };
struct Pool { int FUN_00231770(Node*); };
struct Iter {
  char pad[0x18];
  void FUN_00231160(Pool*);
  Node* FUN_00231180(int, int);
};
struct W {
  char pad[0x10]; Pool* pool;
  void FUN_002659a0(int);
};
void W::FUN_002659a0(int key){
  Iter first;
  first.FUN_00231160(pool);
  Node* n = first.FUN_00231180(key, 0);
  while (n) {
    int count = pool->FUN_00231770(n);
    while (count > 0) {
      n->slot1();
      count--;
    }
    Iter next;
    next.FUN_00231160(pool);
    n = next.FUN_00231180(key, 0);
  }
}
