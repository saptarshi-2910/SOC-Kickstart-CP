// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
class Item{
  public:
    int val,wt;
    Item(int v,int w):val(v),wt(w){}
};

bool cmp(Item &a,Item &b){
    return (double)a.val/a.wt>(double)b.val/b.wt;
}

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<Item> items;
        for(int i=0;i<n;i++)items.emplace_back(val[i],wt[i]);
        sort(items.begin(),items.end(),cmp);
        double total=0.0;
        for(auto &item:items){
            if(capacity>=item.wt){
                total+=item.val;
                capacity-=item.wt;
            }else{
                total+=((double)item.val/item.wt)*capacity;
                break;
            }
        }
        return total;
    }
};