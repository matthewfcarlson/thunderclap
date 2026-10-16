class Result;
class Item {
  public:
    Result* Get();
};
class Result {
  public:
    float* Value();
};
class Host {
  public:
    char pad[0xb8];
    Item* item;
    float* Fun();
};
extern float gZero;
float* Host::Fun() {
    float* p = &gZero;
    Item* x = item;
    if (x) {
        Result* r = x->Get();
        if (r)
            p = r->Value();
    }
    return p;
}