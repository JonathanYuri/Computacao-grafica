extern "C" double* interp(int N_x, int N_xp, const double* x, const double* xp, const double* yp, double left, double right) {

    double* y = new double[N_x];
    for (int i = 0; i < N_x; i++) y[i] = left;

    int ip = 0;
    int ip_next = 1;
    int i = 0;

    while (i < N_x) {
        double m = (yp[ip_next] - yp[ip]) / (xp[ip_next] - xp[ip]);
        double q = yp[ip] - m * xp[ip];
        //std::cout << m << " "<< q<<std::endl;
        while (x[i] < xp[ip_next]) {
            if (x[i] >= xp[ip])
                y[i] = m * x[i] + q;
            //std::cout << y[i] << std::endl; // debug: OK
            i += 1;
            if (i >= N_x) { break; }
            //std::cout << i << " " <<ip <<std::endl;
        }
        ip += 1;
        ip_next += 1;
        if (ip_next == N_xp) {
            while (i < N_x) {
                y[i] = right;
                i++;
            }
            break;
        }
    }

    return y;
}