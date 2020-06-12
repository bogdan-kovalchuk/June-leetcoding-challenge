#include <iostream>
#include <vector>
//#include <random>
#include <set>


using std::vector;
using std::set;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool retval = false;
        if (s.find(val) == s.end()){
            s.insert(val);
            retval = true;
        }
        return retval;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool retval = false;
        if (s.find(val) != s.end()){
            s.erase(val);
            retval = true;
        }
        return retval;
    }

    /** Get a random element from the set. */
    int getRandom() {
        auto it = s.begin();
        int random = std::rand() % s.size();
        std::advance(it, random);
        return *it;
    }
private:
    set<int> s;
};


int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

// Init an empty set.
    RandomizedSet *randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
    randomSet->insert(1);

// Returns false as 2 does not exist in the set.
    randomSet->remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
    randomSet->insert(2);

// getRandom should return either 1 or 2 randomly.
    randomSet->getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
    randomSet->remove(1);

// 2 was already in the set, so return false.
    randomSet->insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
    randomSet->getRandom();

    return 0;
}
