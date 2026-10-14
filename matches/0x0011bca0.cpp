struct Obj_11bca0 {
    char pad[0x28];
    int m28;
    char Set(int v);
};

char Obj_11bca0::Set(int v) {
    m28 = v;
    return 1;
}
