#define d 256
class Solution {
    long long q=INT_MAX;
public:
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        string txt=a;
        int c=1;
        while(txt.size()<b.size())
        {
            c++;
            txt+=a;
        }

        if(txt==b) return c;

        if(rabin(txt,b)!=-1) {return c;}
        //cout<<"a";
        if(rabin(txt+a,b)!=-1) return c+1;
        //cout<<"b";
        return -1;
    }
    int rabin(string s,string b)
    {
        int n=s.size();
        int m=b.size();
        long long p=0;
        long long t=0;
        long long h=1;
        
        for(int i=0;i<m-1;i++) h = (h*d)%q;
        for(int i=0;i<m;i++)
        {
            p = (d*p+b[i])%q;
            t=(d*t+s[i])%q;
        }
        //cout<<n-m;
        for(int i=0;i<=n-m;i++)
        {
            if(p==t)
            {
                
                int j;
                for( j=0;j<m;j++)
                {
                    if(s[i+j]!=b[j]) break;
                }
                if(j==m)
                {
                    return 1;
                }
            }
            //cout<<3;
            //cout<<endl<<i<<" "<<n-m<<endl;
            if(i<n-m)
            {
                t=(d*(t-s[i]*h)+s[i+m])%q;
               // cout<<t;
                if(t<0) t+=q;
            }
        }
        //cout<<2;
        return -1;

    }

};
