#include"cstdlib"
#include"iostream"
#include"fstream"
#include"string.h"
#include"windows.h"
#include"cstring"


using namespace std;// Sirve para poder compilar las instrucciones C++//

//***SUBPROGRAMAS***//

void altas();
void bajas();
void buscarclave();
void consultas();
void salir();
void menu();

//***VARIABLES GLOBALES***// 
char auxNombre[30];
char nombre[30], aula[10], materia[20], hora[10], dia[20], resp[1];
int x, semestre=0, edad=0, clave=0, auxClave=0;
bool encontrado=false;
char auxGrupo[10];
int op=0;

//***En la linea siguiente las cadenas char requieren el espacio en blanco para que sea una sintaxis correcta***//
char mensaje[16]={' ',' ',' ','B','A','S','E',' ','D','E',' ','D','A','T','O','S'};
char mensaje1[13]={' ',' ',' ','C','O','M','P','L','E','T','A','D','O'};
char mensaje2[21]={'U','N','I','V','E','R','S','I','D','A','D',' ','D','E',' ','C','O','L','I','M','A'};
char mensaje3[30]={' ',' ',' ',' ',' ',' ','F','A','C','U','L','T','A','D',' ','D','E',' ','I','N','G','E','N','I','E','R','I','A',' ',' '};
char mensaje4[32]={' ',' ',' ',' ','E','L','E','C','T','R','O','M','E','C','A','N','I','C','A',' ','S','O','F','T','W','A','R','E',' ',' ',' ',' '};
char mensaje5[11]={'C','R','E','A','D','O',' ','P','O','R',':'};
char mensaje6[29]={'K','E','V','I','N',' ','J','E','S','U','S',' ','G','O','N','Z','A','L','E','Z',' ','M','A','R','T','I','N','E','Z'};


int main()//***AQUI EMPIEZA EL PROGRAMA***/
	{
		system("color 80"); //***CAMBIA EL COLOR DE FONDO***//
		menu(); //***EL COLOR SE USARA EN EL MENU***///
		return 0;
		system("PAUSE"); //***PARA EL PROGRAMA HASTA QUE DE UN TECLEO DE LETRA***//
	}
	void menu() //***EMPIEZA EL SUBPROGRAMA MENU***///
		{
			int opcion=0; //***VARIABLE INTERNA***//
		do{ //*** INICIO DEL CICLO ***//
		cout<<"\n\n\t\t\t";
		for (x=0; x<21; x++){
			cout <<mensaje2[x];
			Sleep(50);
		}
			cout<<"\n\t\t";
		for(x=0; x<30; x++){
			cout <<mensaje3[x];
			Sleep(50);
		}
			cout<<"\n\t\t";
		for(x=0; x<32; x++){
			cout <<mensaje4[x];
			Sleep(50);
		}
		cout<<"\n";
		cout<<"\n\t\t C++" <<endl;
		cout<<"\n\t\t 1.-Capturar Datos"<<endl;
		cout<<"\t\t 2.-Eliminar Datos"<<endl;
		cout<<"\t\t 3.-Consultar Datos"<<endl;
		cout<<"\t\t 4.-Buscar Datos"<<endl;
		cout<<"\t\t 5.-Salir"<<endl;
		cout<<"\t\t Elije una opcion... ";
		cin>>opcion;
		switch(opcion){
			case 1:
				altas();
				break;
			case 2:
				bajas();
				break;
			case 3:
				consultas();
				break;
			case 4:
				system("cls");
				system("color B0");
				cout<<"\n\t\t Estas en Buscar"; //***    "<<" SIGNIFICA UNIR ***          ***">>" ALMACENA DICHO VALOR ***//
				cout<<"\n\t\t 1.-Buscar por No. de cuenta"; //*** "COUT" SIGNIFICA IMPRIME LO QUE ESCRIBO ***		*** "CIN" SIGNIFICA LEER ***//
				cout<<"\n\t\t 2.-Salir";
				cout<<"\n\t\t Elige una Opcion: ";
				cin>>op;
				switch(op){
					case 1:
						buscarclave();
						break;
					case 2:
						system("cls");
						system("color 80");
						menu();
						break;
				          }
				          
			case 5: 
				menu();
				break;
			case 6:
				salir();
				break;
		} 
	}while(opcion!=6); //*** FIN DEL CICLO ***//
}//Fin funcion menu



