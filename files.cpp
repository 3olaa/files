/*                                                                               +---------+
                                                                                                 |  main   |
                                                                                                 +---------+
                                                                                                      |
         +------------------+----------+-----------------+--------+-----------------+-----------------+------------------+---------------+--------------------+-----------------------------+
         |                  |          |                 |        |                 |                 |                  |               |                    |                             |
  +-------------+  +------------+ +--------+  +-----------+  +---------+  +----------+  +----------+  +-----------+  +-------------+  +--------+  +---------+  +---------+  +------+  +---------+
  |   loadFile  |  | displayFile| |saveFile|  | createFile|  | counting|  |searchword|  |emptyfile |  | appendData|  | replaceword |  | toUpper|  | toLower |  | copyFile|  |cipher|  |closeFile|
  +-------------+  +------------+ +--------+  +-----------+  +---------+  +----------+  +----------+  +-----------+  +-------------+  +--------+  +---------+  +---------+  +------+  +---------+
*/
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <cstring>
#include <conio.h>

using namespace std;

void loadFile(fstream &file, char *fileName, vector<char> &loadVec);
void createFile();
void displayFile(fstream &file, char *fileName);
void saveFile(fstream &file, char *fileName, vector<char> &loadVec);
void counting (fstream &file, char *fileName);
void emptyfile (fstream &file, char *fileName);
void searchword (fstream &file , char *fileName);
void appendData(fstream &file, char *fileName);
void replaceword (fstream &file, char *fileName);
void toUpper(fstream &file, char *fileName);
void toLower(fstream &file, char *fileName);
void cipher(fstream &file, char *fileName);
void copyFile(fstream &file, char *fileName);
void closeFile(fstream &file);

int main(){
    fstream file;
    char* file_name = (char *) malloc(sizeof(char) * 100);
    int choice;
    vector<char> loadVec;
    while(true){
        cout << "Ahlan ya user ya hbibi\n1-Load an existing file\n" << "2-Creat a new file\n" << "3-Display file content\n" << "4-Save the loaded text from the same file again or different one\n" << "5-count the words and the characters in the file\n" << "6-search for a word in a file\n" << "7-empty file content\n" << "8-Add more content to the end of the file\n" << "9-Replace a word in a file with another word\n" << "10-Turn all the content file to the upper case\n" << "11-Turn all the content file to the lower case\n" << "12-Add another file to the end of the current file\n" << "13-Encrypt and decrypt the file\n" << "14-End\n";
        cin >> choice;
        cout << endl;
        if(cin.fail())
            choice = 14;
        switch(choice){
        case 1:
            loadFile(file, file_name, loadVec);
            break;
        case 2:
            createFile();
            break;
        case 3:
            displayFile(file, file_name);
            break;
        case 4:
            saveFile(file, file_name, loadVec);
            break;
        case 5:
            counting(file, file_name);
            break;
        case 6:
            searchword (file , file_name);
            break;
        case 7:
            emptyfile(file, file_name);
            break;
        case 8:
            appendData(file, file_name);
            break;
        case 9:
            replaceword (file, file_name);
            break;
        case 10:
            toUpper(file, file_name);
            break;
        case 11:
            toLower(file, file_name);
            break;
        case 12:
            copyFile(file, file_name);
            break;
        case 13:
            cipher(file, file_name);
            break;
        case 14:
            closeFile(file);
            cout << "Thanks for using our program! =D";
            return 0;
            break;
        default:
            cout << "Wrong choice, please re-choose a number: ";
            break;
        }
        cout << "\nPress any key to continue... ";
        getch();
        system("cls");
    }
}

void loadFile(fstream &file, char *fileName, vector<char> &loadVec){
    file.close();
    char character;
    cout << "please, Enter the existing file name" << endl;
    cin.ignore();
    cin.getline(fileName, 100, '\n');
    file.open(fileName, ios::in);
    if(file.is_open() && !file.fail()){
        cout << "your file has been opened " << endl;
        while(true){
            file >> noskipws >> character;
            if(file.eof())
                break;
            loadVec.push_back(character);
        }
        cout << "Done loading file!!\n";
    }
    else cout << "file not open" << endl;
}

