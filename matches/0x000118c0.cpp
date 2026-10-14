class C_118c0 {
  public:
    char pad[8];
    void Callee(int* p);
    void Thunk(int* p);
};
void C_118c0::Thunk(int* p) {
    if (p) {
        p = (int*)((char*)p + 8);
        ((C_118c0*)((char*)this + 8))->Callee(p);
    }
}
