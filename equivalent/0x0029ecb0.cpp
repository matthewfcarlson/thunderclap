// STATUS: equivalent (tools/equiv.py level 3: 277 inputs, branch coverage 10/10)
// FUN_0029ecb0 @ 0x0029ecb0
extern void* __cdecl FUN_00263ea0(unsigned int size);
extern void* __cdecl FUN_0008d6d0(unsigned int size);
struct Manager {
 virtual void initialize();
 Manager* FUN_002a1140(int count);
};
struct Entry { unsigned int first; unsigned int unused1; unsigned int second; char unused2[12]; unsigned int third; unsigned int unused3; };
struct Container {
 Manager* manager;
 Entry* entries;
 int count;
 Container* FUN_0029ecb0(int n);
};
Container* Container::FUN_0029ecb0(int n) {
 count = n;
 Manager* allocation = (Manager*)FUN_00263ea0(0x28);
 manager = allocation ? allocation->FUN_002a1140(n) : 0;
 manager->initialize();
 entries = (Entry*)FUN_0008d6d0((unsigned int)n * 32);
 for (int i = 0; i < n; ++i) {
 entries[i].first = 0;
 entries[i].second = 0;
 entries[i].third = 0;
 }
 return this;
}