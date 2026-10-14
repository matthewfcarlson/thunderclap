// STATUS: equivalent (tools/equiv.py level 3: 277 inputs, branch coverage 10/10)
// FUN_0029ecb0 @ 0x0029ecb0
extern void* __cdecl FUN_00263ea0(unsigned int size);
extern void* __cdecl FUN_0008d6d0(unsigned int size);
struct Manager_29ecb0 {
 virtual void initialize();
 Manager_29ecb0* FUN_002a1140(int count);
};
struct Entry_29ecb0 { unsigned int first; unsigned int unused1; unsigned int second; char unused2[12]; unsigned int third; unsigned int unused3; };
struct Container_29ecb0 {
 Manager_29ecb0* manager;
 Entry_29ecb0* entries;
 int count;
 Container_29ecb0* FUN_0029ecb0(int n);
};
Container_29ecb0* Container_29ecb0::FUN_0029ecb0(int n) {
 count = n;
 Manager_29ecb0* allocation = (Manager_29ecb0*)FUN_00263ea0(0x28);
 manager = allocation ? allocation->FUN_002a1140(n) : 0;
 manager->initialize();
 entries = (Entry_29ecb0*)FUN_0008d6d0((unsigned int)n * 32);
 for (int i = 0; i < n; ++i) {
 entries[i].first = 0;
 entries[i].second = 0;
 entries[i].third = 0;
 }
 return this;
}