#include<iostream>
#include<fstream>

using namespace std;
class temp{
    string id,author,name, search;
    string search_name,search_password,search_phone;
    public: 
        void add();
        void show();
        void extract();

}obj;

int main(){
    int choice;
    
    
    while(true){
        cout<<"enter your choice: "<<endl;
        cout<<"1. Add book"<<endl;
        cout<<"2. Show all books"<<endl;
        cout<<"3. Extract book"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>choice;
        
        switch(choice){
            case 1:
            obj.add();
            break;

            case 2:
            obj.show();
            break;
            
            case 3:
            obj.extract();
            break;
            
            case 4:
            return 0;
            break;

            default:
            cout<<"Invalid choice please try again."<<endl;
            break;
        }
    }    
    return 0;
}

void temp:: add(){
    cout<<"-------Add book-------"<<endl;
    cout<<"enter book id: "<<endl;
    cin>>id;
    cout<<"enter book name: "<<endl;
    cin>>name;
    cout<<"enter book author: "<<endl;
    cin>>author;

    ofstream file;

    file.open("library.txt",ios::app);

    if(!file){
        cout<<"error opeaning file!!"<<endl;
        return;
    }

    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();
    cout<<"-------------------"<<endl;
    cout<<"book added successfully!!"<<endl;
    cout<<"\n\n";
}

void temp:: show(){
    cout<<"-------Show all books-------"<<endl;
    
    ifstream file;
    file.open("library.txt",ios::in);

    if(!file){
        cout<<"Error opeaning the file"<<endl;
        return ;
    }

    cout<<"id"<<"\t"<<"name"<<"\t"<<"author"<<endl;
    while(getline(file,id,'*') && getline(file,name,'*') && getline(file,author)){
        cout<<endl;
        cout<<id<<"\t"<<name<<"\t"<<author<<endl;
    }

    cout<<"-------------------"<<endl;
    cout<<"All books shown successfully!!"<<endl;
    file.close();

}

void temp:: extract(){
    cout<<"-------Extract book-------"<<endl;
    cout<<"enter book name: "<<endl;
    cin>>search;

    ifstream file;
    file.open("library.txt",ios::in);

    if(!file){
        cout<<"Error opening file!!"<<endl;
        return;
    }
    bool found=false;
    while(getline(file,id,'*') && getline(file,name,'*') && getline(file,author)){
       if(search==name){
            cout<<"-------------------"<<endl;
            cout<<"book id: "<<id<<endl;
            cout<<"book name: "<<name<<endl;
            cout<<"book author: "<<author<<endl;
            cout<<"-------------------"<<endl;
            found=true;
            break;
        }
       
    }
    file.close();

    if(!found){
        cout<<"book not found!!"<<endl;
        cout<<"-------------------"<<endl;
    }

    
}
