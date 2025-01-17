#include "PmergeMe.hpp"
#include <cmath>
#include <deque>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& pm) { (void)pm; }
PmergeMe& PmergeMe::operator=(const PmergeMe& pm)
{
    (void)pm;
    return *this;
}
PmergeMe::~PmergeMe() {}

long _jacobsthal_number(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }

void PmergeMe::sort_vec(std::vector<int>& vec) { _merge_insertion_sort<std::vector<int> >(vec, 1); }

void PmergeMe::sort_deque(std::deque<int>& deque)
{    _merge_insertion_sort<std::deque<int> >(deque, 1);}