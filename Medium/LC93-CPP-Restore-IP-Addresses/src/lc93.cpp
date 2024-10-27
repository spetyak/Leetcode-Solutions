#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 43% of C++ submissions
 */

class Solution {
public:

    vector<string> possAddresses; // all valid IP addresses that can be made from the given digits

    /*
     * Construct all possible IP's from the given string of digits by recursively attempting 
     * using different sizes of digit combinations for each portion of the IP address.
     *
     * @param given the original 'corrupted' string of digits to be restored to a valid IP address
     * @param currentIP the current restored IP address being built
     * @param portion the current portion of the IP address being worked on
     * @param index the index of the current starting digit being used to create the current portion
     */
    void constructIP(string given, string currentIP, int portion, int index) {

        // if the final portion has been reached
        if (portion > 3)
        {

            // if the current IP being considered is the same size as the original 'corrupted' IP 
            // when the separating dots are removed
            if (currentIP.size()-4 == given.size())
            {

                currentIP.erase(currentIP.size()-1);    // remove final '.'
                possAddresses.push_back(currentIP);     // add valid IP to list of possible addresses

            }
            
            return;

        }

        // for each portion, try different sizes of numbers
        for (int i = 0; i < 3; i++)
        {

            // if it's possible to make a number of size i+1 starting from index in the given string
            if (index+i < given.size())
            {

                // if the current number being made is more than a single character and has a leading 0
                if (i+1 > 1 and given[index] == '0')
                {
                    continue;
                }

                string portionString = given.substr(index, i+1); // grab i+1 numbers from the given string
                int portionNumber = stoi(portionString);            

                // if the number grabbed is within the legal limit of an IP portion number
                if (0 <= portionNumber and portionNumber <= 255)
                {

                    currentIP.append(portionString).append(".");                // add a '.' to separate the current and next portion
                    constructIP(given, currentIP, portion+1, index + (i+1));    // attempt different sizes of next portion
                    currentIP.erase(currentIP.end() - (i+2), currentIP.end());  // remove the last portion added

                }
                
            }

        }

        return;

    }

    /*
     * Given a string s containing only digits, returns all possible valid IP addresses 
     * that can be formed by inserting dots ('.') into s.
     *
     * @param s the string of digits
     * 
     * @return All possible valid IP addresses that can be formed by inserting dots ('.') into s
     */
    vector<string> restoreIpAddresses(string s) {

        int portion = 0;        // counter used to track which portion is being worked on
        string currentIP = "";  // the current IP address being built

        // if the number of digits given could not represent a valid IP address
        if (s.size() < 4 and s.size() > 12)
        {
            return possAddresses;
        }

        constructIP(s, currentIP, portion, 0);

       

        return possAddresses;    
        
    }

};

int main() {

    Solution s;

    vector<string> output = s.restoreIpAddresses("25525511135");

    cout << "Output:" << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }

    return 0;

}