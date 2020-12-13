#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class GlobalClass {
private:
    vector<string> m_outPage;
    string message;
    static GlobalClass* s_instance;

    GlobalClass(vector<string> v = {}, string m = "") {
        m_outPage = v;
        message = m;
    }
public:
    string get_value() {
        string in;
        for (int i = 0; i < m_outPage.size(); i++) {
            if (i < 9) {
                cout << " " << i + 1 << "| " << m_outPage[i] << endl;
            }
            else {
                cout << i + 1 << "| " << m_outPage[i] << endl;
            }
        }
        string nextLine = "------------------------------------------------------------------------------";
        string workMenu = "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후종료";
        cout << nextLine << endl;
        cout << workMenu << endl;
        cout << nextLine << endl;
        cout << message << endl;
        cout << nextLine << endl;
        cout << "입력:";
        getline(cin,in);
        cout << nextLine << endl;
        return in;
    }
    void set_value(vector<string> v, string m) {
        m_outPage = v;
        message = m;
    }
    static GlobalClass* instance() {
        if (!s_instance) {
            s_instance = new GlobalClass;
        }
        return s_instance;
    }
};

string run(vector<string> page) {
    GlobalClass::instance()->set_value(page, "Please input command.");
    return GlobalClass::instance()->get_value();
}

string previousError(vector<string> page) {
    GlobalClass::instance()->set_value(page, "This is the first page!");
    return GlobalClass::instance()->get_value();
}

string error(vector<string> page) {
    GlobalClass::instance()->set_value(page, "Error! Please reinput");
    return GlobalClass::instance()->get_value();
}

string nextError(vector<string> page) {
    GlobalClass::instance()->set_value(page, "This is the last page!");
    return GlobalClass::instance()->get_value();
}

GlobalClass* GlobalClass::s_instance = 0;

