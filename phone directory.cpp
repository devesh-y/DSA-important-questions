//https://practice.geeksforgeeks.org/problems/phone-directory4628/1
class trienode{
    public:
        char data;
        trienode* children[26];
        bool isterminal;
        trienode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isterminal=false;
        }
};
class trie{
    public:
        trienode * root;
        trie(){
            root=new trienode('\0');
        }
        void insertchar(trienode * &root,string word){
            if(word.size()==0){
                root->isterminal=true;
                return;
            }
            int index=word[0]-'a';
            trienode *child;
            if(root->children[index])
            {
                child=root->children[index];
            }
            else{
                child=new trienode(word[0]);
                root->children[index]=child;
            }
            insertchar(child,word.substr(1));
        }
        void insert(string word){
            insertchar(root,word);
        }
    void printsuggestion(trienode *curr,vector<string> &temp,string prefix)
    {
        if(curr->isterminal){
            temp.push_back(prefix);
        }
        for(char ch='a';ch<='z';ch++){
            trienode *next=curr->children[ch-'a'];
            if(next){
                prefix.push_back(ch);
                printsuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }  
    vector<vector<string>> getsuggestion(string s)
    {
        trienode * prev=root;
        vector<vector<string>> output;
        string prefix="";
        for(int i=0;i<s.size();i++){
            char lastch=s[i];
            prefix.push_back(lastch);
            trienode * curr=prev->children[lastch-'a'];
            if(!curr){
                break;
            }
            vector<string> temp;
            printsuggestion(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;

        }
        int nowsize=output.size();
        int diff=s.size()-nowsize;
        vector<string> hello={"0"};
        for(int i=0;i<diff;i++){
            output.push_back(hello);
        }
        return output;
    }
        
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        trie* t=new trie();
        for(int i=0;i<n;i++){
            t->insert(contact[i]);
        }
        return t->getsuggestion(s);
        
    }
};