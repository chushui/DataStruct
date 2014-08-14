#include<iostream>
#include<vector>
#include<string>
using namespace std; 

pair<int ,string> fun(const string & str)
{
    vector<string> substrs;
    int i,j,len=str.length();
    int count=1,maxcout=1;
    string substr;
    for(i=0;i<len;i++)
    {
	substrs.push_back(str.substr(i,len-i));
	//cout<<str.substr(i,len-i)<<endl;
    }
    for(i=0;i<len;i++)
    {
	for(j=i+1;j<len;j++)
	{
	    count=1;
	    if(substrs[i].substr(0,j-i)==substrs[j].substr(0,j-i))
	    {
		count++;
		for(int k=j+(j-i);k<len;k+=(j-i))
		    if(substrs[i].substr(0,j-i)==substrs[k].substr(0,j-i))
			count++;
	            else
		        break;
	    
	   	if(count>maxcout)
	   	{
	            maxcout=count;
         	    substr=substrs[i].substr(0,j-i);
	   	}
	    }
	}
   }
    return make_pair(maxcout,substr);
}
int main()
{
    pair<int, string> rs;  
    string str="hshshsjdlkjfdslhs";
    rs=fun(str);
    cout<<rs.first<<rs.second<<endl;
}
