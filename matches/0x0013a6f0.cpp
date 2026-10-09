// Same code shape as 0x0013a5c0 (propagated; names are from that function)
struct A { void* Get(); };
struct B { int Check(); };
struct C { bool Finish(void*); };
struct Target { char pad[0x20]; A* field20; void* field24; bool Run(); };
bool Target::Run() {
    void* value = field20->Get();
    int result = ((B*)value)->Check();
    if (!result) return true;
    return ((C*)result)->Finish(field24);
}