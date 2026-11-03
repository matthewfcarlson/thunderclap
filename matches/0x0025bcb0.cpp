class C_25bcb0 {
  public:
    int Get();
};
extern int FUN_00246f50(int, const char*, int);
const char format[] = "\"%s\"";
int target(int* stream, C_25bcb0* item) {
    int value = *stream;
    int result = item->Get();
    return FUN_00246f50(value, format, result);
}