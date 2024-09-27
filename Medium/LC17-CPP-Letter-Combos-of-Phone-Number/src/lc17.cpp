#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 74.28% of C++ submissions
 * 
 */

class Solution {
public:

    map<char, string> numToLettersMap;  // a map of a phones number keys to their associated letters
    vector<string> output;              // a vector of all possible string combinations given a short sequence of numbers

    

    /*
     * Recursively build strings of all possible letter combinations using the given digits.
     *
     * @param digits the numbers to be used to create letter combinations
     * @param index the index of the current digit being used to add to the combination string
     * @param currentStr the current combination string being created
     */
    void createCombos(string digits, int index, string currentStr) {

        string letters = numToLettersMap.find(digits.at(index))->second; // determine the letters associated with the current number

        // use each letter to build a new string
        for (int i = 0; i < letters.size(); i++)
        {

            currentStr.push_back(letters.at(i)); // add current letter to the current combo string being built

            if (index != digits.size()-1)
            {
                createCombos(digits, index+1, currentStr); // continue building combination string
            }
            else
            {
                output.push_back(currentStr); // add the current string to the output vector
            }

            currentStr.pop_back(); // remove the last letter added to the current combo string

        }
        
    }

    /*
     * Given a string containing digits from 2-9 inclusive, 
     * return all possible letter combinations that the number could represent.
     *
     * @param digits the numbers to be used to create letter combinations
     *
     * @return a vector of all possible letter combinations using the given digits
     */
    vector<string> letterCombinations(string digits) {

        // populate phone number to letter map
        numToLettersMap['2'] = "abc";
        numToLettersMap['3'] = "def";
        numToLettersMap['4'] = "ghi";
        numToLettersMap['5'] = "jkl";
        numToLettersMap['6'] = "mno";
        numToLettersMap['7'] = "pqrs";
        numToLettersMap['8'] = "tuv";
        numToLettersMap['9'] = "wxyz";  

        // call recursive function to compute combinations
        createCombos(digits, 0, "");

        return output;

    }

};

int main() {

    Solution s;

    string digits = "23";

    vector<string> output = s.letterCombinations(digits);

    cout << "Output:" << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output.at(i) << " ";
    }
    cout << endl;

    return 0;

}
