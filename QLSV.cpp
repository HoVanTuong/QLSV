#include <bits/stdc++.h>
#include<conio.h>
int dem=0;
using namespace std;

struct Student
{
    string name, id;
    double gpa;
    float diem1;
    float diem2;
    float diem3;
    char xeploai;
};
struct SV // khai bao node
{
    Student s;
    SV *next; // tham chieu den sinh vien tiep theo
};
typedef struct SV* sv;// khai bao node de don gian hon khi cap phat dong

// cap phat dong mot node moi voi du lieu la so nguyen x
sv makeNode()
{
	//luu id voi ten vao truoc, vi neu dua vo ham lap for thi se bi lap( neu TH toan ly hoa thoa dieu kien do-while)
    Student s;
    cout <<"Nhap thong tin sinh vien: \n";
    cout <<"Nhap ID: "; cin >> s.id;
    cout <<"Nhap Ten: "; cin.ignore();
    getline(cin, s.name);
    cout<<"Nhan nut bat ki de tiep tuc hoan thanh thong tin sinh vien!"<<endl;
    char h= getch();
    system("cls");
    do{
	system("cls");
    cout <<"NHAP DIEM SINH VIEN\n";
    cout <<"Nhap diem Toan (0-10): "; cin>>s.diem1;
    cout <<"Nhap diem Ly (0-10): "; cin>>s.diem2;
    cout <<"Nhap diem Hoa (0-10): "; cin>>s.diem3;
    s.gpa=((s.diem1+s.diem2+s.diem3)/3)*4/10;
	cout<<"Diem gpa:"<<s.gpa<<endl;
	}
	while(s.diem1>10||s.diem2>10||s.diem3>10||s.diem1<0||s.diem2<0||s.diem3<0);
	if(s.gpa>=3.6){
		cout<<"Xep loai: Xuat sac!!!\n";
		cout<<"Luu thong tin sinh vien thanh cong!!!"<<endl;
	}else if(s.gpa >= 3.2){
		cout<<"Xep loai: Gioi!!!\n";
		cout<<"Luu thong tin sinh vien thanh cong!!!"<<endl;
	} else if(s.gpa>=2.5){
		cout<<"Xep loai: Kha!!!\n";
		cout<<"Luu thong tin sinh vien thanh cong!!!"<<endl;
	} else if(s.gpa>=2){
		cout<<"Xep loai: Trung binh!!!\n";
		cout<<"Luu thong tin sinh vien thanh cong!!!"<<endl;
	}else if(s.gpa>=1){
		cout<<"Xep loai: Yeu!!!\n";
		cout<<"Luu thong tin sinh vien thanh cong!!!"<<endl;
	}else{
		cout<<"Xep loai: Kem!!!\n";
		cout<<"Luu thong tin sinh vien thanh cong!!!"<<endl;
	}
    sv tmp = new SV();
    tmp -> s = s;
    tmp -> next = NULL;
    return tmp;
}
// kiem tra rong
bool empty(sv a)
{
    return a == NULL;
}
// kiem tra danh sach co bao nhieu phan tu
int Size(sv a)
{
  int cnt = 0;
  while(a!=NULL)
  {
    ++cnt;
    a = a->next;// gan dia chi cua node tiep theo cho node hien tai
    // cho node hien tai tro toi node tiep theo
  }
  return cnt;
}
// them mot sinh vien vao dau danh sach lien ket
void addHead(sv &a) //dung tham chieu de thay doi gia tri cua node dau tien khi addHead thay doi
{
   sv tmp = makeNode();
   if(a== NULL)
   {
    a=tmp;
   }
   else
   {
    tmp->next = a;// theo thu tu, neu lam nguoc lai thi se mat lien ket voi cac sinh vien dung sau trong list
    a= tmp;
   }
}
//them sinh vien vao cuoi 
void addLast(sv &a)
{
    sv tmp = makeNode();
    if (a==NULL)
    {
        a= tmp;
    }
    else
    {
        sv p = a;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next = tmp;
    }
}
// them 1 sinh vien vao giua
void addMid(sv &a, int pos)
{
    int n = Size(a);
    if(pos<=0 || pos > pos + 1)
    {
        cout <<"Vi tri chen khong hop le! \n";
    }
    if(n == 1)
    {
       addHead(a); return; 
    }
    else if(n==pos + 1)
    {
       addLast(a); return;
    }
    sv p = a;
    for(int i=1; i< pos-1; i++)
    {
        p = p->next;
    }
    sv tmp = makeNode();
    tmp ->next = p->next;
    p->next = tmp;
}
//xoa sinh vien dau
void deleteHead(sv &a)
{
    if(a==NULL) return;
    a = a->next;
}
// xoa sinh vien cuoi
void deleteLast(sv &a)
{
    if(a == NULL) return;
    sv truoc = NULL, sau = a;
    while(sau->next != NULL)
    {
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL)
    {
        a = NULL;
    }
    else
    {
        truoc->next = NULL;
    }
}
// xoa o giua
void deleteMid(sv &a, int pos)
{
    if(pos <=0 ||  pos > Size(a)) 
    {
        cout <<"Vi tri xoa khong hop le!\n";
        return;
    }
    sv truoc = NULL, sau = a;
    for(int i = 1; i < pos; i++)
    {
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL)
    {
	    a = a->next;
    }
    else
    {
        truoc->next = sau->next;
    }
}

