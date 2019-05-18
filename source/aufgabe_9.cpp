# include <cstdlib>
# include <vector>
# include <list>
# include <iostream>
# include <iterator>
# include <algorithm>

int main() {

    std::vector<int> v_0(10);       //erstellt vector v_0 mit 10 (leeren) elem.

    for (auto &v : v_0) {           //füllt v_0 mit zufallszahlen
        v = std::rand();
    }

    std::cout << "\nv_0:\n" << std::endl;

    std::copy(std::cbegin(v_0), std::cend(v_0), std::ostream_iterator<int>(std::cout, "\n"));   //gibt v_0 aus

    std::list<int> l_0(std::cbegin(v_0), std::cend(v_0));   //erstellt l_0 mit gleichen elem. wie v_0 (v_0 ist const)

    std::list<int> l_1(std::cbegin(l_0), std::cend(l_0));   //erstellt l_1 mit gleichen elem. wie l_0 (l_0 ist const)

    std::reverse(std::begin(l_1), std::end(l_1));       //dreht reihenfolge der Elemente in l_1 um

    std::cout << "\nl_1 (same as v_0 & inverted):\n" << std::endl;

    std::copy(std::cbegin(l_1), std::cend(l_1), std::ostream_iterator<int>(std::cout, "\n"));   //gibt l_1 aus

    l_1.sort();     //sortiert l_1

    std::cout << "\nl_1 (sorted):\n" << std::endl;

    std::copy(l_1.cbegin(), l_1.cend(), std::ostream_iterator<int>(std::cout, "\n"));       //gibt l_1 aus

    std::generate(std::begin(v_0), std::end(v_0), std::rand);       // assigns new random values for all elements in v_0

    std::cout << "\nv_0 (with newly generated random numbers):\n" << std::endl;

    std::copy(v_0.crbegin(), v_0.crend(), std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}