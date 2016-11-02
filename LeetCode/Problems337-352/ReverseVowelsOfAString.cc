// Title: Reverse Vowels of a String
// Language: C++
// Runtime: 16 ms
// Submitted: 2016/7/12

class Solution {
public:
	string reverseVowels(string &s) {
		int v[100000];
		int m = -1, i, j;
		for (i = 0; i < s.length(); i++)
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
				s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
				v[++m] = i;
		for (i = 0, j = m; i < j; i++, j--)
			swap(s[v[i]], s[v[j]]);
		return s;
	}
};
