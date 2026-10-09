struct Manager { int Get(); void Set(int); };
struct Waiter { bool Ready(); };
struct Target { void Run(Waiter *); };
extern Manager *gManager;
extern void __cdecl FUN_00087990();
void Target::Run(Waiter *w) {
 int old = gManager->Get();
 gManager->Set(250000);
 while (!w->Ready()) FUN_00087990();
 gManager->Set(old);
}