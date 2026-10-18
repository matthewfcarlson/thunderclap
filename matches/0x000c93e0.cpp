// FUN_000c93e0 @ 0x000c93e0
// equiv-map: ??1Key@@QAE@XZ = 0x0027af50
struct Triple_c93e0 {
    int a, b, c;
};

struct Key {
    int a, b, c;
    ~Key() throw();
    int FUN_0027b0e0(int index) throw();
};

class Host_c93e0 {
public:
    int FUN_000c8200(int a1, int handle, Triple_c93e0 t1, Triple_c93e0 t2, Key key) throw();
    int FUN_000c93e0(int a1, int index, Triple_c93e0 t1, Triple_c93e0 t2, Key key) throw();
};

int Host_c93e0::FUN_000c93e0(int a1, int index, Triple_c93e0 t1, Triple_c93e0 t2, Key key) throw() {
    return FUN_000c8200(a1, key.FUN_0027b0e0(index), t1, t2, key);
}
