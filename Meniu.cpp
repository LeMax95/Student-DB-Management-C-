


 int meniu_Baza()
	 {
	 	system("cls");
	 	system("color F");
	 	cout<<"\n\n\t  MENIU "<<endl;
        User[userID].admin == 1 ? cout<<"\t  1. Management User "<<endl : cout<<"\t  1. Management Cont"<<endl;
        cout<<"\t  2. Management Student "<<endl;
        cout<<"\t  3. Efectuare Raport "<<endl;
	 	cout<<"\t  4. Statistica "<<endl;
	 	cout<<"\t  5. Creare document nou "<<endl;
     	cout<<"\tESC. EXIT "<<endl;
     	
     	switch(_getch()){
     		case 49:{ 
			    nivel_Meniu = 1; return 0;
				break;
			 }
			 case 50:{ 
			 buf2_nrStud = nrStud;
			    nivel_Meniu = 2; return 0;
			
			 }
			 case 51:{ 
			     return 16;
				break;
			 }
			 
			 	 case 52:{ 
			    return 17;
				break;
			 }
			    case 53:{ 
			    return 18;
				break;
			 }
			 
			 case 27:{ 
			    return 777;
				break;
			 }
		 }
     	
     	return 0;
}

int meniu_User_admin()
	 {
	 	system("cls");
	 	system("color F");
	 	cout<<"\n\n\t  MENIU "<<endl;
	 	cout<<"\t  1. Inserare User "<<endl;
        cout<<"\t  2. Editare User"<<endl;
        cout<<"\t  3. Afisare User "<<endl;
	 	cout<<"\t  4. Cautare User "<<endl;
     	cout<<"\tESC. EXIT "<<endl;
     	
     	switch(_getch()){
     		case 49:{ 
			    return 11;
				break;
			 }
			 case 50:{ 
			    return 12;
				break;
			 }
			 case 51:{ 
			    return 13;
				break;
			 }
			 case 52:{ 
			    return 14;
				break;
			 }
			 case 27:{ 
			    nivel_Meniu=0;
				break;
			 }
		 }
     	
     	return 0;
}

int meniu_User_simple()
	 {
	 	system("cls");
	 	system("color F");
	 	cout<<"\n\n\t  MENIU "<<endl;
	 	cout<<"\t  1. Schimbare nickname "<<endl;
        cout<<"\t  2. Schimbare parola"<<endl;
        cout<<"\t  3. Afisare Statistica "<<endl;
     	cout<<"\tESC. EXIT "<<endl;
     	
     	switch(_getch()){
     		case 49:{ 
			    return 711;
				break;
			 }
			 case 50:{ 
			    return 712;
				break;
			 }
			 case 51:{ 
			    return 713;
				break;
			 }
			 case 27:{ 
			    nivel_Meniu=0;
				break;
			 }
		 }
     	
     	return 0;
}

int meniu_Student()
	 {
	 	system("cls");
	 	system("color F");
	 	cout<<"\n\n\t  MENIU "<<endl;
	 	cout<<"\t  1. Inserare Student "<<endl;
        cout<<"\t  2. Editare Student"<<endl;
        cout<<"\t  3. Afisare Student "<<endl;
	 	cout<<"\t  4. Cautare Student "<<endl;
	 	cout<<"\t  5. Schimbare stare cont"<<endl;
     	cout<<"\tESC. EXIT "<<endl;
     	
     	switch(_getch()){
     		case 49:{ 
			    nivel_Meniu=3;return 0;
				
			 }
			 case 50:{
			buff_nrStud=nrStud;
		    edit=1;
		    state_edit = 1;
			nivel_Meniu=4;
			return 0;
			
			 }
			 case 51:{ 
			 nivel_Meniu=5;
			
				break;
			 }
			 case 52:{ 
			   nivel_Meniu=6;
				break;
			 }
			 
			 case 53:{ 
			   return 776;
				break;
			 }
			 case 27:{ 
			    nivel_Meniu=0;
				break;
			 }
		 }
     	
     	return 0;
}
int meniu_find__Student()
	 {
	 	system("cls");
	 	system("color F");
	 	cout<<"\n\n\t  MENIU - Student "<<endl;
	 	cout<<"\t  1. Cautare nume "<<endl;
        cout<<"\t  2. Cautare  data nasterii"<<endl;
        cout<<"\t  3. Cautare IDNP  "<<endl;
        cout<<"\t  4. Cautare grupa  "<<endl;
        cout<<"\t  5. Cautare oricare caracter  "<<endl;
     	cout<<"\tESC. EXIT "<<endl;
     	
     	switch(_getch()){
     		case 49:{ 
			    return 511;
				break;
			 }
			 case 50:{ 
			    return 512;
				break;
			 }
			 case 51:{ 
			    return 513;
				break;
	         }
	         case 52:{ 
			    return 514;
				break;
	         }
	         
	         case 53:{ 
			    return 515;
				break;
	         }
             case 27:{ 
			    nivel_Meniu=2;
				break;
			 }
		}
    
	}	   

