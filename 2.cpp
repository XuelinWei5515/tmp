#include <bits/stdc++.h>

using namespace std;
#define db double
const db eps = 1e-10;
const int MAXN = 1e4 + 100;
int sgn(db x){
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}
struct Point{
    db x, y;
    Point(){}
    Point(db x, db y): x(x), y(y){}
    Point operator + (const Point &B)const{
        return Point(x + B.x, y + B.y);
    }
    Point operator - (const Point &B)const{
        return Point(x - B.x, y - B.y);
    }
    bool operator < (const Point &B)const{
        return sgn(x - B.x) < 0 || (sgn(x - B.x) == 0 && sgn(y - B.y) < 0);
    }
    bool operator == (const Point &B)const{
        return sgn(x - B.x) == 0 && sgn(y - B.y) == 0;
    }
}s[MAXN], ch[MAXN];
typedef Point Vector;
db Cross(Vector A, Vector B){
    return A.x * B.y - A.y * B.x;
}
int Convex_hull(int n){
    int v = 0;
    for(int i=0;i<n;i++){
        while(v > 1 && sgn(Cross(ch[v - 1] - ch[v - 2], s[i] - ch[v - 2])) <= 0){
            v -= 1;
        }
        ch[v++] = s[i];
    }
    int j = v;
    for(int i=n-2;i>=0;i--){
        while(v > j && sgn(Cross(ch[v - 1] - ch[v - 2], s[i] - ch[v - 2])) <= 0){
            v -= 1;
        }
        ch[v++] = s[i];
    }
    if(n > 1) v -= 1;
    return v;
}
bool check(Point A, int n){
    int l = 1;
    int r = n - 1;
    while(r - l > 1){
        int mid = ((r - l) >> 1) + l;
        db a1 = Cross(ch[mid] - ch[0], A - ch[0]);
        db a2 = Cross(ch[mid + 1] - ch[0], A - ch[0]);
        if(sgn(a1) >= 0 && sgn(a2) <= 0){
            if(sgn(Cross(ch[mid + 1] - ch[mid], A - ch[mid])) >= 0) return true;
            return false;
        }else if(sgn(a1) < 0){
            r = mid;
        }else{
            l = mid;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    db x, y;
    while(cin >> n){
        for(int i=0;i<n;i++){
            cin >> s[i].x >> s[i].y;
        }sort(s, s + n);
        n = unique(s, s + n) - s;
        int len = Convex_hull(n);
        cin >> m;
        int ans = 0;
        for(int i=0;i<m;i++){
            cin >> x >> y;
            if(check(Point(x, y), len)) ans += 1;
        }
        cout << ans <<endl;
    }
    return 0;
}