void altas(){ //Empieza ALTAS
	system("cls");
	system("color 50");
	ofstream escritura; //Creamos la variable de tipo escritura
	ifstream consulta; //Creamos la variable de tipo consulta
	bool repetido=false; //Creamos variable tipo repetido
	
	
	escritura.open("alumnos.txt",ios::out|ios::app); //Abrimos el archivo
	consulta.open("alumnos.txt",ios::in); //Abrimos el archivo
	if(escritura.is_open() && consulta.is_open()){ //Validacion
	do{
		cout<<"\n\t\t ALUMNOS";
		cout<<"\n\t\t Ingresa la clave del alumno: ";
		cin>>auxClave;
		consulta>>clave; //lectura adelantada
		while(!consulta.eof()){ //*** EL .EOF (FIN DE ARCHIVO) SIRVE PARA ABRIR EL ARCHIVO QUE SE TIENE***	***EL SIGNO DE ADMIRACION "!" NEGACION BOOLEANA OSEA QUE SOLO TIENE UN OPERANDO//
			consulta>>nombre>>semestre>>aula>>edad>>materia>>hora>>dia;
			if(clave==auxClave){
				cout<<"\n\t\t Ya Existe un Registro con esta Clave"<<endl; 
				repetido=true;
				break;
			}
			consulta>>clave;
		}
		if(repetido==false){
			cout<<"\n\t\t Ingresa el nombre: ";
			cin>>nombre;
			cout<<"\n\t\t Ingresa el Semestre: ";
			cin>>semestre;
			cout<<"\n\t\t Ingresa el Aula: ";
			cin>>aula;
			cout<<"\n\t\t Ingresa la Edad: ";
			cin>>edad;
			cout<<"\n\t\t Ingresa la Materia: ";
			cin>>materia;
			cout<<"\n\t\t Ingresa la Hora de Registro: ";
			cin>>hora;
			cout<<"\n\t\t Ingresa la fecha de Registro: ";
			cin>>dia;
			escritura<<auxClave<<" "<<nombre<<" "<<semestre<<" "<<aula<<" "<<edad<<" "<<materia<<" "<<hora<<" "<<dia <<endl;
			cout<<"\n\t\t Registro Agregado"<<endl;
			cout<<"\n\t Desea agregar otro Alumno?";
			cin>>resp;
		}
	}while(resp[0]=='S'|resp[0]=='s');
	}
else{
	cout<<"Error, el Archivo No se Pudo Abrir o No ha sido Creado"<<endl;
}
system("pause");
system("cls");
system("color 80"); //*** REGRESA AL MENU CON EL COLOR QUE TENIA ANTERIORMENTE***//
escritura.close();
consulta.close();
}//Fin funcion altas


void consultas(){//Empieza funcion consultas
system("cls");
system("color 60");
ifstream lectura;
lectura.open("alumnos.txt",ios::out|ios::in);
if(lectura.is_open()){ 
cout<<"\n\t\tRegistros del Archivo alumnos.txt"<<endl;
lectura>>clave;
while(!lectura.eof()){
lectura>>nombre>>semestre>>aula>>edad>>materia>>hora>>dia;
cout<<"\t\t________________________________"<<endl;
cout<<"\n\t\tClave: "<<clave<<endl;
cout<<"\t\tNombre: "<<nombre<<endl;
cout<<"\t\tSemestre: "<<semestre<<endl;
cout<<"\t\tGrupo: "<<aula<<endl;
cout<<"\t\tEdad: "<<edad<<endl;
cout<<"\t\tMateria:"<<materia<<endl;
cout<<"\t\tHora:"<<hora<<endl;
cout<<"\t\tDia:"<<dia<<endl;
lectura>>clave;
cout<<"\t\t________________________________"<<endl;
}
}else{
cout<<"\n\t\tError, el Archivo No se Pudo Abrir, No ha sido creado"<<endl;
}
system("pause");
system("cls");
system("color 80");
lectura.close();
}//Fin funcion consultas


