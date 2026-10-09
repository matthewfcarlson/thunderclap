class C { public: char pad[8]; void Callee(int* p); void Thunk(int* p); };
void C::Thunk(int* p) {
    if (p) {
        p = (int*)((char*)p + 8);
        ((C*)((char*)this + 8))->Callee(p);
    }
}
