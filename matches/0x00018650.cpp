class Arr_18650 {
  public:
    int* Get(int index);
    int* m;
};

int* Arr_18650::Get(int index) {
    return m + index;
}
