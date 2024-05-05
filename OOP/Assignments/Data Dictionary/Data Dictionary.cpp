#include <iostream>
#include<string>
#include<fstream>

using namespace std;

void writefile(string filename, string word1) {
    ofstream obj1;
    obj1.open(filename, ios::app);
    if (obj1) {
        obj1 << word1 << endl;
    }
    obj1.close();
    return;
}

void Tokenization(string str, char del) {
    string word1 = "";
    int space = 0;
    int idxspace = 0;
    for (int i = 0; i < str.size() && idxspace != -1; i++) {
        i = 0;
        idxspace = str.find(' ');
        word1 = str.substr(0, idxspace);
        str = str.substr(idxspace + 1, str.size());
        writefile("dic.txt", word1);
        cout << word1 << endl;
    }
}

bool findSynonym(char **dic, int count, string str) {

    int idx_l=0;
    for(int i=0;i<count;i++) {
        idx_l = 0;
        for (int j = 0; j != str.length(); j++) {
            if (str[j] == dic[i][j]) {
                idx_l = i;
            } else {
                idx_l = 0;
                break;
            }
        }
        if(idx_l != 0){
            break;
        }
    }

    for(int j=str.length()+1;dic[idx_l][j]!='\0';j++){
        cout<<dic[idx_l][j];
    }
    cout<<endl;
}

bool findWordInDic(char **dic,string str, int count){
    int idx_l=0;
    for(int i=0;i<count;i++) {
        idx_l = 0;
        for (int j = 0; j != str.length(); j++) {
            if (str[j] == dic[i][j]) {
                idx_l++;
            } else {
                idx_l = 0;
                break;
            }
        }
        if(idx_l != 0){
            return true;
            break;
        }
    }
    return false;
}

int main() {
    char del = ' ';
    string str;
    cout << "Enter String: " << endl;
    getline(cin,str);
    Tokenization(str, del);
    fstream MyReadFile("dic.txt");

    string word;
    int count = 0;
    while (getline(MyReadFile, word)) {
        count++;
    }
    MyReadFile.close();
    cout << count;
    fstream ReadFile("dic.txt");
    char **dic = new char *[count];
    for (int i = 0; i < count; i++) {
        getline(ReadFile, word);
        dic[i] = new char[word.length()];
        strcpy(dic[i], word.c_str());
    }
    string str1,str2;
    cout << "Enter String Synonyms: " << endl;
    getline(cin,str1);
    findSynonym(dic, count, str1);
    cout << "Enter String: " << endl;
    getline(cin,str2);
    string word1 = "";
    int space = 0;
    int idxspace = 0;
    bool flag;
    for (int i = 0; i < str1.size() && idxspace != -1; i++) {
        flag - false;
        i = 0;
        idxspace = str2.find(' ');
        word1 = str2.substr(0, idxspace);
        str2 = str2.substr(idxspace + 1, str2.size());
        flag = findWordInDic(dic, word1,count);
        findSynonym(dic,count,word1);
        if(flag == true){
            cout << word1 << " In Dictionary" << endl;
        }
    }
}