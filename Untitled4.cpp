//Exercise 4
#include <iostream>
using namespace std;
struct Anak{
	char name[10];
	char phone[13];
	Anak* nextAnak;
};
struct Pegawai{
	char info2;
	Anak* FirstAnak;
	Pegawai* next;
};
typedef Pegawai* pointerpeg;
typedef Anak* pointerAnak;
typedef pointerpeg listpeg;

void createListPeg(listpeg& First){
	First=NULL;
}
void createElemntPeg(pointerpeg& pBaru){
	pBaru = new Pegawai;
	cout<<"Input one Alphabet : "; cin>>pBaru->info2;
	pBaru->next=NULL;
	pBaru->FirstAnak=NULL;
}
void createElemntAnak(pointerAnak& pBaru){
	pBaru= new Anak;
	cout<<"Name : "; cin>>pBaru->name;
	cout<<"Phone : "; cin>>pBaru->phone;
	pBaru->nextAnak=NULL;
	cout<<endl;
}
void insertFirstPeg(listpeg& First, pointerpeg pBaru){
	if(First==NULL){
		First=pBaru;
	}
	else{
		pBaru->next=First;
		First=pBaru;
	}
}
void linearSearch(listpeg& First, char key, int& found, pointerpeg& pInduk){
	pInduk=First;
	found=0;
	while(found==0 && pInduk != NULL){
		if(pInduk->info2==key){
			found=1;
		}
		else{
			pInduk=pInduk->next;
		}
	}
}
void insertFirstAnak(listpeg& First, char key, pointerAnak pBaru){
	pointerpeg pInduk;
	int found;
	
	linearSearch(First, key, found, pInduk);
	
	if(found){
		if(pInduk->FirstAnak==NULL){
			pInduk->FirstAnak=pBaru;
		}
		else{
			pBaru->nextAnak=pInduk->FirstAnak;
			pInduk->FirstAnak=pBaru;
		}
	}
	else{
		cout<<"Unfounded"<<endl;
	}
}
void traversalpeg(listpeg First){
	pointerpeg pBantu;
	if(First==NULL){
		cout<<"Empty List...!"<<endl;
	}
	else{
		pBantu=First;
		do{
			cout<<pBantu->info2<<" ";
			pBantu=pBantu->next;
		}
		while(pBantu != NULL);
	}
}
void traversalOrtuAnak(listpeg First){
	pointerpeg pBantupeg;
	pointerAnak pBantuAnak;
	
	pBantupeg=First;
	while(pBantupeg != NULL){
		cout<<pBantupeg->info2<<endl;
		pBantuAnak=pBantupeg->FirstAnak;
		while(pBantuAnak!=NULL){
			cout<<"\t| - "<<pBantuAnak->name<<" / "<<pBantuAnak->phone<<endl;
			pBantuAnak=pBantuAnak->nextAnak;
		}
		pBantupeg=pBantupeg->next;
	}
}
typedef pointerpeg peg[100];
typedef pointerAnak an[100];
main(){
	peg p;
	an na;
	listpeg induk;
	int n, m, found;
	char key, answer;
	
	createListPeg(induk);
	
	cout<<"Masukan Banyak induk yang diinginkan : "; cin>>n;
	for(int i=0; i<n; i++){
		createElemntPeg(p[i]);
		insertFirstPeg(induk, p[i]);
	}
	do{
		cout<<"Daftar Induk : "<<endl;
		traversalpeg(induk);
		cout<<endl;
		cout<<"Input Anak : "<<endl;
		cout<<"Pilih induk yang akan diberi anak huruf : "; cin>>key;
		cout<<"Masukan banyak anak yang diinginkan : "; cin>>m;
		for(int i=0; i<m; i++){
			createElemntAnak(na[i]);
			insertFirstAnak(induk, key, na[i]);
		}
		traversalOrtuAnak(induk);
		cout<<"Apakah anda ingin mengubah data ? "; cin>>answer;
	}
	while(answer=='Y' ||answer=='y');
}
