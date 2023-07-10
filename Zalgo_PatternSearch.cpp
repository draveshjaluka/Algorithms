/* Question Link:
https://www.codingninjas.com/codestudio/problems/pattern-searching-using-z-algorithm_8395752 */

/* New Day new alogrithm, this is a pattern searching algorithm by which we can identify the precense of pattern in the given string, it creates a z function array,
which is responsible to store the length of the pattern matched string.

What we do here is we concatenate the pattern string and source string with a special character(pattern+$+source)
Now the z function duty is to store the lenght the string which contains the prefix(i.e. pattern) and after this we simply match the z array to find the where value is
same as pattern length and get the pos as (indes-pattern_length-1); */

vector<int> search(string s, string pat) {
    // Write Your Code Here
	string a=pat+"$"+s;
	int len=a.size();
	 int z[len];
	 z[0]=0;
	 getz(a,z);
	 vector<int> ans;
	 for(int i=0;i<len;i++)
	 {
		 if(z[i]==pat.size())
		 {
			 //cout<<i;
			 ans.push_back(i-pat.size());
		 }
		 	//ans.push_back(i+1);		 	
	 }
	 return ans;
}
void getz(string a,int *z)
{
	int n=a.size();
	int l=0,r=0;
	int k;
	for(int i=1;i<n;i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<n && a[r]==a[r-l])
				r++;
			z[i]=r-l;
			//cout<<z[i]<<endl;
			r--;
			//cout<<1<<endl;
		}
		else
		{
			k=i-l;
			if(z[k]<r-i+1) z[i] =z[k];
			else
			{
				l=i;
				while(r<n && a[r]==a[r-l])
					r++;
				z[i]=r-l;
				r--;
			}
		}
	}
	
}
