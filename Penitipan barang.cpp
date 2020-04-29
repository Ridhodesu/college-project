#include <iostream>
#include <conio.h>
#include <stdio.h>


using namespace std;

#define max_stak 15

struct stak{
    int top;
	string data[15],urut[15];
}tumpuk;

void push(string d){
    tumpuk.top++;
    tumpuk.data[tumpuk.top]=d;
    cout<<"Data berhasil dimasukkan \n";
    getch();
}

void pop(){
    cout<<tumpuk.data[tumpuk.top]<<" terambil \n";
    tumpuk.top--;
    getch();
}

int isFull(){
    if(tumpuk.top==max_stak-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(tumpuk.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void clear(){
    tumpuk.top=-1;
    cout<<"DATA CLEAR ";
}

void tukar(int a,int b)
{
    string t;
    t=tumpuk.urut[b];
    tumpuk.urut[b]=tumpuk.urut[a];
    tumpuk.urut[a]=t;
}

void print(){

    for(int i=0;i<=tumpuk.top;i++){
        tumpuk.urut[i]=tumpuk.data[i];
    }

        for (int i=tumpuk.top;i>=0;i--)
        cout<<tumpuk.urut[i]<<endl;
    getch();
}

int main()
{
    int a;
    string input;
    tumpuk.top=-1;
    do{
        system("cls");
        cout<<"          Pendataan Barang 			";
		cout<<"\n================================== \n";
		cout<<"1. Masukkan Barang \n";
		cout<<"2. Ambil Satu Barang \n";
		cout<<"3. Hapus Semua Data \n";
		cout<<"4. Cek Isi Gudang \n";
		cout<<"5. KELUAR \n";
		cout<<"\nPilihan Anda  : ";
        cin>>a;

        cout<<"----------------------------------\n";
        switch(a)
        {
        case 1:
            if(isFull()==1){
                cout<<"Stack penuh. \n";
                getch();
            }
            else{
                cout<<"Masukkan data : ";
                //fflush(stdin);
                cin>>input;
                push(input);
            }
            break;
        case 2:
            if(isEmpty()==1){
                cout<<"Stack kosong.";
                getch();
            }
            else{
                pop();
            }
            break;
        case 3:
            clear();
            cout<<"(KOSONG) \n";
            getch();
            break;
        case 4:
            if(isEmpty()==1){
                cout<<"Stack kosong";
                getch();
            }
            else{
                print();
            }
        }
    }while(a!=5);

}
