struct Info {
    char data[24];
    unsigned int a, b;
    char extra[8];
};
extern void fetch(Info*);
extern float v1, v2, v3;
double calc() {
    Info info;
    fetch(&info);
    return (float)info.a * (float)info.b - v3 - v2 - v1;
}