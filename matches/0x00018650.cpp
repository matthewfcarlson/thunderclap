class Arr {
  public:
    int* Get(int index);
    int* m;
};

int* Arr::Get(int index) {
    return m + index;
}
