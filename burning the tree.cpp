//https://practice.geeksforgeeks.org/problems/burning-tree/1?track=amazon-trees

class Solution {
  public:
  Node * findtarget(Node * &root,unordered_map<Node *,Node *> &parentof,int &target){
      queue<Node *> q;
      q.push(root);
      Node * mytarget=NULL;
      parentof[root]=NULL;
      while(!q.empty()){
          Node * front= q.front();
          q.pop();
          if(front->data==target)
          {
              
              mytarget=front;
          }
          if(front->left){
              parentof[front->left]=front;
              q.push(front->left);
          }
          if(front->right){
              parentof[front->right]=front;
              q.push(front->right);
          }
      }
      return mytarget;
  }
  
 void burntree(Node * &root,unordered_map<Node *,Node *>& parentof,int &time)
 {
     unordered_map<Node *,bool> visited;
      queue<Node*> q;
      q.push(root);
      visited[root]=true;
      while(!q.empty()){
          int size=q.size();
          bool flag=false;
          for(int i=0;i<size;i++){
              Node * front=q.front();
              q.pop();
              if(front->left && !visited[front->left]){
                  q.push(front->left);
                  visited[front->left]=true;
                  flag=true;
              }
               if(front->right && !visited[front->right]){
                  q.push(front->right);
                   flag=true;
                  visited[front->right]=true;
              }
              if(parentof[front] && !visited[parentof[front]]){
                  q.push(parentof[front]);
                   flag=true;
                  visited[parentof[front]]=true;
              }
                
          }
          if(flag)
          {
                  time++;
          }
      
      }
      
  }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node *,Node *> parentof;
        Node * mytarget=findtarget(root,parentof,target);
        int time=0;
        burntree(mytarget,parentof,time);
        return time;
    }
};