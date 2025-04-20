#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Paper {
    string judul;
    string sumber;
    string penulis;
    int tahun;
    string link;
};

vector<Paper> loadData(const string& filename) {
    vector<Paper> data;
    ifstream file(filename);
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ';')) {
            tokens.push_back(token);
        }

        if (tokens.size() >= 11 &&
            !tokens[3].empty() &&
            !tokens[5].empty() &&
            !tokens[6].empty() &&
            all_of(tokens[6].begin(), tokens[6].end(), ::isdigit) &&
            !tokens[7].empty() &&
            !tokens[10].empty()) {

            Paper p;
            p.sumber = tokens[3];
            p.judul = tokens[5];
            p.tahun = stoi(tokens[6]);
            p.penulis = tokens[7];
            p.link = tokens[10];
            data.push_back(p);
        }
    }
    return data;
}

void printPaper(const Paper& p) {
    cout << "----------------------------------------\n";
    cout << "Judul Paper: " << p.judul << "\n";
    cout << "Sumber : " << p.sumber << "\n";
    cout << "Penulis (Author) : " << p.penulis << "\n";
    cout << "Tahun Terbit : " << p.tahun << "\n";
    cout << "----------------------------------------\n\n";
}

template<typename T>
void linearSearch(const vector<Paper>& data, const T& keyword, const string& mode) {
    bool found = false;
    for (const auto& p : data) {
        if ((mode == "judul" && p.judul.find(keyword) != string::npos) ||
            (mode == "penulis" && p.penulis.find(keyword) != string::npos) ||
            (mode == "tahun" && to_string(p.tahun) == keyword)) {
            printPaper(p);
            found = true;
        }
    }
    if (!found) cout << "Data tidak ditemukan!\n";
}

bool compareJudul(const Paper& a, const Paper& b) { return a.judul < b.judul; }
bool comparePenulis(const Paper& a, const Paper& b) { return a.penulis < b.penulis; }
bool compareTahun(const Paper& a, const Paper& b) { return a.tahun < b.tahun; }

void binarySearch(vector<Paper>& data, const string& keyword, const string& mode) {
    if (mode == "judul") sort(data.begin(), data.end(), compareJudul);
    else if (mode == "penulis") sort(data.begin(), data.end(), comparePenulis);
    else if (mode == "tahun") sort(data.begin(), data.end(), compareTahun);

    bool found = false;
    for (const auto& p : data) {
        if ((mode == "judul" && p.judul.find(keyword) != string::npos) ||
            (mode == "penulis" && p.penulis.find(keyword) != string::npos) ||
            (mode == "tahun" && to_string(p.tahun) == keyword)) {
            printPaper(p);
            found = true;
        }
    }
    if (!found) cout << "Data tidak ditemukan!\n";
}

int main() {
    vector<Paper> data = loadData("data.csv");
    int metode, tipe;
    string keyword;
    char loop;

    do {
        system("cls");
        cout << "====== Menu Mencari Paper ======\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "Pilih metode pencarian (1-2) : ";
        cin >> metode;
        cin.ignore();

        system("cls");
        cout << "======  Cari berdasarkan  ======\n";
        cout << "1. Judul\n";
        cout << "2. Tahun Terbit\n";
        cout << "3. Nama Penulis\n";
        cout << "Pilih tipe pencarian (1-3) : ";
        cin >> tipe;
        cin.ignore();

        system("cls");
        cout << "======      Keyword       ======\n";
        cout << "Masukkan keyword : ";
        getline(cin, keyword);

        system("cls");
        if (tipe == 2 && metode == 2) binarySearch(data, keyword, "tahun");
        else if (tipe == 2) linearSearch(data, keyword, "tahun");
        else if (tipe == 1 && metode == 2) binarySearch(data, keyword, "judul");
        else if (tipe == 1) linearSearch(data, keyword, "judul");
        else if (tipe == 3 && metode == 2) binarySearch(data, keyword, "penulis");
        else linearSearch(data, keyword, "penulis");

        cout << "Ingin mencari lagi? (Y/N) : ";
        cin >> loop;
    } while (loop == 'Y' || loop == 'y');
    
    system("cls");
    cout << "Program selesai. Terima kasih! ^-^" << endl;
    return 0;
}