struct Obj_1a1f10 {
    char pad[0x10];
    int mValue;
    char SetOldState_001a1f10(int x);
};

char Obj_1a1f10::SetOldState_001a1f10(int x) {
    mValue = x;
    return 1;
}
