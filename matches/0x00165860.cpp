struct Target_165860 {
    char pad[0x30];
    char Set(int arg);
};

char Target_165860::Set(int arg) {
    *(int*)((char*)this + 0x30) = arg;
    return 1;
}
