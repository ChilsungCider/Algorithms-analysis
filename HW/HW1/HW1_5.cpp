#include <iostream>
#include <sys/time.h>

int main() {
    // get the current time (moment 1)
    timeval tv;
    gettimeofday(&tv, nullptr);
    long start = tv.tv_sec * 1000000L + tv.tv_usec;

    // a task that takes time
    int cnt = 0;
    for (int i = 0; i < 1000; i++) {
        cnt++;
    }
    std::cout << "cnt: " << cnt << std::endl;

    // get the current time (moment 2)
    gettimeofday(&tv, nullptr);
    long end = tv.tv_sec * 1000000L + tv.tv_usec;

    // calculate the time difference between the two moments in microseconds
    long difftime = (end - start);

    // print the result
    std::cout << "the time difference: " << difftime << " usec" << std::endl;

    return 0;
}
