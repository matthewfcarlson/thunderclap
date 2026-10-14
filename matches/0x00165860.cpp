struct Target {
    char pad[0x30];
    char Set(int arg);
};

char Target::Set(int arg) {
    *(int*)((char*)this + 0x30) = arg;
    return 1;
}
