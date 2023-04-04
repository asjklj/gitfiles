#include "seqList.h"
#include "sLinkList.h"
int main(){
    //顺序表测试
    // seqList<char>chList(21);
    // char tmp;
    // int n,i,j;
    // cout <<"seqList test:"<<endl;
    // cout <<"number of the elements:"<<endl;
    // cin>>n;
    // cin.get(tmp);
    // cout <<"input the elements:"<<endl;
    // for(int i=0;i<n;i++){
    //     cin.get(tmp);
    //     chList.insert(i,tmp);
    // }
    // tmp= chList.visit(0);
    // chList.remove(0);
    // chList.insert(chList.length()/2,tmp);
    // cout <<"output the elements:"<<endl;
    // chList.traverse();

//单链表测试
    sLinkList<char>sList;
    char tmp;
    int n,i,j;
    cout <<"sLinkList test:"<<endl;
    cout <<"number of the elements:"<<endl;
    cin>>n;
    cin.get(tmp);
    cout <<"input the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin.get(tmp);
        sList.insert(i,tmp);
    }
    tmp= sList.visit(0);
    sList.remove(0);
    sList.insert(sList.length()/2,tmp);
    cout <<"output the elements:"<<endl;
    sList.traverse();
    sList.reverse();
    cout <<"reverse the List elements:"<<endl;
    sList.traverse();
}