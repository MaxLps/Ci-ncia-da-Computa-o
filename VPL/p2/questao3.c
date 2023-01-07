int fat(int n) {
    if (n == 1 || n == 0){
        return 1;
    }
    else {
        return n * fat(n-1);
    }
}

int comb(int n, int p){
    int c;
    c = fat(n) / (fat(p) * fat((n-p)));
    return c;
}