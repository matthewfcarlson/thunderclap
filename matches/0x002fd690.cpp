struct Block {
    unsigned int v[16];
};
void* __fastcall FnA(unsigned int x);
void* __fastcall FnB(void* p);
struct Target {
    unsigned int first;
    char pad[28];
    Block data;
    void Init(unsigned int arg);
};
void Target::Init(unsigned int arg) {
    first = arg;
    void* p = FnB(FnA(arg));
    data = *(Block*)p;
}
