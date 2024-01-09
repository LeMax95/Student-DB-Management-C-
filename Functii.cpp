void search_all(char **a,int w[1000],int n);
void insert_GrStud();
void save_stud_insert();
void show_by_index(int i[100],int n);
void delete_arr(char **a);
void create_arr(char **a);
void create_arr_d(int **a);
void active_arr(int v[100]);

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; 
    SetConsoleCursorInfo(out, &cursorInfo);
}


void clear_screen(char fill = ' ') { 
    COORD tl = {0,0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);   
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}
  
void  ClearScreen() { 
COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
  



void insert_GenStud(){
system("cls");  

	while(1){
		
		cout<< "Student"<<nrStud+1<<" Date Generale - data nasterii"<<endl;
		cout<< "IDNP: "; cin>>Stud[nrStud].idnp;
		cout<< "Ziua: "; cin>>Stud[nrStud].Varsta.zi;
		cout<< "Luna: "; cin>>Stud[nrStud].Varsta.luna;
		cout<< "Anul: "; cin>>Stud[nrStud].Varsta.an;
	    cout<<"\n[ESC]IESIRE MENIU"<<"\t\t\t[ENTER]CONTINUA\n";	
	    
       if(_getch()==27){
       	if(state_edit == 0){
       		cout<<"Doriti sa finalizati insertia si sa treceti la urmatorul student?"<<endl;
       	     	cout<<"\n[ESC]NU"<<"\t\t\t[ENTER]DA\n";
       	     	entry_insert=1;
       	     	if(_getch()!=27){					
		        save_stud_insert();	
		        entry_insert=0;
		        
		   		   break;
		 		}
		 		}
		 	 break;
	}
			else {
		      insert_GrStud(); break;
		}
	
	}	
	
	}
	


int find_STUDENT__any()
  {
    system("cls");
  
   char options[][50]{
             "Nume: ",        
          "Prenume: ",        
          "Patronimic" ,       
       "Grupa: ",         
       "Data nasterii: ",  
       "IDNP: ",      
    "Iesire: " 

   
   };
 int *w= new int[100];  
   int n = 0;
   int max_opt = 7;
   int arrPos=1;
   bool b=0;
  if( nrStud > 0 )
  {   
  char **any = new char*[50];
  create_arr(any);

   int i = 0;   
 while(1){
system("cls");
     ShowConsoleCursor(false);                                                                        
   for( i =0;i<max_opt;i++){
     if(arrPos==i+1){
  
   cout<<"\n\n\t--> "<<options[i];
  }
   else   
   
       cout<<"\n\n\t"<<options[i];
    }    
      
	  
	  
	  cout<<"\n\n\n\n\n\n\n\t[F] - Cautare\t\t [ESC] - CAUTARE NOUA"; cout<<"\t\tREGIM CAUTARE: "; b==0 ? cout<<" PERMIS "<<endl :  cout<<" BLOCAT"<<endl;



  
  
   switch( _getch()){
    
             case 72:{
              
             if(arrPos<=max_opt&&arrPos!=1)
              arrPos--;
              else arrPos=max_opt;

    break;
    
    }
      case 80:{            
      
      if(arrPos<max_opt)
              arrPos++;
             else arrPos=1;

    break;
    
    }
      case 13:{       
      if(arrPos==7) return 0;
              
                   cin>>any[arrPos-1]; 
                    w[n] = arrPos-1;
                    n++;       
 
         break;
    }
      case 70:{

       if(n>0&&b==0){
        search_all(any,w,n); 
        b=1;
       
        
       break;  
              
       }
    
                      else cout<<"Introducet cel putin un parametru"<<endl;
            
     break;                        
      
  }
  
  case 27:{

    delete[] w;  
    int *w = new int[100]; 
    char **any = new char*[50];
    create_arr(any);
    n=0;
    b=0;
  break;
  } 
    
  
 break; 
          
   }

    }                
  
}

}

void save_stud_insert(){

	nrStud++;	

}	


void insert_GrStud(){	
	system("cls");  
	
	do{
		
		cout<< "Student "<<nrStud+1<<" Date - Studii "<<endl;
		cout<< "Grupa: "; cin>>Stud[nrStud].grupa;
			
		do{
		  cout<< "Finantare \n 1 - Contract\n 0 - Buget "; cin>>Stud[nrStud].buget;	
		}while(Stud[nrStud].buget!=0 &&Stud[nrStud].buget!=1);	
	
		
		   if(Stud[nrStud].buget==1){
			cout<<"Suma contract "; cin>>Stud[nrStud].s_contract; 
			do{
			   cout<<" Plata \n 1 - Efectuata\n 0 - Neefectuata "; cin>>Stud[nrStud].plata;	
			}while(Stud[nrStud].plata!=0 &&Stud[nrStud].plata!=1);
			
		}                      
		
		cout<< "Media: "; cin>>Stud[nrStud].media;
		cout<<"\n[ESC]IESIRE MENIU"<<"\t\t\t";
	
				
	}while(_getch()!=27);
	
	if(state_edit == 0){

	cout<<"Doriti sa finalizati insertia si sa treceti la urmatorul student?"<<endl;
       	     	cout<<"\n[ESC]NU"<<"\t\t\t[ENTER]DA\n";
       	     	entry_insert=1;
       	     	if(_getch()!=27){					
		        save_stud_insert();	
		        entry_insert=0;
		   	    
		 		}
		 	
	
       }
       
       else return;

}

void insert_Nstud(){
 system("cls");  
        while(1){
	
		cout<< "Student "<<nrStud+1<<endl;
		cout<< "Nume: "; cin>>Stud[nrStud].Nume.nume;
		cout<< "Prenume: "; cin>>Stud[nrStud].Nume.prenume;
		cout<< "Patronimic: "; cin>>Stud[nrStud].Nume.patronimic;
		cout<<"\n[ESC]IESIRE MENIU"<<"\t\t\t[ENTER]CONTINUA\n";
		
		
	       if(_getch()==27){
       	     if(state_edit == 0){
       	     	system("cls");
       	     	cout<<"Doriti sa finalizati insertia si sa treceti la urmatorul student?"<<endl;
       	     	cout<<"\n[ESC]NU"<<"\t\t\t[ENTER]DA\n";
       	     	entry_insert=1;
       	     	if(_getch()!=27){					
		        save_stud_insert();	
		        entry_insert=0;
		        
		   		   break;
		 		}
		 	
     	}
		
	 break;
	}
	
		else {
		      insert_GenStud(); break;
		}	
	
	}
}

void show_Stud_Gr(){
	int *y = new int[nrStud];
	active_arr(y);
	int *buff_del = new int;
	*buff_del=nrStud;

	system("cls");
	*buff_del-=nrStud_del;

	
if(*buff_del>0){ 
		int spp = *buff_del < 3 ? *buff_del : 3;
        int fin_page=spp, init_page=0;	
        int current_page = 1;
        int nr_page = *buff_del%3==0?*buff_del/3:*buff_del/3+1; 
while(1){
   system("cls");	
   		
	for(int i=init_page;i<fin_page;i++){
		cout<<"Student "<<i+1<<endl;
	    cout<<"Grupa: "<<Stud[y[i]].grupa<<endl;
	    cout<<"Media: "<<Stud[y[i]].media<<endl;	    
		cout<<"Finantare: "; Stud[y[i]].buget == 1? cout<<" Contract "<<endl: cout<<" Buget "<<endl;					
		   if(Stud[y[i]].buget==1){
		cout<<"Suma contract: "<<Stud[y[i]].s_contract<<endl; 		
		cout<<"Plata: "; Stud[y[i]].plata == 1? cout<<" Efectuata "<<endl : cout<< " Neefectuata "<<endl;	
	}
	    current_page = fin_page%spp==0?fin_page/spp:fin_page/spp+1;
	    cout<<"*************************"<<endl;
       }
       cout<<"\n\n Numar pagina  "<<current_page<<"/"<<nr_page;
       cout<<"\t\t\t\t\t";
    if(current_page>1&&current_page<=nr_page)cout<< "<-- Pagina Precedenta"; cout<<"\t\t";
	if(current_page>=1&&current_page<nr_page)cout<<"Pagina Urmatoare -->";
  	switch(_getch()){
		case 77:{ 
		          
		init_page+=spp; fin_page+=spp;
		
		   if(fin_page>*buff_del){
		   	 
		   	  fin_page=*buff_del;
		   	   if (*buff_del%3!=0){
				 
		   	        init_page=*buff_del-*buff_del%3;
		   	        fin=1;
				 }
				 
				   else init_page = *buff_del-spp;
		   }

		   	 
			break;
		}
		
			case 75:{
				if(fin==1) {
					fin_page+=(spp-*buff_del%3);
					fin=0;
				}
				   init_page-=spp; fin_page-=spp;	
					if(init_page<0){				   		  
	                init_page=0; fin_page=spp;
					   } 
					   
								
			          break;
		}
		
			case 27:{
			return;
		}
	}
}
	}
	else {
	cout<<" Nu sunt date"<<endl;
	system("pause");
	}
	
	delete buff_del;
	delete[] y;
}



void show_Stud_gen(){
	int *y = new int[nrStud];
	active_arr(y);
	int *buff_del = new int;
	*buff_del=nrStud;

	system("cls");
	*buff_del-=nrStud_del;

	
if(*buff_del>0){ 
		
		int spp = *buff_del < 3 ? *buff_del : 3;
        int fin_page=spp, init_page=0;	
        int current_page = 1;
        int nr_page = *buff_del%3==0?*buff_del/3:*buff_del/3+1; 
while(1){
   system("cls");	
	for(int i=init_page;i<fin_page;i++){
		cout<<"Student "<<i+1<<endl;
		cout<<"Data Nasterii: "<<Stud[y[i]].Varsta.zi<<"."<<Stud[y[i]].Varsta.luna<<"."<<Stud[y[i]].Varsta.an<<endl;
		cout<<"IDNP: "<<Stud[y[i]].idnp<<endl;
		  current_page = fin_page%spp==0?fin_page/spp:fin_page/spp+1;
		cout<<"*************************************************"<<endl;
	}
	cout<<"\n\n Numar pagina  "<<current_page<<"/"<<nr_page;
	cout<<"\t\t\t\t\t";
    if(current_page>1&&current_page<=nr_page)cout<< "<-- Pagina Precedenta"; cout<<"\t\t";
	if(current_page>=1&&current_page<nr_page)cout<<"Pagina Urmatoare -->";
	switch(_getch()){
		case 77:{ 
		          
		init_page+=spp; fin_page+=spp;
		
		   if(fin_page>*buff_del){
		   	 
		   	  fin_page=*buff_del;
		   	   if (*buff_del%3!=0){
				 
		   	        init_page=*buff_del-*buff_del%3;
		   	        fin=1;
				 }
				 
				   else init_page = *buff_del-spp;
		   }

		   	 
			break;
		}
		
			case 75:{
				if(fin==1) {
					fin_page+=(spp-*buff_del%3);
					fin=0;
				}
				   init_page-=spp; fin_page-=spp;	
					if(init_page<0){				   		  
	                init_page=0; fin_page=spp;
					   } 
					   
								
			          break;
		}
		
			case 27:{
			return;
		}
	}
}
	}
	else {
	cout<<" Nu sunt date"<<endl;
	system("pause");
	}
	delete buff_del;
	delete[] y;	
}
void show_Stud_name(){
	int *y = new int[nrStud];
	active_arr(y);
	int *buff_del = new int;
	*buff_del=nrStud;

	system("cls");
	*buff_del-=nrStud_del;

	
if(*buff_del>0){
 		int spp = *buff_del < 3 ? *buff_del : 3;
        int fin_page=spp, init_page=0;	
        int current_page=1;
        int nr_page = *buff_del%3==0?*buff_del/3:*buff_del/3+1; 
 	while(1){
   system("cls");
	for(int i=init_page;i<fin_page;i++){
	
		cout<<"Student "<<i+1<<endl;
		cout<<"Nume: "<<Stud[y[i]].Nume.nume<<endl;
		cout<<"Prenume: "<<Stud[y[i]].Nume.prenume<<endl;
		cout<<"Patronimic: "<<Stud[y[i]].Nume.patronimic<<endl;
		current_page = fin_page%spp==0?fin_page/spp:fin_page/spp+1;		
		cout<<"*************************************************"<<endl;
		
	}
	cout<<"\n\n Numar pagina  "<<current_page<<"/"<<nr_page;
	cout<<"\t\t\t\t\t";
    if(current_page>1&&current_page<=nr_page)cout<< "<-- Pagina Precedenta"; cout<<"\t\t";
	if(current_page>=1&&current_page<nr_page)cout<<"Pagina Urmatoare -->";
	switch(_getch()){
		case 77:{ 
		          
		init_page+=spp; fin_page+=spp;
		
		   if(fin_page>*buff_del){
		   	 
		   	  fin_page=*buff_del;
		   	   if (*buff_del%3!=0){
				 
		   	        init_page=*buff_del-*buff_del%3;
		   	        fin=1;
				 }
				 
				   else init_page = *buff_del-spp;
		   }

		   	 
			break;
		}
		
			case 75:{
				if(fin==1) {
					fin_page+=(spp-*buff_del%3);
					fin=0;
				}
				   init_page-=spp; fin_page-=spp;	
					if(init_page<0){				   		  
	                init_page=0; fin_page=spp;
					   } 
					   
								
			          break;
		}
		
			case 27:{
			return;
		}
	}
}
	}
	else {
	cout<<" Nu sunt date"<<endl;
	system("pause");
	}
	
	delete buff_del;
	delete[] y;
}

void show_Stud_all(){
	int *y = new int[nrStud];
	active_arr(y);
	int *buff_del = new int;
	*buff_del=nrStud;

	system("cls");
	*buff_del-=nrStud_del;

	
if(*buff_del>0){
int spp = *buff_del < 3 ? *buff_del : 3;
int fin_page=spp, init_page=0;	
int nr_page = *buff_del%3==0?*buff_del/3:*buff_del/3+1; 
int current_page=0;

while(1){
   system("cls");

	for(int i=init_page;i<fin_page;i++){
	
			
	
		cout<<"Student "<<i+1<<endl;
		cout<<"Nume: "<<Stud[y[i]].Nume.nume<<endl;
		cout<<"Prenume: "<<Stud[y[i]].Nume.prenume<<endl;
		cout<<"Patronimic: "<<Stud[y[i]].Nume.patronimic<<endl;
		cout<<"Grupa: "<<Stud[y[i]].grupa<<endl;
		cout<<"Data Nasterii: "<<Stud[y[i]].Varsta.zi<<"."<<Stud[y[i]].Varsta.luna<<"."<<Stud[y[i]].Varsta.an<<endl;
		cout<<"IDNP: "<<Stud[y[i]].idnp<<endl;
		cout<<"Media: "<<Stud[y[i]].media<<endl;
		cout<<"Finantare: "; Stud[y[i]].buget == 1? cout<<" Contract "<<endl: cout<<" Buget "<<endl;	
						
		   if(Stud[y[i]].buget==1){
		cout<<"Suma contract: "<<Stud[y[i]].s_contract<<endl; 		
		cout<<"Plata: "; Stud[y[i]].plata == 1? cout<<" Efectuata "<<endl : cout<< " Neefectuata "<<endl;	
	}
        current_page = fin_page%spp==0?fin_page/spp:fin_page/spp+1;
		cout<<"*************************************************"<<endl;
}
	cout<<"\n\n Numar pagina  "<<current_page<<"/"<<nr_page;
	cout<<"\t\t\t\t\t";
	
    if(current_page>1&&current_page<=nr_page)cout<< "<-- Pagina Precedenta"; cout<<"\t\t";
	if(current_page>=1&&current_page<nr_page)cout<<"Pagina Urmatoare -->";
    	

	switch(_getch()){
		case 77:{ 
		          
		init_page+=spp; fin_page+=spp;
		
		   if(fin_page>*buff_del){
		   	 
		   	  fin_page=*buff_del;
		   	   if (*buff_del%3!=0){
				 
		   	        init_page=*buff_del-*buff_del%3;
		   	        fin=1;
				 }
				 
				   else init_page = *buff_del-spp;
		   }

		   	 
			break;
		}
		
			case 75:{
				if(fin==1) {
					fin_page+=(spp-*buff_del%3);
					fin=0;
				}
				   init_page-=spp; fin_page-=spp;	
					if(init_page<0){				   		  
	                init_page=0; fin_page=spp;
					   } 
					   
								
			          break;
		}
		
			case 27:{
			return;
		}
	
     }
}
}
	
	else {
	cout<<" Nu sunt date"<<endl;
	system("pause");
	}
	
	delete buff_del;
	delete[] y;
}


void del_stud(){
	system("cls");
	int *w = new int;
	bool *ch = new bool;
	bool *change = new bool;
	do{
	
	do{
		cout<<" Introdu ID student"<<endl;
		cin>>*w;
		(*w)--;
	}while(*w>nrStud||*w<0);
	Stud[*w].activ==1? (*change)=1 : (*change)=0;
	cout<<Stud[*w].Nume.nume<<" "<<Stud[*w].Nume.prenume<<endl;
	cout<<" Indica starea contului: \n 1. Activ \n 0. Inactiv \n"<<endl;
	cin>>Stud[*w].activ;
	*ch=Stud[*w].activ;
	if(*ch==0&&*change==1) nrStud_del++;
	else if (nrStud_del>0 && *ch==1 && *change==0) nrStud_del--;
	else nrStud_del=nrStud_del;
	system("cls");
	
	cout<<" [ENTER] MODIFICARE ALT CONT \t\t [ESC] IESIRE"<<endl;
}while(_getch()!=27);

 delete w;	
 delete change;
 delete ch;
}


void find_STUDENT__name()
	 {
	 	bool k=false; char nume[100]; system("cls");
	 
	 if( nrStud > 0 )
	 {   
	     cout<<"\n\n\t Introdu numele  :: "; cin>>nume;
	 	 
	 	 for(int i=0; i < nrStud ; i++)
	 	 {
	 	   if( strnicmp( Stud[i].Nume.nume , nume,strlen(nume) ) == 0 || strnicmp( Stud[i].Nume.prenume , nume,strlen(nume)) ==0) 	
	 	   {
	 	   	    cout<<" Student["<<i+1<<"] "<<endl;
 	  			cout<<" Nume: "<<Stud[i].Nume.nume<<endl;
		        cout<<" Prenume: "<<Stud[i].Nume.prenume<<endl;
 	  			cout<<" Grupa: "<<Stud[i].grupa<<endl;
 	  			cout<<" Data nasterii: "<<Stud[i].Varsta.zi<<"."<<Stud[i].Varsta.luna<<"."<<Stud[i].Varsta.an<<endl;
 	  			cout<<" IDNP: "<<Stud[i].idnp<<endl;
 	            cout<<"************************"<<endl;
		    k=true;   
		   }
         }
         if( k == false ) cout<<"\n\n\t Nu exista studenti cu numele \""<<nume<<"\""<<endl;
       }
	 else {	cout<<"\n\n\t Nu exista studenti "<<endl; }
	 
	 	 cout<<endl;  system("pause"); 	 
	 }
	 

template <typename T>
void save_file(T X[],int n,char nume_file[])	{
	system("cls");
	FILE *fp;
	if((fp=fopen(nume_file,"w+b"))==NULL) {
		cout<<"Error!"<<endl;
		exit((0));
	}
	fwrite(X,sizeof(T),n,fp);
	fclose(fp);
}

template <typename T>
int load_file(T X[],char nume_file[])	{
	FILE *fp;
	if((fp=fopen(nume_file,"r+b"))==NULL) {
		cout<<"Error!"<<endl;
		exit((0));
	}
	int n = fread(X,sizeof(T),1000,fp);
	fclose(fp);
	return n;
}


	 
	 
	 
	void find_STUDENT__grupa()
	 {
	 	bool k=false; char grupa[100]; system("cls");
	 
	 if( nrStud > 0 )
	 {   
	     cout<<"\n\n\t Introdu nr grupei  :: "; cin>>grupa;
	 	 
	 	 for(int i=0; i < nrStud ; i++)
	 	 {
	 	   if( strnicmp( Stud[i].grupa , grupa,strlen(grupa) ) == 0 ) 	
	 	   {
	 	   	    cout<<" Student["<<i+1<<"] "<<endl;
 	  			cout<<" Nume: "<<Stud[i].Nume.nume<<endl;
		        cout<<" Prenume: "<<Stud[i].Nume.prenume<<endl;
 	  			cout<<" Grupa:  "<<Stud[i].grupa<<endl;
 	  			cout<<" Data nasterii:  "<<Stud[i].Varsta.zi<<"."<<Stud[i].Varsta.luna<<"."<<Stud[i].Varsta.an<<endl;
 	  			cout<<" IDNP: "<<Stud[i].idnp<<endl;
 	            cout<<"************************"<<endl;
		    k=true;   
		   }
         }
         if( k == false ) cout<<"\n\n\t Nu exista studenti in grupa   \""<<grupa<<"\""<<endl;
       }
	 else {	cout<<"\n\n\t Nu exista studenti "<<endl; }
	 
	 	 cout<<endl;  system("pause"); 	 
	 }
	 
void find_STUDENT__idnp()
	 {
	 	bool k=false; char IDNP[100]; system("cls");
	 
	 if( nrStud > 0 )
	 {   
	     cout<<"\n\n\t Introdu IDNP :: "; cin>>IDNP;
	 	 
	 	 for(int i=0; i < nrStud ; i++)
	 	 {
	 	   if( strnicmp( Stud[i].idnp , IDNP,strlen(IDNP) ) == 0 ) 	
	 	   {
	 	   	    cout<<" Student["<<i+1<<"] "<<endl;
 	  			cout<<" Nume:   "<<Stud[i].Nume.nume<<endl;
 	  			cout<<" Grupa:  "<<Stud[i].grupa<<endl;
 	  			cout<<" Data nasterii:  "<<Stud[i].Varsta.zi<<"."<<Stud[i].Varsta.luna<<"."<<Stud[i].Varsta.an<<endl;
 	  			cout<<" IDNP: "<<Stud[i].idnp<<endl;
 	            cout<<"************************"<<endl;
		    k=true;   
		   }
         }
         if( k == false ) cout<<"\n\n\t Nu exista studenti cu IDNP-ul \""<<IDNP<<"\""<<endl;
       }
	 else {	cout<<"\n\n\t Nu exista studenti "<<endl; }
	 
	 	 cout<<endl;  system("pause"); 	 
	 }
	 
	 void find_STUDENT__an()
	 {
	 	bool k=false; char an[100]; system("cls");
	 
	 if( nrStud > 0 )
	 {   
	     cout<<"\n\n\t Introdu data nasterii :: "; cin>>an;
	 	 
	 	 for(int i=0; i < nrStud ; i++)
	 	 {
	 	   if( strnicmp( Stud[i].Varsta.an , an,strlen(an) ) == 0|| strnicmp( Stud[i].Varsta.luna , an ,strlen(an)) == 0||strnicmp( Stud[i].Varsta.zi , an ,strlen(an)) == 0) 	
	 	   {
	 	   	    cout<<" Student["<<i+1<<"] "<<endl;
 	  			cout<<" Nume:   "<<Stud[i].Nume.nume<<endl;
 	  			cout<<" Grupa:  "<<Stud[i].grupa<<endl;
 	  			cout<<" Data nasterii:  "<<Stud[i].Varsta.zi<<"."<<Stud[i].Varsta.luna<<"."<<Stud[i].Varsta.an<<endl;
 	  			cout<<"IDNP: "<<Stud[i].idnp<<endl;
 	            cout<<"************************"<<endl;
		    k=true;   
		   }
         }
         if( k == false ) cout<<"\n\n\t Nu exista studenti nascuti in \""<<an<<"\""<<endl;
       }
	 else {	cout<<"\n\n\t Nu exista studenti "<<endl; }
	 
	 	 cout<<endl;  system("pause"); 	 
	 } 

void search_all(char **a, int y[100],int n){
system("cls");
int *u = new int[100];
int *f = new int[100];
int v = 0;
int l = 0;
int nn = 0;
int nnn = 0;
do{

	switch(y[v]){
		case 0:{
			for(int i = 0; i<nrStud;i++){
				strnicmp( Stud[i].Nume.nume , 
				a[y[v]],strlen(a[y[v]]) ) == 0 ? u[l++]=i: i=i;	
	
			}
				v++;

			break;
		}
		
		case 1:{
				for(int i = 0; i<nrStud;i++){
			strnicmp( Stud[i].Nume.prenume , a[y[v]],strlen(a[y[v]]) ) == 0 ? u[l++]=i : i=i;
           
		}
		v++;
            
			break;
	}
	
	case 2:{
				for(int i = 0; i<nrStud;i++){
			strnicmp( Stud[i].Nume.patronimic , a[y[v]],strlen(a[y[v]]) ) == 0 ? u[l++]=i : i=i;
  
		}
		v++;
	
	
	break;
 
         }

	case 3:{
				for(int i = 0; i<nrStud;i++){
			strnicmp( Stud[i].grupa , a[y[v]],strlen(a[y[v]]) ) == 0 ? u[l++]=i : i=i;
 
		}
		v++;
	  	break;
	

 
}

	case 4:{
				for(int i = 0; i<nrStud;i++){
			strnicmp( Stud[i].Varsta.an , a[y[v]],strlen(a[y[v]]) ) == 0 ? u[l++]=i : i=i;
  
		}
		v++;
}
	
	case 5:{
				for(int i = 0; i<nrStud;i++){
			strnicmp( Stud[i].idnp , a[y[v]],strlen(a[y[v]]) ) == 0 ? u[l++]=i : i=i;
  
		}
		v++;
	   default: break;
 
}
}
}while(v<n);
if(l>0&&n==1) show_by_index(u,l);

if(v==2){
	for(int i = 0;i<l;i++){
	for(int j=i+1;j<l;j++){
	if(u[i]==u[j]){
	
	f[nn] = u[i];
	nn++;}
	}
	
}
show_by_index(f,nn);

}
else if(v>=3){
for(int i = 0;i<l;i++){
	for(int j=i+1;j<l;j++){
	if(a[y[u[i]]]==a[y[u[j]]]){
	nnn++;}
	}
	if(nnn==v){
	f[nn] = u[i];
	nn++;
	nnn=0;	
	}
		
}
show_by_index(f,nn);

}


else cout<<" Nici un rezultat gasit :("<<endl;
system("pause");
delete_arr(a);	 
delete[] f;
delete[] u;
return;
}

void delete_arr(char **a){
		for(int i = 0;i<50;i++){
	       delete[] a[i];	
		
	}
	  	 delete[] a;
	  a=NULL;
}

void delete_arr(char **a,int nrstud){
		for(int i = 0;i<nrstud;i++){
	       delete[] a[i];	
		
	}
	  	 delete[] a;
	  a=NULL;
}



void show_by_index(int i[100],int n){

system("pause");
  int spp = n < 3 ? n : 3;
  int fin_page=spp, init_page=0;	
  int nr_page = n%3==0?n/3:n/3+1; 
  int current_page=0;
  while(1){
  	
system("cls");
	 for(int j=init_page;j<fin_page;j++)
	 	 {
	            
	            cout<<" Student["<<i[j]+1<<"] "<<endl;
 	  			cout<<" Nume:   "<<Stud[i[j]].Nume.nume<<endl;
 	  			cout<<" Prenume:   "<<Stud[i[j]].Nume.prenume<<endl;
 	  			cout<<" Patronimic:   "<<Stud[i[j]].Nume.patronimic<<endl;
 	  			cout<<" Grupa:  "<<Stud[i[j]].grupa<<endl;
 	  			cout<<" Data nasterii:  "<<Stud[i[j]].Varsta.zi<<"."<<Stud[i[j]].Varsta.luna<<"."<<Stud[i[j]].Varsta.an<<endl;
 	  			cout<<" IDNP: "<<Stud[i[j]].idnp<<endl;
 	  			cout<<" Media: "<<Stud[i[j]].media<<endl;
 	  			cout<<" Finantare: "; Stud[i[j]].buget == 1? cout<<" Contract "<<endl: cout<<" Buget "<<endl;					
		         if(Stud[i[j]].buget==1){
		        cout<<" Suma contract: "<<Stud[i[j]].s_contract<<endl; 		
		        cout<<" Plata: "; Stud[i[j]].plata == 1? cout<<" Efectuata "<<endl : cout<< " Neefectuata "<<endl;	
	}
 	  			current_page = fin_page%spp==0?fin_page/spp:fin_page/spp+1;
 	            cout<<"************************"<<endl;
 	           
 	           
}
	           cout<<"\n\n Numar pagina  "<<current_page<<"/"<<nr_page;
	           cout<<"\t\t\t\t\t";
    if(current_page>1&&current_page<=nr_page)cout<< "<-- Pagina Precedenta"; cout<<"\t\t";
	if(current_page>=1&&current_page<nr_page)cout<<"Pagina Urmatoare -->";
	        
	           	switch(_getch()){
	           		
		case 77:{ 
		          
		init_page+=spp; fin_page+=spp;
		
		   if(fin_page>n){
		   	 
		   	  fin_page=n;
		   	   if (n%3!=0){
				 
		   	        init_page=n-n%3;
		   	        fin=1;
				 }
				 
				   else init_page = n-spp;
		   }

		   	 
			break;
		}
		
			case 75:{
				if(fin==1) {
					fin_page+=(spp-n%3);
					fin=0;
				}
				   init_page-=spp; fin_page-=spp;	
					if(init_page<0){				   		  
	                init_page=0; fin_page=spp;
					   } 
					   
								
			          break;
		}
		
			case 27:{
			return;
		}

}
  }
}

	







void create_arr(char **a){
		  for(int i =0;i<50;i++){
	 a[i] = new char[100];
	  }
}

void create_arr(char **a,int nrstud){
		  for(int i =0;i<nrstud;i++){
	 a[i] = new char[100];
	  }
}


void conf(){
	FILE *fp;
	if( (fp=fopen("config.ini","r+"))== NULL){
		cout<<" Error loading file conf.ini"<<endl; system("pause");
		return;
	}
	fscanf(fp,"%s%s%s",&nume_file_stud,&nume_file_user,&nume_file_statS);

}

void conf_modif(){
	FILE *fp;
	if( (fp=fopen("config.ini","r+"))== NULL){
		cout<<" Error loading file conf.ini"<<endl; system("pause");
		return;
	}
	

		fprintf(fp,"%s\n%s\n%s",nume_file_stud,nume_file_user,nume_file_statS);	

		
	}
	


void raport_student(){

		FILE *fp;

		char **np = new char*[nrStud];
		create_arr(np,nrStud);
  
        
        
		for(int i = 0;i<nrStud;i++){
							
		   strcpy(np[i],Stud[i].Nume.nume);
           strcat(np[i], " ");
           strncat(np[i],Stud[i].Nume.prenume,1);
           strcat(np[i], ".");
           
		}
	
	if( (fp=fopen("raport_student.doc","w+"))== NULL){
		cout<<" Error loading file raport_student.d"<<endl; system("pause");
		return;
	}
	
		for( int i = 0 ; i<nrStud; i++ )
	 	{
		    if(i==0)
	 		fprintf( fp , "%-12.15s \t\t %-8.15s \t\t %5s \t\t %-5s\t\t\n\n",
			"N.P","Grupa","Media","Finantare");
			if(Stud[i].activ==1)
	 		fprintf( fp, "%-15.100s\t %4s\t %-15s %5.2f\t\t\t %-5s\t \n",np[i], " ",Stud[i].grupa, Stud[i].media,Stud[i].buget==1 ? "Contract":"Buget");
	    }
	 	
	 	fclose(fp);
	 	 
	 	system("raport_student.doc");
	 	delete_arr(np,nrStud);


	 	 	
	 }

void login()
	 {
	 	
	 	system("cls");
	 	
	 	int i = 0 , KEY;
	 	char pass[100];
	 	char username[100];
	 	
	 	cout<<"\n\n\t Nume utilizator :: ";
	 	cin>>username;

	 	cout<<"\n\n\t Parola :: ";
	 	
	 	while(1)
	 	{
	 	  
	 	   KEY = _getch(); 
		   
		   if( KEY == 13 )
		   {
		   	  pass[i] = '\0' ; 
		   	  
		   	  for(int x=0; x < nrUser; x++ )
		   	  {
				 
		   	    if( User[x].stare == true && strcmp( User[x].parola,pass)== 0 &&strcmp( User[x].nume , username ) ==0 )
		   	    {
		   	  	  
		   	  	    userID = x ; 
		   	  	    StatS[userID].Nr_Acces++;
					return; 
			    }
			   
		   	  }
		   	  		   	  
		   	  system("cls");
		   	  system("color 4F");
		   	  cout<<"\n\n\t LOGIN ERROR "<<endl;
		   	  cout<<endl;
		   	  system("pause");
		   	  
		   	  
		   	  i = 0; 
		   	  
		   	  system("cls");
		   	  system("color F");
		   	  cout<<"\n\n\t Nume utilizator :: ";
	 	      cin>>username;
		   	  cout<<"\n\n\t Parola :: ";
		   	  
		   	  
		   }
		   else if( KEY == 8 )
		   {
		   	  if( i > 0 )
		   	  {
		   	     cout<<"\b \b";      
		   	     i--;
			  }
		   }
		   else if( KEY == 27 )
		   {
		   	  exit(0);
		   }
		   else
		   { 
		      cout<<'*';
		   
		      pass[i] = KEY;
		   
		      i++;
		   }
		    
		   	
	    }
	 	
	 }
	 
void insert_user(){
	system("cls");
bool rep=0;

do{ 
    
	cout<<" Nume utilizator: ";
	cin>> User[nrUser].nume;
	cout<<" Parola: ";
	cin>>User[nrUser].parola;
	cout<<" Admin Status\t[ENTER] - DA \t [ESC] - NU"<<endl;
	if(_getch()!=27) User[nrUser].admin=1;
for(int j=0;j<nrUser;j++)	{

	if(strcmp(User[nrUser].nume,User[j].nume)==0){
	system("cls");
	cout<<" Nume utilizator deja in utilizare\t\t [ENTER] - REINTRODUCERE DATE\t [ESC] - IESIRE"<<endl;
	rep =1;
	}
	}
if(rep==0) {
StatS[nrUser].userId=nrUser;
nrUser++;
system("cls");
cout<<"[ENTER] -  Creare utilizator nou \t [ESC] - IESIRE"<<endl;	

}
rep=0;	
}while(_getch()!=27);
system("cls");
	
}

void show_user(){

	
system("cls");
if(nrUser>0){
int spp = nrUser < 3 ? nrUser : 3;
int fin_page=spp, init_page=0;	
int current_page=1;
int nr_page = nrUser%3==0 ? nrUser/3 : nrUser/3+1; 
while(1){
   system("cls");
 
	for(int i=init_page;i<fin_page;i++){
		cout<<"UserId "<<i+1<<endl;
		cout<<"Nume: "<<User[i].nume<<endl;
		cout<<"Stare: ";User[i].stare == 1? cout<<"Activ"<<endl:cout<<"Deactivat"<<endl;
		cout<<"Nr Editari: "<<User[i].nr_editari<<endl;
		cout<<"Nr Inserari: "<<StatS[i].NrStudInsert<<endl;
		cout<<"Statut: "; User[i].admin==1 ? cout<<" Admin "<<endl : cout<<" User "<<endl;
		
		cout<<"*************************************************"<<endl;
		current_page = fin_page%spp==0?fin_page/spp:fin_page/spp+1;		
	}
	cout<<" Numar pagina  "<<current_page<<"/"<<nr_page;
	cout<<"\t\t\t\t\t";
    if(current_page>1&&current_page<=nr_page)cout<< "<-- Pagina Precedenta"; cout<<"\t\t";
	if(current_page>=1&&current_page<nr_page)cout<<"Pagina Urmatoare -->";
	switch(_getch()){
		case 77:{ 
		          
		init_page+=spp; fin_page+=spp;
		
		   if(fin_page>(nrUser)){
		   	 
		   	  fin_page=nrUser;
		   	   if (nrUser%3!=0){
				 
		   	        init_page=nrUser-nrUser%3;
		   	        fin=1;
				 }
				 
				   else init_page = nrUser-spp;
		   }

		   	 
			break;
		}
		
			case 75:{
				if(fin==1) {
					fin_page+=(spp-nrUser%3);
					fin=0;
				}
				   init_page-=spp; fin_page-=spp;	
					if(init_page<0){				   		  
	                init_page=0; fin_page=spp;
					   } 
					   
								
			          break;
		}
		
			case 27:{
			return;
		}
	}
}
	}
	else {
	cout<<" Nu sunt date"<<endl;
	system("pause");
	}
}

int check_rep(char name[256]){
for(int j=0;j<nrUser;j++)	{

	if(strcmp(name,User[j].nume)==0)
	return 1;
	
		
}
return 0;
}
void edit_user(){
	char name[100];
	system("cls");
	int w;
	do{
		
	 	cout<<" Introdu id user"<<endl;
		cin>>w;
		w--;
		}while(w>nrUser||w<0);
system("cls");
do{
system("cls");
	system("color F");
	 	cout<<"\n\n\t  MENIU - User "<<endl;
	 	cout<<"\t  1. Schimbare nume "<<endl;
        cout<<"\t  2. Schimbare  parola"<<endl;
        cout<<"\t  3. Schimbare statut  "<<endl;
        cout<<"\t  4. Schimare stare cont  "<<endl;
        cout<<"\t  5. Alege alt user  "<<endl;
     	cout<<"\t[ESC] EXIT "<<endl;
     	
     	switch(_getch()){
     		case 49:{      		
			    cout<<" Introdu nume:"; cin>>name;
			    if(check_rep(name)==1) {
			    	cout<<" Nume ocupat"<<endl;
			    	system("pause");
				}
			    
			    else strcpy(User[w].nume,name);
	
				break;
				
			 }
			 case 50:{ 
			   cout<<" Introdu parola:"; cin>>User[w].parola;

				break;
				
			 }
			 case 51:{ 
               cout<<"Indica statut:\t[ENTER] - Admin \t [ESC] - User";
	           if(_getch()!=27) User[w].admin=1;
	    
				break;
				
			 case 52:{ 
			   cout<<" Indica stare cont\n1 - Activ:\n0 - Inactiv "; cin>>User[w].stare;
			   
				break;
				
			 }
					
	}       
	case 53:{ 
               do{
		
	 	cout<<" Introdu id user"<<endl;
		cin>>w;
		w--;
		}while(w>nrUser||w<0);

				break;
					
	}
}

}while(_getch()!=27);
}


void find_user__name()
	 {
	 	bool k=false; char nume[100]; system("cls");
	 
	 if( nrStud > 0 )
	 {   
	     cout<<"\n\n\t Introdu numele  :: "; cin>>nume;
	 	 
	 	 for(int i=0; i < nrUser ; i++)
	 	 {
	 	   if( strnicmp( User[i].nume , nume,strlen(nume) ) == 0 ) 	
	 	   {
	 	   	    cout<<" User["<<i+1<<"] "<<endl;
 	  			cout<<" Nume: "<<User[i].nume<<endl;
		        cout<<"Statut: "; User[i].admin==1 ? cout<<" Admin "<<endl : cout<<" User "<<endl;
 	            cout<<"************************"<<endl;
		    k=true;   
		   }
         }
         if( k == false ) cout<<"\n\n\t Nu exista useri cu numele \""<<nume<<"\""<<endl;
       }
	 else {	cout<<"\n\n\t Nu exista useri "<<endl; }
	 
	 	 cout<<endl;  system("pause"); 	 
	 }
	 
	 
void raport_user(){
	
	
		FILE *fp;
	if( (fp=fopen("statS.doc","w+"))== NULL){
		cout<<" Error loading file statS.d"<<endl; system("pause");
		return;
	}

		for( int i = 0 ; i<nrUser; i++ )
		
		
	 	{
		    if(i==0)
	 		fprintf( fp , "%-5.15s \t %-2s \t\t %-2s \t\t %-2s \t\t %-2s \n\n",
	 	
			"Nume","ID","Accesari","Inserari","Editari");
				if(User[i].stare==1){
				fprintf( fp , "%-5.15s %s\t %-2d \t\t %5d \t\t %5d\t\t %5d\t \n",User[i].nume, " ", StatS[i].userId,StatS[i].Nr_Acces,StatS[i].NrStudInsert,User[i].nr_editari);
	
				}
	    }
	 	
	 	fclose(fp);
	 	 
	 	system("statS.doc");
	 	
	 	 	
	 }
	 
void show_user_stat(){
	system("cls");

		cout<<"UserId "<<userID<<endl;
		cout<<"Nume: "<<User[userID].nume<<endl;
		cout<<"Statut: "; User[userID].admin==1 ? cout<<" Admin "<<endl : cout<<" User "<<endl;
		cout<<"Studenti Inserati: "<<StatS[userID].NrStudInsert<<endl;
		cout<<"Numar Editari: "<<User[userID].nr_editari<<endl;
		cout<<"*************************************************"<<endl;
		system("pause");

}	

void edit_user_nick(){
	system("cls");
	char name[100];
	
	do{
 system("cls");
	
	cout<<" Introdu nick-name nou"<<endl;
    cin>>name;
   
			    if(check_rep(name)==1) {
			    	 system("cls");
			    	cout<<" Nume ocupat"<<endl;
			    	
				}
			    
			    else {
			    strcpy(User[userID].nume,name);
			     system("cls");
				cout<<" Nickname schimbat cu succes!"<<endl;	
				}
			  
			    cout<<"[ESC] - IESIRE\t\t [ENTER] - SCHIMBARE NICKNAME"<<endl;
					}while(_getch()!=27);
} 

void edit_user_pass(){
	
	system("cls");
	char pass[100];
	



do{
	
cout<<"Introdu parola curenta"<<endl;
cin>>pass;
system("cls");	
	if(strcmp(User[userID].parola,pass)==0){
	cout<<" Introdu parola noua"<<endl;
	cin>>User[userID].parola;	
	}
	
	else{
		
		cout<<"Parola gresita!"<<endl;
		system("pause");
		
	}
	system("cls");
 cout<<"[ESC] - IESIRE\t\t [ENTER] - SCHIMBARE PAROLA CURENTA"<<endl;
}while(_getch()!=27);	
}
void active_arr(int v[100]){
	int *buff_st_del = new int;
	*buff_st_del=0;
	for(int i = 0,j=0;i<nrStud,j<nrStud;i++){
		if(Stud[i].activ==1){
		v[j]=i;
		j++;	
		}
		else (*buff_st_del)++;
		
	}
	
	nrStud_del=(*buff_st_del);
	
	delete buff_st_del;

}

void del_arr(int v[100]){
	int *buff_st_del = new int;
	*buff_st_del=0;

	   for(int i = 0,j=0;i<nrStud;i++){
		if(Stud[i].activ==0){
		v[j]=i;
		j++;
         (*buff_st_del)++;
		}
	}
	
	nrStud_del=(*buff_st_del);
	delete buff_st_del;

}

void show_Stud_del(){
	int *y = new int[nrStud];
	system("cls");
    del_arr(y);
    if(nrStud_del>0){
      int spp = nrStud_del < 3 ? nrStud_del : 3;
      int fin_page=spp, init_page=0;	
      int nr_page = nrStud_del%3==0?nrStud_del/3:nrStud_del/3+1; 
      int current_page=0;

while(1){
	system("cls");
		for( int i=init_page ; i<fin_page; i++ )
	 	{
		
	 	        cout<<" Student["<<i+1<<"] "<<endl;
 	  			cout<<" Nume: "<<Stud[y[i]].Nume.nume<<endl;
		        cout<<" Prenume: "<<Stud[y[i]].Nume.prenume<<endl;
 	  			cout<<" Grupa: "<<Stud[y[i]].grupa<<endl;
 	  			cout<<" Data nasterii: "<<Stud[y[i]].Varsta.zi<<"."<<Stud[i].Varsta.luna<<"."<<Stud[i].Varsta.an<<endl;
 	  			cout<<" IDNP: "<<Stud[y[i]].idnp<<endl;
 	            cout<<"************************"<<endl;
 	            current_page = fin_page%spp==0?fin_page/spp:fin_page/spp+1;
		  
		    	 }
		    	 
		    	 cout<<"\n\n Numar pagina  "<<current_page<<"/"<<nr_page;
	             cout<<"\t\t\t\t\t";
	
                if(current_page>1&&current_page<=nr_page)cout<< "<-- Pagina Precedenta"; cout<<"\t\t";
	            if(current_page>=1&&current_page<nr_page)cout<<"Pagina Urmatoare -->";
	            
	            switch(_getch()){
	            	
		case 77:{ 
		          
		init_page+=spp; fin_page+=spp;
		
		   if(fin_page>nrStud_del){
		   	 
		   	  fin_page=nrStud_del;
		   	   if (nrStud_del%3!=0){
				 
		   	        init_page=nrStud_del-nrStud_del%3;
		   	        fin=1;
				 }
				 
				   else init_page = nrStud_del-spp;
		   }

		   	 
			break;
		}
		
			case 75:{
				if(fin==1) {
					fin_page+=(spp-nrStud_del%3);
					fin=0;
				}
				   init_page-=spp; fin_page-=spp;	
					if(init_page<0){				   		  
	                init_page=0; fin_page=spp;
					   } 
					   
								
			          break;
		}
		
			case 27:{
			return;
		}
	
     }
}
}
	
	            
		   
         
       	else {
	cout<<" Nu sunt date"<<endl;
	system("pause");
	}
	
	delete[] y;
	
}

void raport_fileName(){
	bool *b = new bool;
	*b = 0;
	while(1){
		

	system("cls");
	cout<<"\n\n"<<endl;
	cout<<"\t  1.File Studenti"<<endl;
	cout<<"\t  2.File User"<<endl;
	cout<<"\t  3.File Statistica"<<endl;
	cout<<"\t  4.Setare Fisier de Baza"<<endl;
	cout<<"\tESC. EXIT "<<endl;
		
	
	
		switch(_getch()){
			
     		case 49:{ 
     		    cout<<"Nume file:: ";
			    cin>>nume_file_stud;
			    strcat(nume_file_stud,".doc");
			 
				break;
			 }
			 case 50:{ 
			 cout<<"Nume file:: ";
		     cin>>nume_file_user;
		     strcat(nume_file_user,".doc");

				break;
			 }
			 case 51:{ 
			    cout<<"Nume file:: ";
			    cin>>nume_file_statS;
			    strcat(nume_file_statS,".doc");
	
				break;
			 }
			 
			case 52:{ 
			    *b =1;
	
				break;
			 }
			 
			 
			 case 27:{
			 if(*b==1 ) conf_modif();
			     return;
			
			 }
			 
			 return;
}
	}
	delete b;
}

void START(){
	

conf();

 nrStud = load_file(Stud,nume_file_stud);
 nrUser = load_file(User,nume_file_user);
          load_file(StatS,nume_file_statS);
          
login();

	while(1){
		switch(load_Menu() ){ 
		
			case 11:			
			{
			insert_user();     
				
				break; 
			}
			case 12:			
			{
			edit_user();     
				
				break; 
			}
			case 13:			
			{
			show_user();     
				
				break; 
			}
			
				case 14:			
			{
			find_user__name();
				
				break; 
			}
			case 16:			
			{
			raport_student();
				
				break; 
			}
			
				case 17:			
			{
			raport_user();
				
				break; 
			}
				case 18:			
			{
			raport_fileName();
				
				break; 
			}
			case 211:			
			{
			insert_Nstud();
				
				break; 
			}
			
			case 212:{
			insert_GenStud();
				
				break; 
			}
			case 213:{
			insert_GrStud();
				
				break; 
			}
			
		  	case 214:{
			  			
			  break; 
			}
			
			case 215:{
			 			
			  break; 
			}
			
				case 277:{
			 	if(entry_insert==1){
				
				 save_stud_insert();
				
				  }	
				   StatS[userID].NrStudInsert+=(nrStud-buf2_nrStud);	
			  break; 
			}
			
	        case 311:{
	        	User[userID].nr_editari++;
			insert_Nstud();
				
				break; 
			}
			
		  	case 312:{
		  	  User[userID].nr_editari++;
			  insert_GenStud();	
			  break; 
			}
			
			case 313:{
				User[userID].nr_editari++;
			 	insert_GrStud();			
			  break; 
			}
			case 314:{
			 	edit=1;			
			  break; 
			}
			
			 case 411:{
		   show_Stud_name();
				
				break; 
			}
			
		  	case 412:{
			 show_Stud_gen();
			  break; 
			}
			
			case 413:{
			 show_Stud_Gr();			
			  break; 
			}
			case 414:{
			  show_Stud_all();			
			  break;                         
			}
			case 416:{
			  show_Stud_del();			
			  break;                          
			}
			
				 case 511:{
		        find_STUDENT__name();
				
				break; 
			}
			
		  	case 512:{
			 find_STUDENT__an();
			  break; 
			}
			
			case 513:{
			 find_STUDENT__idnp();			
			  break; 
			}
			case 514:{
			  find_STUDENT__grupa();			
			  break; 
			}
			
			case 515:{
			  find_STUDENT__any();			
			  break; 
			}
			case 711:{
			  edit_user_nick();			
			  break; 
			}
			
					case 712:{
			  edit_user_pass();			
			  break; 
			}
				case 713:{
			  show_user_stat();			
			  break; 
			}
			
			case 776:{
			  del_stud();			
			  break; 
			}
			case 777:{
				save_file(Stud,nrStud,nume_file_stud);
				save_file(User,nrUser,nume_file_user);
				save_file(StatS,nrUser,nume_file_statS);
				
				
			exit((0));
			}
		}
	}
}
