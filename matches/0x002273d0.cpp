struct V {
    float a, b, c;
};
extern void Sort(V*, int, int, V);
void FUN_002273d0(V* arr, int b, int n, V value) {
    int start = b;
    int c = b + b + 2;
    if (c < n) {
        do {
            if (arr[c].b > arr[c - 1].b)
                --c;
            arr[b] = arr[c];
            b = c;
            c = c + c + 2;
        } while (c < n);
    }
    if (c == n) {
        arr[b] = arr[n - 1];
        b = n - 1;
    }
    Sort(arr, b, start, value);
}
