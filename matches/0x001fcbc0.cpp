struct X_1fcbc0 {
    char pad[0xce];
    char m;
};
struct ThisWrap_001fcbc0 {
    X_1fcbc0* FUN_001fc7f0(void* p);
    void FUN_001fcbc0(void* p, char c);
};
void ThisWrap_001fcbc0::FUN_001fcbc0(void* p, char c) {
    X_1fcbc0* q = this->FUN_001fc7f0(p);
    if (q)
        q->m = c;
}
