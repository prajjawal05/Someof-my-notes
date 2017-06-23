/*
================================
    2017-06-23T14:36:32.893Z
    Prajjawal Agarwal
================================
Help from: https://math.berkeley.edu/~sagrawal/su14_math55/notes_shank.pdf
*/

#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%lld",&x)
#define pr(x) printf("%lld ", x)
#define prn() printf("\n")
#define lint long long int

map<lint,lint> ma;

lint power(lint a,lint b,lint mod)
{
	if(b==0)
		return 1;
	lint x=power(a,b/2,mod);
	if(b%2==0)
		return ((x%mod)*(x%mod))%mod;//if power(a,b/2)*power(a,b/2) then more time;
	else
		return ((((a%mod)*(x%mod))%mod)*(x%mod))%mod;//log b
}
int main()
{
    lint p,m,g,x,l,h,q;
    sc(p);
    sc(g);
    sc(h);

    m = ceil(sqrt(p));
    lint a[m];
    a[0] = 1;
    ma[1] = 1;

    for(lint i=1;i<m;i++)
    {
        a[i] = a[i-1]*g;
        ma[a[i]] = i+1;
        // pr(a[i]);
    }

    x = power(g,p-1-m,p);  //g^(-m)
    // pr(x);
    // prn();
    l = 1;
    for(q = 0;q<10;q++)
    {
        if(ma[(l*h)%p] == 0)
            l *= x;
        else
            break;
        // pr(l/x),pr(ma[l*h/x]);
    }
    // prn();
    // pr(q);
    //pr(ma[(l*h)%p] );
    pr(m*q + ma[(l*h)%p]-1);
    return 0;
}
