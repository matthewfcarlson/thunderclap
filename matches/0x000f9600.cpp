struct Sub {
    void Write(char* out, int a, int b, int c);
};
struct Owner {
    char pad[0x284];
    Sub* sub;
    int Fn(int p);
};
int Owner::Fn(int p) {
    unsigned char tmp[4];
    sub->Write((char*)tmp + 3, 1, 1, 1);
    unsigned int n = tmp[3];
    sub->Write((char*)p, n, 1, 1);
    *((char*)p + n) = 0;
    return p;
}
