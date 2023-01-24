#include <iostream>
#include <vector>
#include <algorithm>
#include<array>
#include <cstring>
#include<bits/stdc++.h>
#define max 4
using namespace std;

int binarySearchString(vector<string> arr, string x, int n) {
   int lower = 0;
   int upper = n - 1;
   while (lower <= upper) {
      int mid = lower + (upper - lower) / 2;
      int res;
      if (x == (arr[mid])){
         res = 0;
      }
      if (res == 0){
         return mid;
      }
      if (x > (arr[mid])){
         lower = mid + 1;
      }
      else{
         upper = mid - 1;
      }
   }
   return -1;
}
void bubblesort(vector<string> &strings)
{
    typedef std::vector<std::string>::size_type size_type;
    for (size_type i = 1; i < strings.size(); ++i)
    {
        for (size_type j = 0; j < (strings.size() - 1); ++j)
        {
            if(strings[j] > strings[j+1])
            {
                std::string const temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j+1] = temp;
            }
        }
    }
}

string strings[max];
int len(string str){
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}
void split (string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= len(str))
    {
        if (str[i] == seperator || i == len(str))
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

int main()
{
    cout << "-= Data Resep Makanan =-" << endl;
    //Temp Variable
    char choice;
    string hapusResep;
    string fullResep;
    string updateResep;
    string cariBahan;

    string fullMenu;
    string fullBahan;
    //Data Resep Makanan
    //Array
    vector<string> arrayResep;

    //Field
    string idMenu;
    string idBahan;
    string namaMenu;
    string namaBahan;
    do{
        cout << "a.Tampilkan Data Resep" << endl;
        cout << "b.Tampilkan Data Resep Secara Terurut" << endl;
        cout << "c.Tambah Resep Baru" << endl;
        cout << "d.Hapus Resep" << endl;
        cout << "e.Update Resep" << endl;
        cout << "f.Cari Bahan Berdasarkan Menu" << endl;
        cout << "g.Cari Menu" << endl;
        cout << "q.Keluar" << endl;
        cout << " " <<endl;
        cout << "Masukan Pilihan Anda contoh (a): ";
        cin >> choice;
        if(choice == 'q' ) {
            printf("Terminating the program...");
        }
        else{
            if(choice == 'a'){
                cout << endl << endl;
                cout << "Data Semua Resep : " << endl;
                for (int i = 0; i < arrayResep.size(); i++){
                    split(arrayResep[i], ';');
                    cout << strings[0] << " | " << strings[1] << " | " << strings[2] << " | " << strings[3];
                    cout << endl;
                }
                cout << endl << endl;
            }else if(choice == 'b'){
                cout << endl << endl;
                cout << "Data Semua Menu : " << endl;
                bubblesort(arrayResep);
                for (int i = 0; i < arrayResep.size(); i++){
                    split(arrayResep[i], ';');
                    cout << strings[0] << " | " << strings[1] << " | " << strings[2] << " | " << strings[3];
                    cout << endl;
                }
                cout << endl << endl;
            }else if(choice == 'c'){
                cout << endl << endl;
                cout << "Masukan ID Menu Makanan : " ;
                getline (cin >> ws, idMenu);
                cout << "Masukan ID Bahan : ";
                getline (cin, idBahan);
                cout << "Masukan Nama Menu : ";
                getline (cin, namaMenu);
                cout << "Masukan Nama Bahan : ";
                getline (cin, namaBahan);
                fullResep = idMenu + ";" + idBahan + ";"  + namaMenu + ";" + namaBahan;
                arrayResep.push_back(fullResep);
                cout << "Resep berhasil ditambahkan!" << endl;
                cout << endl << endl;
            }else if(choice =='d'){
                cout << endl << endl;
                cout << "Data Semua Resep : " << endl;
                for (int i = 0; i < arrayResep.size(); i++){
                    split(arrayResep[i], ';');
                    cout << i << ". "<< strings[0] << " | " << strings[1] << " | " << strings[2] << " | " << strings[3];
                    cout << endl;
                }
                cout << "Silahkan pilih resep yang ingin di hapus : " ;
                getline (cin >> ws, hapusResep);
                for(int i = 0; i < arrayResep.size() ; i++){
                    if (arrayResep[i].find(hapusResep) != std::string::npos) {
                        arrayResep.erase (arrayResep.begin()+i);
                        break;
                    }
                }
                cout << " " << endl;
                cout << "Resep Berhasil Di Hapus!" << endl;
                cout << endl << endl;
            }else if(choice == 'e'){
                cout << endl << endl;
                cout << "Data Semua Resep : " << endl;
                for (int i = 0; i < arrayResep.size(); i++){
                    split(arrayResep[i], ';');
                    cout << i << ". "<< strings[0] << " | " << strings[1] << " | " << strings[2] << " | " << strings[3];
                    cout << endl;
                }
                cout << "Silahkan pilih resep yang ingin di update : ";
                getline (cin >> ws, updateResep);
                for(int i = 0; i < arrayResep.size(); i++){
                    if(arrayResep[i].find(updateResep) != std::string::npos){
                        cout << "Masukan ID Menu Makanan yang baru : " ;
                        getline (cin, idMenu);
                        cout << "Masukan ID Bahan : ";
                        getline (cin, idBahan);
                        cout << "Masukan Nama Menu : ";
                        getline (cin, namaMenu);
                        cout << "Masukan Nama Bahan : ";
                        getline (cin, namaBahan);
                        fullResep = idMenu + ";" + idBahan + ";"  + namaMenu + ";" + namaBahan;
                        arrayResep[i] = fullResep;
                    }
                }
                cout << endl << endl;
            }else if(choice == 'f'){
                cout << endl << endl;
                cout << "Data Semua Resep : " << endl;
                for (int i = 0; i < arrayResep.size(); i++){
                    split(arrayResep[i], ';');
                    cout << i << ". "<< strings[0] << " | " << strings[1] << " | " << strings[2] << " | " << strings[3];
                    cout << endl;
                }
                cout << "Masukan nama menu yang bahannya ingin dicari : ";
                getline (cin >> ws, cariBahan);
                for(int i = 0; i < arrayResep.size(); i++){
                    if(arrayResep[i].find(cariBahan) != std::string::npos){
                        split(arrayResep[i], ';');
                        cout << strings[1] << " | " << strings[3];
                        cout << endl;
                    }
                }
                cout << endl << endl;
            }else if(choice == 'g'){
                string x;
                cout << endl << endl;
                vector<string> arrayMenu;
                for (int i = 0; i < arrayResep.size(); i++){
                    split(arrayResep[i], ';');
                    arrayMenu.push_back(strings[2]);
                }
                cout << "Masukan nama menu : ";
                getline (cin >> ws, x);
                    int n = 4;
                    int result = binarySearchString(arrayMenu, x, n);
                    if(result == -1){
                        cout<<("Data tidak ditemukan!");
                    }else{
                        cout<<("Data ditemkan pada index ke : ")<<result<<endl;
                        split(arrayResep[result], ';');
                        cout << strings[0] << " | " << strings[1] << " | " << strings[2] << " | " << strings[3];
                    }
                cout << endl << endl;
            }
        }
    }while(choice != 'q');

    return 0;
}
