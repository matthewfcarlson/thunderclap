struct G {
    void Run();
};
extern G gObj;
void F1() {
    gObj.Run();
}