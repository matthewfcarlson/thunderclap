extern "C" unsigned __int64 __cdecl Lookup(int, int, int);
extern float fallback;
class Result {
  public:
    Result* Convert(int);
    float* Get();
};
class Owner {
  public:
    Result* Find(unsigned __int64);
    float* Query(int);
};
float* Owner::Query(int id) {
    unsigned __int64 key = Lookup(id, 0, 0);
    Result* r = Find(key);
    if (!r)
        return &fallback;
    r = r->Convert(0);
    if (!r)
        return &fallback;
    return r->Get();
}