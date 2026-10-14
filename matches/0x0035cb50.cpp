struct Obj {
    void Init(const char*, int);
};
extern Obj gObj;
int atexit(void (*)(void));
void Handler();

void Reg() {
    gObj.Init("sound/rsd", 0);
    atexit(Handler);
}
