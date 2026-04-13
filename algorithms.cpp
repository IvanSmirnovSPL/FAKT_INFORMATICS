#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // inner_product
#include <functional>
#include <random>

/*
1. Функции для перебора всех членов коллекции и выполнения определённых действий над каждым из них. К ним относятся count, find, for_each, search, copy, swap, replace, transform, remove, unique, reverse, random_shuffle, partition и другие.
2. Функции для сортировки членов коллекции. К ним относятся sort, stable_sort, nth_element, binary_search, lower_bound, upper_bound, equal_range, merge, includes, min, max, min_element, max_element, lexographical_compare и другие.
3. Функции для выполнения определённых арифметических действий над членами коллекции. К ним относятся accumulate, inner_product, partial_sum, adjacent_difference
*/

/*
* Также алгоритмы STL можно разделить на теоретико-множественные, которые позволяют выполнять операции слияния (std::merge),
объединения (std::set_union), пересечения (std::set_intersection), разности (std::set_difference),
симметрической разности (std::set_symmetric_difference) над отсортированными последовательностями
*/

struct Example
{
    float operator () (int a, double b) { return a - b; }

    static float product(int a, double b) { return a * b; }
};

int main()
{
    std::vector<int> a = { 5, 8, 6,-1, 0 };
    std::vector<float> b = { 10.1, 11.5, -100, 4.8 };
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::copy(b.begin(), b.end(), std::ostream_iterator<float>(std::cout, " "));
    std::cout << std::endl;

    auto sixIter = std::find(a.begin(), a.end(), 6);
    std::cout << sixIter - a.begin() << " " << *sixIter << std::endl;

    std::vector<float> output(b.size());
    std::transform(b.begin(), b.end(), output.begin(), [](float a) { return a * 2; });
    std::copy(output.begin(), output.end(), std::ostream_iterator<float>(std::cout, " "));
    std::cout << std::endl;

    std::sort(a.begin(), a.end()); // TODO: sort-function
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // sort vs stable_sort
    // nth_element - (begin_iter, n_iter, end_iter, comp_func)

    auto rez = std::inner_product(a.begin(), a.begin() + 2, b.begin(), 0);

    // функторы, лямбда
    std::function <float(int, double)> operation = [](int a, double b) /* -> float */ { return a + b; };
    std::cout << operation(1, 2.2) << std::endl;
    operation = Example{};
    std::cout << operation(1, 2.2) << std::endl;
    operation = Example::product;
    std::cout << operation(1, 2.2) << std::endl;
    // [&], [=], [&x, y], [z = x+y]

    // random - pseudo-random generation in c++
    // Seed with a real random value, if available
    std::random_device r;

    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    int mean = uniform_dist(e1);
    std::cout << "Randomly-chosen mean: " << mean << std::endl;;
}