int meniu_show__Student()
	 {
	 	system("cls");
	 	system("color F");
	 	cout<<"\n\n\t  MENIU - Student "<<endl;
	 	cout<<"\t  1. Afisare nume "<<endl;
        cout<<"\t  2. Afisare  date generale"<<endl;
        cout<<"\t  3. Afisare date studii  "<<endl;
        cout<<"\t  4. Afisare conturi deactivate   "<<endl;  
        cout<<"\t  5. Afisare Tot  "<<endl;
     	cout<<"\tESC. EXIT "<<endl;
     	
     		switch(_getch()){
     		case 49:{ 
			    return 411;
				break;
			 }
			 case 50:{ 
			    return 412;
				break;
			 }
			 case 51:{ 
			    return 413;
				break;
	}
           	case 52:{ 
			    return 416;
				break;
           	}
           
             case 27:{ 
			    nivel_Meniu=2;
				break;
			 }
	         case 53:{ 
			    return 414;
				break;
			 }
       }
}
int meniu_Insert__Student()
	 {
	 	system("cls");
	 	system("color F");
	 	cout<<"\n\n\t  MENIU - Student "<<endl;
	 	cout<<"\t  1. Inserare nume "<<endl;
        cout<<"\t  2. Inserare  date generale"<<endl;
        cout<<"\t  3. Inserare date studii  "<<endl;
        cout<<"\t  4. Completare date student  "<<endl;
     	cout<<"\tESC. EXIT "<<endl;
     	cout<<"\t  [5]. SAVE "<<endl;
     	switch(_getch()){
     		case 49:{ 
			    return 211;
				break;
			 }
			 case 50:{ 
			    return 212;
				break;
			 }
			 case 51:{ 
			    return 213;
				break;
	}
             case 27:{ 
			    nivel_Meniu=2;
				return 277;
			 }
	         case 52:{ 
			    return 214;
				break;
			 }
			 	
	        case 53:{ 
			return 215;
			break;
			 }		 
			 	
     	    return 0;
}

}

   int meniu_Edit_Student() {		
	 	system("cls");
	 	if(edit==1){
	 		
		do{
		
	 	cout<<" Introdu id student"<<endl;
		cin>>w;
		w--;
		}while(w>buff_nrStud||w<0);
		
		nrStud=w;
		edit=0;
				
		}
		
		
	 	system("color F");
	 	cout<<"\n\n\t  MENIU - Student "<<endl;
	 	cout<<"\t  1. Editare nume "<<endl;
        cout<<"\t  2. Editare  date generale"<<endl;
        cout<<"\t  3. Editare date studii  "<<endl;
        cout<<"\t  4. Alege alta persoana  "<<endl;
     	cout<<"\t[ESC] EXIT "<<endl;
     	
     	switch(_getch()){
     		case 49:{ 
			    return 311;
				break;
			 }
			 case 50:{ 
			    return 312;
				break;
			 }
			 case 51:{ 
			    return 313;
				break;
	}
	         case 52:{ 
	            entry=1;
			    return 314;
				break;
	}
      case 27:{ 
	  nrStud = buff_nrStud;
	  entry=0;
	  state_edit = 0;
	  nivel_Meniu=2;
	  return 0;
	  break;
	}	
   return 0;  	
}

}

int load_Menu(){
	
	switch(nivel_Meniu){
		
		case 0:{
			return meniu_Baza();
			break;
		}
		case 1:{
	    if(User[userID].admin==1) return  meniu_User_admin();
		else return meniu_User_simple();
        
		
			break;
		}
		
		case 2:{
			return meniu_Student();
			break;
		}
		
		
			case 3:{
			return meniu_Insert__Student();
			break;
		}
			case 4:{
			if(edit==1&&entry==0)
			buff_nrStud=nrStud;
			return meniu_Edit_Student();
			break;
		}
		   	case 5:{
			return meniu_show__Student();
			break;
		}
			case 6:{
			return meniu_find__Student();
			break;
		}
	}
	return 0;
}	
