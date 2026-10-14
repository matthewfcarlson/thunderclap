class A_18cb20 {
  public:
    char pad[0x10];
    struct X_18cb20* Get();
};

struct X_18cb20 {};

X_18cb20* A_18cb20::Get() {
    return (X_18cb20*)((char*)this + 0x10);
}
