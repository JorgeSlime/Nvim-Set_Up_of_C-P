template<typename T>
    T bs(vector<T> &v, T target,T l,T r){
        while(l<=r){
            T m=l+(r-l)/2;
            if(v[m]==target) return m;
            v[m]<target?l=m+1:r=m-1;
        }
        return -1;
    }
