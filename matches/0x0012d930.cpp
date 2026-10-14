struct Sub_12d930 {
    int x;
};
struct A_12d930 {
    char pad[16];
    Sub_12d930 sub;
    Sub_12d930* Get();
};
Sub_12d930* A_12d930::Get() {
    return &sub;
}