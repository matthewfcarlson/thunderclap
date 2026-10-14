class C_fefa0 {
    char pad[0x10c];
    int value;

  public:
    int Get();
};
extern void Init(C_fefa0*, int*);
int C_fefa0::Get() {
    if (!value)
        Init(this, &value);
    return value;
}