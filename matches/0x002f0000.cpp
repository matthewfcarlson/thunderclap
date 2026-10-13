struct X {
    void* Get();
};
void* X::Get() {
    return (char*)this + 0xc;
}
