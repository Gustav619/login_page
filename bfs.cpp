    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    typedef vector<int> vi;
    typedef vector<long long> vll;
    typedef pair<int,int> pi;
     
    const ll mod = 1e9 + 7;
     
    #define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    #define sidha(i,a,b) for(ll i=a;i<=b;++i)
    #define ulta(i,a,b) for(ll i=b;i>=a;--i)
    #define test ll t;cin>>t;while(t--)
  //  #define pb push_back;
    #define mp make_pair
    #define log2(X) (63ll - __builtin_clzll(X))
    #define endl '\n'
    #define modinv(x) power(x, mod-2)
     
    ll power(ll x, ll y) { 
        ll ans=1;
        x=x%mod;
        while(y>0) { 
            if (y&1) 
                ans=(ans*x)%mod; 
            y=y>>1;
            x=(x*x)%mod; 
        } 
        return ans; 
    }
    void bfs(ll k, ll n ,ll dis[],vector<pair<ll,ll>> arr[])
    {
        ll a;
        queue<ll> q;
        ll visited[n+1]={0};
        visited[k]=1;
        for(ll i=0;i<arr[k].size();++i)
        {
            q.push(arr[k][i].first);
            visited[arr[k][i].first]=1;
            dis[arr[k][i].first]=arr[k][i].second;
        }
        
        while(!q.empty())
        {
            a=q.front();
            q.pop();
            for(ll i=0;i<arr[a].size();++i)
            {
                if(visited[arr[a][i].first]==0)
                {
                    visited[arr[a][i].first]=1;
                    dis[arr[a][i].first]=dis[a]+arr[a][i].second;
                    q.push(arr[a][i].first);
                }
            }
        }
    }
    int main()
    {
        boost;
        ll n,a,b,c,q,k;
        cin>>n;
        vector<pair<ll,ll>> arr[n+1];
        ll dis[n+1];
        sidha(i,1,n-1)
        {
            cin>>a>>b>>c;
            arr[a].push_back(mp(b,c));
            arr[b].push_back(mp(a,c));
        }
        cin>>q>>k;
        bfs(k,n,dis,arr);
        for(ll i=0;i<q;++i)
        {
            cin>>a>>b;
            cout<<dis[a]+dis[b]<<endl;
        }
        return 0;
    }