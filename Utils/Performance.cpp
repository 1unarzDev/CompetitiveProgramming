#include <bits/stdc++.h>
#include <matplot/matplot.h>

int main() {
    using namespace matplot;

    std::vector<double> x = {0, 1, 2, 3, 4, 5};
    std::vector<double> y = {0, 21, 42, 79, 85, 109};
    plot(x, y);
    title("Time Plot");
    ylabel("Time");
    xrange({0, 5});
    yrange({0, 120});
    show();
    return 0;
}