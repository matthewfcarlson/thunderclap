struct Obj {
    char pad[0x18];
    int* value;
    int** Get();
};
int** Obj::Get() {
    return &value;
}