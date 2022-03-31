#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <cstring>
#include <bits/stdc++.h>
#include <vector>
using namespace std; 
const char *nom_archivo="archivo.dat";


int cont;
int id;
struct estudiante{
  int codigo;
  char nombre[50];
  char apellido[50];
  char direccion[50];
  int telefono;
  };

void crear();
void leer();
void actualizar();
void del();
void delarchivo();
main(){
  do{
  system("cls");
  std::cout << " BIENVENIDO " << '\n';
  std::cout << "SELECCIONE LO QUE DESEA REALIZAR: " << '\n';
  std::cout << " (1) PARA CREAR ESTUDIANTE" << '\n';
  std::cout << " (2) BUSCAR ESTUDIANTE" << '\n';
  std::cout << " (3) ACTUALIZAR DATOS ESTUDIANTE " << '\n';
  std::cout << " (4) ELIMINAR ESTUDIANTE" << '\n';
  std::cout << " INGRESE (0)" << '\n';
  std::cin >> cont;
  switch (cont) {
    case 0: exit(EXIT_SUCCESS);

    case 1: crear(); break;

    case 2: leer(); break;

    case 3: actualizar(); break;

    case 4: del();

    case 5: delarchivo(); break;

    default : std::cout << "NUMERO INCORRECTO, INTENTE DE NUEVO POR FAVOR" << '\n'; system("pause");
  }



}while(1==1);
}

void crear(){
  FILE* archivo = fopen(nombre_archivo,"ZP");
  char continuar;
  Estudiante *estudiante,d;
  estudiante = &d;

  string nombre,apellido,direccion;
  do{
    system("cls");
    fflush(stdin);
    std::cout << "CODIGO: " << '\n';
    std::cin >> (*estudiante).codigo;
    cin.ignore();

    std::cout << "Nombres: " << '\n';
    getline(cin,nombre);
    strcpy((*estudiante).nombre,nombre.c_str());

    std::cout << "Apellido: " << '\n';
    getline(cin,apellido);
    strcpy((*estudiante).apellido,apellido.c_str());

    std::cout << "Direccion: " << '\n';
    getline(cin,direccion);
    strcpy((*estudiante).direccion,direccion.c_str());

    std::cout << "Telefono: " << '\n';
    std::cin >> (*estudiante).telefono;
    cin.ignore();
    fwrite(&d,sizeof(Estudiante),1,archivo);

    std::cout << "SELECCIONE PARA AGREGAR OTRO ESTUDIANTE (s/n): " << '\n';
    std::cin >> continuar;
  }while(continuar=='s' || continuar=='S');
  fclose(archivo);

}


void leer(){
  system("cls");
  FILE* archivo = fopen(nombre_archivo,"rb");
  if(!archivo){
    std::cerr << "EL ARCHIVO NO ESXISTE " << '\n'; system("pause"); system("cls");
    archivo = fopen(nombre_archivo,"w+b");
  }
  Estudiante *estudiante,d;
  estudiante = &d;

  int id=0;
  fread(&d,sizeof(Estudiante),1,archivo);
  std::cout << "id" << "|" << "nombres" << "|" << "apellido" << "|" << "Direccion" << "|" << "telefono" <<'\n';
    do {
      std::cout << "________________________________________________________________________" << '\n';
      std::cout << id << "|" <<(*estudiante).codigo << "|" << (*estudiante).nombre << "|" << (*estudiante).apellido << "|" << (*estudiante).direccion << "|" << (*estudiante).telefono << '\n';
      fread(&d,sizeof(Estudiante),1,archivo);
      id+=1;
    } while(feof(archivo)==0);
    fclose(archivo);
    system("pause");
}

