class CScriptCamera_aca40 {
  public:
    char pad[0x2c0];
    float a;
    float b;
    float c;
    bool Check();
    bool Target(int arg);
};
bool CScriptCamera_aca40::Target(int arg) {
    if (a >= c)
        return true;
    if (arg && b >= 0.0f && a > b && Check())
        return true;
    return false;
}