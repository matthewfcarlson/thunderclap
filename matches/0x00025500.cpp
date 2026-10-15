struct O {
    char pad[0x50];
    unsigned char b50;
    char pad2[0x80];
    int d1;
    int d2;
    int d3;
    void Fn();
};
void O::Fn() {
    b50 = 1;
    d1 = 4;
    d2 = 3;
    d3 = 1;
}