int main() {
    string stringBuffer;
    vector<string> word;
    streampos begin, end;
    ifstream myfile("test.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, stringBuffer, ' ')) {
            word.push_back(stringBuffer);
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    vector<vector<string>> page;
    vector<string> line;
    int lineByte = word[0].length();
    string tempLine = word[0];

    for (int i = 1; i < word.size(); i++) {
        lineByte += (word[i].length() + 1);
        if (lineByte > 75) {
            line.push_back(tempLine);
            if (line.size() == 20) {
                page.push_back(line);
                line.clear();
            }
            lineByte = word[i].length();
            tempLine = word[i];
        }
        else {
            tempLine.append(" ");
            tempLine.append(word[i]);
        }
    }

    page.push_back(line);

    string in;
    string find;
    string change;
    vector<string> spl;
    bool found;
    int currentPage = 0;
    int index;
    int previous;
    int one, two, three;
    int count;
    int max;
    bool err;

    in = run(page[currentPage]);

    while (true) {
        if (in.find(" ") != string::npos) {
            in = error(page[currentPage]);
        } else {
            if (in[0] == 'p') {
                if (currentPage == 0) {
                    in = previousError(page[currentPage]);
                }
                else {
                    currentPage -= 1;
                    in = run(page[currentPage]);
                }
            }
            else if (in[0] == 'n') {
                if (currentPage == page.size() - 1) {
                    in = nextError(page[currentPage]);
                }
                else {
                    currentPage += 1;
                    in = run(page[currentPage]);
                }
            }
            else if (in[0] == 's') {
                found = false;
                find = in.substr(2, in.length() - 3);

                page.clear();
                line.clear();
                lineByte = word[0].length();
                tempLine = word[0];
                if (find.compare(word[0]) == 0) {
                    currentPage = page.size();
                    found = true;
                }

                for (int i = 1; i < word.size(); i++) {
                    if (find.compare(word[i]) == 0 && !found) {
                        if (line.size() != 0) {
                            page.push_back(line);
                            line.clear();
                        }                      
                        currentPage = page.size();
                        found = true;
                    }
                    lineByte += (word[i].length() + 1);
                    if (lineByte > 75) {
                        line.push_back(tempLine);
                        if (line.size() == 20) {
                            page.push_back(line);
                            line.clear();
                        }
                        lineByte = word[i].length();
                        tempLine = word[i];
                    }
                    else {
                        tempLine.append(" ");
                        tempLine.append(word[i]);
                    }
                }

                page.push_back(line);
                
                in = run(page[currentPage]);
            }
            else if (in[0] == 'c') {
                index = in.find(",");
                find = in.substr(2, index - 2);
                change = in.substr(index + 1, in.length() - index - 2);

                page.clear();
                line.clear();
                lineByte = word[0].length();
                tempLine = word[0];
                if (find.compare(word[0]) == 0) {
                    word[0] = change;
                }

                for (int i = 1; i < word.size(); i++) {
                    if (find.compare(word[i]) == 0) {
                        word[i] = change;
                    }
                    lineByte += (word[i].length() + 1);
                    if (lineByte > 75) {
                        line.push_back(tempLine);
                        if (line.size() == 20) {
                            page.push_back(line);
                            line.clear();
                        }
                        lineByte = word[i].length();
                        tempLine = word[i];
                    }
                    else {
                        tempLine.append(" ");
                        tempLine.append(word[i]);
                    }
                }

                page.push_back(line);

                in = run(page[currentPage]);
            }
            else if (in[0] == 'i') {
                previous = 2;
                index = in.find(',');
                spl.clear();
                while (index != string::npos)
                {
                    tempLine = in.substr(previous, index - previous);
                    spl.push_back(tempLine);
                    previous = index + 1;
                    index = in.find(',', previous);
                }
                tempLine = in.substr(previous, in.length() - previous - 1);
                spl.push_back(tempLine);
                err = false;
                for (int i = 0; i < spl[0].size(); i++) {
                    if (!isdigit(spl[0][i])) {
                        err = true;
                    }
                }
                for (int i = 0; i < spl[1].size(); i++) {
                    if (!isdigit(spl[1][i])) {
                        err = true;
                    }
                }
                if (err) {
                    in = error(page[currentPage]);
                }
                else {
                    one = stoi(spl[0]);
                    two = stoi(spl[1]);
                    if (one > 20) {
                        in = error(page[currentPage]);
                    }
                    else if (spl[2].length() > 75) {
                        in = error(page[currentPage]);
                    }
                    else {
                        count = 0;
                        for (int i = 0; i < currentPage; i++) {
                            for (int j = 0; j < page[i].size(); j++) {
                                istringstream iss(page[i][j]);
                                while (getline(iss, stringBuffer, ' ')) {
                                    count++;
                                }
                            }
                        }
                        for (int j = 0; j < one - 1; j++) {
                            istringstream iss(page[currentPage][j]);
                            while (getline(iss, stringBuffer, ' ')) {
                                count++;
                            }
                        }
                        istringstream iss(page[currentPage][one]);
                        max = 0;
                        while (getline(iss, stringBuffer, ' ')) {
                            max++;
                        }
                        if (max < two) {
                            in = error(page[currentPage]);
                        }
                        else {
                            count += two;
                            count -= 1;
                            word.insert(word.begin() + count, spl[2]);
                            page.clear();
                            line.clear();
                            lineByte = word[0].length();
                            tempLine = word[0];

                            for (int i = 1; i < word.size(); i++) {
                                lineByte += (word[i].length() + 1);
                                if (lineByte > 75) {
                                    line.push_back(tempLine);
                                    if (line.size() == 20) {
                                        page.push_back(line);
                                        line.clear();
                                    }
                                    lineByte = word[i].length();
                                    tempLine = word[i];
                                }
                                else {
                                    tempLine.append(" ");
                                    tempLine.append(word[i]);
                                }
                            }

                            page.push_back(line);

                            in = run(page[currentPage]);
                        }
                    }
                }             
            }
            else if (in[0] == 'd') {
                previous = 2;
                index = in.find(',');
                spl.clear();
                while (index != string::npos)
                {
                    tempLine = in.substr(previous, index - previous);
                    spl.push_back(tempLine);
                    previous = index + 1;
                    index = in.find(',', previous);
                }
                tempLine = in.substr(previous, in.length() - previous - 1);
                spl.push_back(tempLine);
                err = false;
                for (int i = 0; i < spl[0].size(); i++) {
                    if (!isdigit(spl[0][i])) {
                        err = true;
                    }
                }
                for (int i = 0; i < spl[1].size(); i++) {
                    if (!isdigit(spl[1][i])) {
                        err = true;
                    }
                }
                if (err) {
                    in = error(page[currentPage]);
                }
                else {
                    one = stoi(spl[0]);
                    two = stoi(spl[1]);
                    if (one > 20) {
                        in = error(page[currentPage]);
                    }
                    else {
                        count = 0;
                        for (int i = 0; i < currentPage; i++) {
                            for (int j = 0; j < page[i].size(); j++) {
                                istringstream iss(page[i][j]);
                                while (getline(iss, stringBuffer, ' ')) {
                                    count++;
                                }
                            }
                        }
                        for (int j = 0; j < one - 1; j++) {
                            istringstream iss(page[currentPage][j]);
                            while (getline(iss, stringBuffer, ' ')) {
                                count++;
                            }
                        }
                        istringstream iss(page[currentPage][one]);
                        max = 0;
                        while (getline(iss, stringBuffer, ' ')) {
                            max++;
                        }
                        if (max < two) {
                            in = error(page[currentPage]);
                        }
                        else {
                            count += two;
                            count -= 1;
                            word.erase(word.begin() + count);
                            page.clear();
                            line.clear();
                            lineByte = word[0].length();
                            tempLine = word[0];

                            for (int i = 1; i < word.size(); i++) {
                                lineByte += (word[i].length() + 1);
                                if (lineByte > 75) {
                                    line.push_back(tempLine);
                                    if (line.size() == 20) {
                                        page.push_back(line);
                                        line.clear();
                                    }
                                    lineByte = word[i].length();
                                    tempLine = word[i];
                                }
                                else {
                                    tempLine.append(" ");
                                    tempLine.append(word[i]);
                                }
                            }

                            page.push_back(line);

                            in = run(page[currentPage]);
                        }
                    }
                }
            }
            else if (in[0] == 't') {
                ofstream myfile;
                myfile.open("test.txt");
                for (int i = 0; i < word.size(); i++) {
                    myfile << word[i];
                    myfile << " ";
                }
                myfile.close();
                return 0;
            }
            else {
                in = error(page[currentPage]);
            }
        }
    }
}