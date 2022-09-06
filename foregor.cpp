
#include <iostream>
#include <random>

template <size_t N>
double processArray(double(&Array)[N], bool(&Results)[N])
{
    double average = 0;
    for (int i = 0; i < N; i++) {
        Array[i] = static_cast<double>(rand() % 31 - 15);
        average += Array[i];
    }
    average /= N;
    for (int i = 0; i < N; i++) {
        if (Array[i] < average)
            Results[i] = false;
        else Results[i] = true;
    }
    return average;
}

int main()
{
    const int N = 40;
    double Array[N];
    double average;
    bool Results[N];
    average = processArray(Array, Results);
    std::cout << average << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << Array[i] << " ";
        if (Results[i])
            std::cout << "True";
        else std::cout << "False";
        std::cout << std::endl;
    }
}
