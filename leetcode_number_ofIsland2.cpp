class Solution{
public:
    unordered_map<int,int> leader;
    int getLeader(int num){
        if(num==leader[num]){
            return num;
        }
        return leader[num]=getLeader(leader[num]);
    }
    void Union(int l1,int l2){
        leader[l2]=l1;
    }
    vector<int> numIslands2(int n, int m, vector<Point> &operators){
        vector<int> ans;
        int groups=0;
        vector<vector<int>> mat(n);
        for(int i=0;i<n;i++){
            vector<int> temp(m);
            mat[i]=temp;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=0;
            }
        }
        for(int i=0;i<operators.size();i++){
            int row=operators[i].x;
            int col=operators[i].y;
            if(mat[row][col]==1){
                ans.push_back(groups);
                continue;
            }
            mat[row][col]=1;
            int num=row*m+col;
            groups++;
            leader[num]=num;
            int row_dir[]={1,-1,0,0};
            int col_dir[]={0,0,1,-1};
            for(int k=0;k<4;k++){
                int r=row+row_dir[k];
                int c=col+col_dir[k];
                if(r<0 or c<0 or r>=n or c>=m or mat[r][c]==0){
                    continue;
                }
                int l1=getLeader(row*m+col);
                int l2=getLeader(r*m+c);
                if(l1!=l2){
                    groups--;
                    Union(l1,l2);
                }
            }
            ans.push_back(groups);
        }
        return ans;
    }
};