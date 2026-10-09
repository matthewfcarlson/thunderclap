class ScriptReader {
  public:
    char pad0[0x10];
    int index;
    int values[0x43];
    int low;
    int high;
    int limit;
    unsigned __int64 vfunc_14();
};
unsigned __int64 ScriptReader::vfunc_14() {
    if (limit <= values[index])
        return 0;
    return *(unsigned __int64*)((char*)this + 0x120);
}