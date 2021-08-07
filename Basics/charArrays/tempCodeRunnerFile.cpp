string arr[7] = {"I", "V", "X", "L", "C", "D", "M"};
    string vals = "";
    int power = 1;
    for (int i = num; i != 0; i /= 10)
    {
        int dig = i % 10;
        int val = dig * power;
        vals += to_string(val) + " ";
        power *= 10;
    }
    cout << vals << endl;
    string ans = "";
    char *ptr = strtok((char *)vals.c_str(), " ");
    int a = atoi(ptr);
    if (a > 5)
    {
        if (a == 9)
        {
            ans += arr[0] + arr[2];
        }
        else
        {
            ans += arr[1];
            for (int i = 6; i <= a; i++)
            {
                ans += arr[0];
            }
        }
    }
    else if (a < 5)
    {
        if (a == 4)
        {
            ans += arr[0] + arr[1];
        }
        else
        {
            for (int i = 1; i <= a; i++)
            {
                ans += arr[0];
            }
        }
    }
    else
    {
        ans += arr[1];
    }
    ans += " ";
    int step = 2, powerr = 10;
    while (ptr != NULL)
    {
        ptr = strtok(NULL, " ");
        int a = atoi(ptr);
        if(a == 0) {
            powerr *= 10;
            step += 2;
            continue;
        }
        a = a/powerr;
        
        if (a > 5)
        {
            if (a == 9)
            {
                ans += arr[0 + step] + arr[2 + step];
            }
            else
            {
                ans += arr[1+step];
                for (int i = 6; i <= a; i++)
                {
                    ans += arr[0+step];
                }
            }
        }
        else if (a < 5)
        {
            if (a == 4)
            {
                ans += arr[0+step] + arr[1+step];
            }
            else
            {
                for (int i = 1; i <= a; i++)
                {
                    ans += arr[0+step];
                }
            }
        }
        else
        {
            ans += arr[1+step];
        }
        ans += " ";
        step += 2;
        powerr *= 10;
    }
    cout<<ans<<endl;
    string finans = "";
    int len = 0;
    for(int i=0;i<ans.length();i++){
        if(ans[i]==' '){
            len++;
        }
    }
    string *ar = new string[len];
    char *p = strtok((char *)ans.c_str()," ");
    ar[0] = p;
    for(int i =1;i<len;i++){
        p = strtok(NULL," ");
        ar[i] = p;
    }
    reverse(ar,ar+len);
    for(int i=0;i<len;i++){
        finans += ar[i];
    }  
    cout<<finans;