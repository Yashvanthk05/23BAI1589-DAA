#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Activity{
  int start;
  int end;
};

int main(){
  int n;
  cin>>n;
  vector<Activity> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i].start>>arr[i].end;
  vector<int> halls;
  vector<int> hallsassigned(n);
  sort(arr.begin(),arr.end(),[](Activity a,Activity b){
    return a.start<b.start;
  });

  for(int i=0;i<n;i++){
    bool assigned=false;
    for(int j=0;j<halls.size();j++){
      if(halls[j]<=arr[i].start){
        halls[j]=arr[i].end;
        hallsassigned[i]=j+1;
        assigned=true;
        break;
      }
    }
    if(!assigned){
      halls.push_back(arr[i].end);
      hallsassigned[i]=halls.size();
    }
  }
  cout<<halls.size()<<endl;
  for(int i=0;i<n;i++) cout<<hallsassigned[i]<<" ";
  return 0;
}