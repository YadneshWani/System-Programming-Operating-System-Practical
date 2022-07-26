#include<iostream>
using namespace std;

class PageReplacementAlgorithm
{
  int queue[3];
  int front,rear;
  int pf;
  public :
  PageReplacementAlgorithm()
  {
      front=rear=-1;
      pf=0;
  }
  void insert()
  {
      //cout<<"Function Call";
      int no;
      cout<<"\nEnter the Number ";
      cin>>no;
      
      if(front==-1 && rear==-1)
      {
          front=rear=0;
          queue[rear]=no;
          cout<<"Page Miss";
          pf++;
      }
      else
        if(rear!=2)
        {
            rear++;
            queue[rear]=no;
            cout<<"Page Miss";
            pf++;
        }
      else
        if(rear==2)
        {
            queue[front]=no;
            front++;
            cout<<"Page Hit";
            pf++;
        }
        cout<<"\nQueue Elements\n";
        for(int i=0;i<=rear;i++)
        {
            cout<<"|"<<queue[i]<<"|\n";
        }
        
        if(front==3)
            front=0;
        
        
  }
  void PageFault()
  {
      cout<<"\nTotal Number of Page Fault :- "<<pf;
  }
  
};

int main()
{
    int ch;
    PageReplacementAlgorithm obj;
    do{
        cout<<"\n------------MENU------------\n1.Insert a Page\n2.Total Number of Page Fault\n3.Exit\n";
        cin>>ch;

    
         switch(ch)
        {
            case 1:obj.insert();break;
            case 2:obj.PageFault();break;
            case 3:break;
            default:cout<<"Invalid Choice ";
        }
    }while(ch!=3);
    
    return 0;
    
}