void createFile(){
    fstream file;
    char* fileName = (char *) malloc(sizeof(char) * 100);
    char* line = (char *) malloc(sizeof(char) * 256);
    cout<< "please, enter a file name"<<endl;
    cin.ignore();

    cin.getline(fileName, 100, '\n');
    file.open(fileName, ios::out);
    if (file.fail() || !file.is_open()){
        cout << "Error Creating File.";
        return;
    }
    cout << "The file " << fileName << " was created successfully!!" << endl
         << "Add some text to your file then press CTRL-X to exit:\n";
    cin.getline(line, 256, '\x18');
    file << line;
}

void displayFile(fstream &file, char *fileName){
    char character;
    file.close();
    file.open(fileName, ios::in);
    if(file.fail() || !file.is_open()){
        cout << "Error opening file.";
        return;
    }
    cout << "The file content: \n";
    while(true){
        file >> noskipws >> character;
        if(file.eof())
            break;
        cout << character;
    }
    cout << "\nEND OF FILE\n";
}
void saveFile(fstream &file, char *fileName, vector<char> &loadVec){
    if(!file.is_open())
        loadFile(file, fileName, loadVec);
    file.close();
    cout << "Enter name of file to save data in: ";
    cin.ignore();
    cin.getline(fileName, 100, '\n');
    file.open(fileName, ios::in | ios::app);
    for(int i = 0; i < loadVec.size(); i++){
        file << loadVec[i];
    }
    cout << "Done saving data!\n";
}
void counting (fstream &file, char *fileName){
    char* character = (char *) malloc(sizeof(char) * 100);
    int nwords=0;
    int ncharacters=0;
    file.close();
    file.open(fileName,ios::in);
    if (file.fail())
        {cout<< "error"<<endl;}
    while(file>>skipws>>character)
            {
                ++nwords;
                for (int i=0 ; i<strlen(character);i++){
                    ++ncharacters;
                }
            }
    cout<< "the number of words in the file= "<<nwords<<endl;
    cout<< "the number of characters in the file= "<<ncharacters<<endl;
}
void emptyfile (fstream &file, char *fileName){
    file.close();
    file.open(fileName, ios::out | ios::trunc);
    if(file.fail() || !file.is_open()){
        cout << "Error opening file.";
        return;}
    file.close();
    cout<< "Done! your file is empty now"<<endl;

}
void searchword (fstream &file , char *fileName){
    file.close();
    char* line = (char *) malloc(sizeof(char) * 256);
    char* sword = (char *) malloc(sizeof(char) * 100);
    char* index;
    file.open(fileName);
    if(file.fail() || !file.is_open()){
        cout << "Error opening file.";
        return;
    }
    cout<< "enter a word you want to search: ";
    cin>>sword;
    if(file.is_open()){
        while (!file.eof()&& !file.fail())
        {
            file.getline(line, 256);
            for (int i=0; i<strlen(line); i++){
                line[i] = toupper(line[i]);
            }

            for (int i=0; i<strlen(sword); i++){
                sword[i] = toupper(sword[i]);
            }

            index = strstr(line, sword);
            if (index != nullptr){
                cout<< "your word is found in the file"<<endl;
                break;
            }
        }
        if(index == nullptr)  cout<< "your word is not found in the file"<<endl;
    }
}

void replaceword(fstream &file, char *fileName){
    vector<char> fileData;
    vector<char> exword;
    vector<char> repword;
    char character;
    bool is_found = false;
    int index;
    file.close();
    file.open(fileName);
    while(!file.eof()){
        file >> character;
        fileData.push_back(character);
    }

    cout << "Enter word to be replaced: ";
    //cin.clear();
    cin.ignore();
    while(cin.get(character)){
        //cout << character << endl;
        if(character == '\n')
            break;
        exword.push_back(character);
    }

    cout << "\nEnter replacing word: ";
    cin.clear();
    //cin.ignore();
    while(cin.get(character)){
        if(character == '\n')
            break;
        repword.push_back(character);
    }

    for(int i=0; i<fileData.size(); i++){
        for(int j=0; j<exword.size(); j++){
            if(toupper(exword[j]) == toupper(fileData[i])){
                is_found = true;
                i++;
                continue;
            }
            else{
                is_found = false;
                break;
            }
        }
        if(is_found == true){
            index = i - exword.size();
            break;
        }
        is_found = false;

        }
    if(is_found == true){
        repword.push_back(' ');
        fileData.erase(fileData.begin()+index, fileData.begin()+index+exword.size());
        fileData.insert(fileData.begin()+index, repword.begin(), repword.end());
        for(int i=0 ; i< fileData.size()-1;i++)
            cout << fileData[i];
    }
    file.close();
    file.open(fileName, ios::out);
    for (int i=0 ; i< fileData.size()-1;i++)
    {
        file<<fileData[i];
    }




}

