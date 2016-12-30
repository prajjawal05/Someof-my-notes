//Snippet for maximum sum
ll start = 0,i=0;
    while(i<n)
    {
        if(sum>max)
            max=sum;
        while(sum+a[i]>m && start<i)
        {
            sum-=a[start];
            start++;
        }
        if(a[i]>m)
        {
            i++;
            continue;
        }
        sum+=a[i];
        i++;
        if(sum>max)
            max=sum;
    }
