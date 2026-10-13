struct O {
    char pad[0x10];
    int* member();
};
int* O::member() {
    return (int*)((char*)this + 0x10);
}