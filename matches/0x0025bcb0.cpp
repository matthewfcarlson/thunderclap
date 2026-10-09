class C {
  public:
    int Get();
};
extern void FUN_00246f50(int, const char*, int);
const char format[] = "\"%s\"";
void target(int* param_1, C* param_2) {
    int value = *param_1;
    int result = param_2->Get();
    FUN_00246f50(value, format, result);
}