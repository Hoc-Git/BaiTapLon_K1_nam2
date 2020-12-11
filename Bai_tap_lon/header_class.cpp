#include<iostream>
#include<string>
#include<conio.h>
#include<fstream> 
#include<windows.h> 
#include<iomanip>
using namespace std;
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void ToMau(int x, int y, char *a, int color)
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}
void Tomau(char *a,int color){
	textcolor(color);
	cout << a;
	textcolor(7);
}
class Docgia{
	private:
		string Tensinhvien;
		string Mssv;
	public:
		Docgia();
		Docgia(string Tensinhvien,string Mssv);
		~Docgia();
	friend istream &operator  >>(istream &is,Docgia &a);
	friend ostream &operator <<(ostream &os,Docgia a);
	string getTensinhvien();
	string getMssv(); 
};
class Sach{
	private:
		string Tensach;
		string Theloai;
	public:
		Sach();
		Sach(string Tensach,string Theloai);
		~Sach();
	friend istream &operator >>(istream &is,Sach &a);
	friend ostream &operator <<(ostream &os,Sach a);
	string getTensach();
	string getTheloai(); 
};
class Quanli{
	private:
		Docgia docgia;
		int Sosach;
		Sach sach[10];
	public:
	friend istream &operator >>(istream &is,Quanli &a);
	friend ostream &operator <<(ostream &os,Quanli a);
	int getsosach(); 
	string getTensinhvien();
};
class Node
{
	private: 
    Quanli a;
    Node *next;
    public:
	friend class Queue; 
};
class Queue
{
	private: 
    Node *head;
    Node *tail;
    public:
 	void CreateQueue();
 	Node* CreateNode(Quanli b);
 	void DestroyQueue();
 	int IsEmpty();
 	void EnQueue(Node *node);
 	void DeQueue();
 	void Front();
 	void PrintQueue(int &t);
 	void Search(string Ten);
 	void Max();
 	void Gan(Quanli sach[],int n);
 	void Intep(); 
};
void Nhap(Queue &q,int &n); 
void Search(Queue q);
void Max(Queue q);
void Thongke(Queue q); 
void Thongketen(Queue q,int n); 
void Menu(Queue q,int n, int &t);
int main(){
	resizeConsole(1300,700);
	int n;
	Queue q;
	int t=0; 
	cout<<"Hello"; 
	Menu(q,n,t);
	return 0;
}
Docgia::Docgia(){
	Tensinhvien="0";
	Mssv="0";
}
Docgia::Docgia(string Tensinhvien,string Mssv){
	this->Tensinhvien=Tensinhvien;
	this->Mssv=Mssv;
}
istream &operator  >>(istream &is,Docgia &a){
	textcolor(14);
	cout<<"Nhap ten sinh vien vao: ";
	fflush(stdin);
	getline(is,a.Tensinhvien);
	cout<<"Nhap ma so sinh vien vao: ";
	fflush(stdin);
	getline(is,a.Mssv);
	return is;
}
ostream &operator <<(ostream &os,Docgia a){
	textcolor(14);
	cout<<"Ten sinh vien: "<<a.Tensinhvien<<endl<<"Ma so sinh vien: "<<a.Mssv<<endl;
	return os;
}
string Docgia::getMssv(){
	return (this->Mssv);
}
string Docgia::getTensinhvien(){
	return (this->Tensinhvien);
}
Docgia::~Docgia(){
}
Sach::Sach(){
	Tensach="0";
	Theloai="0";
}
string Sach::getTensach(){
	return (this->Tensach) ;
}
string Sach::getTheloai(){
	return (this->Theloai );
} 
Sach::Sach(string Tensach,string Theloai){
	this->Tensach=Tensach;
	this->Theloai=Theloai;
}
istream &operator  >>(istream &is,Sach &a){
	textcolor(3);
	cout<<"Nhap ten sach vao: ";
	fflush(stdin);
	getline(is,a.Tensach);
	cout<<"Nhap the loai sach: ";
	fflush(stdin);
	getline(is,a.Theloai);
	return is;
}
ostream &operator <<(ostream &os,Sach a){
	textcolor(3);
	cout<<"                      Ten sach|                       Theloai| "<<endl;
	cout<<setw(30)<<a.Tensach<<"|"<<setw(30)<<a.Theloai<<"|"<<endl; 
	return os;
}
Sach::~Sach(){
}
istream &operator >>(istream &is,Quanli &a){
	is>>a.docgia;
	cout<<"Nhap so luong sach can muon: ";
	is>>a.Sosach;
	for(int i=0; i<a.Sosach; i++){
	Tomau("Nhap thong tin sach thu ",12);
	cout<<i+1<<" : "<<endl;
	is>>a.sach[i];
	}
	return is;
}
ostream &operator <<(ostream &os,Quanli a){
	cout<<a.docgia;
	for(int i=0; i<a.Sosach; i++){
		textcolor(13);
	cout<<"Thong tin sach thu "<<i+1<<" : "<<endl;
	cout<<a.sach[i];
	}
	return os; 
}
string Quanli::getTensinhvien(){
	Docgia a=this->docgia;
	return(a.getTensinhvien());
}
int Quanli::getsosach(){
	return (this->Sosach); 
} 
void Queue::CreateQueue()
{
    head = NULL;
    tail = NULL;
}
Node* Queue::CreateNode(Quanli b)
{
    Node *node = new Node;
    node->a = b;
    node->next = NULL;
    return node;
}
void Queue::DestroyQueue()
{
    Node *node = head;
    while (head != NULL)
    {
        head = node->next;
        delete node;
        node = head;
    }
    tail = NULL;
}

