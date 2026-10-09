struct Helper2 { void* run(); };
struct Helper1 { Helper2* run(); };
class InterruptPriorityAction { public: char pad[0x18]; void* mAt1c; Helper1* mAt20; virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); };
void InterruptPriorityAction::f4() { Helper2* a = mAt20->run(); int* b = (int*)a->run(); *(int*)((char*)b + 0x31c) -= *(int*)((char*)mAt1c + 0x14); }