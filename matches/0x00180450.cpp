struct A_180450 {
    char pad[0x18];
    A_180450* Get();
};
A_180450* A_180450::Get() {
    return (A_180450*)((char*)this + 0x18);
}
