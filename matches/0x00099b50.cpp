class Sub_99b50 {
  public:
    float Get();
};
class Obj_99b50 {
  public:
    char pad[0xb8];
    Sub_99b50* p;
    float Get();
};

float Obj_99b50::Get() {
    Sub_99b50* q = p;
    if (q)
        return q->Get();
    return -1.0f;
}
