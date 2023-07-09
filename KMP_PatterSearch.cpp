/* In this algorithm our aim is to find a pattern in the given string, but in an efficient way, normally we can take a sliding window and start comparing which would
take O(mn), but using KMP we can do the pattern matching in O(m+n), because instead of backtracking in the main string we can know the positon in the pattern from
which we need compare again, we make and *lps* array which stores this information. 

Lps(longest prefix suffix): we pass the pattern string here and get the longest prefix which is also suffix, it is actually a preprocessing step that act as an map
which states at which position should we go if characters missmatch happens */

//code for finding lps, of string pat;
void lpsa(string pat,int m,int *lps)
{
	int len=0;
	lps[len]=0;
	int i=1;
	while(i<m)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else 
			{
				lps[i]=0;
				i++;
			}
		}
	}
}

//now using the lps map we will find the occurence postions of pattern in the given text
vector<int> stringMatch(string txt, string pat) {
	// Write your code here.
	int m=pat.size();
	int n=txt.size();
	vector<int>ans;
	int lps[m];
	lpsa(pat,m,lps);
	int i=0,j=0;
	while((n-i)>=(m-j))
	{
		if(txt[i]==pat[j])
		{
			i++;j++;
		}
		if(j==m)
		{
			ans.push_back(i-j+1);
			j=lps[j-1];
		}
		else if(i<n && pat[j]!=txt[i])
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else i=i+1;
		}
	}
	return ans;
}

