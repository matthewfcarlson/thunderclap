struct T {
    char pad[0x38];
    void* Value();
};
void* T::Value() {
    return (void*)((char*)this + 0x38);
}