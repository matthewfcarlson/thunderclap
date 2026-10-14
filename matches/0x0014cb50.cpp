struct Obj_14cb50 {
    char pad[0x18];
    int* value;
    int** Get();
};
int** Obj_14cb50::Get() {
    return &value;
}