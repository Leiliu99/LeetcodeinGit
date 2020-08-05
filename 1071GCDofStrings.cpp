class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)//if one is alredy the mutiply of another
		    ? str1.substr(0, gcd(size(str1), size(str2)))//get the common greatest divisor of two sizes
			: "";//otherwise these two could not form a grd at all, simply return an empty string


    }
};