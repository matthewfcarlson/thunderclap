struct Pair {
    int a, b;
};
Pair __cdecl convert(int);
class CTriggerVolumeManager_1fd7a0 {
  public:
    int check(int, int);
    char run(int);
};
char CTriggerVolumeManager_1fd7a0::run(int x) {
    Pair p = convert(x);
    return check(p.a, p.b) != 0;
}