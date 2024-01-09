struct grupa{
		char id[50];
		char limba[50];
		char an[50];
		char spec[50];
		
}Grupa[5];

struct user{
	
	char nume[100];
	char parola[100];
	bool stare=1;
	bool admin = 0;
	int nr_editari=0;
}User[1000];

int nrUser=0;

struct stud{	
	struct nume{
		char nume[100];
		char prenume[100];
		char patronimic[100];
	}Nume;
	
	struct varsta{
		char an[20];
		char luna[20];
		char zi[20];
	}Varsta;
	
    char idnp[20];
    bool activ = 1;
    char grupa[20];
    float media;
    bool buget=0;
    double s_contract;
    bool plata=0;
	
}Stud[1000];

      

struct statScx{
	int userId=0;
	int Nr_Acces = 0;
	int NrStudInsert = 0;
	
}StatS[1000];

int nivel_Meniu=0;
int nrStud = 0;
int nrStud_del = 0;
bool edit = 0;
bool entry = 0;
bool entry_insert = 0;
bool state_edit = 0;
bool fin=0;
int buff_nrStud;
int userID;
int w;
int buf2_nrStud;



char nume_file_stud[256];
char nume_file_user[256];
char nume_file_statS[256];