void in(Student s)
{
    cout <<"-----------------\n";
    cout<<"STT"<<setw(5)<<"ID"<<setw(18)<<"Ho va Ten"<<setw(18)<<"Diem Toan"<<setw(12)<<"Diem Ly"<<setw(12)<<"Diem Hoa"<<setw(12)<<"Diem gpa"<<endl;
    cout<<++dem<<setw(6)<<s.id<<setw(18)<<s.name<<setw(18)<<s.diem1<<setw(12)<<s.diem2<<setw(12)<<s.diem3<<setw(12)<<s.gpa<<endl;
	if(s.gpa>=3.6){
		cout<<"Xep loai: Xuat sac!!!\n";
	} else if(s.gpa>=3.2){
		cout<<"Xep loai: Gioi!!!\n";
	} else if(s.gpa>=2.5){
		cout<<"Xep loai: Kha!!!\n";
	} else if(s.gpa>=2){
		cout<<"Xep loai: Trung binh!!!\n";
	} else if(s.gpa>=1){
		cout<<"Xep loai: Yeu!!!\n";
	} else{
		cout<<"Xep loai: Kem!!!\n";
	}
}
void inds(sv a)
{
    cout <<"Danh sach sinh vien:\n";
    while(a!=NULL)
    {
        in(a->s);
        a = a -> next; 
    }
    cout << "\n---------------------";
}
void sapxep(sv &a)
{
    for(sv p = a ; p->next != NULL;p = p->next)
    {
       sv min = p ;
       for(sv q = p->next; q!=NULL; q = q->next){
	        if(q->s.gpa < min->s.gpa){
                min =  q;
			}
       }
       Student tmp = min ->s;
       min->s =p->s;
       p->s = tmp;
    }
}
void pressAnyKey() {
    cout <<"\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
int main()
{
  sv head = NULL;
  while(1)
  {
    cout <<"CHUONG TRINH QUAN LY SINH VIEN CUA NHOM 10"<<"\n";
    cout <<"========================================="<<"\n";
    cout <<"|                MENU                   |"<<"\n";
    cout <<"| 1. Them sinh vien                     |"<<"\n";
    cout <<"| 2. Chen sinh vien vao dau danh sach   |"<<"\n";
    cout <<"| 3. Chen sinh vien vao cuoi danh sach  |"<<"\n";
    cout <<"| 4. Chen sinh vien vao giua danh sach  |"<<"\n";
    cout <<"| 5. Xoa sinh vien o dau danh sach      |"<<"\n";
    cout <<"| 6. Xoa sinh vien o cuoi danh sach     |"<<"\n";
    cout <<"| 7. Xoa sinh vien o giua danh sach     |"<<"\n";
    cout <<"| 8. Duyet danh sach                    |"<<"\n";
    cout <<"| 9. Sap xep cac sinh vien              |"<<"\n";
    cout <<"| 0. Thoat                              |"<<"\n";
    cout <<"========================================="<<"\n";
    cout <<"Nhap lua chon: ";
    int lc; cin >>lc;
    if(lc == 1){
    	cout<<"Them sinh vien\n ";
    	addHead(head);
    	pressAnyKey();
		}
	else if(lc == 2)
    {
        addHead(head);
        cout<<endl;
        cout<<"DANH SACH SAU KHI CHEN LA: "<<endl;
        inds(head);
        pressAnyKey();
    }
    else if(lc == 3)
    {
        addLast(head);
        cout<<endl;
        cout<<"DANH SACH SAU KHI CHEN LA: "<<endl;
        inds(head);
        pressAnyKey();
    }
    else if(lc == 4)
    {
        int pos; cout<<"Nhap vi tri can chen: "; cin>> pos;
	    addMid(head,pos);
	    cout<<endl;
        cout<<"DANH SACH SAU KHI CHEN LA: "<<endl;
	    inds(head);
        pressAnyKey();
    }
    else if(lc == 5)
    {
        deleteHead(head);
        cout<<"Ban da xoa thanh cong!"<<endl;
        cout<<endl;
        pressAnyKey();
    }
    else if(lc == 6)
    {
    	deleteLast(head);
        cout<<"Ban da xoa thanh cong!"<<endl;
        cout<<endl;
        pressAnyKey();
    }
    else if(lc == 7)
    {
        int pos; cout<<"Nhap vi tri can xoa:"; cin>>pos;
        deleteMid(head,pos);
        cout<<endl;
        cout<<"DANH SACH SAU KHI XOA LA: "<<endl;
        inds(head);
        pressAnyKey();
    }
    else if(lc == 8)
    {
        inds(head);
        pressAnyKey();
    }
    else if(lc == 9)
    {
        sapxep(head);
        pressAnyKey();
    }   
    else if(lc == 0)
    {
        break;
    }
    }
  return 0;
}	         // CODE BY NHOM 10
