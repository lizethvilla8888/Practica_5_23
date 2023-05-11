#include "database.h"

database::database()
{
    limit_append = '\n';
    limit_col = ',';
}

//guarda info en name privada
void database::set_name(string name)
{
    this->name = name;
}

//guarda info en path privada
void database::set_path(string path)
{
    this->path = path;
}

//puedo modificar el valor del limite de info por cualquier caracter \n
// main texto_viejo objeto_database.set_append_char (";")
void database::set_append_char(char a)
{
    limit_append = a;
}

//retorna info guardada en all_info
string database::get_all_database()
{
    read_all_database();
    return all_info;
}

//concatena un dato, recibe el string
//data el cual quiero concatenar, agrega caracter demimitador mas data
void database::append_data(string data)
{
    fstream file;
    string app_data;

    file.open(path+name, ios_base::app);

    if(file.is_open()){
        app_data.push_back(limit_append);
        app_data = app_data + data;
        file << app_data;
    }
    file.close();
}

//dato a ingresar en filas, # de fila donde quiero ingresar dato
// lee toda la base de datos
// separa mediente saltos de linea split
void database::insert_row(string data, unsigned int row)
{
    vector<string> info;

    read_all_database();
    info = split_string(all_info,'\n');
    if(row<info.size()){
        info.insert(info.begin()+row,data);
        write_database(vector2string(info,limit_append));
    }

}

//agrega una columna en el txt, recibe txt y el char limitador
void database::append_data_col(string data, char limitator)
{
    vector<string> info, col_info;

    read_all_database();
    info = split_string(all_info,'\n');
    col_info = split_string(data,limitator);
    if(col_info.size()==info.size()){
        for(unsigned long long i=0; i < info.size(); i++){
            info[i].push_back(limit_col);
            info[i] += col_info[i];
        }
        write_database(vector2string(info,limit_append));
    }
}

// elimina filas de txt
void database::delete_row(unsigned int row)
{
    vector<string> info;

    read_all_database();
    info = split_string(all_info,'\n');
    if(row<info.size()){
        info.erase(info.begin()+row);
        write_database(vector2string(info,limit_append));
    }
}

//retorna info permite tener info en el main
string database::get_row(unsigned int row)
{
    vector<string> info;

    read_all_database();
    info = split_string(all_info,'\n');

    return info[row];
}

//carga todas las filas a el main
vector<string> database::get_all_rows()
{
    vector<string> info;

    read_all_database();
    info = split_string(all_info,'\n');

    return info;
}

// ?? carga todas las columnas al main
vector<string> database::get_col(unsigned int col)
{
    vector<string> info, col_info, aux;

    read_all_database();
    info = split_string(all_info,'\n');

    for(unsigned long long i=0; i < info.size(); i++){
        aux = split_string(info[i],limit_col);
        col_info.push_back(aux[col]);
    }
    return col_info;
}


// Privadas

//lee toda la base de datos caracter por caracter
void database::read_all_database()
{
    fstream file;

    file.open(path+name, ios_base::in);

    while (!file.eof() && file.is_open()) {
        all_info.push_back(file.get());
    }
    all_info.pop_back();
    file.close();
}

//funcion que recibe texto de txt, y un caracter para buscarlo en el texto
// similar a practica 3
vector<string> database::split_string(string info, char a)
{
    int pos = 0, char_pos;
    vector<string> aux;

    char_pos = info.find(a,pos);

    while (char_pos != -1) {
        aux.push_back(info.substr(pos,char_pos-pos));
        pos = char_pos +1;
        char_pos = info.find(a,pos);
    }
    aux.push_back(info.substr(pos,info.size()-pos));

    return  aux;
}

//escribir en txt
void database::write_database(string info)
{
    fstream file;

    file.open(path+name, ios_base::out);
    file << info;
    file.close();
}

// La función concatena todas las cadenas en el vector "info",
//separadas por el carácter "a", y devuelve la cadena resultante.
string database::vector2string(vector<string> info, char a)
{
    string aux;

    for(unsigned long long i=0; i < info.size(); i++){
        aux += info[i];
        aux.push_back(a);
    }

    return aux;
}
