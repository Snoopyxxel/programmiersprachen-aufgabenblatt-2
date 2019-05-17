#include <list>
#include <random>
#include <iostream>
#include <set>
#include <map>

int main(){
    std::list<unsigned int> rand100(100);
    std::set<unsigned int> diff_num;
    std::map<unsigned int, unsigned int> count_diffs;

    for(auto & i : rand100)
        i = random() % 10;

    for (auto i : rand100)
        diff_num.insert(i);

    for (auto i : rand100)
        count_diffs[i] += 1;

    for(auto i : rand100)
        std::cout << i << ", ";

    std::cout << "\nDifferent Elements: ";
    for (auto i : diff_num)
        std::cout << i << ", ";

    std::cout << "\n[Zahl : Häufigkeit] : ";
    for (auto const& i : count_diffs)
        std::cout << "[" << i.first << " : " << i.second << "], ";

    std::cout << "\nSize of list is: " << rand100.size() << std::endl;
    std::cout << "There are " << diff_num.size() << " different Elements in the list." << std::endl;
}