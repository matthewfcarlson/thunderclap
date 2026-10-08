struct ParamEnumConstList {
    char pad[0x14];
    int mValue;
    int GetEnum(int index);
};

int ParamEnumConstList::GetEnum(int index) {
    return mValue;
}