void actualizar(){
  FILE* archivo = fopen(nombre_archivo,"r+b");
  int id;
  Estudiante *estudiante,d;
  estudiante = &d;
  string nombre,apellido,direccion;
  std::cout << "ingrese el id a modificar: ";
  std::cin >> id;
  fseek(archivo,id *sizeof(Estudiante),SEEK_SET);

  std::cout << "ingrese codigo: " << '\n';
  std::cin >> (*estudiante).codigo;
  cin.ignore();

  std::cout << "ingrese nombres: " << '\n';
  getline(cin,nombre);
  strcpy((*estudiante).nombre,nombre.c_str());

  std::cout << "ingrese apellido: " << '\n';
  getline(cin,apellido);
  strcpy((*estudiante).apellido,apellido.c_str());

  std::cout << "ingrese direccion: " << '\n';
  getline(cin,direccion);
  strcpy((*estudiante).direccion,direccion.c_str());

  std::cout << "ingrese telefono: " << '\n';
  std::cin >> (*estudiante).telefono;
  cin.ignore();
  fwrite(&d,sizeof(Estudiante),1,archivo);
  fclose(archivo);


}
//hay un fallo al recopilar la informacion del archivo .dat y no deja insertarla en el nuevo documento
//solo funciona con archivo.txt
/*
void del(){
	FILE *archivo, *Ftemp;
  char str[MAX], temp[] = "Ftemp.dat";
  int lno,ctr =0;

	archivo=fopen(nombre_archivo,"r");
  if(!archivo){
    std::cout << "archivo no encotrado" << '\n';
  }
  //abre un archivo temporal para copiar el contenido
	Ftemp=fopen(temp,"w");
  if(!Ftemp){
    std::cout << "archivo no encontrado" << '\n';
  }
	cout<<"ingresa el codigo del alumno a eliminar:"<<endl;
	cin>>lno;
  lno++;
		while(!feof(archivo)){
      strcpy(str, "\0");
      fgets(str, MAX, archivo);
			if (!feof(archivo)){
        ctr++;
        if(ctr != lno){
          fprintf(Ftemp, "%s", str);
        }
      }
		//	fwrite(&d,sizeof(Estudiante),1,Ftemp);
			}
		fclose(Ftemp);
		fclose(archivo);
    remove(nombre_archivo);
    rename(temp,nombre_archivo);
}*/


/*
void del(){
  FILE *archivo, *ftemp;
  char *temp = "Ftemp.dat";
  char curr;
  int del, line_number = 0;
  printf("ingresa la linea : ");
  scanf("%d", &del);
  archivo = fopen(nombre_archivo,"r");
  ftemp = fopen(temp, "w");
  curr = getc(archivo);
  if(curr!=EOF) {line_number =1;}
  while(1){
    if(del != line_number)
      putc(curr, ftemp);
      curr = getc(archivo);
      if(curr =='\n') line_number++;
      if(curr == EOF) break;
}
fclose(archivo);
fclose(ftemp);
remove(nombre_archivo);
rename(temp, nombre_archivo);



}*/

/*
void del(){
  FILE *archivo, *ftemp;
  //const char *nombre_archivo="archivo.dat";
  char temp[MAX];
  char buffer[MAX];
  int delete_line = 0;

  strcpy(temp,"temp____");
  strcat(temp, nombre_archivo);
  std::cout << "linea que desea eliminar: " << '\n';
  std::cin >> delete_line;

  archivo = fopen(nombre_archivo, "r");
  ftemp = fopen(temp,"w");

  if(archivo==NULL || ftemp==NULL){
    std::cout << "error abriendo archivos" << '\n';
  }

  bool keep_reading = true;
  int current_line = 1;
  do{
    fgets(buffer, MAX, archivo);

    if(feof(archivo)) keep_reading = false;
    else if (current_line != delete_line)
      fputs(buffer, ftemp);

    current_line++;


  }while(keep_reading);

  fclose(archivo);
  fclose(ftemp);
  remove(nombre_archivo);
  rename(temp, nombre_archivo);

}*/


void del(){
  std::cout << "ingrese la linea  quedeseas borrar: " << '\n';
  std::cin >> n;
  string line;
  ifstream in("archivo.dat");
  if( !in.is_open())
  {
        cout << "Input file failed to open\n";

  }
  ofstream out("temp.dat");

   while( getline(in,line) )
   {
       if(line != n)
           out << line << "\n";
   }
   in.close();
   out.close();

   remove("archivo.dat");

   rename("temp.dat","archivo.dat");
}

/*
void del(){
  vector<string> STR;
  ifstream infile;

  infile.open ("names.txt");

  for(size_t i = 0; i < 7; i++)
  {
      string st;
      getline (infile, st);
      STR.push_back(st);
      cout << STR[i] << endl;
  }

  infile.close();

}*/

void delarchivo(){
  if (remove("archivo.dat") == 0)
        std::cout << "el archivo se elimino con exito" << '\n';
     else{
        std::cerr << "archivo no encotrado" << '\n'; system("pause");
      }
}
