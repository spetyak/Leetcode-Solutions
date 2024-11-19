#include <iostream>
#include <vector>

using namespace std;

/*
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 29.47% of C++ submissions
 */

class Solution {
public:

    vector<int> graySequence; // the sequence of binary numbers

    /*
     * Flips individual bits of the given integer recursively,
     * generating the next number in the gray code sequence.
     *
     * @param a the integer being modified to be the next number in the sequence
     * @param n the number of bits to alter
     */
    void flipBits(int &a, int n) {

        a ^= 1 << n; // flip the nth bit of a

        graySequence.push_back(a); // add the new slightly altered number to the sequence

        // flip all bits of a within the range [0, n)
        for (int i = 0; i < n; i++)
        {
            flipBits(a, i);
        }

    }

    /*
     * Generates a sequence of binary numbers where all adjacent numbers and the 
     * first and last value differ by a single bit.
     *
     * @param n the number of bits each number in the sequence has
     * 
     * @return The gray code sequence of binary numbers.
     */
    vector<int> grayCode(int n) {

        int a = 0; // base value
        graySequence.push_back(a); // add base value to sequence

        // start flipped bit at all bits in range [0, n)
        for (int i = 0; i < n; i++)
        {
            flipBits(a, i);
        }

        return graySequence;
        
    }

};

int main() {

    Solution s;

    int n = 3;

    vector<int> output = s.grayCode(n);

    cout << "Output:" << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;

}