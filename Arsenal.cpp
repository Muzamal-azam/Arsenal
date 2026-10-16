#include<iostream>
#include<fstream>
#include<string>
#include <stdexcept>
#include<limits>
using namespace std;
class weapon{
	protected:
		string scope;
		int ammo;
		string name;
	public:
		weapon(string n,string s,int a):name(n),scope(s),ammo(a){
		}
		virtual void shoot(){
		}
		virtual void refill(){
		}
		void storeData(){
			fstream ofs;
			ofs.open("dataFile.txt",ios::app);
			if(!ofs) cout<<"\nerror in oppening file data not saved"<<endl;
			else{
				ofs<<name<<" "<<scope<<" "<<ammo<<endl;
				ofs.close();
			}
		}
		void show(){
			cout<<"name = "<<name<<"\nammo = "<<ammo<<"\nscope = "<<scope<<endl;
		}
		void setAmmo(int a){
			ammo=a;
		}
};
class pistol:public weapon{
	public:
		pistol():weapon("pistol","no_scope",10){
		}
		void shoot(){
			if(ammo>0){
				ammo-=1;
				cout<<"pistol shot\n";
				cout<<"ammo = "<<ammo<<endl;
			}
			else
				cout<<"no ammo";		
		}
		void refill(){
			ammo=10;
			cout<<"\n current ammo : "<<ammo;
		}			
};
class riffle:public weapon{
	public:
		riffle():weapon("riffle","2x",30){
		}
		void shoot(){
			if(ammo>0){
				ammo-=1;
				cout<<"riffle shot\n";
				cout<<"ammo = "<<ammo<<endl;
			}
			else
				cout<<"no ammo";	
		}
		void refill(){
			ammo=30;
			cout<<"\n current ammo : "<<ammo;
		}
};
class pump:public weapon{	
	public:
		pump():weapon("pump","no_scope",2){
		}	
		void shoot(){
			if(ammo>0){
				ammo-=1;
				cout<<"pump shot\n";
				cout<<"ammo = "<<ammo<<endl;
			}
			else
				cout<<"no ammo";
		}
		void refill(){
			ammo=2;
			cout<<"\n current ammo : "<<ammo;
		}
};
string nm,scp,op;
int amo,cnt=0;
bool x=false;
string arsenal[5]={};
string red="\033[31m";
string green="\033[32m";
string blue	="\033[34m";
string nrml="\033[0m";
void clrall(){
	cout<<"\033[H\033[J"<<std::flush;
}
void clrscrn(){
	cout<<"\033[2;1H\033[J"<<std::flush;
}
bool checkFile(string a){
	int ch=0;
	fstream ifs;
	ifs.open("dataFile.txt",ios::in);
	if(!ifs) throw runtime_error("error in opening the file");
	else{
		while(ifs>>nm>>scp>>amo){
			if(nm==a){
				ch=1;
				break; 
			}
		}
		if(ch==0) return true;// returns true if the weapon is not found in file;
		else
			return false;
		
	}
	
}
void storeArsenal(string n){
	if(cnt<5){
		arsenal[cnt] = n;
		cnt++;
	}
}
bool searchArsenal(string n){
	for(int i=0;i<cnt;i++){
		if(arsenal[i]==n){
			return true; // returns true when the weapon is in arsenal;
		}
	}
	return false;
}
int main(){
	int a=0;
	bool x=false;
	weapon *wp = NULL;
	riffle rf;
	pistol pl;
	pump pmp;
	cout<<"want to continue from where you left of?\nenter yes or no\n";
	cin>>nm;
	if(nm=="yes"){
		fstream ifs("dataFile.txt",ios::in);
		if(!ifs) cout<<"error in continuing ";
		else{
		clrall();
		while(ifs>>nm>>scp>>amo){
			if(nm=="pump"){
				if(!searchArsenal("pump")){
					storeArsenal("pump");
				}
				pmp.setAmmo(amo);
				wp=&pmp; // simply passing the object to last gun in the file;
			}
			if(nm=="riffle"){
				if(!searchArsenal("riffle")){
					storeArsenal("riffle");
				}
//				y=true;
				rf.setAmmo(amo);
				wp=&rf;
			}
			if(nm=="pistol"){
				if(!searchArsenal("pistol")){
					storeArsenal("pistol");
				}
//				z=true;
				pl.setAmmo(amo);
				wp=&pl;
			}	
		}
		ifs.close();	
		cout<<blue<<"current weapon : "<<nrml<<nm<<endl;
		}
	}
	else{
	fstream ofs("dataFile.txt",ios::out);
	ofs<<"";
	ofs.close();
	clrall();	
	}
	while(true){
	cout<<green<<"chose one option\n enter the option number"<<nrml<<"\n";
	cout<<" 1. aquire weapon\n 2. select  weapon\n 3. show arsenal\n 4. shoot\n 5. refill\n 6."<<red<<"save and exit"<<nrml<<"\n";
	int n;
	try{		
		if(!(cin>>n)){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			throw runtime_error("enter respective option number");
		}
	}
	catch(const runtime_error& e){
		cout<<red<<"error in input: "<<e.what()<<nrml<<endl;
		continue;
	}
	if(n==6) break;
	switch(n){
		case 1:{
			clrscrn();
			cout<<" 1. pump\n 2. riffle\n 3. pistol\n";
			int c;
			try{		
				if(!(cin>>c)){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				throw runtime_error("enter respective option number");
				}
			}
			catch(const runtime_error& e){
				cout<<red<<"error in input: "<<e.what()<<nrml<<endl;
			continue;
			}
			switch(c){
				case 1:{
					wp=&pmp;
					x=checkFile("pump");
					if(x==true){ // returns true if the weapon is not found in file;
						wp->storeData();
						storeArsenal("pump");
					}
					clrall();
					cout<<blue<<"current weapon ="<<nrml<<" pump action\n";
					x = false;
					break;
				}
				case 2:{
					wp=&rf;
					x=checkFile("riffle"); //checks file for the weapon name;
					if(x==true){ 
						wp->storeData();
						storeArsenal("riffle");
					}
					clrall();
					cout<<blue<<"current weapon ="<<nrml<<" riffle\n";
					x=false;
					break;
				}
				case 3:{
					wp=&pl;
					x=checkFile("pistol");
					if(x==true){ 
						wp->storeData();
						storeArsenal("pistol");
					}
					clrall();
					cout<<blue<<"current weapon ="<<nrml<<" pistol\n";
					x=false;
					break;
				}
			}
			break;
		}
		case 2:{
			fstream ifs;
			ifs.open("dataFile.txt",ios::in);
			if(!ifs) cout<<"error";
			else{
				clrscrn();
				while(ifs>>nm>>scp>>amo){
					cout<<nm<<endl;
					cout<<" chose this weapon?\n yes or no(show next)\n";
					cin>>op;
					if(op=="yes"){
						clrscrn();
						if(nm=="riffle"){
							wp=&rf;
							clrall();
							cout<<blue<<"current weapon ="<<nrml<<" riffle\n";
							cout<<"current stat : \n";
							rf.show();	
							a=1;
						}
						else if(nm=="pistol"){
							wp=&pl;
							clrall();
							cout<<blue<<"current weapon ="<<nrml<<" pistol\n";
							cout<<"current stat : \n";
							pl.show();
							a=1;	
						}
						else if(nm=="pump"){
							wp=&pmp;
							clrall();
							cout<<blue<<"current weapon ="<<nrml<<" pump action\n";
							cout<<"current stat : \n";
							pmp.show();	
							a=1;
						}
						break;
					}
					clrscrn();
				}
				if(a==0){
					cout<<red<<"no weapon selected from arsenal\n"<<nrml;;
				}
				a=0;
			}
			break;
		}
		case 3:{
			x=false;
			clrscrn();
			cout<<green<<"current arsenal"<<nrml<<"\n";	
			x=searchArsenal("pump");
			if(x==true) {
				
				pmp.show();
				x=false;
			}
			x=searchArsenal("riffle");
			if(x==true){
				rf.show();
				x=false;
			}
			x=searchArsenal("pistol");
			if(x==true) {
				pl.show();
				x=false;
			}
			break;
		}
		case 4:{
			clrscrn();
			if(wp != NULL) wp->shoot();
			else 
			cout<<red<<"no weapon selected\n"<<nrml;
//			wp->storeData();
			break;
		}
		case 5:{
			clrscrn();
			if(wp != NULL) wp->refill();
			else
			cout<<red<<"no weapon selected"<<nrml;
//			wp->storeData();
			break;
		}
		default:{
			clrscrn();
			cout<<red<<"enter correct options\n"<<nrml;
			break;
		}
	}
	}
	fstream ofs;
	ofs.open("dataFile.txt",ios::out);
	ofs<<"";
	ofs.close();
	
	x=searchArsenal("pump");
	if(x==true) {
		pmp.storeData();
		x=false;
	}
	x=searchArsenal("riffle");
	if(x==true){
		rf.storeData();
		x=false;
	}
	x=searchArsenal("pistol");
	if(x==true) {
		pl.storeData();
		x=false;
	}
	return 0;	
}
