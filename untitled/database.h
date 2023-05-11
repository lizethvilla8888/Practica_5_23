#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class database
{
public:
    database();
    void set_name(string name);
    void set_path(string path);
    void set_append_char(char a);
    string get_all_database();
    void append_data(string data);
    void insert_row(string data, unsigned int row);
    void append_data_col(string data, char limitator);
    void delete_row(unsigned int row);
    string get_row(unsigned int row);
    vector<string> get_all_rows();
    vector<string> get_col(unsigned int col);

private:

    void read_all_database();
    vector<string> split_string(string info, char a);
    void write_database(string info);
    string vector2string(vector<string> info, char a);

    vector<string> info_row;
    string name, path, all_info;
    char limit_append, limit_col;
};

#endif // DATABASE_H