void appendData(fstream &file, char *fileName ){
    file.close();
    file.open(fileName , ios::in | ios::out | ios::app);
    if(file.fail() || !file.is_open()){
        cout << "Error opening file.";
        return;
    }
    char* app_content = (char *) malloc(sizeof(char) * 256);
    cout<< "Enter more data at the end of the file, press CTRL-X to save: ";
    cin.ignore();
    cin.getline(app_content, 256, '\x18');
    file<<" "<<app_content;
}

void copyFile(fstream &file, char *fileName){
    file.close();
    char* character = (char *) malloc(sizeof(char) * 100);
    char* fileName2 = (char *) malloc(sizeof(char) * 100);
    cout << "Enter File Name: ";
    cin.ignore();
    cin.getline(fileName2, 100, '\n');
    file.open(fileName2, ios::in);
    if(file.is_open())
        cout << "File opened" << endl;
    //file << "copyyyy";
    file.getline(character, 1000, EOF);
    file.close();
    file.open(fileName, ios::out | ios::app);
    file<< " ";
    for(int i=0; i<strlen(character); i++)
        file << character[i];
    cout << "Done copying..\n";


}

void toUpper(fstream &file, char *fileName){
    file.close();
    char* line = (char *) malloc(sizeof(char) * 256);
    file.open(fileName);
    while (!file.eof()& !file.fail())
    {
        file.getline(line, 256, '\n');
        for (int i=0 ; i<strlen(line);i++)
        {
            if (line[i]>=97 && line[i]<=123)               //small letters between 97 and 123
            {
                 line[i]-=32;
            }
        }
        cout<<line<< " ";
    }
    file.close();
    file.open(fileName, ios::out);
        for (int i=0 ; i< strlen(line);i++)
    {
        file<<line[i];
    }


}

void toLower(fstream &file, char *fileName){
    file.close();
    char* line = (char *) malloc(sizeof(char) * 256);
    file.open(fileName);
    while (!file.eof()& !file.fail())
    {
        file.getline(line, 256, '\n');
        for (int i=0 ; i<strlen(line);i++)
        {
            if (line[i]>=65 && line[i]<=91)        //capital letter between 65 and 91
            {
                 line[i]+=32;
            }
        }
        cout<<line<< " ";
    }
    file.close();
    file.open(fileName, ios::out);
        for (int i=0 ; i< strlen(line);i++)
    {
        file<<line[i];
    }

}

void cipher(fstream &file, char *fileName){
    char character;
    vector<char> charVec;
    cout<< "choose \n"<< "1-cipher \n"<<"2-decipher \n"<<endl;
    int choise;
    cin>>choise;
    if (choise==1 || choise==2){
        file.close();
        file.open(fileName, ios::in);
        string part1="ABCDEFGHIJKLM";
        string part2="NOPQRSTUVWXYZ";
        while(!file.eof ()& !file.fail()){
            file >> noskipws >> character;
            if (islower(character)){
                character = toupper(character);
            }

            for(unsigned int w = 0; w < part1.size(); w++){
                if(character == ' '){
                    //cout << character;
                    charVec.push_back(character);
                    break;
                }
                if(character == '\n'){
                    //cout << character;
                    charVec.push_back(character);
                    break;
                }
                if(character == part1[w]){
                    //cout << part2[w];
                    charVec.push_back(part2[w]);
                }
                if(character == part2[w]){
                    //cout << part1[w];
                    charVec.push_back(part1[w]);
                }
            }
        }
    }
    cout<< "DONE!"<<endl;
    file.close();
    file.open(fileName, ios::out | ios::trunc);
    for (int i=0 ; i< charVec.size()-1;i++)
    {
        file<<charVec[i];
    }

    file.close();
    cout << endl;
}

void closeFile(fstream &file){
    file.close();
}

