class C_25bcb0 {
  public:
    int Get();
};
extern int FUN_00246f50(int, const char*, int);
const char format[] = "\"%s\"";
int target(int* param_1, C_25bcb0* param_2) {
    int value = *param_1;
    int result = param_2->Get();
    return FUN_00246f50(value, format, result);
}