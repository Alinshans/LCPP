// Title: Implement strStr()
// Language: C++
// Runtime: 4 ms
// Submitted: 2016/7/12

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (!needle.length() || !haystack.compare(needle))  return 0;
		int next[needle.length()];
		int i = 0, j = next[0] = -1;
		while (i<needle.length())
		{
			while (j != -1 && needle[i] != needle[j])    j = next[j];
			next[++i] = ++j;
		}
		i = j = 0;
		while (i < haystack.length())
		{
			while (j != -1 && haystack[i] != needle[j])
				j = next[j];
			i++;
			j++;
			if (j >= needle.length())    return i - needle.length();
		}
		return -1;
	}
};
