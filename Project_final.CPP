#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

class animal
{ private:
  int animal_id,cage_no,age;
  char name[20],dob[15],doen[15],dod[15],doex[15],gender[5],species[20];
  char ftype[20],des[50],health[20],rarity[20];
  public:
  void show()
  { cout<<"\nAnimal ID      :"<<animal_id;
    cout<<"\nName           :"<<name;
    cout<<"\nGender         :"<<gender;
    cout<<"\nAge            :"<<age;
    cout<<"\nCage Number    :"<<cage_no;
    cout<<"\nDate of Birth  :"<<dob;
    cout<<"\nDate of Entry  :"<<doen;
    cout<<"\nDate of Exit   :"<<doex;
    cout<<"\nDate of Death  :"<<dod;
    cout<<"\nSpecies        :"<<species;
    cout<<"\nFood Type      :"<<ftype;
    cout<<"\nHealth         :"<<health;
    cout<<"\nRarity         :"<<rarity;
    cout<<"\nDescription    :"<<des;
  }

   void get()
  { cout<<"Animal ID                 :";
    cin>>animal_id;
    cout<<"Name                      :";
    gets(name);
    cout<<"Gender(M,F,NS)            :";
    gets(gender);
    cout<<"Age                       :";
    cin>>age;
    cout<<"Cage Number               :";
    cin>>cage_no;
    cout<<"Date of Birth (dd/mm/yyyy):";
    gets(dob);
    cout<<"Date of Entry (dd/mm/yyyy):";
    gets(doen);
    cout<<"Date of Exit  (dd/mm/yyyy):";
    gets(doex);
    cout<<"Date of Death (dd/mm/yyyy):";
    gets(dod);
    cout<<"Species                   :";
    gets(species);
    cout<<"Food Type                 :";
    gets(ftype);
    cout<<"Health                    :";
    gets(health);
    cout<<"Rarity                    :";
    gets(rarity);
    cout<<"Description               :";
    gets(des);
  }
int reta_id()
 {
  return animal_id;
 }

char* retan()
 {
   return (name);
 }

char* retdoen()
 {
  return (doen);
 }

char* retdoex()
 {
  return (doex);
 }
char* retsp()
 {
  return (species);
 }

int ret_cn()
 {
  return cage_no;
 }

char* ret_rarity()
{ return rarity;
}
char * rethealth()
{ return health;
}

};
fstream f,temp;
animal a,a2;
char ans;


void count()
{ int c3;
  cout<<"\n1.Count total records.";
  cout<<"\n2.Count total animals.";
  cout<<"\n3.Count animals of given species.";
  cout<<"\n4.Count animals in a given cage.";
  cin>>c3;
  switch(c3)
 { case 1: f.open("zoo.dat",ios::in|ios::binary);
	   f.seekg(0,ios::end);
	   int ip=f.tellg();
	   int s=sizeof(a);
	   int ir=ip/s;
	   f.close();
	   cout<<"\nTotal number of records are:"<<ir;
	   break;

  case 2: int r=0;
	  int ct=0;
	  f.open("zoo.dat",ios::in|ios::binary);
	  while(f.read((char*)&a,sizeof(a)))
	  { ct++;
	   ++r;
	  }
	  f.close();
	  cout<<"\nTotal animals of zoo are:"<<ct;
	  break;

    case 3:int r2=0;
	  int ct2=0;
	  char ispecies[20];
	  cout<<"Enter the species to count:";
	  gets(ispecies);
	  f.open("zoo.dat",ios::in|ios::binary);
	  while(f.read((char*)&a,sizeof(a)))
	  { if((strcmpi(a.retsp(),ispecies)==0))
	    ct2++;
	    ++r2;
	  };
	  f.close();
	  cout<<"\nTotal animals of "<<ispecies<<" category in zoo are:"<<ct2;
	  break;

   case 4:int r3=0;
	  int ct3=0;
	  int icn;
	  cout<<"Enter the cage number:";
	  cin>>icn;
	  f.open("zoo.dat",ios::in|ios::binary);
	  while(f.read((char*)&a,sizeof(a)))
	  { if(a.ret_cn()==icn)
	    ct3++;
	    ++r3;
	  };
	  f.close();
	  cout<<"\nTotal animals in cage number "<<icn<<" are:"<<ct3;
	  break;
 }
}

void write()
{ f.open("zoo.dat",ios::out|ios::binary);
  ans='y';
  while(ans=='y'||ans=='Y')
  {
    a.get();
    f.write((char*)&a,sizeof(a));
    cout<<"\nDo You Want to Continue(Y/N)?";
    cin>>ans;
  };
  f.close();
}

void showfile()
{ f.open("zoo.dat",ios::in|ios::binary);
     while(f.read((char*)&a,sizeof(a)))
     { a.show();
       cout<<"\n\n";
     };
  f.close();
}

