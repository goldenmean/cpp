
//Iterators

std::vector<int> nums = {1, 2, 3, 4};
std::istream_iterator<int> input(std::cin);
std::copy(input, std::istream_iterator<int>(), std::back_inserter(nums));

std::vector<int> nums = {1, 2, 3, 4};
std::ostream_iterator<int> output(std::cout, ", ");
std::copy(nums.begin(), nums.end(), output);

std::list<int> nums = {1, 2, 3, 4};
std::list<int>::reverse_iterator itr = nums.rbegin();
while (itr != nums.rend())
{
    std::cout << *itr << " ";
    ++itr;
}

//Bidirectional iterators
std::list<int> nums = {1, 2, 3, 4};
std::list<int>::iterator itr;
for (itr = nums.begin(); itr != nums.end(); ++itr) {
    std::cout << *itr << " ";
}
for (--itr; itr != nums.begin(); --itr) {
    std::cout << *itr << " ";
}

std::vector<int> nums = {1, 2, 3, 4};
std::vector<int>::iterator itr;
for (itr = nums.begin(); itr != nums.end(); ++itr) {
    std::cout << *itr << " ";
}
for (itr -= 1; itr != nums.begin() - 1; --itr) {
    std::cout << *itr << " ";
}

//STL Algorithm
#include <algorithm>
#include <iostream>
#include <vector> 
//using namespace std;
std::vector<int> nums = {1, 2, 3, 4};
std::sort(nums.begin(), nums.end());

std::find(nums.begin(), nums.end(), 3)

std::binary_search(nums.begin(), nums.end(), 3)

/*
std::stable_sort( ) 
std::partial_sort( )
std::nth_element( )
std::is_sorted( )
std::is_sorted_until( )
std::minmax_element( )
std::minmax( )
std::reverse( )
std::remove( )
std::remove_if( )
std::replace( )
std::replace_if( )
std::search( )
std::search_n( )
std::sort( )
std::sort( )
std::swap( )
std::swap_ranges( )
std::transform( )
std::unique( )
std::unique_copy( )
std::adjacent_difference( )
std::adjacent_find( )
std::count( )
std::count_if( )
std::equal( )
std::equal_range( )
std::find( )
std::find_end( )
std::find_first_of( )
std::find_if( )
std::find_if_not( )
std::find_last_of( )
std::find_last_not( )
std::mismatch( )
std::search_n( )
std::set_difference( )
std::set_intersection( )
std::set_symmetric_difference( )
std::set_union( )   
std::mismatch( )
std::equal( )
std::lexicographical_compare( )

*/