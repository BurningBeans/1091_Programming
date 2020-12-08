#include <bits\stdc++.h>
#include "cocktailsort.h"
#include "selectionsort.h"
int main()
{
    std::vector <int> numbers;
    int input;
    while(std::cin>>input)
    {
        numbers.push_back(input);
    }
    //cocktail_sort(numbers);
    //selection_sort(numbers);
    for (auto i : numbers) // access by const reference
    std::cout << i << ' ';
}