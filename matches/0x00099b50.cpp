class Sub {
  public:
    float Get();
};
class Obj {
  public:
    char pad[0xb8];
    Sub* p;
    float Get();
};

float Obj::Get() {
    Sub* q = p;
    if (q)
        return q->Get();
    return -1.0f;
}
