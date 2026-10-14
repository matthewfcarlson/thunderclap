struct O_15a830 {
    char pad[0x10];
    int* member();
};
int* O_15a830::member() {
    return (int*)((char*)this + 0x10);
}