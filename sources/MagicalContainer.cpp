
#include "MagicalContainer.hpp"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <algorithm>
#include <stdexcept>
using namespace std;
using namespace ariel;

void MagicalContainer :: addElement(int element){
	auto in = _elements.insert(element); // in gets a pair in this situation

	if (in.second) // checks if the insretion was sucssesful
	{
		/*Handle prime order -  find the correct place to insert the element. the lower_bound func returns 
        an iterator to the right palce which the ellemnt should be in , in order to keep an ascending order*/ 
		if (isPrime(element))
		{
			auto right_index = lower_bound(_elements_prime_order.begin(), _elements_prime_order.end(), &(*in.first), [](const int *a, const int *b) {
				return *a < *b;
			});

			_elements_prime_order.insert(right_index, &(*in.first));
		}

		// Handle ascending order -  find the correct place to insert the element.
		auto right_index = lower_bound(_elements_ascending_order.begin(), _elements_ascending_order.end(), &(*in.first), [](const int *a, const int *b) {
			return *a < *b;
		});

		_elements_ascending_order.insert(right_index, &(*in.first));

		// Handle sidecross order - rebuild the vector (Easier than reordering it).
		_elements_sidecross_order.clear();

		if (size() == 1)
			_elements_sidecross_order.push_back(_elements_ascending_order.front());

		else
		{
			size_t start = 0, end = size() - 1;

			while (start <= end && end != 0)
			{
				_elements_sidecross_order.push_back(_elements_ascending_order.at(start));

				if (start != end)
					_elements_sidecross_order.push_back(_elements_ascending_order.at(end));

				start++;
				end--;
			}
		}
	}

    
}

void MagicalContainer::removeElement(int element){
    
}


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& _container): container(_container), index(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& _container, size_t _index): container(_container), index(_index) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other): container(other.container), index(other.index) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& _container): container(_container), index(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& _container, size_t _index): container(_container), index(_index) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other): container(other.container), index(other.index) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& _container): container(_container), index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& _container, size_t _index): container(_container), index(_index) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other): container(other.container), index(other.index) {}