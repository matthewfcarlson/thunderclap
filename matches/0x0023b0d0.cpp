namespace fight {
class ScriptReader {
  public:
    virtual void f0();
    char pad[12];
    int index;
    int values[67];
    volatile int a;
    int b;
    int limit;
    int vfunc_13();
};
int ScriptReader::vfunc_13() {
    if ((a | b) && limit > values[index])
        return 1;
    return 0;
}
} // namespace fight