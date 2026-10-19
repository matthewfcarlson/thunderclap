struct Object {
    int FUN_001def30(int);
    int FUN_001d7100(int);
    int FUN_001df130(int);
};
int Object::FUN_001df130(int value) {
    int ret = -1;
    Object* result = (Object*)FUN_001def30(value);
    if (result)
        ret = result->FUN_001d7100(ret);
    return ret;
}