int Queue::IsEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
}

void Queue::EnQueue(Node *node)
{
	if (IsEmpty())
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}
void Queue::Intep(){
	ofstream File;
	File.open("DanhSachTheoThuTu.txt",ios::out); 
	Node *node = head;
	int t=1; 
    while (node != NULL)
    {
    	
    	Quanli b=node->a; 
    	File<<"Danh sach theo thu tu muon sach: "<<endl; 
		File<<t<<"."<<b.getTensinhvien()<<"("<<b.getsosach()<<"cuon )"<<endl; 
		t=t+1; 
		node = node->next;
	}
	File.close(); 
}
void Queue::DeQueue()
{
    if (IsEmpty())
    cout<<"Danh sach rong!"<<endl;
    Node *node = head;
    head = node->next;
    delete node;
}

void Queue::Front()
{
    if (IsEmpty())
        cout<<"Danh sach rong!"; 
    else {
    	Quanli b=head->a; 
    	cout<<b; 
	} 
}

void Queue::PrintQueue(int &t)
{
    Node *node = head;
    while (node != NULL)
    {
    	cout<<setfill('_');
    	Quanli b=node->a; 
        cout <<b<<endl;
        cout<<setw(100)<<" "<<endl;
        t=t+b.getsosach();
        node = node->next;
    }
}
void Queue::Search(string Ten)
{
	int t=0;
	Node *p=NULL;
	for(Node* node=head;node !=NULL;node=node->next){
		if(Ten==node->a.getTensinhvien()){
			p = node;
			t=1;
			break;
		}
	} 
	textcolor(4);
    if(t) cout<<"Co sinh vien "<<Ten<<" trong danh sach"<<endl<<p->a;
    else cout<<"Khong co sinh vien "<<Ten<<" trong danh sach!"<<endl;
}
void Queue::Gan(Quanli sach[],int n){
	Node* node = head;
	for(int i=0;i<n; i++ ){
		sach[i]=node->a;
		node=node->next;
	}
}
void Queue::Max()
{
	Node *p=head;
	Node *Max=head;
	int max=Max->a.getsosach();
	for(Max=Max->next ; Max !=NULL;Max=Max->next){
		if(max<Max->a.getsosach()){
			p=Max;
			max=Max->a.getsosach();
		}
	} 
	cout<<"Nguoi muon nhieu sach nhat la: "<<endl<<p->a<<endl;
	cout<<"So sach muon la: "<<max<<endl;
}
void Nhap(Queue &q,int &n){
	q.CreateQueue();
 	Node *node;
	cout<<"Nhap so nguoi muon vao: ";
	cin>>n; 
 	for (int i = 0; i < n; i++)
 	{ 
 	 	Quanli b;
 	 	textcolor(2);
		cout<<"Nhap sinh vien thu "<<i+1<<" vao: "<<endl;
		cin>>b; 
       	node = q.CreateNode(b);
  		q.EnQueue(node);
  		cout<<endl; 
 	}
}
void Thongke(Queue q){
 	int t=0; 
	cout<<"Danh sach:"<<endl;
	q.PrintQueue(t);
	textcolor(7);
	cout<<"Tong sach cho muon la: "<<t<<endl;
}
void Search(Queue q){
	string Ten;
	cout<<"Nhap ten can tim vao: ";
	fflush(stdin);
	getline(cin,Ten);
	q.Search(Ten);
}
void Max(Queue q){
	q.Max();
}
void Thongketen(Queue q,int n){
	Quanli *sach = new Quanli [n] ;
	ofstream file;
	file.open("DanhSachTheoTen.txt",ios::out); 
    int* b = new int[n];
	for(int i=0; i<n; i++){
		b[i]=1;
	}
	//gan danh sach lien ket qua mang sach[n]
	q.Gan(sach,n); 
	for(int i=0; i<n; i++){
		for(int j=i+1;j<n;j++){
			if((sach[i].getTensinhvien()).compare(sach[j].getTensinhvien())>0){
				Quanli a=sach[i];
				sach[i]=sach[j];
				sach[j]=a;
			}
		}
	}
	cout<<"Danh sach sach theo ten (A->Z)"<<endl;
	file<<"Danh sach theo ten (A->z) "<<endl;
	for(int i=0; i<n; i++){
		cout<<sach[i]<<endl;
		file<<i+1<<"."<<sach[i].getTensinhvien()<<"("<<sach[i].getsosach()<<"cuon )"<<endl; 
	}
	file.close();
}
void Menu(Queue q,int n,int &t){
	int c;
	system("cls");
   while (1)
   {
   	ToMau(70,1,"Chuong trinh quan li sach",253);
   	ToMau(30,3,"1.Nhap danh sach                                                                                       ",252);
   	ToMau(30,4,"2.Them vao danh sach                                                                                   ",251);
   	ToMau(30,5,"3.Xoa phan tu dau                                                                                      ",250);
   	ToMau(30,6,"4.Lay gia tri dau                                                                                      ",249);
   	ToMau(30,7,"5.Thong ke                                                                                             ",248);
   	ToMau(30,8,"6.Tim kiem                                                                                             ",240);
   	ToMau(30,9,"7.Thong tin nguoi muon sach nhieu nhat                                                                 ",246);
   	ToMau(30,10,"8.Thong ke theo ten(A->Z) va in ra tep                                                                 ",245);
	ToMau(30,11,"9.In ra tep                                                                                            ",243);
	ToMau(30,12,"10.Xoa danh sach                                                                                       ",242);
	ToMau(30,13,"11.Thoat                                                                                               ",241);
	ToMau(10,15,"Nhap su lua chon vao:",6);  	  
//      cout<<"1.Nhap danh sach"<<endl;
//      cout<<"2.Them vao danh sach"<<endl;
//      cout<<"3.Xoa phan tu dau"<<endl;
//	    cout<<"4.Lay gia tri dau "<<endl;
//      cout<<"5.Thong ke theo thu tu muon sach"<<endl;
//      cout<<"6.Tim kiem"<<endl;
//      cout<<"7.Thong tin nguoi muon sach nhieu nhat"<<endl;
//      cout<<"8.Thong ke theo ten(A->Z) va in ra tep "<<endl;
//      cout<<"9.In ra tep"<<endl;
//      cout<<"10.Xoa danh sach"<<endl;
//      cout<<"11.Thoat"<<endl;
//      cout<<"Nhap su lua chon: ";
      cin>>c;
      switch(c) {
         case 1:
         	Nhap(q,n);
         	t=1;
         	Tomau("Hoan thanh!",124);
            getch();
            return Menu(q,n,t);
         case 2:
         	if(t==1){
         	Node *node;
         	Quanli b;
			cin>>b; 
       		node = q.CreateNode(b);
  			q.EnQueue(node);
  			cout<<endl; 
  			n=n+1;
         	Tomau("Hoan thanh!",124);
        	 }
        	 else Tomau("Phai nhap truoc! Lua chon 1.",4);
         	getch();
            return  Menu(q,n,t);
         case 3:
         	if(t==1){
         		q.DeQueue(); 
         	Tomau("Hoan thanh!",124);
         	n=n-1;
        	 }
        	 else Tomau("Phai nhap truoc! Lua chon 1.",4);
         	getch();
            return  Menu(q,n,t);
         case 4:
         	if(t==1){
         		q.Front(); 
         	Tomau("Hoan thanh!",124);
        	 }
        	 else Tomau("Phai nhap truoc! Lua chon 1.",4);
         	getch();
            return  Menu(q,n,t);
         case 5:
         	if(t==1){
         		Thongke(q);
         	Tomau("Hoan thanh!",124);
        	 }
        	 else Tomau("Phai nhap truoc! Lua chon 1.",4);
         	getch();
            return  Menu(q,n,t);
         case 6:
         	if(t==1){
         		Search(q);
         	Tomau("Hoan thanh!",124); 
        	 }
        	 else Tomau("Phai nhap truoc! Lua chon 1.",4);
         	getch();
            return  Menu(q,n,t);
         case 7:
         	if(t==1){
         		Max(q);
         	Tomau("Hoan thanh!",124);
        	 }
        	 else Tomau("Phai nhap truoc! Lua chon 1.",4);
         	getch();
            return  Menu(q,n,t);
         case 8:
         	if(t==1){
         	Thongketen(q,n);
         	Tomau("Hoan thanh!",124);
        	 }
        	 else Tomau("Phai nhap truoc! Lua chon 1.",4);
         	getch();
            return  Menu(q,n,t);
         case 9:
         	if(t==1){
         		q.Intep();
         	Tomau("Hoan thanh!",124);
        	 }
        	 else Tomau("Phai nhap truoc! Lua chon 1.",4);
         	getch();
            return  Menu(q,n,t);
         case 10:
         	if(t==1){
         		q.DestroyQueue();
         	Tomau("Hoan thanh!",124); 
        	 }
        	 else Tomau("Phai nhap truoc! Lua chon 1.",4);
         	getch();
            return  Menu(q,n,t);
         case 11:
         	q.DestroyQueue(); 
            exit(1);
         default:
         	textcolor(4);
            cout<<"Nhap sai! Nhap lai."<<endl;
            getch();
            return Menu(q,n,t);
      }
   }
}