void append()
{ f.open("zoo.dat",ios::app|ios::binary);
  ans='y';
  while(ans=='y'||ans=='Y')
  { a.get();
    f.write((char*)&a,sizeof(a));
    cout<<"Do you want to enter another record?(Y/N)\n";
    cin>>ans;
  };
  f.close();
}

void search()
{ int choice;
  f.open("zoo.dat",ios::in|ios::binary);
  cout<<"\nSearch on the basis of:\n";
  cout<<"1.Animal_ID\n";
  cout<<"2.Cage Number\n";
  cout<<"3.Animal Name\n";
  cout<<"4.Animal Species\n";
  cout<<"5.Date of Entry\n";
  cout<<"6.Date of Exit\n";
  cout<<"7.Animal Health\n";
  cin>>choice;

  switch(choice)
  {
    case 1: int s_id;
	    cout<<"Enter Animal_Id to search:\n";
	    cin>>s_id;
	    while(f.read((char*)&a,sizeof(a)))
	    { if(a.reta_id()==s_id)
	      a.show();
	      cout<<endl;
	    };
	    f.close();
	    break;

   case 2: int cn;
	   cout<<"Enter Cage Number to search:\n";
	   cin>>cn;
	   while(f.read((char*)&a,sizeof(a)))
	   { if(a.ret_cn()==cn)
		a.show();
		cout<<endl;
	   };
	   f.close();
	   break;

   case 3: char an[20];
	   cout<<"Enter Animal Name to search:\n";
	   gets(an);
	   while(f.read((char*)&a,sizeof(a)))
	   { if(strcmpi(an,a.retan())==0)
	     a.show();
	     cout<<endl;
	   };
	   f.close();
	   break;

   case 4:  char sp[20];
	   cout<<"Enter Animal Species to search:\n";
	   gets(sp);
	   while(f.read((char*)&a,sizeof(a)))
	   { if(strcmpi(sp,a.retsp())==0)
	     a.show();
	     cout<<endl;

	   };
	   f.close();
	   break;

   case 5:  char d_en[20];
	   cout<<"Enter Date of Entry to search:\n";
	   gets(d_en);
	   while(f.read((char*)&a,sizeof(a)))
	   { if(strcmpi(d_en,a.retdoen())==0)
	     a.show();
	     cout<<endl;
	   };
	   f.close();
	   break;

   case 6:  char d_ex[20];
	   cout<<"Enter Date of Exit search:\n";
	   gets(d_ex);
	   while(f.read((char*)&a,sizeof(a)))
	   { if(strcmpi(d_ex,a.retdoex())==0)
	      a.show();
	      cout<<endl;
	   };
       f.close();
	   break;

   case 7:  char ihealth[20];
	   cout<<"Enter health status to search:\n";
	   gets(ihealth);
	   while(f.read((char*)&a,sizeof(a)))
	   { if(strcmpi(ihealth,a.rethealth())==0)
	      a.show();
	      cout<<endl;
	   };
	   f.close();
	   break;
  }
  cout<<"\n\n";
}

void editrec()
{ f.open("zoo.dat",ios::in|ios::binary);
  temp.open("new.dat",ios::out|ios::binary);
  int r=0;
  int er;
  cout<<"\nEnter Record to edit:";
  cin>>er;
  while(f.read((char*)&a2,sizeof(a2)))
  { r++;
    if(r==er)
    { cout<<"\nEnter new record\n";
      a2.get();
    }
    temp.write((char*)&a2,sizeof(a2));
  }
  temp.close();
  f.close();
  remove("zoo.dat");
  rename("new.dat","zoo.dat");
}


