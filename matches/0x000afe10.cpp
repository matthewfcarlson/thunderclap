class Other_afe10 {
  public:
    void Run(int);
};
class Thing_afe10 {
  public:
    char pad[5];
    unsigned char flag;
    Other_afe10* p;
    void Set(int);
};
void Thing_afe10::Set(int value) {
    if (flag != (unsigned char)value) {
        if (p)
            p->Run(value);
        flag = (unsigned char)value;
    }
}