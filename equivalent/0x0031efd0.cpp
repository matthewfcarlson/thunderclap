// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 6/6)
// FUN_0031efd0 @ 0x0031efd0
void* __cdecl FUN_0008d690(unsigned int size);
inline void* __cdecl operator new(unsigned int, void* address) { return address; }
namespace pure3d {
class pddiFogState {
public:
 virtual void FUN_0008d690();
 char data[16];
};
template<class T> class pddiStack {
public:
 virtual void FUN_0008d690();
 int capacity;
 int count;
 T* entries;
 pddiStack(int n);
};
template<> pddiStack<pddiFogState>::pddiStack(int n) {
 pddiFogState* memory = (pddiFogState*)::FUN_0008d690((unsigned int)n * 20u);
 if (memory && (int)((unsigned int)n - 1u) >= 0) {
  unsigned int remaining = (unsigned int)n;
  pddiFogState* item = memory;
  do {
   new (item) pddiFogState;
   ++item;
  } while (--remaining);
 }
 capacity = n;
 entries = memory;
 count = 0;
}
}
