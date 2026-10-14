struct Block_2fd690 {
    unsigned int v[16];
};
void* __fastcall FnA(unsigned int x);
void* __fastcall FnB(void* p);
struct Target_2fd690 {
    unsigned int first;
    char pad[28];
    Block_2fd690 data;
    void Init(unsigned int arg);
};
void Target_2fd690::Init(unsigned int arg) {
    first = arg;
    void* p = FnB(FnA(arg));
    data = *(Block_2fd690*)p;
}
