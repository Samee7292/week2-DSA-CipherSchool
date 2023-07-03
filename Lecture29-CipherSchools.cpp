#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;

class Heap
{
public:
    vector<int> getvector(int n)
    {   vector<int> operation;
        int a;
        cout<<"Enter the elements: "<<endl;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            operation.push_back(a);

        }
        return operation;

    }
   //==========================================index operation=======================================================

    int getleftchild(vector<int> &operation, int parent)
    {
      int leftchildindex=(parent*2)+1;
      if(leftchildindex<operation.size())
      {
          return leftchildindex;
      }
      else return -1;

    }

    int getrightchild(vector<int> &operation, int parent)
    {
      int rightchildindex=(parent*2)+2;
      if(rightchildindex<operation.size())
        return rightchildindex;

      else return -1;

    }

    int getparent(int child)
    {
         return (child-1)/2;

    }
     //===============================================================insert=======================================
    void doinsert(vector<int> &operation)
    {   cout<<"insert your element at the end;";
        int a;
        cin>>a;
        operation.push_back(a);
        doprecolateup(operation, operation.size()-1);
    }

    void doprecolateup(vector<int> &operation, int pos)
    {

        int parentindex=getparent(pos);
        if(operation[parentindex]<operation[pos])// to maintain max heap
        {
            swap(operation[parentindex], operation[pos]);
            doprecolateup(operation, parentindex);
        }
    }
    //====================================================delete element==================================================
    void dodelete(vector<int> &operation)
    {
        operation[0]=operation[operation.size()-1];
        operation.pop_back();

        doprecolatedown(operation, 0);
    }

    void doprecolatedown(vector<int> &operation, int pos)
    {
        int leftchildindex=getleftchild(operation, pos);
        int rightchildindex=getrightchild(operation, pos);
        int maxindex=pos;

        if(leftchildindex!=-1 && operation[leftchildindex]>operation[maxindex])
            maxindex=leftchildindex;

        if(rightchildindex!=-1 && operation[rightchildindex]>operation[maxindex])
            maxindex=rightchildindex;

        if(pos!=maxindex)
        {
            swap(operation[pos], operation[maxindex]);
            doprecolatedown(operation, maxindex);
        }


    }

    //====================================================show=====================================================================
    void show(vector<int> &operation)
    {
        cout<<"showing vector: "<<endl;
        for(int i=0; i<operation.size(); i++)
        {
            cout<<operation[i]<<" " ;
        }
        cout<<endl;
    }



};

int main()
{
    Heap obj;
    vector<int> operation;

    cout<<"Enter the size of vector: "<<endl;
    int n;
    cin>>n;

    operation=obj.getvector(n);
    obj.show(operation);

    obj.doinsert(operation);
    obj.show(operation);

    obj.dodelete(operation);
    obj.show(operation);

}