void bajas(){//Empieza bajas
system("cls");
system("color 20");
ofstream aux;
ifstream lectura;
encontrado=false;
auxClave=0;
aux.open("auxiliar.txt",ios::out);
lectura.open("alumnos.txt",ios::in);
if (aux.is_open() && lectura.is_open()){
cout <<"\n\tIngresa la Clave del Alumno que deseas Eliminar: ";
cin >>auxClave;
lectura>>clave;
while(!lectura.eof()){
lectura>>nombre>>semestre>>aula>>edad>>materia>>hora>>dia;
if(auxClave==clave){
encontrado=true;
cout <<"\n\tRegistro Eliminado"<<endl;
}else{
aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<aula<<" "<<edad<<" "<<materia<<" "<<hora<<" "<<dia <<endl;
}
lectura>>clave;
}
}else{
cout<<"\n\tNo se pudo Abrir el Archivo, o aun no ha sido Creado"<<endl;
}
if(encontrado==false){
cout <<"\n\tNo se encontro ningun Registro con Clave: " <<auxClave<<endl;
}
system("pause");
system("cls");
system("color 80");
aux.close();
lectura.close();
remove("alumnos.txt");
rename("auxiliar.txt","alumnos.txt");
}//Fin bajas


//**********************BUSCAR POR CLAVE**********************************
void buscarclave(){
ifstream lectura;//Creamos la variable de tipo lectura
lectura.open("alumnos.txt",ios::out|ios::in);//Abrimos el archivo
//validando la apertura del archivo
encontrado=false;
if(lectura.is_open()){
cout<<"\n\t\tIngresa la Clave del Alumno que deseas Buscar: ";
cin>>auxClave;
lectura>>clave;//lectura adelantada

while(!lectura.eof()){
lectura>>nombre>>semestre>>aula>>edad>>materia>>hora>>dia;//leyendo los campos del registro
//Comparar cada registro para ver si es encontrado
if(auxClave==clave){
cout<<"\n\t\t______________________________"<<endl;
cout<<"\t\tClave: "<<clave<<endl;
cout<<"\t\tNombre: "<<nombre<<endl;
cout<<"\t\tSemestre: "<<semestre<<endl;
cout<<"\t\tGrupo: "<<aula<<endl;
cout<<"\t\tEdad: "<<edad<<endl;
cout<<"\t\tMateria:"<<materia<<endl;
cout<<"\t\tHora:"<<hora<<endl;
cout<<"\t\tDia:"<<dia<<endl;
cout<<"\t\t______________________________"<<endl;
encontrado=true;
}

lectura>>clave;//lectura adelantada
}
if(encontrado==false){
cout<<"\n\t\tNo hay registros con la Clave "<<auxClave<<endl;
}
}else{
cout<<"\n\t\tNo se pudo Abrir el Archivo, aun no ha sido Creado"<<endl;
}
system("pause");
system("cls");
system("color 80");
//cerrando el archivo
lectura.close();

}


void salir(){
x=0;
cout <<"\n\n\t\t\t";
for (x=0; x<16; x++){
cout <<mensaje[x];
Sleep(100);
}
cout <<"\n\t\t\t ";
for (x=0; x<13; x++){
cout <<mensaje1[x];
Sleep(100);
}
cout<<"\n\n\t\t";
		for (x=0; x<11; x++)
			{
				cout <<mensaje5[x];
				Sleep(10);
			}
cout<<"\n\n\t\t";
		for (x=0; x<32; x++)
			{
				cout <<mensaje6[x];
				Sleep(10);
			}
cout<<"\n\n\t\t";
}
