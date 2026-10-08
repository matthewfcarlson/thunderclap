class Obj {
public:
  char pad[0x24];
  int mValue;
  int GetValue();
};

int Obj::GetValue() {
  return mValue;
}