void delrec()
{ int c1;
  f.open("zoo.dat",ios::in|ios::binary);
  temp.open("new.dat",ios::out|ios::binary);
  cout<<"\n1.Delete First Record.\n";
  cout<<"2.Delete Last Record.\n";
  cout<<"3.Delete Any Record.\n";
  cout<<"4.Delete Animal_ID.\n";
  cout<<"5.Delete Animal Name.\n";
  cout<<"6.Delete All Records.\n";
 cin>>c1;
 switch(c1)
 { case 1: f.read((char*)&a,sizeof(a));
	   while(f.read((char*)&a,sizeof(a)))
	   {
	   temp.write((char*)&a,sizeof(a));
	   }
	   temp.close();
	   f.close();
	   remove("zoo.dat");
	   rename("new.dat","zoo.dat");
	   break;

   case 2: f.seekg(0,ios::end);
	   int ip=f.tellg();
	   int s=sizeof(a);
	   int ir=ip/s;
	   int r=1;
	   f.seekg(0);
	   while(f.read((char*)&a,sizeof(a)))
	   {
	   if(r!=ir)
	   temp.write((char*)&a,sizeof(a));
	   r++;
	   }
	   temp.close();
	   f.close();
	   remove("zoo.dat");
	   rename("new.dat","zoo.dat");
	   break;

   case 3: r=1;
	   int dr;
	   cout<<"\nEnter a Record to delete.";
	   cin>>dr;
	   f.seekg(0);
	   while(f.read((char*)&a,sizeof(a)))
	   {
	   if(r!=dr)
	   temp.write((char*)&a,sizeof(a));
	   r++;
	   }
	   temp.close();
	   f.close();
	   remove("zoo.dat");
	   rename("new.dat","zoo.dat");
	   break;

   case 4: int c_aid;
	   cout<<"\nEnter Animal_ID to delete.";
	   cin>>c_aid;
	   f.seekg(0);
	   while(f.read((char*)&a,sizeof(a)))
	   {
	    if(a.reta_id()!=c_aid)
	    temp.write((char*)&a,sizeof(a));
	   }
	   temp.close();
	   f.close();
	   remove("zoo.dat");
	   rename("new.dat","zoo.dat");
	   break;

   case 5: char cname[20];
	   cout<<"\nEnter Animal Name to delete.";
	   gets(cname);
	   f.seekg(0);
	   while(f.read((char*)&a,sizeof(a)))
	   {
	    if(strcmp(a.retan(),cname)!=0)
	    temp.write((char*)&a,sizeof(a));
	   }
	   temp.close();
	   f.close();
	   remove("zoo.dat");
	   rename("new.dat","zoo.dat");
	   break;
   case 6:f.open("zoo.dat",ios::in|ios::binary);
	  temp.open("new.dat",ios::out|ios::binary);
	  f.close();
	  temp.close();
	  remove("zoo.dat");
	  rename("new.dat","zoo.dat");
	  break;
 }
}


void instrec()
{ f.open("zoo.dat",ios::in|ios::binary);
  temp.open("temp.dat",ios::out|ios::binary);
  int c2;
  cout<<"Enter Record To Insert:\n";
  a2.get();
  cout<<endl;
  cout<<"\n1.Insert at First.";
  cout<<"\n2.Insert at Last.";
  cout<<"\n3.Insert at dersired location.";
  cout<<"\n4.Insert after an Animal_Id";
  cin>>c2;

  switch(c2)
  {
    case 1:temp.write((char*)&a2,sizeof(a2));
	   while(f.read((char*)&a,sizeof(a)))
	   {
	   temp.write((char*)&a,sizeof(a));
	   }
	   temp.close();
	   f.close();
	   remove("zoo.dat");
	   rename("temp.dat","zoo.dat");
	   break;

    case 2:
	   while(f.read((char*)&a,sizeof(a)))
	   {
	   temp.write((char*)&a,sizeof(a));
	   }
	   temp.write((char*)&a2,sizeof(a2));
	   temp.close();
	   f.close();
	   remove("zoo.dat");
	   rename("temp.dat","zoo.dat");
	   break;

    case 3: int r=0;
	    int ir;
	    cout<<"\nEnter a Record number after which you want to insert.";
	    cin>>ir;
	    while(f.read((char*)&a2,sizeof(a2)))
	    {
	    r++;
	    if(r==ir)
	    temp.write((char*)&a2,sizeof(a2));
	    temp.write((char*)&a,sizeof(a));
	    }
	    temp.close();
	    f.close();
	    remove("zoo.dat");
	    rename("temp.dat","zoo.dat");
	    break;
	    
	   case 4:
	   while(f.read((char*)&a2,sizeof(a2)))
	    {
	    temp.write((char*)&a,sizeof(a));
	    if(a.reta_id()==a2.reta_id())
	    temp.write((char*)&a2,sizeof(a2));
	    temp.write((char*)&a,sizeof(a));
	    }
	    temp.close();
	    f.close();
	    remove("zoo.dat");
	    rename("temp.dat","zoo.dat");
	    break;
	   

     }
  }

void main()

{ clrscr();
 int i;
 char o='y';
  cout<<"Welcome to the Program.\n\n\n";
 while(o=='y'||o=='Y')
 {
  cout<<"\nSelect one of the following options:\n\n";
  cout<<"1.Enter a New Animal Record.\n";
  cout<<"2.Show existing Animal Records.\n";
  cout<<"3.Append a New Animal Record.\n";
  cout<<"4.Search Record.\n";
  cout<<"5.Edit Record.\n";
  cout<<"6.Count.\n";
  cout<<"7.Delete Records.\n";
  cout<<"8.Insert Records.\n";
  cout<<"9.Exit Program.\n";
  cin>>i;

  switch(i)
  { case 1: write();
	    break;
    case 2: showfile();
	    break;
    case 3: append();
	    break;
    case 4: search();
	    break;
    case 5: editrec();
	    break;
    case 6: count();
	    break;
    case 7: delrec();
	    break;
    case 8: instrec();
	    break;
    case 9: exit(0);
	    break;

  }
  cout<<"\nDo you want to continue with the program?(Y/N)";
  cin>>o;
 }
 cout<<"\n\nThank You for visiting us!";
 getch();

}



















