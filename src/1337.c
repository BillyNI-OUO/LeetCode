//The K Weakest Rows in a Matrix

class Solution {
public:
	struct cmp{
		bool operator()(pair<int, int> a, pair<int, int> b) {
        	if(a.first == b.first)return a.second > b.second;
        	return a.first > b.first;

    	}
	};
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
  		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  		for(int i = 0; i < mat.size(); i ++){
  			int cnt = 0;
  			for(int j = 0; j < mat[i].size(); j ++){
  				if(mat[i][j] == 1)cnt++;
  			}

  			pq.push({cnt, i});
  		}
  		vector<int> res;
  		for(int i = 0; i < k; i ++){
  			auto temp = pq.top();
  			pq.pop();
  			res.push_back(temp.second);
  		}      
  		return res;
    }
};