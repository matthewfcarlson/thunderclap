struct CSPManager_1df130 {
    int FUN_001def30(int);
    int FUN_001d7100(int);
    int FUN_001df130(int);
};
int CSPManager_1df130::FUN_001df130(int value) {
    int ret = -1;
    CSPManager_1df130* result = (CSPManager_1df130*)FUN_001def30(value);
    if (result)
        ret = result->FUN_001d7100(ret);
    return ret;
}